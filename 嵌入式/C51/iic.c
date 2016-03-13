#include "iic.h"

// void iicDelay(int xms)
// {
// 	uchar a,b;
// 	for (; xms>0; xms--)
// 	{
// 		 for (b=199;b>0;b--)
// 		 {
// 		  	for(a=1;a>0;a--);
// 		 }      
// 	}
// }
void iicDelay(void)
{
	; ;
}



//初始化
void iicInit()		
{
	SCL=1;
	iicDelay();
	SDA=1;
	iicDelay();
}

//起始信号
void iicStart()	    
{
	SDA=1;
	iicDelay();
	SCL=1;
	iicDelay();
	SDA=0;
	iicDelay();
}

//停止信号
void iicStop()		
{
	SDA=0;
	iicDelay();
	SCL=1;
	iicDelay();
	SDA=1;
	iicDelay();
}

//应答信号
void iicRespons()		
{
	uchar i=0;
	SCL=1;
	iicDelay();
	while((SDA==1)&&(i<255))
	{
		i++;
	}		
	SCL=0;
	iicDelay();
}

//	写一个字节
void iicWriteByte(uchar date)
{
	uchar i,temp;
	temp=date;
	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		SCL=0;
		iicDelay();
		SDA=CY;
		iicDelay();
		SCL=1;
		iicDelay();	
	}
	SCL=0;
	iicDelay();
	SDA=1;
	iicDelay();
}

//读一个字节
uchar iicReadByte()
{
	uchar i,j,k;
	SCL=0;
	iicDelay();
	SDA=1;
	for(i=0;i<8;i++)
	{
		SCL=1;
		iicDelay();
		if(SDA==1)
		{
		    j = 1;
		}
		else
		{
			j = 0;
		}
		k=(k<<1)|j;
		SCL=0;
		iicDelay();
	}
	iicDelay();
	return k;
}

