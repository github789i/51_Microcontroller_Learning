#include <REGX52.H>

void main()
{
	// MCU default high state when start
//	P2=0xFE;
	P2_0=0;
	while(1)
	{
		if(P3_1==0)//TXD button Press
		{
			P2_0=0;//LED light
		}
		else//loose
		{
			P2_0=1;//LED no light
		}
	}
}
