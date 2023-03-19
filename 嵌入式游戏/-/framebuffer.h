#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__
#include <types.h>
void PutPixel(UINT32 x, UINT32 y, UINT32 color);
void DrawLine(int x1,int y1,int x2,int y2,int color);
void Mire(void);
void ClearScr(UINT32 color);

#endif /*__FRAMEBUFFER_H__*/
void huatu(void);
void start(void);
