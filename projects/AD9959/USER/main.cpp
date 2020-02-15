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
#include "AD9959.h"
}

//1¶È(¡ã)=0.0174533»¡¶È(rad)

int main(void)
{
	AD9959_Init();
	
	AD9959_WriteFreq(0,200000000);
	AD9959_WriteAmplitude(0,400);
//	AD9959_Write_Phase(0,0);
	
	AD9959_WriteFreq(1,200000000);
	AD9959_WriteAmplitude(1,400);
//	AD9959_Write_Phase(1,90);
	
	AD9959_WriteFreq(2,200000000);
	AD9959_WriteAmplitude(2,400);
//	AD9959_Write_Phase(2,0);
//	
	AD9959_WriteFreq(3,200000000);
	AD9959_WriteAmplitude(3,400);
//	AD9959_Write_Phase(3,0);
	
	while(1);
}



