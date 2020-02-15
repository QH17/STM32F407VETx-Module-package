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

extern "C"
{
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "lcd.h"
#include "Interrupt.h"
}
#include "LCD_CPP.h"
#include "Capture.h"

extern u8  TIM5CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u32	TIM5CH1_CAPTURE_VAL;	//输入捕获值  
u16 pwmval=0;    
u8 dir=1;  

int main(void)
{ 	
	long long temp=0; 
	//设置系统中断优先级分组2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//初始化延时函数
	delay_init(168);  
	
	LCD_Config	lcd;
	Capture cap;
   	while(1)
	{			
 		delay_ms(10);
		//成功捕获到了一次高电平
 		if(TIM5CH1_CAPTURE_STA&0X80)        
		{
			//获得[0:5]的数值，得到计数值
			temp=TIM5CH1_CAPTURE_STA&0X3F;
			//溢出时间总和
			temp*=0XFFFFFFFF;
			//得到总的高电平时间
			//temp+=TIM5CH1_CAPTURE_VAL;		   
			LCD_ShowNum(30,70,1000000/(TIM5CH1_CAPTURE_VAL*2),16,16);
			//开启下一次捕获
			TIM5CH1_CAPTURE_STA=0;			     
		}
	}
}


