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
                
    printf("Õ»ÖÐÔªËØÒÀ´ÎÎª£º");
    StackTraverse(s);
    
    Pop(&s,&e);
    printf("µ¯³öµÄÕ»¶¥ÔªËØe=%d\n",e);
    
    printf("Õ»¿Õ·ñ£º%d(1:¿Õ0:·ñ)\n",StackEmpty(s));
    
    GetTop(s,&e);
    printf("Õ»¶¥ÔªËØe=%dÕ»µÄ³¤¶ÈÎª%d\n",e,StackLength(s));
    
    ClearStack(&s);
    printf("Çå¿ÕÕ»ºó£¬Õ»¿Õ·ñ£º%d(1:¿Õ0:·ñ)\n",StackEmpty(s));
    
    return 0;
}
