#include "llvm/Pass.h"
#include "llvm/Module.h"
#include "llvm/Support/raw_ostream.h"

namespace {
struct FuncClone :  public llvm::ModulePass
{

    static char ID;                           
    FuncClone() : llvm::ModulePass(ID) {}

    virtual bool runOnModule(llvm::Module &M) {
	llvm::errs() << "FuncClone: ";
        llvm::errs().write_escaped(M.getName()) << "\n";
        return false;
    }

};
}

char FuncClone::ID = 0;
static RegisterPass<FuncClone> X("func_clone", "Function Cloning Pass", false, false);



