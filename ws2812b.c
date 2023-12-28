

#include "stm32f303xe.h"
#include "ws2812b.h"
#include "tim17.h"
#include "pll.h"

void WS2812B_GPIO_Config(void){
	RCC->AHBENR|=RCC_AHBENR_GPIOBEN;
	GPIOB->MODER &=~ GPIO_MODER_MODER8_Msk;
	GPIOB->MODER |= GPIO_MODER_MODER8_0;
	GPIOB->OTYPER &=~ GPIO_OTYPER_OT_8;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8_Msk;
	GPIOB->PUPDR &=~ GPIO_PUPDR_PUPDR8_Msk;
	GPIOB->ODR &=~ GPIO_ODR_8;
}

void WS2812B_GPIO_Set(uint8_t state){
	if(state==1){
		GPIOB->ODR |= GPIO_ODR_8;
	}else{
		GPIOB->ODR &=~ GPIO_ODR_8;
	}
}

void WS2812B_Data_Bit_Low(void){
	WS2812B_GPIO_Set(1);
	TIM17_T0H();
	WS2812B_GPIO_Set(0);
	TIM17_T0L();
}

void WS2812B_Data_Bit_High(void){
	WS2812B_GPIO_Set(1);
	TIM17_T1H();
	WS2812B_GPIO_Set(0);
	TIM17_T1L();
}

void WS2812B_Data_Bit(uint8_t val){
	if(val==1){
		WS2812B_Data_Bit_High();
	}else{
		WS2812B_Data_Bit_Low();
	}
}

void WS2812B_Init(void){
	PLL_Set_48MHz();
	TIM17_Clock_Enable();
	WS2812B_GPIO_Config();
}




