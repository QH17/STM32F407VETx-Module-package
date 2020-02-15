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
#include "stm32f4xx_iwdg.h"
#include "stm32f4xx_gpio.h"
}
#include "IWDG.h"
//1¶È(¡ã)=0.0174533»¡¶È(rad)
void LED_Init();
void Key_Init();

int main(void)
{
	delay_init(168);
	watch_dog	iwdg;
	LED_Init();
	Key_Init();
	iwdg.IWDG_Init(4,500);
	delay_ms(500);
	while(1)
	{
		if(!PEin(3))
		{
			PAout(5) = 0;
		}
		else
		{
			iwdg.feed();
		}
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
	PAout(5) = 1;
}

void Key_Init()
{
	GPIO_InitTypeDef	KEY;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	
	KEY.GPIO_Mode	=	GPIO_Mode_IN;
	KEY.GPIO_Pin	=	GPIO_Pin_3;
	KEY.GPIO_PuPd	=	GPIO_PuPd_UP;
	
	GPIO_Init(GPIOE,&KEY);
}
