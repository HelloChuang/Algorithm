#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
struct node
{
	int val;
	struct node *next;
};
node head ;

	vector<int> printListFromTailToHead(struct node *head) {
		vector<int> value;
		if (head!=NULL)
		{
			value.insert(value.begin(), head->val);
			while (head->next!=NULL)
			{
				value.insert(value.begin(), head->next->val);
				head = head->next;

			}
		}
		return value;
	}
	void CreatList(node * head,int n) {
		head->next = NULL;

		for (int i = 0; i < n; i++) {
			node *p = (node*)malloc(sizeof(node));
			p->val = i;
			p->next=head->next;
			head->next = p;
		}
	}
	void PrintList(node * head) {
		node *p = head->next;
		while (p)
		{
			printf("%d ",p->val);
			p = p->next;

		}
		printf("\n");
	}
	void PrintVector(vector<int>vec) {
		copy(vec.cbegin(), vec.cend()-1, ostream_iterator<int>(cout, " "));
	}

int main() {
CreatList(&head,5);
PrintList(&head);
PrintVector(printListFromTailToHead(&head));
}
