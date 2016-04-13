#include "seq_stack.h"

int main()
{
    int j;
    SqStack s;
    int e;
    if(InitStack(&s)==OK)
    {
    	for(j=1; j<=10; j++)
        	Push(&s,j);		
	}
                
    printf("ջ��Ԫ������Ϊ��");
    StackTraverse(s);
    
    Pop(&s,&e);
    printf("������ջ��Ԫ��e=%d\n",e);
    
    printf("ջ�շ�%d(1:��0:��)\n",StackEmpty(s));
    
    GetTop(s,&e);
    printf("ջ��Ԫ��e=%dջ�ĳ���Ϊ%d\n",e,StackLength(s));
    
    ClearStack(&s);
    printf("���ջ��ջ�շ�%d(1:��0:��)\n",StackEmpty(s));
    
    return 0;
}
