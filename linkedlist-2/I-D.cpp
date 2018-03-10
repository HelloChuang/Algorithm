#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE    5    //链表初始长度  
#define ERROR   0
#define OK      1

//链表结构体
struct LNode
{
	int data;
	struct LNode *next;
};

//获取链表中指定位置的数据
int GetElem_L(struct LNode *L, int i, int *e)
{
	//L为带头结点的单链表的头指针。当第i个元素存在时，其赋值给e并返回OK，否则返回ERROR
	struct LNode *p;
	p = L->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i) return ERROR;
	*e = p->data;
	return OK;
}

//向链表中指定位置插入数据
int ListInsert_L(struct LNode *L, int i, int *e)
{
	struct LNode *p, *s;
	p = L;
	int j = 0;
	while (p&&j<i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i - 1) return ERROR;

	s = (struct LNode *) malloc(sizeof(struct LNode));
	s->data = *e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//删除链表中指定位置的数据
int ListDelete_L(struct LNode *L, int i, int *e)
{
	struct LNode *p, *q;
	p = L;
	int j = 0;
	while (p->next && j<i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j>i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

//创建链表,录入n个原始数据
void CreateList_L(struct LNode *L, int n)
{
	int i;
	int v;
	struct LNode *p;
	L->next = NULL;

	//循环录入数据
	for (i = n; i>0; --i)
	{
		p = (struct LNode *) malloc(sizeof(struct LNode));
		scanf_s("%d", &v);
		p->data = v;
		p->next = L->next;  //头插法
		L->next = p;
	}
}

//输出链表中的数据
int PrintList_L(struct LNode *L, char* s) {
	struct LNode *p;
	printf("%s", s);
	p = L->next;
	if (p == NULL)
	{
		printf("链表为空\n");
		return ERROR;
	}
	while (p != NULL) {
		printf("%d   ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
int main()
{
	//定义链表
	struct LNode L;

	//初始化链表
	printf("请输入链表中初始的%d个数据：", LIST_INIT_SIZE);
	CreateList_L(&L, LIST_INIT_SIZE);
	PrintList_L(&L, "初始化的链表：");

	//定义插入/删除操作时位置和数值参数  
	int s, v;

	//插入功能演示
	printf("请输入数据插入的位置s 和数值v ：");
	scanf_s("%d%d", &s, &v);
	printf("%s", ListInsert_L(&L, s, &v) ? "插入成功.\n" : "插入失败.\n");
	PrintList_L(&L, "插入后的链表：");

	//删除功能演示
	printf("请输入数据删除的位置s ：");
	scanf_s("%d", &s);
	if (ListDelete_L(&L, s, &v))
		printf("删除成功.删除的数据是：%d\n", v);
	else
		printf("删除失败.位置有误.");
	PrintList_L(&L, "删除后的链表：");

	//查询功能演示
	printf("请输入要查询的数据位置s ：");
	scanf_s("%d", &s);
	GetElem_L(&L, s, &v);
	printf("第%d个数是：%d\n\n", s, v);

	system("pause");
	return 0;
}

