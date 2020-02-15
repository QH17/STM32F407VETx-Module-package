#ifndef	__ESP8266_H
#define __ESP8266_H
extern "C"{
	#include "usart.h"
	#include "delay.h"
	#include "string.h"
}

class	ESP8266
{
public:
	ESP8266();
	~ESP8266();
public:
	void reset();				//复位
	void station_init();
public:
	void wifi_connect(const char* SSID,const char* PASSWORD);		//连接指定 WIFI
	void udp_init(const char* IP = "192.168.43.41", u16 Port = 8001, u16 local_port = 1112);//设置UDP的IP,远端端口号，近端端口号
	void txt_send(u8 size, const char* text);						//输入数据大小和数据内容
	void val_send(u8 size, float value, bool isFloat = 0);
};

#endif
