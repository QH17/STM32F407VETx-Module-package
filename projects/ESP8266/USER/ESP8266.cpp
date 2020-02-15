#include "ESP8266.h"

ESP8266::ESP8266()
{
	uart2_init(115200);
	delay_init(168);
	station_init();
	udp_init("192.168.4.2",8001,1112);
}

ESP8266::~ESP8266()
{
	
}
//复位
void ESP8266::reset()
{
	printf_u2("AT+RST\r\n");
}
//建站
void ESP8266::station_init()
{
	printf_u2("AT+CWMODE=3\r\n");
	delay_ms(300);
	printf_u2("AT+CWSAP=\"ESP\",\"12345678\"\r\n");
	delay_ms(100);
}
//连接至WIFI
void ESP8266::wifi_connect(const char* SSID,const char* PASSWORD)
{
	printf_u2("AT+CWJAP=\"%s\",\"%s\"\r\n",SSID,PASSWORD);

	delay_ms(2000);
}
//建立UDP服务器
void ESP8266::udp_init(const char* IP, u16 Port, u16 local_port)
{
	printf_u2("AT+CIPSTART=\"UDP\",\"%s\",%d,%d,0\r\n", IP, Port, local_port);
	delay_ms(300);
}
//发送文本
void ESP8266::txt_send(u8 size, const char* text)
{
	printf_u2("AT+CIPSEND=%d\r\n",size);
	delay_ms(10);
	printf_u2("%s",text);
}
//发送数值
void ESP8266::val_send(u8 size, float value, bool isFloat)
{
	printf_u2("AT+CIPSEND=%d\r\n",size);
	if(isFloat)
	{
		printf_u2("%f",value);	
	}
	else
	{
		printf_u2("%d",(u16)value);	
	}
}
