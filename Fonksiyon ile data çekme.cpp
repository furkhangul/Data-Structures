#include<iostream>
#include<stdlib.h>
using namespace std;

struct n {
	int x;
	n* next;
};
typedef n node;

void bastir(node * r) {
	while (r != NULL) {
		
		cout << "Adress: " << r << " Value: " << r->x << "\n";
		r = r->next;

	}

};
int main() 
{
	node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 10;
	root->next = (node*)malloc(sizeof(node));
	root->next->x = 10;
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->x = 30;
	root->next->next->next = (node*)malloc(sizeof(node));
	root->next->next->next->x = 40;
	root->next->next->next->next = (node*)malloc(sizeof(node));
	root->next->next->next->next->x = 50;
	root->next->next->next->next->next = NULL;
	node* iter;
	iter = root;
	while (iter != NULL) 
	{
		cout << "Adress: " << iter << " Value: " << iter->x << "\n";
		iter = iter->next;
	}
	iter = root;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	for (int i = 0; i <= 5; i++) 
	{
		iter = iter->next;
		iter = (node*)malloc(sizeof(node));
		iter->x = (i + 1) * 2;
		cout << "Adress: " << iter << " Value: " << iter->x << "\n";
		iter->next = NULL;

	}
	iter = root;
	bastir(iter);
	return 0;
}
