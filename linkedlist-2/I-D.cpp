#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE    5    //�����ʼ����  
#define ERROR   0
#define OK      1

//����ṹ��
struct LNode
{
	int data;
	struct LNode *next;
};

//��ȡ������ָ��λ�õ�����
int GetElem_L(struct LNode *L, int i, int *e)
{
	//LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ���丳ֵ��e������OK�����򷵻�ERROR
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

//��������ָ��λ�ò�������
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

//ɾ��������ָ��λ�õ�����
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

//��������,¼��n��ԭʼ����
void CreateList_L(struct LNode *L, int n)
{
	int i;
	int v;
	struct LNode *p;
	L->next = NULL;

	//ѭ��¼������
	for (i = n; i>0; --i)
	{
		p = (struct LNode *) malloc(sizeof(struct LNode));
		scanf_s("%d", &v);
		p->data = v;
		p->next = L->next;  //ͷ�巨
		L->next = p;
	}
}

//��������е�����
int PrintList_L(struct LNode *L, char* s) {
	struct LNode *p;
	printf("%s", s);
	p = L->next;
	if (p == NULL)
	{
		printf("����Ϊ��\n");
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
	//��������
	struct LNode L;

	//��ʼ������
	printf("�����������г�ʼ��%d�����ݣ�", LIST_INIT_SIZE);
	CreateList_L(&L, LIST_INIT_SIZE);
	PrintList_L(&L, "��ʼ��������");

	//�������/ɾ������ʱλ�ú���ֵ����  
	int s, v;

	//���빦����ʾ
	printf("���������ݲ����λ��s ����ֵv ��");
	scanf_s("%d%d", &s, &v);
	printf("%s", ListInsert_L(&L, s, &v) ? "����ɹ�.\n" : "����ʧ��.\n");
	PrintList_L(&L, "����������");

	//ɾ��������ʾ
	printf("����������ɾ����λ��s ��");
	scanf_s("%d", &s);
	if (ListDelete_L(&L, s, &v))
		printf("ɾ���ɹ�.ɾ���������ǣ�%d\n", v);
	else
		printf("ɾ��ʧ��.λ������.");
	PrintList_L(&L, "ɾ���������");

	//��ѯ������ʾ
	printf("������Ҫ��ѯ������λ��s ��");
	scanf_s("%d", &s);
	GetElem_L(&L, s, &v);
	printf("��%d�����ǣ�%d\n\n", s, v);

	system("pause");
	return 0;
}

