#ifndef _LIST_H_
#define _LIST_H_

#define MAX_SIZE 100
typedef struct 
{
	int element[MAX_SIZE];
	int size;
}List;
#endif


List* CreateList()
{
	List* p = (List*)malloc(sizeof(List));
	p->size = 0;
	return p;
}


void ChangeMember(List *list,int e,int index)
{
	List->element[index] = e;
	(list->size)++;
}


int Size(List *list)
{
	return list->size;
}


int FindKth(List *list,int index);
{
	return list->element[index];		
}


int Serach(List *list,int e)
{
	int i = 0;
	while(list->element[i] != e && i < list->size)
	{
		i++;
	}
	if (i>list->size)
	{
		i = -1;
	}
	return i;
}


void insert(List *list,int e,int index);
{
	int i;
	for(i=list->size; i>index; i--)
	{
		list->element[i+1] = list->element[i];
	}
	list->element[index] = e;
	(list->size)++;
}


int Delete(List *list,int index)
{
	int i;
	int temp;
	temp = list->element[i] 
	for( i=index; i<list->size; i++)
	{
		list->element[i-1] = list->element[i]
	}
	(list->size)--;

	return temp;
}

