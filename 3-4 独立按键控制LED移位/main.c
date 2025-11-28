#include <REGX52.H>
void Delay(unsigned int t);

unsigned char LEDNum;

void main()
{
	P2=~0x01;
	while(1)
	{
		if(P3_1==0)//press
		{
			//filter fluctuation
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
				LEDNum=0;
			P2=~(0x01<<LEDNum);//reverse LED light
		}
		if(P3_0==0)//press
		{
			//filter fluctuation
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			if(LEDNum<=0)
				LEDNum=7;
			else
				LEDNum--;
			P2=~(0x01<<LEDNum);//reverse LED light
		}
	}
}

void Delay(unsigned int t)		//@12.000MHz
{
	unsigned char i, j;
	while(t)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}
}