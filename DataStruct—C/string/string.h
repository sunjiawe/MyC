#ifndef _STRING_H_
#define _STRING_H_

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40	/*�洢�ռ��ʼ������*/
typedef int Status;/*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/
typedef int ElemType;/*ElemType���͸���ʵ������������������Ϊint*/
typedef char String[MAXSIZE+1];/*0�ŵ�Ԫ��Ŵ��ĳ���*/



Status StrAssign(String T,char *chars);
Status StrCopy(String T,String S);
Status StrEmpty(String S);
Status ClearString(String S);

int StrCompare(String S,String T);
int StrLength(String S);

Status Concat(String T,String S1,String S2);
Status SubString(String Sub,String S,int pos,int len);
int Index(String S,String T,int pos);
int Index2(String S,String T,int pos);
Status StrInsert(String S,int pos,String T);
Status StrDelete(String S,int pos,int len);
Status Replace(String S,String T,String V);

void StrPrint(String T);

#endif