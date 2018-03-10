#include<stdio.h>
#include <cstdlib>

int Compare(const void * num1,const void *num2)
{
	unsigned int *p1, *p2;
	p1 = (unsigned int*)num1;
	p2 = (unsigned int*)num2;
	return *p1 - *p2;
}

const int NUM = 5;
int main()
{
	unsigned int a[NUM] = {50,20,60,40,80};
	for (int i = 0; i<NUM; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	qsort(a, NUM, sizeof(unsigned int), Compare);
	for (int i = 0; i<NUM; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}