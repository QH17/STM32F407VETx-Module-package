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
#include "PWM.h"


int main(void)
{
	PWM	pwm;
	pwm.CLK_set(100);
//	pwm.compare_set(TIM14,250);
	while(1);
}




