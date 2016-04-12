#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_


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
typedef int QElemType;/*QElemType���͸���ʵ������������������Ϊint*/
typedef struct QNode/*���ṹ*/
{
    QElemType data;
    struct QNode*next;
}QNode,*QueuePtr;

typedef struct/*���е�����ṹ*/
{
    QueuePtr front,rear;/*��ͷ����βָ��*/
}LinkQueue;


Status visit(QElemType c);
Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);

Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q,QElemType *e);

Status EnQueue(LinkQueue *Q,QElemType e);
Status DeQueue(LinkQueue *Q,QElemType *e);
Status QueueTraverse(LinkQueue Q);


#endif