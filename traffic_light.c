#include<reg51.h>

sbit gled=P3^4;
sbit rled=P3^6;
sbit yled=P3^2;
unsigned int j;
void delay()
{
	TMOD=0x11;
	TH0=00;
	TL0=00;
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;
}

void main()
{ 
// traffic light sequence green -> yellow -> red
	while(1)
	{
		gled=0;  //green is on
		yled=1;
		rled=1;
	  for(j=0;j<10;j++)
		{delay();
		}
		
		gled=1;
		yled=0;  // yellow is on
		rled=1;
	  for(j=0;j<50;j++)
		{delay();
		}
		
		gled=1;
		yled=1;
		rled=0;  //red is on
	  
		for(j=0;j<50;j++)
		{delay();
		}
		
	}
}