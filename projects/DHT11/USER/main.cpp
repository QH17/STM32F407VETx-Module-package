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
#include "lcd.h"
#include "stm32f4xx_fsmc.h"
#include "stdio.h"
}
#include "LCD_CPP.h"
#include "DHT11.h"

int main(void)
{
	LCD_Config B;
	DHT11	DHT;
	
	while(1)
	{
		DHT.Func_Activate();	
	}

}



