	.file	"example0.bc"
	.text
	.globl	scan_int
	.align	16, 0x90
	.type	scan_int,@function
scan_int:                               # @scan_int
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp2:
	.cfi_def_cfa_offset 16
.Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, %rcx
	movq	%rcx, -8(%rbp)
	movl	$.L.str, %edi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	callq	__isoc99_scanf
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp5:
	.size	scan_int, .Ltmp5-scan_int
	.cfi_endproc

	.globl	print_int
	.align	16, 0x90
	.type	print_int,@function
print_int:                              # @print_int
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp8:
	.cfi_def_cfa_offset 16
.Ltmp9:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp10:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, %ecx
	movl	%ecx, -4(%rbp)
	movl	$.L.str1, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp11:
	.size	print_int, .Ltmp11-print_int
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp14:
	.cfi_def_cfa_offset 16
.Ltmp15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp16:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	leaq	-8(%rbp), %rdi
	callq	scan_int
	movl	$.L.str2, %edi
	xorl	%eax, %eax
	callq	printf
	movl	-8(%rbp), %edi
	callq	print_int
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp17:
	.size	main, .Ltmp17-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d"
	.size	.L.str, 3

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"%d \n"
	.size	.L.str1, 5

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"The entered value is: "
	.size	.L.str2, 23


	.ident	"clang version 3.4 (tags/RELEASE_34/final)"
	.section	".note.GNU-stack","",@progbits
