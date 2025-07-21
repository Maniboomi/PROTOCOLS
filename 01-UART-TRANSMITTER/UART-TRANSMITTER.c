#include<reg51.h>

void uart_control(void);
void uart_trans(char ch);
void delay();
void uart_control(void)
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TL1 = 0xFD;
	TR1 = 1;
	PCON = 0x80;
}
void uart_trans(char ch)
{
	char c;
	SBUF = ch;
	while(TI == 0);
		TI = 0;
	c = SBUF;
	P1 = ch;
	delay();
	P1 = 0x00;
	delay();
}

void delay(){
	int i;
for(i=0;i<50000;i++);
}
void main(void)
{
	uart_control();
	uart_trans('X');
}
		