#include "font.h"
void DrawPoint(char *vram, int xsize,int x,int y,int color);//画一个点
void PutChar(char *vram, int xsize,int x,int y, char put_char, int color);//画一个字符

char *Int2String(int a, char *buf);

void PutCharHex(char *vram, int xsize,int x, int y, int color, char c);
void PutIntHex(char *vram, int xsize,int x,int y,int color, int a);


extern const char font_code_global[94][16];


typedef int* va_list;
#define va_start(ap, A)   (ap = (int *)&(A) + 1)
#define va_arg(ap, T)     (*(T *)ap++)
#define va_end(ap)        ((void)0)


/* void DrawPoint(int x,int y,int color)
{
    char *p;
     p = (char*)(0xFD000000 + (320 * y + x) * 3);//计算某个像素的内存地址
    *(p+2) = (char)(color >> 16);//color是int型，4字节，最高字节保留不用，剩下为rgb，向右移动10位，把R值取出
    *(p+1) = (char)((color >> 8) & 0xFF);//向右移动8字节，然后 &0x11111111，得到G
    *p     = (char)(color & 0xFF);//同理，B值
    return;
} */


 void DrawPoint(char *vram, int xsize,int x,int y,int color)
{
    char *p;
      p = (vram + xsize * y + x);//计算某个像素的内存地址
    
    *p     = color ;
    return;
}

void PutString(char *vram, int xsize,int x,int y, int color, unsigned char *str111)//输出字符串，输出直到结尾为\0停止符
{
     int i=0;
    //char *p=str111;
    
     while(str111[i] != '\0')
     {
        PutChar(vram,  xsize,x+8*i , y, str111[i],color);//there are 2 pixels between char
         i++;
     }

}




/* void putfont8( int x, int y, char c, char *font)
{
	int i;
	char *p, d ;
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
} */

/* void PutChar(int x,int y, char *put_char, int color)//输出一个字符
{

    int i;
    char d;
    
        for (i=0;i<16;i++)//扫描点阵，从上到下16行
        {
            d=put_char[i];
            if((d & 0x80) != 0) //compare font & 1000 0000
                DrawPoint(x+0,y+i,color);
            if((d & 0x40) != 0) //compare font & 0100 0000
                DrawPoint(x+1,y+i,color);
            if((d & 0x20) != 0) //compare font & 0010 0000
                DrawPoint(x+2,y+i,color);
            if((d & 0x10) != 0) //compare font & 0001 0000
                DrawPoint(x+3,y+i,color);
            if((d & 0x08) != 0) //compare font & 0000 1000
                DrawPoint(x+4,y+i,color);
            if((d & 0x04) != 0) //compare font & 0000 0100
                DrawPoint(x+5,y+i,color);
            if((d & 0x02) != 0) //compare font & 0000 0010
                DrawPoint(x+6,y+i,color);
            if((d & 0x01) != 0) //compare font & 0000 0001
                DrawPoint(x+7,y+i,color);
        }
    
} */

void PutChar(char *vram, int xsize,int x,int y, char put_char, int color)//输出一个字符
{

    int i;
    if (put_char >= 0x21 && put_char <= 0x7e)
    {
        for (i=0;i<16;i++)//扫描点阵，从上到下16行
        {
            if((font_code_global[put_char-0x21][i] & 0x80) == 0x80) //compare font & 1000 0000
                DrawPoint(vram,  xsize,x+0,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x40) == 0x40) //compare font & 0100 0000
                DrawPoint(vram,  xsize,x+1,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x20) == 0x20) //compare font & 0010 0000
                DrawPoint(vram,  xsize,x+2,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x10) == 0x10) //compare font & 0001 0000
                DrawPoint(vram,  xsize,x+3,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x08) == 0x08) //compare font & 0000 1000
                DrawPoint(vram,  xsize,x+4,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x04) == 0x04) //compare font & 0000 0100
                DrawPoint(vram,  xsize,x+5,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x02) == 0x02) //compare font & 0000 0010
                DrawPoint(vram,  xsize,x+6,y+i,color);
            if((font_code_global[put_char-0x21][i] & 0x01) == 0x01) //compare font & 0000 0001
                DrawPoint(vram,  xsize,x+7,y+i,color);
        }
    }
}
/* struct BOOTINFO2{
       char xyls, leds, vmode, reserve;
       short scrnx, scrny;
       char *vram ;
};
struct BOOTINFO2 *binfo02= (struct BOOTINFO2 * ) 0x0ff0;
 */
//把int转化为一个字符串
char *Int2String(int a, char *buf)
{
    int num = a;
    int i = 0;
    int len = 0;

    do 
    {
        buf[i++] = num % 10 + '0';
        num /= 10;        
    } while (num);
    buf[i] = '\0';

    len = i;
    for (i = 0; i < len/2; i++)
    {
        char tmp;
        tmp = buf[i];
        buf[i] = buf[len-i-1];
        buf[len-i-1] = tmp;
    }

    return buf;    
}
//输出一个16进制字符穿
void PutCharHex(char *vram, int xsize,int x, int y, int color, char c)
{
    char * hex = "0123456789ABCDEF";
    PutChar(vram,xsize, x,y,hex[(c>>4) & 0x0F],color);
    PutChar(vram,xsize, x+8,y,hex[(c>>0) & 0x0F],color);
}
//输出一个int的16进制字符串
void PutIntHex(char *vram, int xsize,int x,int y,int color, int a)
{
    PutCharHex(vram,xsize,x,y,color, (a>>24) & 0xFF );
    PutCharHex(vram,xsize,x+16,y,color, (a>>16) & 0xFF );
    PutCharHex(vram,xsize,x+32,y,color, (a>>8) & 0xFF );
    PutCharHex(vram,xsize,x+48,y,color, (a>>0) & 0xFF );
}
// you can add this option at  gcc commandline : -fno-stack-protector, otherwise this function is essential
  void __stack_chk_fail_local(void) { 

      // printaaa(binfo->vram, binfo->scrnx, 10, 30, 7, "some infomation you want tell end user");
  }

int printaaa(char *vram, int xsize,int x, int y, int color, const char * format, ...)
{
   

    //binfo = (struct BOOTINFO1 * ) 0x0ff0;

   
    char c;    
    va_list ap;
    va_start(ap, format);
    int i=0;
    while ((c = *format++) != '\0')
    {
    i++;
        switch (c)
        {
            case '%':
                c = *format++;
                switch (c)
                {
                    char ch;
                    char * p;
                    int a;
                    char buf[100];            
                    case 'c':
                        ch = va_arg(ap, int); 
                        PutChar(vram,xsize, x+8*i,y,ch,color);
                        //PutChar(vram,  xsize,x+8*i , y, str111[i],color);
                        break;
                    case 's':
                        p = va_arg(ap, char *);
                        //p = (char *)ap++;
                        PutString(vram,xsize,x+8*i, y, color, p);
                        break;                    
                    case 'x':
                        a = va_arg(ap, int);
                        PutIntHex(vram,xsize,x,y,color,a);
                        break;        
                    case 'd':
                        a = va_arg(ap, int);
                        Int2String(a, buf);
                        PutString(vram,xsize,x+8*i, y, color, buf);
                        break;    

                    default:
                        break;
                }                
                break;        

            default:
                PutChar(vram,xsize,x+8*i,y,c,color);
                break;
        }
    }
    return 0;    
} 
