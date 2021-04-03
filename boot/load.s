#*************************************************************************
#	> File:		load.s
#	> Desc:		1.设置新的数据段等
#				2.将内核剩余部分移动到load.s后面
#				3.显示babyos 加载成功的Logo
#	> Author:	孤舟钓客
#	> Mail:		guzhoudiaoke@126.com 
#	> Time:		2012年12月30日 星期日 22时23分55秒
#*************************************************************************
 
.include "include/kernel.inc"
 
.section .text
.global	_start
 
.org	0
 
_start:
	movl	$DATA_SELECTOR,			%eax
	movw	%ax,					%ds
	movw	%ax,					%es
	movw	%ax,					%fs
	movw	%ax,					%gs
	movw	%ax,					%ss
	movl	$STACK_BOTTOM,			%esp
 
load_lefted_kernel:
	cld
	movl	$0x10200,				%esi
	movl	$0x200,					%edi
	movl	$(KERNEL_SECT_NUM-1)<<7,%ecx
	rep		movsl
 
show_logo:
	movl	$0xe0000000,			%edi
	addl	$272 + 800*10,			%edi
	movl	$0x400,					%esi
 
	movl	$128,					%ebx
	movl	$1,						%eax
1:	
	movl	$256,					%ecx
set_line_mem:	
	cmpb	$255,					(%esi)
	je		2f
	movb	%al,					(%edi)
2:
	inc		%esi
	inc		%edi
	loop	set_line_mem
	
	addl	$800-256,				%edi
	decl	%ebx
	jnz		1b
 
3:	
	jmp		3b
 
	.org	512,	0x90	