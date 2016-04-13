#include "seq_stack.h"

Status
visit(SElemType c)
{
    printf("%d",c);
    return OK;
}


/*����һ����ջS*/
Status
InitStack(SqStack *S)
{
    /*S.data=(SElemType
    *)malloc(MAXSIZE*sizeof(SElemType));*/
    S->top=-1;
    return OK;
}


/*��S��Ϊ��ջ*/
Status
ClearStack(SqStack *S)
{
    S->top=-1;
    return OK;
}


/*��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE*/
Status
StackEmpty(SqStack S)
{
    if(S.top==-1)
        return TRUE;
    else
        return FALSE;
}


/*����S��Ԫ�ظ�������ջ�ĳ���*/
int StackLength(SqStack S)
{
    return S.top+1;
}


/*��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR*/
Status
GetTop(SqStack S,SElemType *e)
{
    if(S.top==-1)
        return ERROR;
    else
        *e=S.data[S.top];
    return OK;
}


/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status
Push(SqStack *S,SElemType e)
{
    if(S->top==MAXSIZE-1)/*ջ��*/
        {
            return ERROR;
        }

    S->top++;
    /*ջ��ָ������һ*/
    S->data[S->top]=e;
    /*���²���Ԫ�ظ�ֵ��ջ���ռ�*/
    return OK;
}


/*��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status
Pop(SqStack *S,SElemType *e)
{
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top];/*��Ҫɾ����ջ��Ԫ�ظ�ֵ��e*/
    S->top--;/*ջ��ָ���һ*/
    return OK;
}


/*��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ*/
Status
StackTraverse(SqStack S)
{
    int i;
    i=0;
    while(i<=S.top)
        {
            visit(S.data[i++]);
        }
    printf("\n");
    return OK;
}

