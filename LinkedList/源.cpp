#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node * nextPtr;
};

typedef struct node Node;
typedef struct node * NodePtr;
void insert(NodePtr *sPtr,int num);
void delate(NodePtr *newNode, int num);
void Print();

int main(void) {
	NodePtr startPtr = NULL;
	int choice=1;
	int num;
	Print();

	while (choice != 0)
	{
		switch(choice) {
			case 1:
				printf("Please enter a number");
				scanf_s("\n%d",&num);
				insert(&startPtr,num);
				break;
			case 2:
				printf("to do");
		}
	}
}

void insert(NodePtr * sPtr,int num) {
	NodePtr newPtr;/*指向一个新的节点*/
	NodePtr previousPtr;/*指向链表中前一个节点的指针*/
	NodePtr currentPtr;/*指向链表中当前节点的指针*/

	newPtr = (Node*)malloc(sizeof(Node));

	if (newPtr != NULL)
	{
		newPtr->num = num;
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && num > currentPtr->num)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (previousPtr ==NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			previousPtr->nextPtr = *sPtr;

		}
	}

}
void Print()
{
	printf("萱萱我爱你");
}