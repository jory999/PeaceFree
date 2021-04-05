/*************************************************************************
	> File:		test.c
	> Describe:	尝试使用点阵字体显示ASCII 码和汉字
	> Author:	孤舟钓客
	> Mail:		guzhoudiaoke@126.com 
	> Time:		2013年01月01日 星期二 00时47分17秒
 ************************************************************************/
 
#include <stdio.h>
 
unsigned char font_asc[4096];
unsigned char font_hzk[267616];
 
int load_asc()
{
	FILE *fp;
	
	fp = fopen("./resource/font/ASC16", "rb");
	if (fp == NULL)
	{
		printf ("read ASC16 file failed!");
		return 0;
	}
 
	fread(font_asc, 1, 4096, fp);
	fclose(fp);
 
	return 1;
}
 
int load_hzk()
{
	FILE *fp;
	
	fp = fopen("./resource/font/HZK16", "rb");
	if (fp == NULL)
	{
		printf ("read HZK16 file failed!");
		return 0;
	}
 
	fread(font_hzk, 1, 267616, fp);
	fclose(fp);
 
	return 1;
}
 
int disp_asc(unsigned char c)
{
	unsigned char *pc = font_asc + (int)c * 16;
 
	int i, j;
	for (i = 0; i < 16; i++)
	{
		unsigned char test_bit = 128;
		for (j = 0; j < 8; j++)
		{
			if (*pc & test_bit)
				printf("*");
			else
				printf(" ");
 
			test_bit >>= 1;
		}
		printf("\n");
		pc++;
	}
 
	return 1;
}
 
int disp_hzk(unsigned char ch[3])
{
	unsigned char qu_no	 = ch[0] - 0xa0;
	unsigned char wei_no = ch[1] - 0xa0;
	unsigned long offset = (94*(qu_no-1) + (wei_no-1)) * 32;
	unsigned char *pc = font_hzk + offset;
	
	int i, j;
	for (i = 0; i < 32; i++)
	{
		unsigned char test_bit = 128;
		for (j = 0; j < 8; j++)
		{
			if (*pc & test_bit)
				printf("@");
			else
				printf(" ");
 
			test_bit >>= 1;
		}
 
		pc++;
		if (i & 1)
			printf("\n");
	}
	
	return 1;
}
 
int main()
{
	if (!load_asc() || !load_hzk())
	{
		printf("load font error!");
		return 0;
	}
 
	unsigned char c = 'G';
	disp_asc(c);
 
	unsigned char hz[3] = "钓";
	disp_hzk(hz);
	disp_hzk("客");
 
	return 0;
}