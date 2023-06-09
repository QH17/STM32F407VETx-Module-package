/**
 **********************************************************************
 *@Copyright(c)		Lance Zhang
 *@Identification	CHIC
 *@Describtion		Template
 *
 *@PresentVersion	1.0
 *@Writer			Lance Zhang
 *@Date				7/20/2019
 **********************************************************************/
/**********************************************************************
 *@Instruction
 *使用方法：
 *
 *1、初始化watch_dog类
 *2、调用IWDG_Init()函数进行初始化
 *3、用feed()函数喂狗
 **********************************************************************/
/**********************************************************************
 *@Attention		构造函数里没有对看门狗进行初始化，需要手动初始
 *@Attention		默认的定时器初始化为prer = 5 ,rlr = 400,1秒喂一次狗
 **********************************************************************
 *@Compatibility	调用了stm32f4xx_iwdg.h对独立看门狗进行了初始化
 *					没有使用看门狗中断，因此没有包含interrupt.c
 *
 *整体兼容性：高
 *
 *@Characteristic	硬件计数，一般情况下不会被中断服务函数打断
 *					目前已知能够打断计数的服务函数只有复位
 **********************************************************************/

#ifndef	__IWDG_H
#define __IWDG_H
extern "C"{
	#include "stm32f4xx_iwdg.h"
}

class	watch_dog
{
public:
	watch_dog();
	~watch_dog();
	//初始化看门狗,默认一秒钟喂一次狗
	void IWDG_Init(u8 prer = 5, u16 rlr = 400);
	//喂狗
	void feed();
};

#endif
