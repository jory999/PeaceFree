
void DrawPoint(int x,int y,int color);//画一个点
void PutChar(int x,int y, char put_char, int color);//画一个字符
void PutString(int x,int y, char* string, int color);//输出字符串，输出直到结尾为\0停止符
int printfa(int x, int y, int color, const char * format, ...);

void DrawFontPoint(int x,int y,int color);
char *Int2String(int a, char *buf);
void PutCharHex(int x, int y, int color, char c);
void PutIntHex(int x,int y,int color, int a);
