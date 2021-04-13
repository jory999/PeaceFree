
#include "hello.h"
int main(void){
   
    	myprint("Hello World ");
    
        return 0;
}

################################################################babyos2

# bootpack传递
movedata:
		MOVl		$bootpack,      %ESI	# 源
		MOVl		$BOTPAK,      %EDI		# 目标 0x00280000
		MOVl		$0x20000,  %ECX    #512*1024/4
		CALL	    memcpy

# 传输磁盘数据

#从引导区开始

		MOVl		$0x7c00,	      %ESI	       #      源
		MOVl		$DSKCAC,          %EDI		# 目标0 x00100000
		MOVl		$0x80,           %ECX      #512/4
		CALL	    memcpy

# 剩余的全部

		MOVl		$0x00008200,           %ESI	# 源 0x00008000	(DSKCAC0+512)
		MOVl		$0x00100200,           %EDI	# 目标0x00100000  DSKCAC+512)
		MOVl		$0,                      %ECX
		MOVb		$10,                     %CL
		IMUL	    $0x6c,                   %ECX	# 除以4得到字节数 (512*18*2/4)
		SUBl		$0x80,	                 %ECX	# IPL偏移量 (512/4)
		CALL	    memcpy



#bootpack启动

		#MOVl		$BOTPAK,         %EBX
		#MOVl		16(%EBX),        %ECX
		#ADDl		$3,              %ECX			#ECX += 3;
		#SHRl		$2,              %ECX			# ECX /= 4;
		#JZ		    skip			# 传输完成
		#MOVl		20(%EBX),        %ESI	# 源
		#ADDl		%EBX,            %ESI
		#MOVl		12(%EBX),        %EDI	# 目标
		#CALL	    memcpy
skip:
		MOVl		$BOTPAK,         %EBX
		MOVl		12(%EBX),        %ESP	# 堆栈的初始化

		#JMP		    DWORD 2*8:0x0000001b

#protect mode start
    #ljmp    $0x0010,	$0   #16位描述子：32位位移
    #ljmp    $0x0008,	$(start_protect-start)   #16位描述子：32位位移
	ljmp    $0x0008,	$start_protect 

start_protect:
 
     .code32
   
   

    
	#movw    $0x0010,   %ax
    #movw    %ax,       %ds
    #movw    $0x0018,   %ax
    #movw    %ax,       %ss
    #movl    $0x7a00,   %esp

    call    SysMain



memcpy:
		MOVl		(%ESI),            %EAX
		ADDl		$4,                %ESI
		MOVl		%EAX,             (%EDI)
		ADDl		$4,                %EDI
		SUBl		$1,                %ECX
		JNZ		    memcpy			# 运算结果不为0跳转到memcpy
		RET
# memcpy地址前缀大小

		
GDT0:
		.quad	    0x0000000000000000				# 初始值
		.quad	    0x00cf92000000ffff
		.quad	    0x00479a280000ffff
		
		#.word		0xffff,0x0000,0x9200,0x00cf	# 写32bit位段寄存器
		#.word		0xffff,0x0000,0x9a28,0x0047	# 可执行的文件的32bit寄存器（bootpack用）
                                        
		.word		0
GDTR0:
		.word		8*3-1
		.long 		GDT0

	

################################################################babyos2


bootpack:	
