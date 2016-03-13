#ifndef _IIC_H_
#define _IIC_H_

#include <reg52.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

sbit SCL = P2^1;
sbit SDA = P2^0;

void iicDelay(void);
void iicInit();
void iicStart();
void iicStop();
void iicRespons();
void iicWriteByte(uchar date);
uchar iicReadByte();




#endif