
//#include "font.h"
//#include <stdio.h> 
//#include <string.h>
extern unsigned char table_rgb[16 * 3];
extern const char font_code_globalA[16];
extern const char font_code_global[94][16];
extern char cursor[16][16];

extern void FunctionCli(void);
extern void FunctionSti(void);
extern void FunctionOut8(int port, int data);
extern int FunctionLoadEflags(void);
extern void FunctionStoreEflags(int eflags);

void InitPalette();
void DrawRectangle(int x1,int y1,int x2,int y2,int color);
void init_screen(char *vram, int x, int y);

#define PALETTE_NUMBER 16

#define COL8_000000		0
#define COL8_FF0000		1
#define COL8_00FF00		2
#define COL8_FFFF00		3
#define COL8_0000FF		4
#define COL8_FF00FF		5
#define COL8_00FFFF		6
#define COL8_FFFFFF		7
#define COL8_C6C6C6		8
#define COL8_840000		9
#define COL8_008400		10
#define COL8_848400		11
#define COL8_000084		12
#define COL8_840084		13
#define COL8_008484		14
#define COL8_848484		15

struct BOOTINFO{
       char xyls, leds, vmode, reserve;
       short scrnx, scrny;
       char *vram ;

};

//static const char font_code_globalA[16] = {0x00,0x18,0x18,0x18,0x18,0x24,0x24,0x24,0x24,0x7e,0x42,0x42,0x42,0xe7,0x00,0x00};

void putfont8( int x, int y, char c, char *font)
{
	int i;  //
	char *p ;/* data */
	char d;
	for (i = 0; i < 16; i++) {
		p = 0xa0000 + (y + i) * 320 + x;
		d = font[i];
        
		if ((d & 0x80) != 0) { p[0] = c; }
		if ((d & 0x40) != 0) { p[1] = c; }
		if ((d & 0x20) != 0) { p[2] = c; }
		if ((d & 0x10) != 0) { p[3] = c; }
		if ((d & 0x08) != 0) { p[4] = c; }
		if ((d & 0x04) != 0) { p[5] = c; }
		if ((d & 0x02) != 0) { p[6] = c; }
		if ((d & 0x01) != 0) { p[7] = c; }
	}
	return;
}

void putfonts8_asc( int x, int y, char c, unsigned char *s)
{
	//int iii=s[0] - 0x21;
	//putfont8( x, y+10, c, &font_code_global[iii]);
	//putfont8( x+10, y+10, c, &font_code_global[s[1] - 0x21]);
	 for (; *s != 0x00; s++) {
		putfont8( x, y, c, font_code_global[ *s - 0x21]);
		//putfont8( x, y, c, &font_code_global[0x20]);
		x += 8;
	} 
	return;
}

////////////draw cursor

void init_mouse_cursor8(char *mouse, char bc)

{
	/* static char cursor[16][16] = {
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
	}; */
	int x, y;

	for (y = 0; y < 16; y++) {
		for (x = 0; x < 16; x++) {
			if (cursor[y][x] == '*') {
				mouse[y * 16 + x] = COL8_000000;
			}
			if (cursor[y][x] == 'O') {
				mouse[y * 16 + x] = COL8_FFFFFF;
			}
			if (cursor[y][x] == '.') {
				mouse[y * 16 + x] = bc;
			}
		}
	}
	return;
}

void putblock8_8(char *vram, int vxsize, int pxsize,
	int pysize, int px0, int py0, char *buf, int bxsize)
{
	int x, y;
	for (y = 0; y < pysize; y++) {
		for (x = 0; x < pxsize; x++) {
			vram[(py0 + y) * vxsize + (px0 + x)] = buf[y * bxsize + x];
		}
	}
	return;
}

/////cursor end

 //unsigned char p[99]="My Great World...\0";
  char *p="My Great World...\0";


