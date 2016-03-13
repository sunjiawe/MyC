#ifndef _AT24C16_H_
#define _AT24C16_H_

#include <reg52.h>
#include "iic.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

void at24c16Init(void);
void at24c16WriteAddress(uchar address,uchar info);
uchar at24c16ReadAddress(uchar address);


#endif