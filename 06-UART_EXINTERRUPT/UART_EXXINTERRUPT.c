#include<reg51.h>
void uart_init(void);
void uart_string(char *str);
void uart_trans(char ch);
char uart_receive(void);
void delay(void);
sbit led = P1^0;
void uart_init(void)
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TL1 = 0xFD;
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
	char rx;
	while(RI == 0);
	RI = 0;
	rx = SBUF;
	return rx;
}
void delay(void)
{
	unsigned int i,j;
	for(i=0;i<14;i++)
	{
		for(j=0;j<5000;j++);
	}
}
void main(void)
{
	char ch;
	char mode = 0;
	uart_init();
	uart_string("SILICON\r\n");
	
	while(1)
	{
		if(RI == 1)
		{
			ch = uart_receive();
			if(ch == 'A')
			{
				mode = 1;
			}
			else if(ch == 'B')
			{
				mode = 2;
			}
			else if(ch == 'C')
			{
				mode = 3;
			}
		}
		if(mode == 1)
		{
			led = 1;
			delay();
			led = 0;
			delay();
		}
		else if(mode == 2)
		{
			led = 1;
		}
		else if(mode == 3)
		{
			led = 0;
		}
	}
}