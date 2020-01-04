	.file	"name_maker.c"
	.text
	.section	.rodata
.LC0:
	.string	"Kevin"
.LC1:
	.string	"Briony"
.LC2:
	.string	"Patrick"
.LC3:
	.string	"Mitchell"
.LC4:
	.string	"Wood"
.LC5:
	.string	"Holloway"
	.text
	.globl	assign_names
	.type	assign_names, @function
assign_names:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movq	$.LC0, -48(%rbp)
	movq	$.LC1, -40(%rbp)
	movq	$.LC2, -32(%rbp)
	movq	$.LC3, -80(%rbp)
	movq	$.LC4, -72(%rbp)
	movq	$.LC5, -64(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L2
.L3:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	$16, %edi
	call	malloc
	movq	%rax, (%rbx)
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	movq	-48(%rbp,%rdx,8), %rdx
	movq	%rdx, (%rax)
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	movq	-80(%rbp,%rdx,8), %rdx
	movq	%rdx, 8(%rax)
	addl	$1, -20(%rbp)
.L2:
	cmpl	$2, -20(%rbp)
	jle	.L3
	nop
	nop
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	assign_names, .-assign_names
	.section	.rodata
.LC6:
	.string	"%s %s\n"
	.text
	.globl	print_names
	.type	print_names, @function
print_names:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L5:
	cmpl	$2, -4(%rbp)
	jle	.L6
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	print_names, .-print_names
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	assign_names
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	print_names
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
