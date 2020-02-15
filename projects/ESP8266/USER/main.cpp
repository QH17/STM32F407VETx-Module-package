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
#include "ESP8266.h"
//1¶È(¡ã)=0.0174533»¡¶È(rad)
#include "screen.h"
int main(void)
{
	ESP8266		wifi;
	while(1)
	{
		wifi.txt_send(3,"123");
		delay_ms(100);
	}
}


//	while(1)
//	{
//		if(USART2_RX_STA&0x8000)
//		{
//			u16 len=USART2_RX_STA&0x3fff;
//			char *s;
//			for(int i=0;i<len;i++)
//			{
//				sprintf(s+i,"%c",*(USART2_RX_BUF+i));
//			}
//			src.info_send(s,"t5");
//			USART2_RX_STA = 0;
//			if(!strncmp(s,"WIFI GOT IP",11))
//			{
//				src.info_send("2","t6");
//				break;
//			}
//		}
//	}
