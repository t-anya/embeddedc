#include<reg51.h>
sbit led1=P3^2;
sbit led2=P3^3;
sbit buzzer=P3^4;
sbit sensor=P3^1;
void main()
{	
	sensor=1; //i/p
	while(1)
	{
		if(sensor)
		{
			led1=0;
			led2=0;
			buzzer=1;
		}
		else
		{
			led1=1;
			led2=1;
			buzzer=0;
		}
	}
}