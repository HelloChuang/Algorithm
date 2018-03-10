#include <stdio.h>
#include<stdlib.h>
struct node
{
	int id;
	struct node *next;
};
typedef struct node * NodePtr;
NodePtr head = NULL;

void Insert(int num)
{
	node *p, *f,*newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->id = num;
	newNode->next = NULL;
	f = NULL;
	p = head;
	while (p!=NULL&&num<p->id)
	{
		f = p;
		p = p->next;
	}
	if (f==NULL)//如果此次插入的是第一个元素
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		newNode->next = p;
		f->next = newNode;
	}
}
void Print()
{
	struct node *p = head;//******
	while (p)
	{
		printf("%d ",p->id);
		p = p->next;
	}
}
int main()

{
	int num, n;
	printf("enter the length of list : ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("enter the number : ");
		scanf_s("%d", &num);
		Insert(num);
	}
	Print();
	return 0;
}