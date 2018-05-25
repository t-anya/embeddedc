//data transfer via bluetooth
#include<reg51.h>
	unsigned int i,j;
	char str;
	sbit led=P3^2;
void main()
{
	TMOD=0x20; //set mode
	TH1=0xFD;  //baud rate
	SCON=0x50; //serial communication
	TR1=1;
	// while(1)
 //sending data to mobile

		SBUF='S';
		for(i=0;i<10000;i++)
		{
			for(j=0;j<10;j++);
		}
		//sending data to led
		
		if(!RI)  //for sending ddata
		{
			str=SBUF;  
			RI=0;
			if(str=='1')
				led=1; //led not glowing
			else if(str=='2')
				led=0;
		}
		for(i=0;i<10000;i++)
		{
			for(j=0;j<10;j++);
		}
	
	
}
