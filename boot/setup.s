.code16
.section .text
.set    CYLS,   0X0FF0
.set    LEDS,   0X0FF1
.set    VMODE,  0X0FF2
.set    SCRNX,  0X0FF4
.set    SCRNY,  0X0FF6
.set    VRAM,   0X0FF8
start:
    movb    $0x13, %al
    movb    $0x00, %ah
    int $0x10

    movb    $8,    VMODE
    movw    $320,  SCRNX
    movw    $200,  SCRNY
    movl    $0x000a000,    VRAM

    movb    $0x02, %ah
    int $0x16
    mov %al,    LEDS

    movw    %cs,    %ax
    movw    %ax,    %ds
    movw    %ax,    %es
    movw    %ax,    %ss
    movw    $0x100,    %sp

########################################start 32
############set GDT
    movl    gdt_base,    %eax  



############0# empty GDT
    movl    $0x00000000,   0(%eax)
    movl    $0x00000000,   4(%eax)
############1# code GDT
    movl    $0x8200ffff,   8(%eax)
    movl    $0x00409a00,   12(%eax)
############2# data GDT
    movl    $0x0000ffff,   16(%eax)
    movl    $0x00cf9200,   20(%eax)
############3# stack GDT
    movl    $0x00007a00,   24(%eax)
    movl    $0x00409600,   28(%eax)

#close interrupt
    cli 
    lgdt    gdt_size 
#turn on A2
    #inb     $0x92,     %al
    #orb     $0x02,     %al
    #outb    %al,       $0x92

  #enable_a20:	
    #inb		$0x64,			%al			# 从端口0x64读取数据
	#testb	$0x02,			%al			# 测试读取数据第二个bit
	#jnz		enable_a20					# 忙等待

	#movb	$0xdf,			%al
	#outb	%al,			$0x60		# 将0xdf写入端口0x60

seta20.1:
    inb $0x64, %al                                  # Wait for not busy(8042 input buffer empty).
    testb $0x2, %al
    jnz seta20.1

    movb $0xd1, %al                                 # 0xd1 -> port 0x64
    outb %al, $0x64                                 # 0xd1 means: write data to 8042's P2 port

seta20.2:
    inb $0x64, %al                                  # Wait for not busy(8042 input buffer empty).
    testb $0x2, %al
    jnz seta20.2

    movb $0xdf, %al                                 # 0xdf -> port 0x60
    outb %al, $0x60                                 # 0xdf = 11011111, means set P2's A20 bit(the 1 bit) to 1    

#configure CR0
    movl	%cr0,			%eax		# 读取cr0寄存器
	orl		$0x01,			%eax		# 置位最后以为即PE位
	movl	%eax,			%cr0		# 写cr0寄存器



	

#protect mode start
    ljmp    $0x0008,	$(start_protect-start) #16位描述子：32位位移

start_protect:
.code32
    movw    $0x0010,   %ax
    movw    %ax,        %ds
    movw    $0x0018,   %ax
    movw    %ax,        %ss
    movl    $0x7a00,   %esp

    call    SysMain


gdt_size:   .word   31
gdt_base:   .long   0x9000 #定义GDT位置
