#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;


void main()
{
	UART_Init();
	while(1)
	{

	}
}

//单片机接收数据时 产生 串口接收中断，跳转到以下程序
void UART_Routine() interrupt 4
{
	if(RI==1)//接收控制中断(判断是发送还是接收)
	{
		P2=~SBUF;//读出数据SBUF
		UART_SendByte(SBUF);
		RI=0;//软件复位
	}
}