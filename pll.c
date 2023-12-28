

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
}

void PLL_PLLSRC_Set_HSIDIV2(void){
	RCC->CFGR &=~ RCC_CFGR_PLLSRC_Msk;
}

void PLL_PLLMUL_Set_x12(void){
	RCC->CFGR &=~ RCC_CFGR_PLLMUL_Msk;
	RCC->CFGR |= RCC_CFGR_PLLMUL12;
}

void PLL_Wait_To_Stabilize(void){
	RCC->CR |= RCC_CR_PLLON;
	while((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY){}
}

void PLL_Set_SysClk_PLL(void){
	RCC->CFGR &=~ RCC_CFGR_SW_Msk;
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL){}
}

void PLL_Set_48MHz(void){
	PLL_Set_SysClk_HSI();
  PLL_Clear_PLLON();
  PLL_PLLSRC_Set_HSIDIV2();
  PLL_PLLMUL_Set_x12();
  PLL_Wait_To_Stabilize();
  PLL_Set_SysClk_PLL();
}


