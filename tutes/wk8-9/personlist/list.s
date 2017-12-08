	.file	"list.c"
	.text
	.globl	get_next_id
	.type	get_next_id, @function
get_next_id:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	curid.2884(%rip), %eax
	addl	$1, %eax
	movl	%eax, curid.2884(%rip)
	movl	curid.2884(%rip), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	get_next_id, .-get_next_id
	.globl	list_init
	.type	list_init, @function
list_init:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movl	$16, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movl	$1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	list_init, .-list_init
	.section	.rodata
.LC0:
	.string	"malloc failed"
	.text
	.globl	list_add
	.type	list_add, @function
list_add:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	$0, -16(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -24(%rbp)
	call	get_next_id
	movl	%eax, -28(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L6
	movl	$.LC0, %edi
	call	perror
	movl	$0, %eax
	jmp	.L7
.L6:
	movq	-48(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, 88(%rax)
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	testl	%eax, %eax
	jne	.L8
	movq	-40(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	leal	1(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 8(%rax)
	movl	$1, %eax
	jmp	.L7
.L8:
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L9
.L11:
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L9:
	cmpq	$0, -8(%rbp)
	je	.L10
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	person_cmp
	testl	%eax, %eax
	js	.L11
.L10:
	cmpq	$0, -16(%rbp)
	jne	.L12
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L13
.L12:
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L13:
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	leal	1(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 8(%rax)
	movl	$1, %eax
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	list_add, .-list_add
	.section	.rodata
	.align 8
.LC1:
	.string	"Error: can't delete from an empty list.\n"
.LC2:
	.string	"Error: item not found.\n"
	.text
	.globl	list_remove
	.type	list_remove, @function
list_remove:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	$0, -16(%rbp)
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	testl	%eax, %eax
	jne	.L15
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$40, %edx
	movl	$1, %esi
	movl	$.LC1, %edi
	call	fwrite
	movl	$0, %eax
	jmp	.L14
.L15:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L17
.L19:
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L17:
	cmpq	$0, -8(%rbp)
	je	.L18
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	88(%rax), %eax
	cmpl	-28(%rbp), %eax
	jl	.L19
.L18:
	cmpq	$0, -8(%rbp)
	je	.L20
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	88(%rax), %eax
	cmpl	-28(%rbp), %eax
	je	.L21
.L20:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC2, %edi
	call	fwrite
	movl	$0, %eax
	jmp	.L14
.L21:
	cmpq	$0, -16(%rbp)
	jne	.L22
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	jmp	.L23
.L22:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
.L23:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 8(%rax)
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	list_remove, .-list_remove
	.globl	list_free
	.type	list_free, @function
list_free:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L25
.L26:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
.L25:
	cmpq	$0, -8(%rbp)
	jne	.L26
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	list_free, .-list_free
	.local	curid.2884
	.comm	curid.2884,4,4
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-11)"
	.section	.note.GNU-stack,"",@progbits
