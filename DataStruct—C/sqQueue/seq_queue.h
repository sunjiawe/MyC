#ifndef _SEQ_QUEUE_H_
#define _SEQ_QUEUE_H_


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
/*ѭ�����е�˳��洢�ṹ*/
typedef struct
{
    QElemType data[MAXSIZE];
    int front;/*ͷָ��*/
    int rear;/*βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/
}SqQueue;


Status InitQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
Status QueueEmpty(SqQueue Q);
Status visit(QElemType c);

int QueueLength(SqQueue Q);
Status GetHead(SqQueue Q,QElemType *e);


Status EnQueue(SqQueue *Q,QElemType e);
Status DeQueue(SqQueue *Q,QElemType *e);
Status QueueTraverse(SqQueue Q);


#endif