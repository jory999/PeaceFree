
void DrawPoint(char *vram, int xsize,int x,int y,int color);//画一个点
void PutChar(char *vram, int xsize,int x,int y, char put_char, int color);//画一个字符
void PutString(char *vram, int xsize,int x,int y, int color,  char *str111);//输出字符串，输出直到结尾为\0停止符
int printaaa(char *vram, int xsize,int x, int y, int color,  const char * format, ...);
//int printaaa(char *vram, int xsize,int x, int y, int color, const (char *)&format, ...);

void DrawFontPoint(int x,int y,int color);
char *Int2String(int a, char *buf);
void PutCharHex(char *vram, int xsize,int x, int y, int color, char c);
void PutIntHex(char *vram, int xsize,int x,int y,int color, int a);

//static char font_code_globalA[16]={0x00,24,24,0x18,0x18,36,0x24,0x24,0x24,0x7e,0x42,0x42,0x42,0xe7,0x00,0x00};
// const char font_code_globalA[16] = {0x00,0x18,0x18,0x18,0x18,0x24,0x24,0x24,0x24,0x7e,0x42,0x42,0x42,0xe7,0x00,0x00};

struct FIFO8 {
	unsigned char *buf;
	int p, q, size, free, flags;
};

#define PIC0_ICW1		0x0020
#define PIC0_OCW2		0x0020
#define PIC0_IMR		0x0021
#define PIC0_ICW2		0x0021
#define PIC0_ICW3		0x0021
#define PIC0_ICW4		0x0021
#define PIC1_ICW1		0x00a0
#define PIC1_OCW2		0x00a0
#define PIC1_IMR		0x00a1
#define PIC1_ICW2		0x00a1
#define PIC1_ICW3		0x00a1
#define PIC1_ICW4		0x00a1
void fifo8_init(struct FIFO8 *fifo, int size, unsigned char *buf);
int fifo8_put(struct FIFO8 *fifo, unsigned char data);
int fifo8_get(struct FIFO8 *fifo);
int fifo8_status(struct FIFO8 *fifo);

