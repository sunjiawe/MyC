#include "at24c16.h"


void at24c16Init()
{
	iicInit();
}




//指定地址写一个字节数据
void at24c16WriteAddress(uchar address,uchar info)
{
	iicStart();
	iicWriteByte(0xa0);
	iicRespons();
	iicWriteByte(address);
	iicRespons();
	iicWriteByte(info);
	iicRespons();
	iicStop();
}


//指定地址读一个字节数据
uchar at24c16ReadAddress(uchar address)
{
	uchar dd;
	iicStart();
	iicWriteByte(0xa0);
	iicRespons();
	iicWriteByte(address);
	iicRespons();
	iicStart();
	iicWriteByte(0xa1);
	iicRespons();
	dd=iicReadByte();
	iicStop();
	return dd;
}