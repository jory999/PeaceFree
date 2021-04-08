#include "font.h"
const char font_code_global[94][16]={//Ó¢ÎÄ»ò±êµã·ûºÅ //0x21 -- 0x7e
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x80,},//!
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0xa0,0xa0,},//"
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x28,0xfc,0x28,0x50,0xfc,0x50,0x50,},//#
    {0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x78,0xa8,0xa0,0x60,0x30,0x28,0xa8,0xf0,0x20,},//$
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xa8,0xb0,0x50,0x28,0x34,0x54,0x48,},//%
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x50,0x50,0x78,0xa8,0xa8,0x90,0x6c,},//&
    {0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},//'
    {0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x40,0x80,0x80,0x80,0x80,0x80,0x80,0x40,0x20,},//(
    {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x20,0x20,0x20,0x20,0x20,0x40,0x80,},//)
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xa8,0x70,0x70,0xa8,0x20,},//*
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0xf8,0x20,0x20,0x20,},//+
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x80,},//,
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,},//-
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,},//.
    {0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x10,0x10,0x10,0x20,0x20,0x40,0x40,0x40,0x80,},///
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x70,},//0
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xc0,0x40,0x40,0x40,0x40,0x40,0xe0,},//1
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x88,0x10,0x20,0x40,0x80,0xf8,},//2
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x08,0x30,0x08,0x08,0x88,0x70,},//3
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x30,0x50,0x50,0x90,0x78,0x10,0x18,},//4
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x80,0x80,0xf0,0x08,0x08,0x88,0x70,},//5
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x90,0x80,0xf0,0x88,0x88,0x88,0x70,},//6
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x90,0x10,0x20,0x20,0x20,0x20,0x20,},//7
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x88,0x70,0x88,0x88,0x88,0x70,},//8
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x88,0x88,0x78,0x08,0x48,0x70,},//9
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x80,},//:
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x80,},//;
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x10,0x20,0x40,0x80,0x40,0x20,0x10,0x08,},//<
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x00,0x00,0xf8,},//=
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x80,},//>
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x88,0x10,0x20,0x20,0x00,0x20,},//?
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x98,0xa8,0xa8,0xb8,0x80,0x78,},//@
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x30,0x50,0x50,0x78,0x48,0xcc,},//A
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x48,0x48,0x70,0x48,0x48,0x48,0xf0,},//B
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x88,0x80,0x80,0x80,0x80,0x88,0x70,},//C
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x48,0x48,0x48,0x48,0x48,0x48,0xf0,},//D
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x48,0x50,0x70,0x50,0x40,0x48,0xf8,},//E
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x48,0x50,0x70,0x50,0x40,0x40,0xe0,},//F
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x48,0x80,0x80,0x9c,0x88,0x48,0x30,},//G
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xcc,0x48,0x48,0x78,0x48,0x48,0x48,0xcc,},//H
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x20,0x20,0x20,0x20,0x20,0x20,0xf8,},//I
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x10,0x10,0x10,0x10,0x10,0x10,0x90,0xe0,},//J
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xec,0x48,0x50,0x60,0x50,0x50,0x48,0xec,},//K
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x40,0x40,0x40,0x40,0x40,0x44,0xfc,},//L
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd8,0xd8,0xd8,0xd8,0xa8,0xa8,0xa8,0xa8,},//M
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xdc,0x48,0x68,0x68,0x58,0x58,0x48,0xe8,},//N
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x70,},//O
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x48,0x48,0x70,0x40,0x40,0x40,0xe0,},//P
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x88,0x88,0x88,0xe8,0x98,0x70,0x18,},//Q
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x48,0x48,0x70,0x50,0x48,0x48,0xec,},//R
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x88,0x80,0x60,0x10,0x08,0x88,0xf0,},//S
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0xa8,0x20,0x20,0x20,0x20,0x20,0x70,},//T
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xcc,0x48,0x48,0x48,0x48,0x48,0x48,0x30,},//U
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xcc,0x48,0x48,0x50,0x50,0x30,0x20,0x20,},//V
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa8,0xa8,0xa8,0x70,0x50,0x50,0x50,0x50,},//W
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd8,0x50,0x50,0x20,0x20,0x50,0x50,0xd8,},//X
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd8,0x50,0x50,0x20,0x20,0x20,0x20,0x70,},//Y
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x90,0x10,0x20,0x20,0x40,0x48,0xf8,},//Z
    {0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xe0,},//[
    {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x40,0x40,0x20,0x20,0x20,0x10,0x00,},/* \ */
    {0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xe0,},//]
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xa0,},//^
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,},//_
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,},//`
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x90,0x70,0x90,0x78,},//a
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x40,0x40,0x70,0x48,0x48,0x48,0x70,},//b
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x90,0x80,0x80,0x70,},//c
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x10,0x10,0x70,0x90,0x90,0x90,0x78,},//d
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x90,0xf0,0x80,0x70,},//e
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x40,0x40,0xf0,0x40,0x40,0x40,0xf0,},//f
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x90,0x60,0x80,0xf0,0x88,0x70,},//g
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x40,0x40,0x70,0x48,0x48,0x48,0xec,},//h
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0xc0,0x40,0x40,0x40,0xe0,},//i
    {0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x30,0x10,0x10,0x10,0x10,0x10,0xe0,},//j
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x40,0x40,0x5c,0x50,0x70,0x48,0xec,},//k
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x20,0x20,0x20,0x20,0x20,0x20,0xf8,},//l
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xa8,0xa8,0xa8,0xa8,},//m
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x48,0x48,0x48,0xec,},//n
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x90,0x90,0x90,0x60,},//o
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x48,0x48,0x48,0x70,0x40,0xe0,},//p
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x90,0x90,0x90,0x70,0x10,0x38,},//q
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd8,0x60,0x40,0x40,0xe0,},//r
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x80,0x60,0x10,0xf0,},//s
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0xe0,0x40,0x40,0x40,0x30,},//t
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd8,0x48,0x48,0x48,0x3c,},//u
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xec,0x48,0x50,0x30,0x20,},//v
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa8,0xa8,0x70,0x50,0x50,},//w
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd8,0x50,0x20,0x50,0xd8,},//x
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xec,0x48,0x50,0x30,0x20,0x20,0xc0,},//y
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x20,0x40,0x40,0xf0,},//z
    {0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x40,0x40,0x40,0x80,0x40,0x40,0x40,0x40,0x60,},//{
    {0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,},//|
    {0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x40,0x40,0x40,0x20,0x40,0x40,0x40,0x40,0xc0,},//}
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xa4,0x18,},//~
};

