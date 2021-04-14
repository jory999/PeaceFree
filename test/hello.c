
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



* Copyright (C) 1989-2020 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */

#ifndef _STDARG_H
#ifndef _ANSI_STDARG_H_
#ifndef __need___va_list
#define _STDARG_H
#define _ANSI_STDARG_H_
#endif /* not __need___va_list */
#undef __need___va_list

/* Define __gnuc_va_list.  */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif

/* Define the standard macros for the user,
   if this invocation was from the user program.  */
#ifdef _STDARG_H

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L \
    || __cplusplus + 0 >= 201103L
#define va_copy(d,s)	__builtin_va_copy(d,s)
#endif
#define __va_copy(d,s)	__builtin_va_copy(d,s)

/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */

#ifdef _BSD_VA_LIST
#undef _BSD_VA_LIST
#endif

#if defined(__svr4__) || (defined(_SCO_DS) && !defined(__VA_LIST))
/* SVR4.2 uses _VA_LIST for an internal alias for va_list,
   so we must avoid testing it and setting it here.
   SVR4 uses _VA_LIST as a flag in stdarg.h, but we should
   have no conflict with that.  */
#ifndef _VA_LIST_
#define _VA_LIST_
#ifdef __i860__
#ifndef _VA_LIST
#define _VA_LIST va_list
#endif
#endif /* __i860__ */
typedef __gnuc_va_list va_list;
#ifdef _SCO_DS
#define __VA_LIST
#endif
#endif /* _VA_LIST_ */
#else /* not __svr4__ || _SCO_DS */

/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */
#if !defined (_VA_LIST_) || defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__) || defined(WINNT)
/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
#ifndef _VA_LIST_DEFINED
/* The macro _VA_LIST is used in SCO Unix 3.2.  */
#ifndef _VA_LIST
/* The macro _VA_LIST_T_H is used in the Bull dpx2  */
#ifndef _VA_LIST_T_H
/* The macro __va_list__ is used by BeOS.  */
#ifndef __va_list__
typedef __gnuc_va_list va_list;
#endif /* not __va_list__ */
#endif /* not _VA_LIST_T_H */
#endif /* not _VA_LIST */
#endif /* not _VA_LIST_DEFINED */
#if !(defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__))
#define _VA_LIST_
#endif
#ifndef _VA_LIST
#define _VA_LIST
#endif
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif
#ifndef _VA_LIST_T_H
#define _VA_LIST_T_H
#endif
#ifndef __va_list__
#define __va_list__
#endif

#endif /* not _VA_LIST_, except on certain systems */

#endif /* not __svr4__ */

#endif /* _STDARG_H */

#endif /* not _ANSI_STDARG_H_ */
#endif /* not _STDARG_H */
