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
#include "DAC_Internal.h"
//1¶È(¡ã)=0.0174533»¡¶È(rad)

int main(void)
{
	delay_init(168);
	DAC_Internal	dac;
	//u8 i = 0;
	dac.DAC_Reset(10);
	while(1)
	{

	}
}