const char font_code_globalA[16] = {0x00,0x18,0x18,0x18,0x18,0x24,0x24,0x24,0x24,0x7e,0x42,0x42,0x42,0xe7,0x00,0x00};

 unsigned char table_rgb[16 * 3] = {
		0x00, 0x00, 0x00,	/*  0:黑 */
		0xff, 0x00, 0x00,	/*  1:梁红 */
		0x00, 0xff, 0x00,	/*  2:亮绿 */
		0xff, 0xff, 0x00,	/*  3:亮黄 */
		0x00, 0x00, 0xff,	/*  4:亮蓝 */
		0xff, 0x00, 0xff,	/*  5:亮紫 */
		0x00, 0xff, 0xff,	/*  6:浅亮蓝 */
		0xff, 0xff, 0xff,	/*  7:白 */
		0xc6, 0xc6, 0xc6,	/*  8:亮灰 */
		0x84, 0x00, 0x00,	/*  9:暗红 */
		0x00, 0x84, 0x00,	/* 10:暗绿 */
		0x84, 0x84, 0x00,	/* 11:暗黄 */
		0x00, 0x00, 0x84,	/* 12:暗青 */
		0x84, 0x00, 0x84,	/* 13:暗紫 */
		0x00, 0x84, 0x84,	/* 14:浅暗蓝 */
		0x84, 0x84, 0x84	/* 15:暗灰 */
	};

     char cursor[16][16] = {
		"**************..",
		"*OOOOOOOOOOO*...",
		"*OOOOOOOOOO*....",
		"*OOOOOOOOO*.....",
		"*OOOOOOOO*......",
		"*OOOOOOO*.......",
		"*OOOOOOO*.......",
		"*OOOOOOOO*......",
		"*OOOO**OOO*.....",
		"*OOO*..*OOO*....",
		"*OO*....*OOO*...",
		"*O*......*OOO*..",
		"**........*OOO*.",
		"*..........*OOO*",
		"............*OO*",
		".............***" 
	}; 

