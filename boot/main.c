#include "font.h"
//#include <stdio.h> 

extern void FunctionCli(void);
extern void FunctionSti(void);
extern void FunctionOut8(int port, int data);
extern int FunctionLoadEflags(void);
extern void FunctionStoreEflags(int eflags);

void InitPalette();
void DrawRectangle(int x1,int y1,int x2,int y2,int color);
#define PALETTE_NUMBER 16

struct BOOTINFO{
       char xyls, leds, vmode, reserve;
       short scrnx, scrny;
       char *vram ;

};

void SysMain()
{
    char *vram;
    int xsize, ysize;
    struct BOOTINFO *binfo;
    
      PutString(20,20,"hello world...\0",0xc6c6c6);
      PutString(30, 30,"There Is An INT!!!!\0",0xff00ff);
        
    InitPalette();
    //DrawRectangle(0,0,320,320,9);
    //DrawRectangle(10,10,100,100,10);
    
    DrawRectangle(10,150,300,200,1);
    DrawRectangle(19,170,90,190,0x840000);

    //PutString(20,160,9,"hello world\0");

   
    while(1);
}
void InitPalette()
{
    int i,eflags;
    static unsigned char table_rgb [PALETTE_NUMBER*3 ] = {
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

    eflags = FunctionLoadEflags();
    FunctionCli();
    FunctionOut8(0x03c8,0);
    for (i=0;i<PALETTE_NUMBER*3;i++)
    {
        FunctionOut8(0x03c9,table_rgb[i] / 4 );
        //FunctionOut8(0x03c9,table_rgb[3*i-3]  );
        //FunctionOut8(0x03c9,table_rgb[3*i-2]  );
        //FunctionOut8(0x03c9,table_rgb[3*i-1]  );
    }
    FunctionStoreEflags(eflags);
    //FunctionSti();
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