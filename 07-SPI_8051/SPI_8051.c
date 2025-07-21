#include<stdio.h>
#include<reg51.h>
#define MASTER P2
#define SLAVE P3
sbit CPOL = P1^0;
sbit CPHA = P1^1;
sbit SCLK = P1^2;
sbit CC = P1^3;
sbit L_MISO = P1^4;
sbit L_MOSI = P1^5;
void delay(void)
{
	unsigned int k,g;
	for(k=0;k<14;k++)
	{
		for(g=0;g<65535;g++);
	}
}
void spi_init(void)
{
	//MODE 1 
	CPOL = 0;
	CPHA = 1;
	SCLK = 0;
	CC = 1; //slave 1
}
void main(void)
{
	unsigned char Mdata = 83;
	unsigned char Sdata = 63;
	unsigned char Adata;
	unsigned int i;
	unsigned int MOSI;
	unsigned int MISO;
	Adata = Sdata;
	spi_init();
	for(i=0;i<8;i++)
		{
			MOSI = (Mdata >> (7-i))&0x01;
			delay();
			SCLK = 1;
			Sdata = (Sdata << 1) | (MOSI & 0x01);
			delay();
			SCLK = 0;
			delay();
		}
		//MOSI = 1; // after getting the data from master to slave.
		L_MOSI = 1;
		MASTER = Sdata;
		Sdata = Adata;
		for(i=0;i<8;i++)
		{
			MISO = (Sdata >> (7-i))&0x01;
			SCLK = 1;
			Mdata = (Mdata << 1) | (MISO & 0x01);
			SCLK = 0;
		}
		//MISO = 1; //after getting the data from slave to master. 
		L_MISO = 1;
		SLAVE = Mdata;
		while(1);
}
		
		