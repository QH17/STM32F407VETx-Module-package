#ifndef	__SCREEN_H
#define __SCREEN_H
extern "C"
{
	#include "sys.h"
	#include "usart.h"
}

//‡≈£ø£ø£ø£ø£ø£ø£ø£ø£ø£ø
//#define	freq	0x00;
//#define	DC		0x01
//#define AC		0x02

class	screen
{
public:
	screen();
	~screen();

	void update(u8 vol,u8 channel = 0);
	void clear_screen(void);
	void txt_send(float val,const char* id,const char* name);
private:

};

#endif
