/*********************************************************************
*中断定义基础功能：
*	命名：类名一律小写
*	函数：功能初始化函数
*		  功能选择函数
*********************************************************************
*
*文件名：EXTI.h
*所需库：stm32f4xx_syscfg.c, stm32f4xx_exti.h
*********************************************************************/
//#ifndef __EXTI
//#define __EXTI

//extern "C"{
//#include "stm32f4xx.h"
//#include "stm32f4xx_gpio.h"
//#include "delay.h"
//#include "stm32f4xx_exti.h"
//#include "stm32f4xx_syscfg.h"
//}

//#include "LCD_CPP.h"

//class exti
//{
//public:
//	exti();
//	~exti();
//private:
//	void func_init();
//	void EXIO_Init();
//	//测试用
//	void LED_Init();
//	LCD_Config lcd;
//};


//#endif
#ifndef __EXTI
#define __EXIT	 
extern "C"
{
	#include "sys.h" 	
}

void EXTIX_Init(void);	//外部中断初始化
void EXIO_Init(void);
#endif
