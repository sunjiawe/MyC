#include "link_queue.h"

Status
visit(QElemType c)
{
    printf("%d",c);
    return OK;
}


/*构造一个空队列Q*/
Status
InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        exit(OVERFLOW);
    Q->front->next=NULL;
    return OK;
}


/*销毁队列Q*/
Status
DestroyQueue(LinkQueue *Q)
{
    while(Q->front)
        {
            Q->rear=Q->front->next;
            free(Q->front);
            Q->front=Q->rear;
        }
    return OK;
}


/*将Q清为空队列*/
Status
ClearQueue(LinkQueue *Q)
{
    QueuePtr p,q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;
    while(p)
        {
            q=p;
            p=p->next;
            free(q);
        }
    return OK;
}


/*若Q为空队列,则返回TRUE,否则返回FALSE*/
Status
QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}


/*求队列的长度*/
int QueueLength(LinkQueue Q)
{
    int i=0;
    QueuePtr p;
    p=Q.front;
    while(Q.rear!=p)
        {
            i++;
            p=p->next;
        }
    return i;
}


/*若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR*/
Status
GetHead(LinkQueue Q,QElemType *e)
{
    QueuePtr p;
    if(Q.front==Q.rear)
        return ERROR;
    p=Q.front->next;
    *e=p->data;
    return OK;
}


/*插入元素e为Q的新的队尾元素*/
Status
EnQueue(LinkQueue *Q,QElemType e)
{
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s)/*存储分配失败*/
        exit(OVERFLOW);
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;/*把拥有元素e的新结点s赋值给原队尾结点的后继，见图中①*/
    Q->rear=s;/*把当前的s设置为队尾结点，rear指向s，见图中②*/
    return OK;
}


/*若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR*/
Status
DeQueue(LinkQueue *Q,QElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;/*将欲删除的队头结点暂存给p，见图中①*/
    *e=p->data;/*将欲删除的队头结点的值赋值给e*/
    Q->front->next=p->next;/*将原队头结点的后继p->next赋值给头结点后继，见图中②*/
    if(Q->rear==p)/*若队头就是队尾，则删除后将rear指向头结点，见图中③*/
        Q->rear=Q->front;
    free(p);
    return OK;
}

/*从队头到队尾依次对队列Q中每个元素输出*/
Status
QueueTraverse(LinkQueue Q)
{
    QueuePtr p;
    p=Q.front->next;
    while(p)
        {
            visit(p->data);
            p=p->next;
        }
    printf("\n");
    return OK;
}
