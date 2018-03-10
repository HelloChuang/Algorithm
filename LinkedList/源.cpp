#include<stdio.h>
#include<stdlib.h>

struct node
{
	int id;
	struct node * nextPtr;
};

typedef struct node Node;
typedef struct node * NodePtr;
void insert(int num);
void delate(NodePtr *newNode, int num);
void Print();
NodePtr head = NULL;
int main(void) {
	
	int choice;
	int num;
	Print();
	scanf_s("\n%d",&choice);
	while (choice != 0)
	{
		switch(choice) {
			case 1:
				printf("Please enter a number");
				scanf_s("\n%d",&num);
				insert(num);
				Print();
				break;
			case 2:
				printf("to do");
		}
	}
	Print();
}

void insert(int num) {
	/*ָ��һ���µĽڵ�*/
	node  *follow;/*ָ��������ǰһ���ڵ��ָ��*/
	node  *p;/*ָ�������е�ǰ�ڵ��ָ��*/

	NodePtr newPtr = (Node*)malloc(sizeof(Node));

	if (newPtr != NULL)
	{
		newPtr->id = num;
		newPtr->nextPtr = NULL;

		follow = NULL;
		p = head;

		while (p != NULL && num > p->id)
		{
			follow = p;
			p = p->nextPtr;
		}
		if (follow ==NULL)
		{
			newPtr->nextPtr = head;
			head = newPtr;
		}
		else
		{
			follow->nextPtr = newPtr;
			newPtr->nextPtr = p;

		}
	}

}
void Print()
{
	node *p = head;
	while (p)
	{
		printf("%d ",p->id);
		p = p->nextPtr;
	}
}