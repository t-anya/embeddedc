#include<reg51.h>
sbit RS=P2^0;  //for command or data
sbit EN=P2^1;  //for enable
char arr[20];  //for sending string character by character
int x,i=0;
void delay();  
void cmdtolcd(unsigned char cmd);  //sending command to lcd
void datatolcd(unsigned char dat);  //sending Data to lcd


void delay()
{
	int j;
	for(j=0;j<1000;j++)
	
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
	SCON=0x50;  //serial communication via bluetooth
	TR1=1;      
	do
	{ 
    if(!RI) //Data not transmitted yet
    { 
			arr[i++]=SBUF;   //sending Data Using a character array
		  RI=0;
	    datatolcd(arr[i]);
	    delay();
    }
	}
		while(arr[i]!=0);  // if the user sends 0 then dataa transfer will stop
    delay();
}		

