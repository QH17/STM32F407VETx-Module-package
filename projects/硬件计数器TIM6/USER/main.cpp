/*
 **********************************************************************
 *Copyright(c)		Lance Zhang
 *Identification	CHIC
 *Describtion		Template
 *
 *Present Version	1.0
 *Writer			Lance Zhang
 *Date				8/16/2018
 **********************************************************************
**/


extern "C" { 
#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "arm_math.h"
#include "stm32f4xx_tim.h"
}
#include "screen.h"
#include "debug_timer.h"
//1¶È(¡ã)=0.0174533»¡¶È(rad)

void LED_Init();

int main(void)
{
	delay_init(168);
	debug_timer	timer;
	uart_init(115200);
	while(1)
	{
		TIM_SetCounter(TIM6,0);
		delay_ms(10);
		float time = TIM_GetCounter(TIM6);
		printf("\r\n%f\r\n",time);
	}
}

void LED_Init()
{
	GPIO_InitTypeDef	LED;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	LED.GPIO_Mode	=	GPIO_Mode_OUT;
	LED.GPIO_OType	=	GPIO_OType_PP;
	LED.GPIO_Pin	=	GPIO_Pin_5;
	LED.GPIO_PuPd	=	GPIO_PuPd_UP;
	LED.GPIO_Speed	=	GPIO_Speed_100MHz;
	
	GPIO_Init(GPIOA,&LED);
}

