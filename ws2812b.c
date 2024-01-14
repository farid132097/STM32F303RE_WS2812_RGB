

#include "stm32f303xe.h"
#include "ws2812b.h"
#include "tim17.h"
#include "pll.h"

#define  TOTAL_PIXEL 10

void WS2812B_GPIO_Config(void){
	RCC->AHBENR|=RCC_AHBENR_GPIOBEN;
	GPIOB->MODER &=~ GPIO_MODER_MODER8_Msk;
	GPIOB->MODER |= GPIO_MODER_MODER8_0;
	GPIOB->OTYPER &=~ GPIO_OTYPER_OT_8;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8_Msk;
	GPIOB->PUPDR &=~ GPIO_PUPDR_PUPDR8_Msk;
	GPIOB->ODR &=~ GPIO_ODR_8;
}

void WS2812B_Data_Bit_Low(void){
	GPIOB->ODR |= GPIO_ODR_8;
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	GPIOB->ODR &=~ GPIO_ODR_8;
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
}

void WS2812B_Data_Bit_High(void){
	GPIOB->ODR |= GPIO_ODR_8;
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	GPIOB->ODR &=~ GPIO_ODR_8;
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
}

void WS2812B_Data_Bit(uint8_t val){
	if(val==1){
		WS2812B_Data_Bit_High();
	}else if(val==0){
		WS2812B_Data_Bit_Low();
	}
}

void WS2812B_Clear(void){
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
	WS2812B_Data_Bit_Low();
}

void WS2812B_Send_Byte(uint8_t val){
	if(val & 0x80){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
	if(val & 0x40){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
	if(val & 0x20){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
	if(val & 0x10){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
	if(val & 0x08){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
	if(val & 0x04){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
	if(val & 0x02){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
	if(val & 0x01){
	  WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
}

void WS2812B_Send_Pixel(uint8_t r, uint8_t g, uint8_t b){
	WS2812B_Send_Byte(g);
	WS2812B_Send_Byte(r);
	WS2812B_Send_Byte(b);
}

void WS2812B_Pixel_Delay(void){
	for(uint32_t i=0;i<40000;i++){
		__NOP();
	}
}

void WS2812B_Init(void){
	PLL_Set_72MHz();
	TIM17_Clock_Enable();
	WS2812B_GPIO_Config();
	for(uint8_t j=0;j<TOTAL_PIXEL;j++){
		WS2812B_Clear();
	}
}




