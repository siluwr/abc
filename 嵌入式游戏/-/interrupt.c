#include "s3c24xx.h"
#include "framebuffer.h"
extern int m;
extern int weizhi;
extern int fen;
void EINT_Handle()
{
    unsigned long oft = INTOFFSET;
    unsigned long val = EINTPEND;
    switch (oft)
    {
    case 0:   //s2被按下时
    {
        if (weizhi == 0)fen++;   //判断击打方块的位置是否正确，是得分，不是扣分
        else fen--;
        break;
    }
    
    case 2: // s3被按下
    {
        if (weizhi == 1)fen++;    //判断击打方块的位置是否正确，是得分，不是扣分
        else fen--;
        break;
    }

   
    case 5:
    {
        if (val & (1 << 11))     // s4被按下
        {
            if (weizhi == 2)fen++;    //判断击打方块的位置是否正确，是得分，不是扣分
            else fen--;
            break;
        }
        else if (val & (1 << 19))  // s5被按下
        {
            m = m + 1;      //将m+1，使主函数发生改变
            if (m == 5) m = 1;//若m为5，则将其改为1
            break;
        }
    }
    default:
        break;
    }
    if (oft == 5)
    {
        EINTPEND = (1 << 11);   //清中断标志位
        EINTPEND = (1 << 19);   //清中断标志位
    }
    SRCPND = 1 << oft;         
    INTPND = 1 << oft;            
}
