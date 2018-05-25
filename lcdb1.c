#include<reg51.h>
sbit RS=P2^0;  //for command or data
sbit EN=P2^1;  //for enable
unsigned char str;  //for sending character
void delay();  
void cmdtolcd(unsigned char cmd);  //sending command to lcd
void datatolcd(unsigned char dat);  //sending Data to lcd


void delay()
{
	int j;
	for(j=0;j<1000;j++);
	
}

void cmdtolcd(unsigned char cmd)
{
	P0=cmd;  //placing command in port 0
	RS=0;    //command mode
	EN=1;    
	delay();
	EN=0;
}
void datatolcd(unsigned char dat)
{ 
	P0=dat;  //placing Data in port 0
	RS=1;    //Data mode
	EN=1;
	delay();
	EN=0;
}
void main(void)
{
	cmdtolcd(0x38);  //initialize
	delay();
	cmdtolcd(0x0E);  //display on cursor on
	delay();
	cmdtolcd(0x80);  //cursor on first line first position
	delay();
	cmdtolcd(0x01);  //clear display screen
	delay();
	
	TMOD=0x20;  //setting timer mode
	TH1=0xFD;   //baud rate 9600
	SCON=0x50;  //serial communoication via bluetooth
	TR1=1;      
	
	
    if(!RI) //Data not transmitted yet
    { 
			str=SBUF;   //sending Data Using a character array
		  
	    datatolcd(str);
			delay();
			RI=0;
	    
    }
	
		 
    delay();
}		