//extern void PutString(int x,int y, int color, unsigned char *str111);
struct BOOTINFO1{
       char xyls, leds, vmode, reserve;
       short scrnx, scrny;
       char *vram ;

};
void DefaultIntCallBack()//回调函数
{
    char *vram;
    int xsize, ysize;
    struct BOOTINFO1 *binfo;

    binfo = (struct BOOTINFO1 * ) 0x0ff0;
    xsize = (*binfo).scrnx;
    ysize = (*binfo).scrny;
    vram  = (*binfo).vram;
    //PutString(100, 100,"There Is An INT!!!!\0",0xffffff);
    static unsigned  char nowput9[66]="There Is An INT";
      PutString(binfo->vram, binfo->scrnx,60, 90,7,nowput9);
	/* unsigned  char *nowput9="There Is An INT";
      PutString(binfo->vram, binfo->scrnx,10, 90,7,nowput9); */

	
}  

 void inthandler21(int *esp)
/* 来自PS/2键盘的中断 */
{
	struct BOOTINFO1 *binfo = (struct BOOTINFO *) 0x0ff0;
	boxfill8(binfo->vram, binfo->scrnx, 9, 0, 0, 32 * 8 - 1, 15);
    static unsigned  char nowput91[66]="INT 21 (IRQ-1) : PS/2 keyboard";
	putfonts8_asc(binfo->vram, binfo->scrnx, 0, 0, 7, nowput91);
	for (;;) {
		FunctionHlt();
	}
}

void inthandler2c(int *esp)
/* 来自PS/2鼠标的中断 */
{
	struct BOOTINFO1 *binfo = (struct BOOTINFO *) 0x0ff0;
	boxfill8(binfo->vram, binfo->scrnx, 0, 0, 0, 32 * 8 - 1, 15);
	putfonts8_asc(binfo->vram, binfo->scrnx, 0, 0, 7, "INT 2C (IRQ-12) : PS/2 mouse");
	for (;;) {
		FunctionHlt();
	}
}

void inthandler27(int *esp)
/* PIC0中断的不完整策略 */
/* 这个中断在Athlon64X2上通过芯片组提供的便利，只需执行一次 */
/* 这个中断只是接收，不执行任何操作 */
/* 为什么不处理？
	→  因为这个中断可能是电气噪声引发的、只是处理一些重要的情况。*/
{
	FunctionOut8(0x0020, 0x67); /* 通知PIC的IRQ-07（参考7-1） */
	return;
}
void asm_inthandler21(void);
void asm_inthandler27(void);
void asm_inthandler2c(void);

extern void FunctionLidt(short, void *);


/* void set_gatedesc(struct GATE_DESCRIPTOR *gd, int offset, int selector, int ar)
{
	gd->offset_low   = offset & 0xffff;
	gd->selector     = selector;
	gd->dw_count     = (ar >> 8) & 0xff;
	gd->access_right = ar & 0xff;
	gd->offset_high  = (offset >> 16) & 0xffff;
	return;
} */

void InitIDT()
{
    static struct idt_struct{
    short   offset1;
    short   selector;
    short   no_use;
    short   offset2;
    } idt[0x30];//初始化0~0x30的中断

   

    int i;
    ////////////#0，必须有0项
    idt[0].offset1 = 0x00;
    idt[0].selector = 0x00;
    idt[0].no_use = 0x00;
    idt[0].offset2 = 0x00;
    for (i=1;i<0x30;i++)
    {
       
        
        idt[i].offset1 = (short)((int)(void*)DefaultIntCallBack-0x8200);
        idt[i].selector = 0x0008;
        idt[i].no_use = 0x8e00;
        idt[i].offset2 = (short)(((int)(void*)DefaultIntCallBack-0x8200)>>16);  
    }
        idt[0x21].offset1 = (short)((int)(void*)asm_inthandler21-0x8200);
        idt[0x21].selector = 0x0008;
        idt[0x21].no_use = 0x8e00;
        idt[0x21].offset2 = (short)(((int)(void*)asm_inthandler21-0x8200)>>16);  

        idt[0x2c].offset1 = (short)((int)(void*)asm_inthandler2c-0x8200);
        idt[0x2c].selector = 0x0008;
        idt[0x2c].no_use = 0x8e00;
        idt[0x2c].offset2 = (short)(((int)(void*)asm_inthandler2c-0x8200)>>16);  

    /* IDT设置*/
/* 
	set_gatedesc(idt + 0x21, (int) asm_inthandler21, 2 * 8, AR_INTGATE32);
	set_gatedesc(idt + 0x27, (int) asm_inthandler27, 2 * 8, AR_INTGATE32);
	set_gatedesc(idt + 0x2c, (int) asm_inthandler2c, 2 * 8, AR_INTGATE32);
     */
    FunctionLidt(0x30*8-1,idt);
}