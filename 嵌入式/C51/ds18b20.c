#include "ds18b20.h"

void ds18b20Delayms(uint xms)
{
	uint x;
	for( ; xms>0; xms--)
	{
		for(x=110; x>0; x--);
	}
}

uchar ds18b20Init()
{
	uchar i;
	ds_dat = 0;
	// delayus(640);
	i = 70;	
	while(i--); 
	ds_dat = 1;
	i = 0;
	while(ds_dat == 1)
	{
		i++;
		if(i>5)
		{
			return 0;
		}
		ds18b20Delayms(1);
	}
	return 1;
}


void ds18b20WriteBit(uchar dat)
{
	uchar i;
	if(dat == 0)
	{
		ds_dat = 0;
		// delayus(60);
		i = 8;
		while(i--);
		ds_dat = 1;
		i++;i++;	
	}else
	{
		ds_dat = 0;
		// delayus(5);
		i++;
		i++;
		ds_dat = 1;
		// delayus(60);	
		i=8;
		while(i--);	
	}

}

void ds18b20WriteByte(uchar dat)
{
	int i;
	int mask;
	for(i=0; i<8; i++)
	{
		mask = (dat >> i) & 0x01;
		ds18b20WriteBit(mask);
	}

}


// void ds18b20WriteByte(uchar dat)
// {
// 	uint i, j;

// 	for(j=0; j<8; j++)
// 	{
// 		ds_dat = 0;	     	  //Ã¿Ð´ÈëÒ»Î»Êý¾ÝÖ®Ç°ÏÈ°Ñ×ÜÏßÀ­µÍ1us
// 		i++;
// 		ds_dat = dat & 0x01;  //È»ºóÐ´ÈëÒ»¸öÊý¾Ý£¬´Ó×îµÍÎ»¿ªÊ¼
// 		i=6;
// 		while(i--); //ÑÓÊ±68us£¬³ÖÐøÊ±¼ä×îÉÙ60us
// 		ds_dat = 1;	//È»ºóÊÍ·Å×ÜÏß£¬ÖÁÉÙ1us¸ø×ÜÏß»Ö¸´Ê±¼ä²ÅÄÜ½Ó×ÅÐ´ÈëµÚ¶þ¸öÊýÖµ
// 		dat >>= 1;
// 	}
// }



// uchar Ds18b20ReadByte()
// {
// 	uchar byte, bi;
// 	uint i, j;	
// 	for(j=8; j>0; j--)
// 	{
// 		ds_dat = 0;//ÏÈ½«×ÜÏßÀ­µÍ1us
// 		i++;
// 		ds_dat = 1;//È»ºóÊÍ·Å×ÜÏß
// 		i++;
// 		i++;//ÑÓÊ±6usµÈ´ýÊý¾ÝÎÈ¶¨
// 		bi = ds_dat;	 //¶ÁÈ¡Êý¾Ý£¬´Ó×îµÍÎ»¿ªÊ¼¶ÁÈ¡
// 		/*½«byte×óÒÆÒ»Î»£¬È»ºóÓëÉÏÓÒÒÆ7Î»ºóµÄbi£¬×¢ÒâÒÆ¶¯Ö®ºóÒÆµôÄÇÎ»²¹0¡£*/
// 		byte = (byte >> 1) | (bi << 7);						  
// 		i = 4;		//¶ÁÈ¡ÍêÖ®ºóµÈ´ý48usÔÙ½Ó×Å¶ÁÈ¡ÏÂÒ»¸öÊý
// 		while(i--);
// 	}				
// 	return byte;
// }



uchar ds18b20ReadBit(void)
{
	uchar i;
	bit dat;
	ds_dat = 0;	i++;
	ds_dat = 1;
	// delayus(8);
	i++;
	i++;
	dat =ds_dat;
	i=8;while(i--);
	return dat;
}

uchar ds18b20ReadByte()
{
	uchar dat;
	uchar j;
	uchar i;
	for(i=0; i<8; i++)
	{
		j = ds18b20ReadBit();
		if (j == 1)
		{
			dat |= 0x01 << i;	
		}
		else
		{
			dat &= ~(0x01 << i);
		}
	}
	return dat;
}

void ds18b20Change(void)
{
	ds18b20Init();
	ds18b20Delayms(1);
	ds18b20WriteByte(0xcc);
	ds18b20WriteByte(0x44);
}

float ds18b20GetTemp(void)
{
	int temp;
	uchar tmh,tml;
	ds18b20Init();
	ds18b20Delayms(1);
	ds18b20WriteByte(0xcc);
	ds18b20WriteByte(0xbe);
	tml = ds18b20ReadByte();
	tmh = ds18b20ReadByte();
	temp = tmh;
	temp <<= 8;
	temp = temp | tml;

	return (float)temp * 0.0625*100+0.5;
}


