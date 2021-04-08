
void DrawPoint(char *vram, int xsize,int x,int y,int color);//画一个点
void PutChar(char *vram, int xsize,int x,int y, char put_char, int color);//画一个字符
void PutString(char *vram, int xsize,int x,int y, int color, unsigned char *str111);//输出字符串，输出直到结尾为\0停止符
int printaaa(char *vram, int xsize,int x, int y, int color, const char * format, ...);

void DrawFontPoint(int x,int y,int color);
char *Int2String(int a, char *buf);
void PutCharHex(char *vram, int xsize,int x, int y, int color, char c);
void PutIntHex(char *vram, int xsize,int x,int y,int color, int a);

//static char font_code_globalA[16]={0x00,24,24,0x18,0x18,36,0x24,0x24,0x24,0x7e,0x42,0x42,0x42,0xe7,0x00,0x00};
// const char font_code_globalA[16] = {0x00,0x18,0x18,0x18,0x18,0x24,0x24,0x24,0x24,0x7e,0x42,0x42,0x42,0xe7,0x00,0x00};