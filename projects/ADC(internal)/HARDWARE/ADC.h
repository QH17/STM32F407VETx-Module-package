#ifndef __ADC_H
#define __ADC_H
extern "C"
{
	#include "stm32f4xx_adc.h"
}

class ADC_Internal
{
public:
	ADC_Internal();
	~ADC_Internal();

	u16 Get_Adc(u8 ch = ADC_Channel_5);
	u16 Get_Adc_Average(u8 ch,u8 times);

private:
	void func_Init();
};

#endif
