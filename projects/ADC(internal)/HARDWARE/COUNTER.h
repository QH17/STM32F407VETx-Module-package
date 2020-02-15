#ifndef __COUNTER_H
#define __COUNTER_H
extern "C"
{
	#include "stm32f4xx_tim.h"
	#include "sys.h"
	#include "interrupt.h"
}

class COUNTER
{
public:
	COUNTER();
	~COUNTER();
private:
	void TIM3_Int_Init(u16 arr = 4999,u16 psc = 8399);
	void LED_Init(void);
};

#endif
