#include <stdlib.h>
#include <stdio.h>

typedef int Rank;  //秩
#define CAPACITY 50  //默认初始容量


typedef struct
{
	int elem[CAPACITY];
	Rank size;
}Vector;

int size(const Vector* a)
{
	return a->size;
}

int get(const Vector* a,int r)
{
	return a->elem[r];
}

void put(Vector* a,int r,int e)
{
	a->elem[r] = e;
}

void insert(Vector* a,int r,int e)
{
	int i;
	for(i=a->size; i>r;i-- )
	{
		a->elem[i] = a->elem[i-1];
	}
	a->elem[r] = e;
	a->size = a->size + 1;
}

int rm(Vector* a,int r)
{
	int ret;
	int i;
	ret = a->elem[r];
	for(i=r; i<a->size; i++)
	{
		a->elem[i] = a->elem[i+1];
	}
	a->size = a->size - 1;
	return ret;
}

Vector* CreatVector()
{
	Vector* p;
	p = (Vector*)malloc(sizeof(Vector));
	p->size = 0;
	return p;
}

int find(Vector* a,int e)
{
	int ret = -1;
	int i = 0;
	while(i != a->size+1)
	{
		if(a->elem[i] == e)
		{
			ret = i;
			break;
		}
		i++;
	}

	return ret;
}


int main()
{
	Vector* p;
	p = CreatVector();
	insert(p,0,9);
	insert(p,0,4);
	insert(p,1,5);
	put(p,1,2);
	printf("%d\n",get(p,0));
	printf("%d\n",get(p,1));
	printf("%d\n",get(p,2));
	printf("%d\n",find(p,5));
	
	
	return 0;
}
