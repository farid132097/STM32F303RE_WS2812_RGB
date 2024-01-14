
#include "stm32f303xe.h"
#include "ws2812b.h"
#include "tim17.h"
#include "pll.h"

uint8_t  red=0, green=0, blue=0;
uint8_t  red_dir=0, green_dir=0, blue_dir=0;

#define  RED_MAX   255
#define  GREEN_MAX 255
#define  BLUE_MAX  255

#define  UPCOUNT   0
#define  DOWNCOUNT 1
#define  HALT      2

int main(void){
	
	WS2812B_Init();
	
	red=RED_MAX;
	red_dir=HALT;
	green_dir=HALT;
	blue_dir=HALT;
	
	while(1){
		
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Send_Pixel(red,green,blue);
		WS2812B_Pixel_Delay();
		
		
		
		
		if(red_dir==UPCOUNT){
			if(red<RED_MAX){
				red++;
			}
		}else if(red_dir==DOWNCOUNT){
			if(red>0){
			  red--;
			}
		}
		
		if(green_dir==UPCOUNT){
			if(green<GREEN_MAX){
				green++;
			}
		}else if(green_dir==DOWNCOUNT){
			if(green>0){
			  green--;
			}
		}
		
		if(blue_dir==UPCOUNT){
			if(blue<BLUE_MAX){
				blue++;
			}
		}else if(blue_dir==DOWNCOUNT){
			if(blue>0){
			  blue--;
			}
		}
		
		if     ((red == RED_MAX) && (green == 0  ) && (blue == 0)){
			red_dir   = HALT;
			green_dir = UPCOUNT;
			blue_dir  = HALT;
		}
		
		else if((red == RED_MAX) && (green == GREEN_MAX) && (blue == 0)){
			red_dir   = DOWNCOUNT;
			green_dir = HALT;
			blue_dir  = HALT;
		}
		
		else if((red == 0  ) && (green == GREEN_MAX) && (blue == 0)){
			red_dir   = HALT;
			green_dir = HALT;
			blue_dir  = UPCOUNT;
		}
		
		else if((red == 0  ) && (green == GREEN_MAX) && (blue == BLUE_MAX)){
			red_dir   = UPCOUNT;
			green_dir = DOWNCOUNT;
			blue_dir  = HALT;
		}
		
		/*else if((red == 0  ) && (green == 0) && (blue == BLUE_MAX)){
			red_dir   = UPCOUNT;
			green_dir = HALT;
			blue_dir  = HALT;
		}*/
		
		else if((red == RED_MAX) && (green == 0) && (blue == BLUE_MAX)){
			red_dir   = HALT;
			green_dir = HALT;
			blue_dir  = DOWNCOUNT;
		}
		
	}
	
}



