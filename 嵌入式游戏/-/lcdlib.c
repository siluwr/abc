
#include <stdio.h>
#include "lcddrv.h"
#include "framebuffer.h"
void Test_Lcd_Tft_16Bit_480272(void)
{
    Lcd_Port_Init();                     
    Tft_Lcd_Init(MODE_TFT_16BIT_480272); 
    Lcd_PowerEnable(0, 1);             
    Lcd_EnvidOnOff(1);                  
    Lcd_EnvidOnOff(0);
}



