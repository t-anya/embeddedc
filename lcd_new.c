#include<reg51.h>
//sfr info=0x80;
sbit RS=P2^0;
sbit EN=P2^2;
void cmdtolcd(unsigned char cmd);
void datatolcd(unsigned char info);
void delay(unsigned int x);

void main(){
//	unsigned int x;
	
	while(1){
		cmdtolcd(0x38);
		delay(50);
	  cmdtolcd(0x0E);
		delay(80);
	  cmdtolcd(0x01);
		delay(80);
	  cmdtolcd(0x80); //to print in the second line the use 0xC0
	  delay(80);
		datatolcd('S');
		delay(80);
		datatolcd('T');
		delay(80);
		datatolcd('P');
		delay(100);
	}
}

void cmdtolcd(unsigned char cmd){
	P0=cmd;
	RS=0;
	EN=1;
	delay(1);
	EN=0;
}
void datatolcd(unsigned char info){
	P0= info;
	RS=1;
	EN=1;
	delay(1);
	EN=0;
}

void delay(unsigned int x){
	unsigned int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<1275;j++);
	}
}