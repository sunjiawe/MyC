#include "lcd.h"

void lcdDelay(int xms)
{
	uchar a,b;
	for (; xms>0; xms--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
}

void lcdWriteCmd(int cmd)
{
	LCD_RS = 0;
	LCD_RW = 0;
	dataPin = cmd;
	LCD_E = 1;
	lcdDelay(1);
	LCD_E = 0;
}


void lcdWriteDat(int dat)
{
	LCD_RS = 1;
	LCD_RW = 0;
	dataPin = dat;
	LCD_E = 1;
	lcdDelay(1);
	LCD_E = 0;
}


void lcdInit()
{
	lcdDelay(15);
	lcdWriteCmd(0x38);
	lcdDelay(5);
	lcdWriteCmd(0x38);
	lcdDelay(5);
	lcdWriteCmd(0x38);
	lcdWriteCmd(0x38);
	lcdWriteCmd(0x08);
	lcdWriteCmd(0x01);
	lcdWriteCmd(0x06);
	lcdWriteCmd(0x0c);
}


