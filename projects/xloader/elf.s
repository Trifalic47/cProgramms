	.file	"elf.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"test"
	.text
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rsi, %rbx
	cmpl	$1, %edi
	jle	.L6
.L2:
	movq	8(%rbx), %rdi
	call	validate_elf@PLT
	cmpl	$-1, %eax
	je	.L4
	movq	8(%rbx), %rdi
	call	read_header@PLT
	movq	%rax, %rbx
	movq	%rax, %rdi
	call	read_elf@PLT
	movq	%rax, %r14
	movq	%rbx, %rdi
	call	read_Phdr@PLT
	movq	%rax, %rsi
	subq	$64, %rsp
	.cfi_def_cfa_offset 96
	movl	$14, %ecx
	movq	%rsp, %rdi
	rep movsl
	subq	$64, %rsp
	.cfi_def_cfa_offset 160
	movl	$16, %ecx
	movq	%rsp, %rdi
	movq	%r14, %rsi
	rep movsl
	call	print_Ahdr@PLT
	subq	$-128, %rsp
	.cfi_def_cfa_offset 32
	movq	%rbx, %rdi
	call	free@PLT
	movl	$0, %eax
.L1:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	leaq	.LC0(%rip), %rax
	movq	%rax, 8(%rsi)
	jmp	.L2
.L4:
	movl	$1, %eax
	jmp	.L1
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
