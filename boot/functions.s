.code32
.section .text
.global FunctionHlt
.global FunctionOut8, FunctionOut16, FunctionOut32
.global FuntionIn8, FuntionIn16, FuntionIn32
.global FunctionCli, FunctionSti
.global FunctionLoadEflags, FunctionStoreEflags
.global FunctionLidt
.global asm_inthandler21,asm_inthandler27,asm_inthandler2c
.global load_gdtr,load_idtr

FunctionHlt:    #void FunctionHlt(void)
    hlt
    ret

FunctionOut8:   #void FunctionOut8(int port, int data)
    movl    4(%esp),    %edx
    movb    8(%esp),    %al
    outb    %al,        %dx
    ret

FunctionOut16:  #void FunctionOut16(int port, int data)
    movl    4(%esp),    %edx
    movw    8(%esp),    %ax
    outw    %ax,        %dx
    ret

FunctionOut32:  #void FunctionOut32(int port, int data)
    movl    4(%esp),    %edx
    movl    8(%esp),    %eax
    outl    %eax,       %dx
    ret

FuntionIn8: #int FunctionIn8(int port)
    movl    4(%esp),    %edx
    movb    $0,        %al
    inb %dx,        %al
    ret

FuntionIn16:    #int FunctionIn16(int port)
    movl    4(%esp),    %edx
    movw    $0,        %ax
    inw %dx,        %ax
    ret

FuntionIn32:    #int FunctionIn32(int port)
    movl    4(%esp),    %edx
    movl    $0,        %eax
    inl %dx,        %eax
    ret

FunctionCli:    #void FunctionCli(void)
    cli
    ret

FunctionSti: #void FunctionSti(void)
    sti
    ret

FunctionLoadEflags: #int FunctionLoadEflags(void)
    pushf
    pop %eax
    ret

FunctionStoreEflags:    #void FunctionStoreEflags(int eflags)
    movl 4(%esp),    %eax
    push    %eax
    popf
    ret

FunctionLidt: #void FunctionLidt(short,void *)
    movw    4(%esp),    %ax
    movw    %ax,        6(%esp) 
    lidt    6(%esp) #巧妙使用
    sti
    ret   

asm_inthandler21:
		pushw	%es
		pushw	%ds
		pushal
		movl		%esp,%eax
		pushl	%eax
		movw		%ss,%ax
		movw		%ax,%ds
		movw		%ax,%es
		CALL	inthandler21
		popl		%eax
		popal
		pop		%ds
		pop		%es
		iretl

asm_inthandler27:
		pushw	%es
		pushw	%ds
		pushal
		movl		%esp,%eax
		pushl	%eax
		movw		%ss,%ax
		movw		%ax,%ds
		movw		%ax,%es
		CALL	inthandler27
		popl		%eax
		popal
		pop		%ds
		pop		%es
		iretl

asm_inthandler2c:
		pushw	%es
		pushw	%ds
		pushal
		movl		%esp,%eax
		pushl	%eax
		movw		%ss,%ax
		movw		%ax,%ds
		movw		%ax,%es
		CALL	inthandler2c
		popl		%eax
		popal
		pop		%ds
		pop		%es
		iretl

load_gdtr:		# void load_gdtr(int limit, int addr);
		movw	4(%ESP)	,    %AX	# limit
		movw	%AX,          6(%ESP)
		lgdt	6(%ESP)
		ret

load_idtr:		#void load_idtr(int limit, int addr);
		MOV		4(%ESP),	 %AX	# limit
		MOV		%AX ,        6(%ESP)
		LIDT	 6(%ESP)
		ret
 


