/**********************************************************************
 *Copyright(c)		Lance Zhang
 *Identification	CHIC
 *Describtion		Template
 *
 *Present Version	1.0
 *Writer			Lance Zhang
 *Date				8/16/2018
 **********************************************************************
**/
/**********************************************************************
 *@Attention 	由于初始化串口，此功能可能会与其他usart功能冲突
 *@Attention	用到delay.h
 **********************************************************************
**/
#ifndef	__SCREEN_H
#define __SCREEN_H
extern "C"
{
	#include "sys.h"
	#include "usart.h"
	#include "delay.h"
}

//嗯？？？？？？什么操作？？？？
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
	//发送纯文本信息
	void info_send(const char* info,const char* id);
	//控制进度条
	void prosess_bar(u8 status,const char* id = "j0");
	//设置字体颜色
	void txt_color(const char* id,const char* color = "RED");
	//直接通过串口发送代码
	void send(const char* cmd = "");
	//翻页
	void to_page(u8 page);

public:
	void func_start();
};

#endif
