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
**中断服务函数文件
 **********************************************************************
 *中断服务函数不能放在.cpp文件中，因此需要额外建立一个.c文件
 **********************************************************************
**/
#include "Interrupt.h"
#include "stm32f4xx_adc.h"
/************************************************************************
 *输入捕获状态
 *[7]:	0:没有成功的捕获;
 *		1:成功捕获到一次.
 *
 *[6]:	0:还没捕获到低电平;
 *		1:已经捕获到低电平.
 *
 *[5:0]:捕获低电平后溢出的次数
************************************************************************/

/*未成功捕获时的状态*/
/*-------------------------------
 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 
 --------------------------------
 | 0 | x | x | x | x | x | x | x |
**-------------------------------*/
/*成功捕获到高电平时的状态*/
/*-------------------------------
 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 
 --------------------------------
 | x | 1 | x | x | x | x | x | x |
**-------------------------------*/
/*捕获溢出*/
/*-------------------------------
 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 
 --------------------------------
 | x | x | 1 | 1 | 1 | 1 | 1 | 1 |
**-------------------------------*/

//输入捕获状态		    	
u8  TIM5CH1_CAPTURE_STA=0;	
//输入捕获值(TIM2/TIM5是32位)
u32	TIM5CH1_CAPTURE_VAL;	
//定时器5中断服务程序	
/************************************************************************
 *用于捕获一个正频宽（如果要捕获整个周期，去下面把下降沿捕获换成上升沿就行）
************************************************************************/
void TIM5_IRQHandler(void)
{ 		    
//	//还未成功捕获	
// 	if((TIM5CH1_CAPTURE_STA&0X80)==0)
//	{
//		//在等待过程中溢出，基本不存在的
//		if(TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
//		{	     
//			//已经捕获到高电平
//			if(TIM5CH1_CAPTURE_STA&0X40)
//			{
//				//高电平太长
//				if((TIM5CH1_CAPTURE_STA&0X3F)==0X3F)
//				{
//					//标记成功捕获一次
//					TIM5CH1_CAPTURE_STA|=0X80;		
//					TIM5CH1_CAPTURE_VAL=0XFFFFFFFF;
//				}else TIM5CH1_CAPTURE_STA++;
//			}	 
//		}
//		//捕获1发生捕获事件
//		if(TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)
//		{	
//			//捕获到一个下降沿
//			if(TIM5CH1_CAPTURE_STA&0X40)		 		
//			{	 
//				//标记成功捕获到一次高电平脉宽
//				TIM5CH1_CAPTURE_STA|=0X80;		
//				//获取当前的捕获值.
//				TIM5CH1_CAPTURE_VAL=TIM_GetCapture1(TIM5);
//				//CC1P=0 设置为上升沿捕获
//	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Rising); 
//				TIM_Cmd(TIM5,ENABLE);
//			}
//			//当前为第一次捕获上升沿
//			else  								
//			{
//				//清空STA和VAL
//				TIM5CH1_CAPTURE_STA=0;			
//				TIM5CH1_CAPTURE_VAL=0;
//				//设置第6位为1，标记捕获到了上升沿信号
//				TIM5CH1_CAPTURE_STA|=0X40;
//				//定时器计数值清零
//	 			TIM_SetCounter(TIM5,0);
//				//CC1P=1 设置为下降沿捕获
//	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Falling);
//				//使能定时器5
//				TIM_Cmd(TIM5,ENABLE); 	
//			}		    
//		}			     	    					   
// 	}
//	//清除中断标志位
//	TIM_ClearITPendingBit(TIM5, TIM_IT_CC1|TIM_IT_Update); 
}

//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		//extern u16 adcx;
		//PAout(5) =!PAout(5);//D3 翻转
		//adcx=Get_Adc(ADC_Channel_5);//获取通道5的转换值，20次取平均
		flag = !flag;
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}
