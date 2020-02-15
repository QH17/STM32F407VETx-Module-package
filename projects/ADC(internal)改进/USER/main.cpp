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
}
#include "ADC.h"
#include "screen.h"
//1¶È(¡ã)=0.0174533»¡¶È(rad)
int main(void)
{
	delay_init(168);
	//uart_init(115200);
	screen	src;
	//COUNTER	timer;
	ADC_Internal	adc;
	while(1)
	{
		//printf("\r\n%d\r\n",VOLTAGE);
		src.txt_send(*adc.vol,"t2","v");
		delay_ms(500);
	}
}



