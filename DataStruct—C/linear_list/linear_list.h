#ifndef _LINEAR_LIST_H_
#define _LINEAR_LIST_H_

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

typedef int Status;	   /*Status是函数的类型,其值是函数结果状态代码，如OK等*/
typedef int ElemType;	/*ElemType类型根据实际情况而定，这里假设为int*/

typedef struct
{
    ElemType data[MAXSIZE];	/*数组，存储数据元素*/
    int length;	/*线性表当前长度*/
}SqList;



Status InitList(SqList *L);      //初始化列表
Status ListEmpty(SqList L);		 //列表是否为空
Status ClearList(SqList *L);     //清空列表

Status visit(ElemType c);       //打印元素
int ListLength(SqList L);       //列表长度
Status GetElem(SqList L,int i,ElemType *e);   //返回第i个元素的值
int LocateElem(SqList L,ElemType e);          //查找元素


Status ListInsert(SqList *L,int i,ElemType e);    //插入元素
Status ListDelete(SqList *L,int i,ElemType *e);   //删除元素
Status ListTraverse(SqList L);                    //遍历列表

void unionL(SqList *La,SqList Lb);          //合并两个列表,把Lb的副本加入La中


#endif
