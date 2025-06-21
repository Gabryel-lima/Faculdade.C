	.file	"livros.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"\n"
	.text
	.p2align 4
	.type	read_line, @function
read_line:
.LFB20:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	stdin(%rip), %rdx
	movq	%rdi, %rbx
	call	fgets@PLT
	testq	%rax, %rax
	je	.L6
	movq	%rbx, %rdi
	leaq	.LC0(%rip), %rsi
	call	strcspn@PLT
	movb	$0, (%rbx,%rax)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	.cfi_restore_state
	movb	$0, (%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE20:
	.size	read_line, .-read_line
	.section	.rodata.str1.1
.LC1:
	.string	"+++ Cadastro dos Livros +++"
.LC2:
	.string	"\nLivro %d%d\n"
.LC3:
	.string	"Titulo (at\303\251 %d caracteres): "
.LC4:
	.string	"Autor (at\303\251 %d caracteres): "
.LC5:
	.string	"Ano de publica\303\247\303\243o: "
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC6:
	.string	" Entrada inv\303\241lida. Digite o ano novamente: "
	.section	.rodata.str1.1
.LC7:
	.string	"%d"
.LC8:
	.string	"\n=== Livros cadastrados ==="
.LC9:
	.string	"[%d]\n"
.LC10:
	.string	"T\303\255tulo : %s\n"
.LC11:
	.string	"Autor  : %s\n"
.LC12:
	.string	"Ano    : %d\n\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB21:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	$58, %ecx
	xorl	%r15d, %r15d
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	.LC6(%rip), %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	leaq	.LC7(%rip), %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$488, %rsp
	.cfi_def_cfa_offset 544
	movq	%fs:40, %rax
	movq	%rax, 472(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rdi
	movq	%rsp, %r13
	movq	%r13, %r14
	rep stosq
	movl	$0, (%rdi)
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
.L11:
	addl	$1, %r15d
	movl	$3, %ecx
	movl	$2, %edi
	xorl	%eax, %eax
	movl	%r15d, %edx
	leaq	.LC2(%rip), %rsi
	leaq	152(%r14), %rbx
	call	__printf_chk@PLT
	movl	$100, %edx
	leaq	.LC3(%rip), %rsi
	xorl	%eax, %eax
	movl	$2, %edi
	call	__printf_chk@PLT
	movl	$101, %esi
	movq	%r14, %rdi
	call	read_line
	movl	$50, %edx
	leaq	.LC4(%rip), %rsi
	xorl	%eax, %eax
	movl	$2, %edi
	call	__printf_chk@PLT
	leaq	101(%r14), %rdi
	movl	$51, %esi
	call	read_line
	leaq	.LC5(%rip), %rsi
	movl	$2, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	.p2align 4,,10
	.p2align 3
.L8:
	xorl	%eax, %eax
	movq	%rbx, %rsi
	movq	%rbp, %rdi
	call	__isoc99_scanf@PLT
	cmpl	$1, %eax
	je	.L10
	.p2align 4,,10
	.p2align 3
.L9:
	movq	stdin(%rip), %rdi
	call	getc@PLT
	cmpl	$10, %eax
	jne	.L9
	movq	stdout(%rip), %rcx
	movl	$44, %edx
	movl	$1, %esi
	movq	%r12, %rdi
	call	fwrite@PLT
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L10:
	movq	stdin(%rip), %rdi
	call	getc@PLT
	cmpl	$10, %eax
	jne	.L10
	addq	$156, %r14
	cmpl	$3, %r15d
	jne	.L11
	leaq	.LC8(%rip), %rdi
	xorl	%ebx, %ebx
	leaq	.LC9(%rip), %r15
	call	puts@PLT
	leaq	.LC10(%rip), %r14
	leaq	.LC11(%rip), %r12
	leaq	.LC12(%rip), %rbp
.L12:
	addl	$1, %ebx
	movq	%r15, %rsi
	movl	$2, %edi
	xorl	%eax, %eax
	movl	%ebx, %edx
	call	__printf_chk@PLT
	movq	%r13, %rdx
	movq	%r14, %rsi
	movl	$2, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	101(%r13), %rdx
	movq	%r12, %rsi
	xorl	%eax, %eax
	movl	$2, %edi
	addq	$156, %r13
	call	__printf_chk@PLT
	movl	-4(%r13), %edx
	movq	%rbp, %rsi
	xorl	%eax, %eax
	movl	$2, %edi
	call	__printf_chk@PLT
	cmpl	$3, %ebx
	jne	.L12
	movq	472(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L20
	addq	$488, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L20:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE21:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
