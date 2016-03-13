#ifndef _LCD_H_
#define _LCD_H_

#include <reg52.h>

//注意这里的条件编译，能防止出错
#ifndef uchar	
#define uchar unsigned char 
#endif

#ifndef uint
#define uint unsigned int
#endif 

//接口定义
sbit LCD_RS = P2^6;        	//寄存器选择；高电平数据，低电平命令 
sbit LCD_RW = P2^5;		   	//读写选择；高电平读，低电平写
sbit LCD_E = P2^7;			//输出使能；高电平使能
#define dataPin P0			//数据口  8条


//函数定义

/****************************
功能：初始化LCD屏
参数：无
返回：无
****************************/
void lcdInit(void);

/****************************
功能：写数据
参数：要写入数据的ASCII码
返回：无
****************************/
void lcdWriteDat(int dat);	

/****************************
功能：写命令
参数：命令  
返回：无
****************************/
void lcdWriteCmd(int cmd);

/****************************
功能：延时
参数：毫秒数
返回：无
****************************/
void lcdDelay(int xms);

#endif