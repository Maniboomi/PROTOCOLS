#include<stdio.h>
#include<reg51.h>
sbit SRED = P0^0;
sbit SYELLOW = P0^1;
sbit SGREEN = P0^2;
sbit SRIGHT = P0^3;
sbit SOUTH = P0^4;
sbit NRED = P1^0;
sbit NYELLOW = P1^1;
sbit NGREEN = P1^2;
sbit NRIGHT = P1^3;
sbit NORTH = P1^4;
sbit ERED = P2^0;
sbit EYELLOW = P2^1;
sbit EGREEN = P2^2;
sbit ERIGHT = P2^3;
sbit EAST = P2^4;
sbit WRED = P3^0;
sbit WYELLOW = P3^1;
sbit WGREEN = P3^2;
sbit WRIGHT = P3^3;
sbit WEST = P3^4;
void traf_init(void)
{
	SOUTH = 0;
	NORTH = 0;
	EAST = 0;
	WEST = 0;
}
void delay_us(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<65535;j++);
	}
}
void south(void)
{
	SOUTH = 1;
	if(SOUTH == 1)
	{
		SRED = 1;
		delay_us(70);
		SRED = 0;
		SYELLOW = 1;
		delay_us(28);
		SYELLOW = 0;
		SGREEN = 1;
		SRIGHT = 1;
		delay_us(70);
		SGREEN = 0;
	}
	SOUTH = 0;
}
void north(void)
{
	NORTH = 1;
	if(NORTH == 1)
	{
		NRED = 1;
		delay_us(70);
		NRED = 0;
		NYELLOW = 1;
		delay_us(28);
		NYELLOW = 0;
		NGREEN = 1;
		NRIGHT = 1;
		delay_us(70);
		NGREEN = 0;
	}
	NORTH = 0;
}
void east(void)
{
	EAST = 1;
	if(EAST == 1)
	{
		ERED = 1;
		delay_us(70);
		ERED = 0;
		EYELLOW = 1;
		delay_us(28);
		EYELLOW = 0;
		EGREEN = 1;
		ERIGHT = 1;
		delay_us(70);
		EGREEN = 0;
	}
	EAST = 0;
}
void west(void)
{
	WEST = 1;
	if(WEST == 1)
	{
		WRED = 1;
		delay_us(70);
		WRED = 0;
		WYELLOW = 1;
		delay_us(28);
		WYELLOW = 0;
		WGREEN = 1;
		WRIGHT = 1;
		delay_us(70);
		WGREEN = 0;
	}
	WEST = 0;
}
void main(void)
{
	traf_init();
	south();
	north();
	east();
	west();
}
	
	

