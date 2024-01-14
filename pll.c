

#include "stm32f303xe.h"
#include "pll.h"

void PLL_HSI_On(void){
	if( (RCC->CR & RCC_CR_HSION) != RCC_CR_HSION ){
		RCC->CR |= RCC_CR_HSION;
		while( !(RCC->CR & RCC_CR_HSIRDY) ){}
	}
}

void PLL_Set_SysClk_HSI(void){
	PLL_HSI_On();
	if((RCC->CFGR & RCC_CFGR_SWS_HSI) != RCC_CFGR_SWS_HSI){
		RCC->CFGR &=~ RCC_CFGR_SW_Msk;
		while((RCC->CFGR & RCC_CFGR_SWS_HSI) != RCC_CFGR_SWS_HSI){}
	}
}

void PLL_Clear_PLLON(void){
	RCC->CR &=~ RCC_CR_PLLON;
	while((RCC->CR & RCC_CR_PLLRDY) != 0){}
}

void PLL_PLLSRC_Set_HSI(void){
	RCC->CFGR &=~ RCC_CFGR_PLLSRC_Msk;
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_PREDIV;
}

void PLL_Prescale_APB1(void){
	RCC->CFGR &=~RCC_CFGR_PPRE1_Msk;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
}

void PLL_Set_PLLMUL(void){
	RCC->CFGR &=~ RCC_CFGR_PLLMUL_Msk;
	RCC->CFGR |= RCC_CFGR_PLLMUL9;
}

void PLL_Wait_To_Stabilize(void){
	RCC->CR |= RCC_CR_PLLON;
	while((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY){}
}

void PLL_Set_SysClk_PLL(void){
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL){}
}

void PLL_Set_72MHz(void){
	PLL_Set_SysClk_HSI();
  PLL_Clear_PLLON();
	FLASH->ACR=FLASH_ACR_LATENCY_1|FLASH_ACR_PRFTBE;
	
  PLL_PLLSRC_Set_HSI();
	PLL_Prescale_APB1();
  PLL_Set_PLLMUL();
  PLL_Wait_To_Stabilize();
  PLL_Set_SysClk_PLL();
}




