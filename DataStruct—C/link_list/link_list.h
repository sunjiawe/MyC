#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

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

#define MAXSIZE 20		/*�洢�ռ��ʼ������*/

typedef int Status;		/*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/
typedef int ElemType;	/*ElemType���͸���ʵ������������������Ϊint*/

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node* LinkList;/*����LinkList*/



Status InitList(LinkList *L);
Status ListEmpty(LinkList L);
Status ClearList(LinkList *L);
void CreateListHead(LinkList *L,int n);
void CreateListTail(LinkList *L,int n);

Status visit(ElemType c);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType *e);
int LocateElem(LinkList L,ElemType e);

Status ListInsert(LinkList *L,int i,ElemType e);
Status ListDelete(LinkList *L,int i,ElemType *e);
Status ListTraverse(LinkList L);

#endif 	
/*!_LINK_LIST_H_*/
