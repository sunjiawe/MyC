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
#define MAXSIZE 20	/*�洢�ռ��ʼ������*/

typedef int Status;	   /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/
typedef int ElemType;	/*ElemType���͸���ʵ������������������Ϊint*/

typedef struct
{
    ElemType data[MAXSIZE];	/*���飬�洢����Ԫ��*/
    int length;	/*���Ա�ǰ����*/
}SqList;



Status InitList(SqList *L);      //��ʼ���б�
Status ListEmpty(SqList L);		 //�б��Ƿ�Ϊ��
Status ClearList(SqList *L);     //����б�

Status visit(ElemType c);       //��ӡԪ��
int ListLength(SqList L);       //�б���
Status GetElem(SqList L,int i,ElemType *e);   //���ص�i��Ԫ�ص�ֵ
int LocateElem(SqList L,ElemType e);          //����Ԫ��


Status ListInsert(SqList *L,int i,ElemType e);    //����Ԫ��
Status ListDelete(SqList *L,int i,ElemType *e);   //ɾ��Ԫ��
Status ListTraverse(SqList L);                    //�����б�

void unionL(SqList *La,SqList Lb);          //�ϲ������б�,��Lb�ĸ�������La��


#endif
