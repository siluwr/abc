#include "framebuffer.h"
extern unsigned int fb_base_addr;
extern unsigned int bpp;
extern unsigned int xsize;
extern unsigned int ysize;
extern int m;
void game(void);
void yidong( int wz,int i);
void PutPixel(UINT32 x, UINT32 y, UINT32 color)
{
	UINT16 *addr = (UINT16 *)fb_base_addr + (y * xsize + x);
            *addr = (UINT16) color;
}


void ClearScr(UINT32 color)
{   
    UINT32 x,y;
    for (y = 0; y < ysize; y++)
        for (x = 0; x < xsize; x++)
            PutPixel(x, y, color);
}
extern unsigned char gImage_666[];
extern int fanhui;
void huatu(void)
{
	UINT32 x, y;
	UINT32 color; int z;
	z=0;
	for (y = 0; y < ysize; y++)
		for (x = 0; x < xsize; x++)
	{
		z = (480*y+x)*2;
		color = ((gImage_666[z+1] << 8) | gImage_666[z]);
		PutPixel(x, y, color);
				
	}
}
int n;
extern unsigned char gImage_kaishi[];
void start(void)
{		UINT32 x, y;
		UINT32 color; int z;
		z=0;
	for (y = 0; y < ysize; y++)
		for (x = 0; x < xsize; x++)
	{
		z = (480*y+x)*2;
		color = ((gImage_kaishi[z+1] << 8) | gImage_kaishi[z]);
		PutPixel(x, y, color);}
}
int suiji[40]={0,1,2,2,1,0,2,1,0,2,1,0,0,2,1,2,0,1,1,0,1,2,2,0,0,1,1,2,1,0,1,2,0,0,0,1,2,1,2,1,1,0,0};
int weizhi;
int fen;
void game(void)
{
ClearScr(0x0);
fen=0;
UINT32 x, y;
int wz,i;
int sj=0;
while(m==3)
{wz= suiji[sj];
weizhi=999;
for (y = 0; y < 120; y++)
		for (x = 160*wz; x < 160*wz+160; x++)
	{
		PutPixel(x, y, 0xffff);}
sj++;
if(sj>40) m=4;
for(i=0;i<272;i++)
yidong(wz,i);
}
}
void yidong( int wz,int i)
{
UINT32 x, y;
y=120+i;
int kop;
for(kop=0;kop<19;kop++);
for(x=160*wz;x<160*wz+160;x++)
{PutPixel(x, y, 0xffff);
if(y>272) weizhi=wz;
 PutPixel(x, y-120, 0x0);}
}
extern  unsigned char gImage_win[] ;
void win1(void);
void winwin(void)
{

		UINT32 x, y;
		UINT32 color; int z;
		z=0;
	for (y = 0; y < ysize; y++)
		for (x = 0; x < xsize;x++)
	{
		z = (480*y+x)*2;
		color = ((gImage_win[z] << 8) | gImage_win[z+1]);
		PutPixel(x, y, color);
	}
}
extern unsigned char gImage_loss[];
void lossloss(void)
{	UINT32 x, y;
	UINT32 color; int z;
	z=0;
	for (y = 0; y < ysize; y++)
		for (x = 0; x < xsize; x++)
	{
		z = (480*y+x)*2;
		color = ((gImage_loss[z+1] << 8) | gImage_loss[z]);
		PutPixel(x, y, color);			
	}
}
