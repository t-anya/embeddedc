//data transfer via bluetooth
#include<reg51.h>
void main()
{
	TMOD=0x20; //set mode
	TH1=0xFD;  //baud rate
	SCON=0x50; //serial communication
	TR1=1;
	while(1)
	{
		int i,j;
		SBUF='S';
		for(i=0;i<10000;i++)
		{
			for(j=0;j<10;j++);
		}
	}
}
