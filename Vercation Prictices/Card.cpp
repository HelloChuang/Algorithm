#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
//Card * const deak 和Card deak[]所表示的应该是一个意思
struct card
{
	const char *face;
	const char *suit;

};

typedef struct card Card;
void gotodeak(const char *face[],const char *suit[],Card * const deak);
void xipai(Card deak[]);
void print(Card deak[]);


int main(void) {
	Card deak[52];
	const char *face[] = {"ACE","2","3","4","5","6","7","8","9","10","J","Q","K"};
	const char *suit[] = {"heitao","hongtao","meihua","fangpian"};

	srand(time(NULL));
	gotodeak(face,suit,deak);
	print(deak);
	printf("\n");
	xipai(deak);
	print(deak);
	system("pause");
}
void gotodeak(const char *face[], const char *suit[], Card * const deak) {//用来给52张扑克牌排序
	for (int i = 0; i < 52; i++) {

				deak[i].face = face[i % 13];
				deak[i].suit = suit[i % 4];
				
	}
	
}
void xipai(Card deak[]) {
	Card temp;
	int j = rand() % 52;
	for (int i = 0; i < 52; i++) {
		j = rand() % 52;
		temp = deak[i]; 
		deak[i] = deak[j];
		deak[j] = temp;
	}
}

void print(Card deak[]) {
	for (int i = 0; i < 52; i++) {
		printf("%5s of %-8s%s",deak[i].face,deak[i].suit,(i+1)%4 ? " " : "\n");
	}
}