#include <reg52.h>
#define lcd P2
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
sbit GET=P1^3;

void delay();
void LCD_CMD(int x);
void LCD_DATA(unsigned char c);
void LCD_INIT();
void SEND(unsigned char *s);

void delay(){
	 int i,j;
  for(i=0;i<14;i++){
	 for(j=0;j<65536;j++);
	}
}
void LCD_INIT(){
  LCD_CMD(0x38);
	delay() ;
	LCD_CMD(0x01);
	delay();
	LCD_CMD(0x80);
	delay();
	LCD_CMD(0x0c);
	delay();
}
void LCD_CMD(int x)
{
  EN=1;
	RS=0;
	RW=0;
	lcd=x;
	delay();
	EN=0;
}

void SEND(unsigned char *s)
{
  while(*s){
		  LCD_DATA(*s);
		  while(TI==0);
		   TI=0;
			 SBUF=*s++;
			 GET=0;
	}
}
void LCD_DATA(unsigned char c)
{
  EN=1;
	RS=1;
	RW=0;
	lcd=c;
	delay();
	EN=0;
}

 int main()
 {
	 unsigned char ch;
	TMOD=0x20;
	SCON=0x50;
	TH1=0xFD;
  TR1=1;
  LCD_INIT();
	LCD_CMD(0x80);
  SEND("SILICON");
	while(1)
	{
		while(RI==0);
		ch=SBUF;
		RI=0;
		LCD_DATA(ch);
		SBUF=ch ;
		while(TI==0);
		TI=0;
		}
		return 0;
 }