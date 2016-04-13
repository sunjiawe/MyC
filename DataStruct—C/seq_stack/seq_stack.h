#ifndef _SEQ_STACK_H_
#define _SEQ_STACK_H_

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

#define MAXSIZE 20	/*�洢�ռ��ʼ������*/

typedef int Status;
typedef int SElemType;/*SElemType���͸���ʵ������������������Ϊint*//*˳��ջ�ṹ*/

typedef struct
{
    SElemType data[MAXSIZE];
    int top;/*����ջ��ָ��*/
}SqStack;


Status visit(SElemType c);
Status InitStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S,SElemType *e);
Status Push(SqStack *S,SElemType e);
Status Pop(SqStack *S,SElemType *e);
Status StackTraverse(SqStack S);



#endif