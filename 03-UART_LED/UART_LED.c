#include<reg51.h>
#include<stdio.h>
void uart_init(void);
void uart_string(char *str);
void uart_trans(char ch);
char uart_receive(void);
void delay(void);
sbit push_button = P3^3;
void uart_init(void)
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	PCON = 0x00;
}
void uart_string(char *str)
{
	while(*str != '\0')
	{
		uart_trans(*str);
		str++;
	}
}
void uart_trans(char ch)
{
	SBUF = ch;
	while(TI == 0);
	TI = 0;
}
char uart_receive(void)
{	
	while(RI == 0);
	RI = 0;
	return SBUF;  
}
void delay(void)
{
	unsigned int i, j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<65535;j++);
	}
}
void main(void)
{ 
	unsigned int i;
	unsigned char str[] = "SILICON";
	unsigned char received;
	uart_init();
	for(i=0;str[i] != '\0';i++)
	{
		uart_trans(str[i]);
		push_button = 0;
		received = uart_receive();
		P2 = received;
		delay();
		P2 = 0x00;
	}
	while(1);
}