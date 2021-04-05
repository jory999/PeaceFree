
//#include "font.h"
//#include <stdio.h> 
extern unsigned char table_rgb[16 * 3];
extern const char font_code_globalA[16];
extern const char font_code_global[94][16];

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

void SysMain()
{
    char *vram;
    int xsize, ysize;
    struct BOOTINFO *binfo;

     binfo = (struct BOOTINFO * ) 0x0ff0;
    xsize = (*binfo).scrnx;
    ysize = (*binfo).scrny;
    vram  = (*binfo).vram;

    InitPalette();
    init_screen(binfo->vram, binfo->scrnx, binfo->scrny);
	
    
	 
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
      PutString(10, 10,1,nowput);

	  unsigned  char nowstr[66]="Hello Great World...";
	  putfonts8_asc(10, 60,1,nowstr);
        
    
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
