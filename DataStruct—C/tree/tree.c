#include <stdlib.h>


typedef struct {
	node *root = null; 
	int height;
}tree;

typedef struct a 
{
	int data;
	struct a* parent;
	struct a* lChild;
	struct a* rChild;
}node;



node* creatTree(void)
{
	node* p =malloc(sizeof(node));
	p->data = 0;
	p->parent = NULL;
	p->lChild = NULL;
	p->rChild = NULL;
	return p;
}

void insertAsLC(int e,node* p)
{
	if(p->lChild == 0)
	{
		node* a = malloc(sizeof(node));
		p->lChild = a;
		a->data = e;
		a->parent = p;
	}
}

void insertAsRC(int e,node* p)
{
	if(p->rChild == 0)
	{
		node* a = malloc(sizeof(node));
		p->rChild = a;
		a->data = e;
		a->parent = p;	
	}	
	
}



//根节点
root();

//父节点
parent();

//长子
firstChild();

//兄弟
nextSibling();

//将e作为第i个孩子插入
insert();

//删除第i的孩子（及其后代）
remove();

//遍历
traverse();