void SysMain()
{
    char *vram;
    int xsize, ysize;
    struct BOOTINFO *binfo;

    binfo = (struct BOOTINFO * ) 0x0ff0;
    xsize = (*binfo).scrnx;
    ysize = (*binfo).scrny;
    vram  = (*binfo).vram;

	char s[40], mcursor[256];
	int mx, my;

    InitPalette();
    init_screen(binfo->vram, binfo->scrnx, binfo->scrny);
	
    mx = (binfo->scrnx - 16) / 2; /* 计算画面的中心坐标*/
	my = (binfo->scrny - 28 - 16) / 2;
	init_mouse_cursor8(mcursor, COL8_008484);
	putblock8_8(binfo->vram, binfo->scrnx, 16, 16, mx, my, mcursor, 16);
	 
      //putfont8(20,20,1,font_code_globalA);
     /*  PutChar( 20,10, 'H', 1) ;
	  PutChar( 30,10, 'e', 1) ;
	  PutChar( 40,10, 'l', 1) ;
	  PutChar( 50,10, 'l', 1) ;
	  PutChar( 60,10, 'o', 1) ;

	  PutChar( 80,10, 'W', 1) ;
	  PutChar( 90,10, 'o', 1) ;
	  PutChar( 100,10, 'r', 1) ;
	  PutChar( 110,10, 'l', 1) ;
	  PutChar( 120,10, 'd', 1) ; */
    
      
	  unsigned  char nowput[99]="GOD Will Bless My Family...";
      PutString(10, 10,7,nowput);

	  unsigned  char nowstr[66]="Hello Great World...";
	  putfonts8_asc(20, 60,7,nowstr);

//char p[77]="My Great World...\0";
	  putfonts8_asc(30, 100,7,p);
	  PutString(10, 30,7,p);
        
    
    //DrawRectangle(0,0,320,320,9);
    //DrawRectangle(10,10,100,100,10);
    
    //DrawRectangle(10,150,300,200,1);
    //DrawRectangle(19,170,90,190,10);

    //PutString(20,160,9,"hello\0");

   
    while(1);
}
 
void InitPalette()
{
   
	set_palette(0, 15, table_rgb);
	return;

	/* C语言中的static char语句只能用于数据，相当于汇编中的DB指令 */
}

void set_palette(int start, int end, unsigned char *rgb)
{
	int i, eflags;
	eflags = FunctionLoadEflags();	/* 记录中断许可标志的值 */
	FunctionCli(); 					/* 将中断许可标志置为0,禁止中断 */
	FunctionOut8(0x03c8, start);
	for (i = start; i <= end; i++) {
		FunctionOut8(0x03c9, rgb[0] / 4);
		FunctionOut8(0x03c9, rgb[1] / 4);
		FunctionOut8(0x03c9, rgb[2] / 4);
		rgb += 3;
	}
	FunctionStoreEflags(eflags);	/* 复原中断许可标志 */
	return;
}

void DrawRectangle(int x1,int y1,int x2,int y2,int color)
{
    int k;
    //k=color+10;
    int i,j;
    char *p;
    for (i=y1;i<=y2;i++)
    {

        for (j=x1;j<=x2;j++)
        {
            p = (char*)(0xa0000 + 320 * i + j);
           
            *p = color;
        }
    }
    return;
} 

void boxfill8(unsigned char *vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1)
{
	int x, y;
	for (y = y0; y <= y1; y++) {
		for (x = x0; x <= x1; x++)
			vram[y * xsize + x] = c;
	}
	return;
}

void init_screen(char *vram, int x, int y)
{
	boxfill8(vram, x, COL8_008484,  0,     0,      x -  1, y - 29);
	boxfill8(vram, x, COL8_C6C6C6,  0,     y - 28, x -  1, y - 28);
	boxfill8(vram, x, COL8_FFFFFF,  0,     y - 27, x -  1, y - 27);
	boxfill8(vram, x, COL8_C6C6C6,  0,     y - 26, x -  1, y -  1);

	boxfill8(vram, x, COL8_FFFFFF,  3,     y - 24, 59,     y - 24);
	boxfill8(vram, x, COL8_FFFFFF,  2,     y - 24,  2,     y -  4);
	boxfill8(vram, x, COL8_848484,  3,     y -  4, 59,     y -  4);
	boxfill8(vram, x, COL8_848484, 59,     y - 23, 59,     y -  5);
	boxfill8(vram, x, COL8_000000,  2,     y -  3, 59,     y -  3);
	boxfill8(vram, x, COL8_000000, 60,     y - 24, 60,     y -  3);

	boxfill8(vram, x, COL8_848484, x - 47, y - 24, x -  4, y - 24);
	boxfill8(vram, x, COL8_848484, x - 47, y - 23, x - 47, y -  4);
	boxfill8(vram, x, COL8_FFFFFF, x - 47, y -  3, x -  4, y -  3);
	boxfill8(vram, x, COL8_FFFFFF, x -  3, y - 24, x -  3, y -  3);
	return;
}
 

 /* void SysMain()
{
    int i;
    char *p;
    for(i = 0x00000;i<0x0ffff;i++)
    {
        p = (char *)i;
        *p = 101;
    }
    while(1);
}
 */
