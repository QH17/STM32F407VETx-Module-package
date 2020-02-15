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
#include "MAX262.h"

int main(void)
{
	MAX262	max;
	max.Filter_On();
	//float ff = max.bs_WorkFclk();
	//max.CLK_set(ff);
	while(1);
}



