
#include "stm32f303xe.h"
#include "ws2812b.h"
#include "tim17.h"
#include "pll.h"

int main(void){
	
	WS2812B_Init();
	uint32_t i;
	WS2812B_GPIO_Set(0);
	for(i=0;i<3200;i++){
		__NOP();
	}
	
	for(i=0;i<48;i++){
		WS2812B_Data_Bit(1);
		//WS2812B_Data_Bit(0);
	}
	
	while(1){
		
	}
	
}



