#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/ADT/ilist.h"
#include "llvm/IR/Function.h" 
#include "llvm/Support/Casting.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/ADT/Twine.h"

namespace   {
    struct FuncClone : public llvm::ModulePass   {
        static char ID;
        unsigned cloneCount;

        FuncClone() : llvm::ModulePass(ID)   { cloneCount = 0; }

        llvm::Function *cloningPass(const llvm::Function *F) {
            llvm::ClonedCodeInfo codeInfo;
            llvm::ValueToValueMapTy VMap;

            llvm::Function* clone = llvm::CloneFunction(F, VMap, false, &codeInfo);
            llvm::Twine suffix = llvm::Twine("_clone_").concat(llvm::Twine(cloneCount));
            
            llvm::Twine newN = llvm::Twine(clone->getName()).concat(suffix);
            clone->setName(newN);
            cloneCount++;

            return clone;
        }
        
        bool modifyClone(llvm::Function *F, llvm::GlobalVariable *global) {
            bool hasRetVal = false;
            for (llvm::inst_iterator I = llvm::inst_begin(F), E = llvm::inst_end(F); I != E; ++I)   {
                if (llvm::ReturnInst* retInst = llvm::dyn_cast<llvm::ReturnInst>(&*I)) {
                    llvm::Value* retVal = retInst->getReturnValue();
                    if (retVal) {
                        llvm::StoreInst* storeToGlobal = new llvm::StoreInst(retVal, global, retInst);
                        hasRetVal = true;
                    }
                   
                    llvm::CallInst* callPop = llvm::CallInst::Create(F->getParent()->getFunction("pop_direct_branch"),
                                "", retInst);
                }
            }
            return hasRetVal;
        }
        
        unsigned getInstructionCount(llvm::Function* F) const {
            llvm::inst_iterator I = llvm::inst_begin(F), E = llvm::inst_end(F);
            unsigned NumInstrs = std::distance(I, E); 
            
            return NumInstrs;
        }

        virtual bool runOnModule(llvm::Module &m)   {
            /* Initialize Global Variable */
            llvm::ConstantInt* const_int32_7 = llvm::ConstantInt::get(m.getContext(), llvm::APInt(32, llvm::StringRef("0"), 10));
            llvm::GlobalVariable* gvar_int32_global = new llvm::GlobalVariable(m, llvm::IntegerType::get(m.getContext(), 32), false,
                llvm::GlobalValue::ExternalLinkage, 0, "global");

            gvar_int32_global->setAlignment(4);
            gvar_int32_global->setInitializer(const_int32_7);
            /* loop through instructions to find call sites */
            llvm::errs() << "Proj: ";
            llvm::errs().write_escaped(m.getModuleIdentifier()) << '\n';
            llvm::errs() << gvar_int32_global->getInitializer()->getUniqueInteger() << '\n';
            for(llvm::Module::iterator Fb = m.begin(), Fe = m.end(); Fb != Fe; ++Fb)    {
                llvm::Function *F = llvm::dyn_cast<llvm::Function>(&*Fb);
                for (llvm::inst_iterator I = llvm::inst_begin(F), E = llvm::inst_end(F); I != E; ++I)   {
                    if (llvm::CallInst* callInst = llvm::dyn_cast<llvm::CallInst>(&*I)) {
                        llvm::errs() << *callInst << "\n";
                        /* Call site found: Check if there's a calling fn */
                        llvm::Function *Callee = callInst->getCalledFunction();
                        if (Callee && Callee->getName()[0] == 'p' &&
                                getInstructionCount(Callee) != 0) {
                            /* clone the found function */
                            llvm::errs() << Callee->getName() << "\n";
                            llvm::errs() << getInstructionCount(Callee) << "\n";
                            llvm::Function *clone = cloningPass(Callee);
                            llvm::errs() << clone->getName() << "\n";
                            m.getFunctionList().push_front(clone);
                            bool hasRetVal = modifyClone(clone, gvar_int32_global);
                            if (hasRetVal) {
                                /* Cloned function has a retVal */
                                llvm::Instruction *next = &*(++I);
                                llvm::LoadInst *loadGlobal = new llvm::LoadInst(gvar_int32_global, "", next);
                                callInst->replaceAllUsesWith(loadGlobal);
                                --I; // Reset iterator so we don't skip instructions.
                            }
                            callInst->setCalledFunction(clone);
                        }
                    }
                }
            }
            llvm::errs() << gvar_int32_global->getInitializer()->getUniqueInteger() << '\n';
            return true; // Module is always modified since we create a global.
        }

    };
}

char FuncClone::ID = 0;
static llvm::RegisterPass<FuncClone> X("func_clone", "Function Cloning Pass", false, false);
