#include<iostream>
#include<stdlib.h>

using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;


int main()
{
	node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 10;
	root->next = (node*)malloc(sizeof(node));
	root->next->x = 20;
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->x = 30;

	node* iter;
	iter = root;
	cout << iter << "\n";
	cout << iter->x << "\n";
	iter = iter->next;
	cout << iter << "\n";
	cout << iter->x << "\n";
	iter = iter->next;
	cout << iter << "\n";
	cout << iter->x << "\n";
	return 0;
}
