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
    case 0:   //s2������ʱ
    {
        if (weizhi == 0)fen++;   //�жϻ��򷽿��λ���Ƿ���ȷ���ǵ÷֣����ǿ۷�
        else fen--;
        break;
    }
    
    case 2: // s3������
    {
        if (weizhi == 1)fen++;    //�жϻ��򷽿��λ���Ƿ���ȷ���ǵ÷֣����ǿ۷�
        else fen--;
        break;
    }

   
    case 5:
    {
        if (val & (1 << 11))     // s4������
        {
            if (weizhi == 2)fen++;    //�жϻ��򷽿��λ���Ƿ���ȷ���ǵ÷֣����ǿ۷�
            else fen--;
            break;
        }
        else if (val & (1 << 19))  // s5������
        {
            m = m + 1;      //��m+1��ʹ�����������ı�
            if (m == 5) m = 1;//��mΪ5�������Ϊ1
            break;
        }
    }
    default:
        break;
    }
    if (oft == 5)
    {
        EINTPEND = (1 << 11);   //���жϱ�־λ
        EINTPEND = (1 << 19);   //���жϱ�־λ
    }
    SRCPND = 1 << oft;         
    INTPND = 1 << oft;            
}
