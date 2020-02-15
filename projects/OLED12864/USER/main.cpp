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
}
#include "oled.h"


int main(void)
{
	delay_init(168);     
	uart_init(115200);
	OLED12864 oled;
	while(1);
}
