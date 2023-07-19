	.file	"main.c"
	.text
	.section	.rodata
.LC2:
	.string	"%d"
	.align 8
.LC3:
	.string	"Not a valid comparator! Enter a number between 1 and 6\n"
.LC4:
	.string	"%25s %25s %5d %6.2f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$2208, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movq	$0, -2192(%rbp)
	jmp	.L2
.L3:
	leaq	-2176(%rbp), %rcx
	movq	-2192(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rcx, %rax
	movq	%rax, %rdi
	call	randTitle@PLT
	leaq	-2176(%rbp), %rcx
	movq	-2192(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	addq	$5, %rax
	movq	%rax, %rdi
	call	randAuthor@PLT
	movl	$1000, %esi
	movl	$10, %edi
	call	randInt@PLT
	movl	%eax, %ecx
	movq	-2192(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$1974, %rax
	movw	%cx, (%rax)
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	randReal@PLT
	movq	%xmm0, %rdx
	movq	-2192(%rbp), %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,8), %rcx
	addq	%rcx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$1968, %rax
	movq	%rdx, (%rax)
	addq	$1, -2192(%rbp)
.L2:
	cmpq	$9, -2192(%rbp)
	jbe	.L3
	movb	$0, -2197(%rbp)
	jmp	.L4
.L7:
	leaq	-2196(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-2196(%rbp), %eax
	testl	%eax, %eax
	jle	.L5
	movl	-2196(%rbp), %eax
	cmpl	$6, %eax
	jle	.L6
.L5:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$55, %edx
	movl	$1, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	jmp	.L4
.L6:
	movb	$1, -2197(%rbp)
.L4:
	movzbl	-2197(%rbp), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	.L7
	movl	-2196(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movq	%rax, %rdx
	leaq	-2176(%rbp), %rax
	movq	%rdx, %rcx
	movl	$216, %edx
	movl	$10, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	movq	$0, -2184(%rbp)
	jmp	.L8
.L9:
	movq	-2184(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$1968, %rax
	movq	(%rax), %rcx
	movq	-2184(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$1974, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %edx
	leaq	-2176(%rbp), %rdi
	movq	-2184(%rbp), %rsi
	movq	%rsi, %rax
	addq	%rax, %rax
	addq	%rsi, %rax
	leaq	0(,%rax,8), %rsi
	addq	%rsi, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rdi, %rax
	leaq	5(%rax), %rsi
	leaq	-2176(%rbp), %r8
	movq	-2184(%rbp), %rdi
	movq	%rdi, %rax
	addq	%rax, %rax
	addq	%rdi, %rax
	leaq	0(,%rax,8), %rdi
	addq	%rdi, %rax
	salq	$3, %rax
	addq	%r8, %rax
	movq	%rcx, %xmm0
	movl	%edx, %ecx
	movq	%rsi, %rdx
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	addq	$1, -2184(%rbp)
.L8:
	cmpq	$9, -2184(%rbp)
	jbe	.L9
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1079574528
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0"
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
