
#include "stm32f303xe.h"

void WS2812B_GPIO_Config(void);
void WS2812B_Data_Bit_Low(void);
void WS2812B_Data_Bit_High(void);
void WS2812B_Data_Bit(uint8_t val);
void WS2812B_Clear(void);
void WS2812B_Send_Byte(uint8_t val);
void WS2812B_Send_Pixel(uint8_t r, uint8_t g, uint8_t b);
void WS2812B_Pixel_Delay(void);
void WS2812B_Init(void);


