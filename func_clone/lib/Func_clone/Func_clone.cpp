#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/ADT/ilist.h"
#include "llvm/IR/Function.h" 
#include "llvm/Support/Casting.h"
#include "llvm/IR/Instructions.h"

namespace   {
    struct Proj : public llvm::ModulePass   {
        static char ID;
        Proj() : llvm::ModulePass(ID)   {}

        virtual bool runOnModule(llvm::Module &m)   {
            llvm::ConstantInt* const_int32_7 = llvm::ConstantInt::get(m.getContext(), llvm::APInt(32, llvm::StringRef("5"), 10));
            llvm::GlobalVariable* gvar_int32_global = new llvm::GlobalVariable(m, llvm::IntegerType::get(m.getContext(), 32), false,
llvm::GlobalValue::ExternalLinkage, 0, "global");

            gvar_int32_global->setAlignment(4);
            gvar_int32_global->setInitializer(const_int32_7);   
            llvm::errs() << "Proj: ";
            llvm::errs().write_escaped(m.getModuleIdentifier()) << '\n';
            llvm::errs() << gvar_int32_global->getInitializer()->getUniqueInteger() << '\n';
            for(llvm::Module::iterator Fb = m.begin(), Fe = m.end(); Fb != Fe; ++Fb)    {
                llvm::Function *F = llvm::dyn_cast<llvm::Function>(&*Fb);
                for (llvm::inst_iterator I = llvm::inst_begin(F), E = llvm::inst_end(F); I != E; ++I)   {
                    if (llvm::CallInst* callInst = llvm::dyn_cast<llvm::CallInst>(&*I)) {
                        llvm::errs() << *callInst << "\n";      
                    }
                }
            }
            llvm::errs() << gvar_int32_global->getInitializer()->getUniqueInteger() << '\n';
            return false;
        }

    };
}

char Proj::ID = 0;
static llvm::RegisterPass<Proj> X("proj", "Custom Pass", false, false);
