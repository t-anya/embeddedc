//to blink an LED
#include<reg51.h>     //library included so as to use registers defined in it
sbit LED1=P3^2;		 //variable LED1 has the value of pin 2 of port 3
sbit LED2=P3^3;     //variable LED2 has the value of pin 3 of port 3
void delay(unsigned int i);	 //prototype of delay function		

void main(void)
{
	while(1)
	{
		
          	  LED1=0; LED2=1;		//LED1 is ON and LED2 is OFF
	  delay(75);			//calling the delay function with 75  input
	  LED1=1; LED2=0;      //LED1 is OFF and LED2 is ON
	  delay(75);          
	}
}
//definition of delay function
void delay(unsigned int i)
	{
		unsigned int k;
	  unsigned int j;
		for(j=0;j<i;j++)        //loop goes from 0 to input(75 )
		for(k=0;k<7500;k++);     //loop goes from 0 to 7500 
	}
		
		
