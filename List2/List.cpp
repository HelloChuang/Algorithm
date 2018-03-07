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

int main()
{
	insert(1);
	insert(2);
	printf("ordinarary\n");
	Print();
	Modify(2, 200);
	printf("new\n");
	Print();

	system("pause");
}


