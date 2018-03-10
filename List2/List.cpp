#include <stdio.h>
#include <cstdlib>

struct node
{
	int num;
	struct node *next;
};
node * g_pHead = NULL;



void insert(int num)
{
	

		node * p = (node*)malloc(sizeof(node));
		p->num = num;
		p->next = g_pHead;
		g_pHead = p;
	

}
void Modify(int num,int newNum)
{
	node *p = g_pHead;
	while (p)
	{
		if (p->num == num)
		{
			p->num = newNum;
		}
		p = p->next;

	}
}
int  Delete(int num)
{
	node *p = g_pHead,*p1=NULL;
	while (p)
	{
		if (p->num==num)
		{
			p1->next = p->next;
			free(p);
			return 1;
		}
		p1 = p;
		p = p->next;

	}
	return  0;
	printf("\n");
}
void Print()
{
	node *p = g_pHead;
	while (p)
	{
		printf("%d ", p->num);
		p = p->next;

	}
	printf("\n");
}
int  change()
{
	node *p = g_pHead;
	p->next = p->next->next;

	return  p->num;
}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	printf("ordinarary\n");
	Print();
	Modify(2, 200);
	printf("new\n");
	Print();
	Delete(1);
	Print();

	printf("%d\n",change());
	Print();
	insert(3);
	insert(2);
	insert(1);

	Print();
	system("pause");
}


