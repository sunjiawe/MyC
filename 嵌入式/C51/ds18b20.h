#ifndef _DS18B20_H_
#define _DS18B20_H_

#include <reg52.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

sbit ds_dat = P3^7;



void ds18b20Delayms(uint xms);
uchar ds18b20Init(void);
void ds18b20WriteBit(uchar dat);
void ds18b20WriteByte(uchar dat);
uchar ds18b20ReadBit(void);
uchar ds18b20ReadByte();
void ds18b20Change(void);
float ds18b20GetTemp(void);

#endif