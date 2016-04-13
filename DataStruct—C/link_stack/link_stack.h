#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_


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

#define MAXSIZE 20	/*存储空间初始分配量*/

typedef int Status;
typedef int SElemType;/*SElemType类型根据实际情况而定，这里假设为int*/
/*链栈结构*/

typedef struct StackNode
{
    SElemType data;
    struct StackNode*next;
}StackNode,*LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;

Status visit(SElemType c);
Status InitStack(LinkStack *S);
Status ClearStack(LinkStack *S);
Status StackEmpty(LinkStack S);
int StackLength(LinkStack S);
Status GetTop(LinkStack S,SElemType *e);
Status Push(LinkStack *S,SElemType e);
Status Pop(LinkStack *S,SElemType *e);
Status StackTraverse(LinkStack S);


#endif