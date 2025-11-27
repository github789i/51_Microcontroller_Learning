#include <REGX52.H>

void Delay(unsigned int t)		//@12.000MHz
{
	unsigned char i, j;
	while(t--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


void main()
{
	unsigned char LEDNum=0;
	while(1)
	{
		if(P3_1==0)//press
		{
			//filter fluctuation
			Delay(20);
			while(P3_1==0);
			Delay(20);
			//P2 default state: 1111 1111
			
			LEDNum++;
			P2=~LEDNum;;//reverse LED light
		}
	}
}