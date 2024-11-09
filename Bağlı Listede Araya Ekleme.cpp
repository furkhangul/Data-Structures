#include<iostream>
using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;

void look(node * r)
{
	while (r != NULL)
	{
		cout << "Adress: " << r << " Value: "<< r -> x << "\n";
		r = r->next;
	}
}

void Add(node* r, int x)
{
	while (r->next != NULL) {
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}

int main() {
	node* root;
	root = (node*)malloc(sizeof(node));
	root -> x = 10;
	root->next = NULL;
	node* iter;
	iter = root;
	for (int i = 0; i < 5; i++) {
		Add(iter, iter->x + 7);
		iter = iter->next;
	}

	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->x = 11;
	temp->next = NULL;
	temp->next = iter->next;
	iter->next = temp;
	for (int i = 0; i < 5; i++) {
		Add(iter, iter->x + 7);
		iter = iter->next;
	}
	iter = root;
	look(iter);
}
