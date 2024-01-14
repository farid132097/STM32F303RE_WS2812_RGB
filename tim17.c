
#include "stm32f303xe.h"
#include "tim17.h"

uint16_t clk_counter=0;

void TIM17_Clock_Enable(void){
	RCC->APB2ENR |= RCC_APB2ENR_TIM17EN;
	TIM17->CR1   |= TIM_CR1_CEN;
}

void TIM17_T0H(void){
	TIM17->CNT = 0;
	while(TIM17->CNT < 5){}
}

void TIM17_T0L(void){
	TIM17->CNT = 0;
	while(TIM17->CNT < 26){}
}

void TIM17_T1H(void){
	TIM17->CNT = 0;
	while(TIM17->CNT < 20){}
}

void TIM17_T1L(void){
	TIM17->CNT = 0;
	while(TIM17->CNT < 42){}
}



