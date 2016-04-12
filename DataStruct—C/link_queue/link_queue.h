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

#define MAXSIZE 20	/*存储空间初始分配量*/
typedef int Status;
typedef int QElemType;/*QElemType类型根据实际情况而定，这里假设为int*/
typedef struct QNode/*结点结构*/
{
    QElemType data;
    struct QNode*next;
}QNode,*QueuePtr;

typedef struct/*队列的链表结构*/
{
    QueuePtr front,rear;/*队头、队尾指针*/
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