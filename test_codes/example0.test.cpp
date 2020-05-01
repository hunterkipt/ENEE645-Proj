// Generated by llvm2cpp - DO NOT MODIFY!

#include <llvm/Pass.h>
#include <llvm/PassManager.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/MathExtras.h>
#include <algorithm>
using namespace llvm;

Module* makeLLVMModule();

int main(int argc, char**argv) {
  Module* Mod = makeLLVMModule();
  verifyModule(*Mod, PrintMessageAction);
  PassManager PM;
  PM.add(createPrintModulePass(&outs()));
  PM.run(*Mod);
  return 0;
}


Module* makeLLVMModule() {
 // Module Construction
 Module* mod = new Module("example0.bc", getGlobalContext());
 mod->setDataLayout("e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128");
 mod->setTargetTriple("x86_64-unknown-linux-gnu");
 
 // Type Definitions
 ArrayType* ArrayTy_0 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 3);
 
 PointerType* PointerTy_1 = PointerType::get(ArrayTy_0, 0);
 
 ArrayType* ArrayTy_2 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 5);
 
 PointerType* PointerTy_3 = PointerType::get(ArrayTy_2, 0);
 
 ArrayType* ArrayTy_4 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 23);
 
 PointerType* PointerTy_5 = PointerType::get(ArrayTy_4, 0);
 
 std::vector<Type*>FuncTy_6_args;
 FunctionType* FuncTy_6 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_6_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_7 = PointerType::get(FuncTy_6, 0);
 
 std::vector<Type*>FuncTy_8_args;
 PointerType* PointerTy_9 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);
 
 FuncTy_8_args.push_back(PointerTy_9);
 FunctionType* FuncTy_8 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_8_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_10 = PointerType::get(PointerTy_9, 0);
 
 PointerType* PointerTy_11 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);
 
 std::vector<Type*>FuncTy_13_args;
 FuncTy_13_args.push_back(PointerTy_11);
 FunctionType* FuncTy_13 = FunctionType::get(
  /*Result=*/IntegerType::get(mod->getContext(), 32),
  /*Params=*/FuncTy_13_args,
  /*isVarArg=*/true);
 
 PointerType* PointerTy_12 = PointerType::get(FuncTy_13, 0);
 
 std::vector<Type*>FuncTy_14_args;
 FuncTy_14_args.push_back(IntegerType::get(mod->getContext(), 32));
 FunctionType* FuncTy_14 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_14_args,
  /*isVarArg=*/false);
 
 std::vector<Type*>FuncTy_15_args;
 FunctionType* FuncTy_15 = FunctionType::get(
  /*Result=*/IntegerType::get(mod->getContext(), 32),
  /*Params=*/FuncTy_15_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_16 = PointerType::get(FuncTy_8, 0);
 
 PointerType* PointerTy_17 = PointerType::get(FuncTy_14, 0);
 
 
 // Function Declarations
 
 Function* func_pop_direct_branch = mod->getFunction("pop_direct_branch");
 if (!func_pop_direct_branch) {
 func_pop_direct_branch = Function::Create(
  /*Type=*/FuncTy_6,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"pop_direct_branch", mod); 
 func_pop_direct_branch->setCallingConv(CallingConv::C);
 }
 AttributeSet func_pop_direct_branch_PAL;
 {
  SmallVector<AttributeSet, 4> Attrs;
  AttributeSet PAS;
   {
    AttrBuilder B;
    B.addAttribute(Attribute::NoUnwind);
    B.addAttribute(Attribute::UWTable);
    PAS = AttributeSet::get(mod->getContext(), ~0U, B);
   }
  
  Attrs.push_back(PAS);
  func_pop_direct_branch_PAL = AttributeSet::get(mod->getContext(), Attrs);
  
 }
 func_pop_direct_branch->setAttributes(func_pop_direct_branch_PAL);
 
 Function* func_scan_int = mod->getFunction("scan_int");
 if (!func_scan_int) {
 func_scan_int = Function::Create(
  /*Type=*/FuncTy_8,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"scan_int", mod); 
 func_scan_int->setCallingConv(CallingConv::C);
 }
 AttributeSet func_scan_int_PAL;
 {
  SmallVector<AttributeSet, 4> Attrs;
  AttributeSet PAS;
   {
    AttrBuilder B;
    B.addAttribute(Attribute::NoUnwind);
    B.addAttribute(Attribute::UWTable);
    PAS = AttributeSet::get(mod->getContext(), ~0U, B);
   }
  
  Attrs.push_back(PAS);
  func_scan_int_PAL = AttributeSet::get(mod->getContext(), Attrs);
  
 }
 func_scan_int->setAttributes(func_scan_int_PAL);
 
 Function* func___isoc99_scanf = mod->getFunction("__isoc99_scanf");
 if (!func___isoc99_scanf) {
 func___isoc99_scanf = Function::Create(
  /*Type=*/FuncTy_13,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"__isoc99_scanf", mod); // (external, no body)
 func___isoc99_scanf->setCallingConv(CallingConv::C);
 }
 AttributeSet func___isoc99_scanf_PAL;
 {
  SmallVector<AttributeSet, 4> Attrs;
  AttributeSet PAS;
   {
    AttrBuilder B;
    PAS = AttributeSet::get(mod->getContext(), ~0U, B);
   }
  
  Attrs.push_back(PAS);
  func___isoc99_scanf_PAL = AttributeSet::get(mod->getContext(), Attrs);
  
 }
 func___isoc99_scanf->setAttributes(func___isoc99_scanf_PAL);
 
 Function* func_print_int = mod->getFunction("print_int");
 if (!func_print_int) {
 func_print_int = Function::Create(
  /*Type=*/FuncTy_14,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"print_int", mod); 
 func_print_int->setCallingConv(CallingConv::C);
 }
 AttributeSet func_print_int_PAL;
 {
  SmallVector<AttributeSet, 4> Attrs;
  AttributeSet PAS;
   {
    AttrBuilder B;
    B.addAttribute(Attribute::NoUnwind);
    B.addAttribute(Attribute::UWTable);
    PAS = AttributeSet::get(mod->getContext(), ~0U, B);
   }
  
  Attrs.push_back(PAS);
  func_print_int_PAL = AttributeSet::get(mod->getContext(), Attrs);
  
 }
 func_print_int->setAttributes(func_print_int_PAL);
 
 Function* func_printf = mod->getFunction("printf");
 if (!func_printf) {
 func_printf = Function::Create(
  /*Type=*/FuncTy_13,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"printf", mod); // (external, no body)
 func_printf->setCallingConv(CallingConv::C);
 }
 AttributeSet func_printf_PAL;
 {
  SmallVector<AttributeSet, 4> Attrs;
  AttributeSet PAS;
   {
    AttrBuilder B;
    PAS = AttributeSet::get(mod->getContext(), ~0U, B);
   }
  
  Attrs.push_back(PAS);
  func_printf_PAL = AttributeSet::get(mod->getContext(), Attrs);
  
 }
 func_printf->setAttributes(func_printf_PAL);
 
 Function* func_main = mod->getFunction("main");
 if (!func_main) {
 func_main = Function::Create(
  /*Type=*/FuncTy_15,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"main", mod); 
 func_main->setCallingConv(CallingConv::C);
 }
 AttributeSet func_main_PAL;
 {
  SmallVector<AttributeSet, 4> Attrs;
  AttributeSet PAS;
   {
    AttrBuilder B;
    B.addAttribute(Attribute::NoUnwind);
    B.addAttribute(Attribute::UWTable);
    PAS = AttributeSet::get(mod->getContext(), ~0U, B);
   }
  
  Attrs.push_back(PAS);
  func_main_PAL = AttributeSet::get(mod->getContext(), Attrs);
  
 }
 func_main->setAttributes(func_main_PAL);
 
 // Global Variable Declarations

 
 GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/ArrayTy_0,
 /*isConstant=*/true,
 /*Linkage=*/GlobalValue::PrivateLinkage,
 /*Initializer=*/0, // has initializer, specified below
 /*Name=*/".str");
 gvar_array__str->setAlignment(1);
 
 GlobalVariable* gvar_array__str1 = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/ArrayTy_2,
 /*isConstant=*/true,
 /*Linkage=*/GlobalValue::PrivateLinkage,
 /*Initializer=*/0, // has initializer, specified below
 /*Name=*/".str1");
 gvar_array__str1->setAlignment(1);
 
 GlobalVariable* gvar_array__str2 = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/ArrayTy_4,
 /*isConstant=*/true,
 /*Linkage=*/GlobalValue::PrivateLinkage,
 /*Initializer=*/0, // has initializer, specified below
 /*Name=*/".str2");
 gvar_array__str2->setAlignment(1);
 
 // Constant Definitions
 Constant *const_array_18 = ConstantDataArray::getString(mod->getContext(), "%d", true);
 Constant *const_array_19 = ConstantDataArray::getString(mod->getContext(), "%d \x0A", true);
 Constant *const_array_20 = ConstantDataArray::getString(mod->getContext(), "The entered value is: ", true);
 ConstantInt* const_int32_21 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
 std::vector<Constant*> const_ptr_22_indices;
 ConstantInt* const_int32_23 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
 const_ptr_22_indices.push_back(const_int32_23);
 const_ptr_22_indices.push_back(const_int32_23);
 Constant* const_ptr_22 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_22_indices);
 std::vector<Constant*> const_ptr_24_indices;
 const_ptr_24_indices.push_back(const_int32_23);
 const_ptr_24_indices.push_back(const_int32_23);
 Constant* const_ptr_24 = ConstantExpr::getGetElementPtr(gvar_array__str1, const_ptr_24_indices);
 std::vector<Constant*> const_ptr_25_indices;
 const_ptr_25_indices.push_back(const_int32_23);
 const_ptr_25_indices.push_back(const_int32_23);
 Constant* const_ptr_25 = ConstantExpr::getGetElementPtr(gvar_array__str2, const_ptr_25_indices);
 
 // Global Variable Definitions
 gvar_array__str->setInitializer(const_array_18);
 gvar_array__str1->setInitializer(const_array_19);
 gvar_array__str2->setInitializer(const_array_20);
 
 // Function Definitions
 
 // Function: pop_direct_branch (func_pop_direct_branch)
 {
  
  BasicBlock* label_26 = BasicBlock::Create(mod->getContext(), "",func_pop_direct_branch,0);
  
  // Block  (label_26)
  InlineAsm* ptr_28 = InlineAsm::get(FuncTy_6, "popq %rbp
	addq $$8, %rsp
	leave
	movq (%rsp), %rax
	addq $$8, %rsp
	jmp *%rax
	", "~{dirflag},~{fpsr},~{flags}",true);
  CallInst* void_27 = CallInst::Create(ptr_28, "", label_26);
  void_27->setCallingConv(CallingConv::C);
  void_27->setTailCall(false);
  AttributeSet void_27_PAL;
  {
   SmallVector<AttributeSet, 4> Attrs;
   AttributeSet PAS;
    {
     AttrBuilder B;
     B.addAttribute(Attribute::NoUnwind);
     PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }
   
   Attrs.push_back(PAS);
   void_27_PAL = AttributeSet::get(mod->getContext(), Attrs);
   
  }
  void_27->setAttributes(void_27_PAL);
  
  ReturnInst::Create(mod->getContext(), label_26);
  
 }
 
 // Function: scan_int (func_scan_int)
 {
  Function::arg_iterator args = func_scan_int->arg_begin();
  Value* ptr_x = args++;
  ptr_x->setName("x");
  
  BasicBlock* label_30 = BasicBlock::Create(mod->getContext(), "",func_scan_int,0);
  
  // Block  (label_30)
  AllocaInst* ptr_31 = new AllocaInst(PointerTy_9, "", label_30);
  ptr_31->setAlignment(8);
  StoreInst* void_32 = new StoreInst(ptr_x, ptr_31, false, label_30);
  void_32->setAlignment(8);
  LoadInst* ptr_33 = new LoadInst(ptr_31, "", false, label_30);
  ptr_33->setAlignment(8);
  std::vector<Value*> int32_34_params;
  int32_34_params.push_back(const_ptr_22);
  int32_34_params.push_back(ptr_33);
  CallInst* int32_34 = CallInst::Create(func___isoc99_scanf, int32_34_params, "", label_30);
  int32_34->setCallingConv(CallingConv::C);
  int32_34->setTailCall(false);
  AttributeSet int32_34_PAL;
  int32_34->setAttributes(int32_34_PAL);
  
  ReturnInst::Create(mod->getContext(), label_30);
  
 }
 
 // Function: print_int (func_print_int)
 {
  Function::arg_iterator args = func_print_int->arg_begin();
  Value* int32_x = args++;
  int32_x->setName("x");
  
  BasicBlock* label_36 = BasicBlock::Create(mod->getContext(), "",func_print_int,0);
  
  // Block  (label_36)
  AllocaInst* ptr_37 = new AllocaInst(IntegerType::get(mod->getContext(), 32), "", label_36);
  ptr_37->setAlignment(4);
  StoreInst* void_38 = new StoreInst(int32_x, ptr_37, false, label_36);
  void_38->setAlignment(4);
  LoadInst* int32_39 = new LoadInst(ptr_37, "", false, label_36);
  int32_39->setAlignment(4);
  std::vector<Value*> int32_40_params;
  int32_40_params.push_back(const_ptr_24);
  int32_40_params.push_back(int32_39);
  CallInst* int32_40 = CallInst::Create(func_printf, int32_40_params, "", label_36);
  int32_40->setCallingConv(CallingConv::C);
  int32_40->setTailCall(false);
  AttributeSet int32_40_PAL;
  int32_40->setAttributes(int32_40_PAL);
  
  CallInst* void_41 = CallInst::Create(func_pop_direct_branch, "", label_36);
  void_41->setCallingConv(CallingConv::C);
  void_41->setTailCall(false);
  AttributeSet void_41_PAL;
  void_41->setAttributes(void_41_PAL);
  
  ReturnInst::Create(mod->getContext(), label_36);
  
 }
 
 // Function: main (func_main)
 {
  
  BasicBlock* label_43 = BasicBlock::Create(mod->getContext(), "",func_main,0);
  
  // Block  (label_43)
  AllocaInst* ptr_44 = new AllocaInst(IntegerType::get(mod->getContext(), 32), "", label_43);
  ptr_44->setAlignment(4);
  AllocaInst* ptr_a = new AllocaInst(IntegerType::get(mod->getContext(), 32), "a", label_43);
  ptr_a->setAlignment(4);
  StoreInst* void_45 = new StoreInst(const_int32_23, ptr_44, false, label_43);
  CallInst* void_46 = CallInst::Create(func_scan_int, ptr_a, "", label_43);
  void_46->setCallingConv(CallingConv::C);
  void_46->setTailCall(false);
  AttributeSet void_46_PAL;
  void_46->setAttributes(void_46_PAL);
  
  CallInst* int32_47 = CallInst::Create(func_printf, const_ptr_25, "", label_43);
  int32_47->setCallingConv(CallingConv::C);
  int32_47->setTailCall(false);
  AttributeSet int32_47_PAL;
  int32_47->setAttributes(int32_47_PAL);
  
  LoadInst* int32_48 = new LoadInst(ptr_a, "", false, label_43);
  int32_48->setAlignment(4);
  CallInst* void_49 = CallInst::Create(func_print_int, int32_48, "", label_43);
  void_49->setCallingConv(CallingConv::C);
  void_49->setTailCall(false);
  AttributeSet void_49_PAL;
  void_49->setAttributes(void_49_PAL);
  
  ReturnInst::Create(mod->getContext(), const_int32_23, label_43);
  
 }
 
 return mod;
}