#include<reg51.h>
#include<stdio.h>
void uart_init(void);
void uart_string(char *str);
void uart_trans(char ch);
void uart_receive(void);
void delay();

void uart_init(void)
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TL1 = 0xFD;
	TR1 = 1;
	PCON = 0x80;
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
void uart_receive(void)
{
	char c;
	while(RI == 0);
	RI = 0;
	c = SBUF;
	uart_trans(c);
	P1 = c;
	delay();
	P1 = 0x00;
	delay();
  
}
void delay(void)
{
	unsigned int i;
	for(i=0;i<100000;i++);
}
void main(void)
{ 
	unsigned int i;
	uart_init();
	uart_string("SILICON\r\n");
	while(1)
	{
		
	 uart_receive();
		
  for(i=0;i<5;i++){		
		delay();
   }
	}

}