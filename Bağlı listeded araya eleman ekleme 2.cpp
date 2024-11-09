#include<iostream>
#include<stdlib.h>
using namespace std;

struct n {
	int x;
	n* next;
};
typedef n node;

void look(node* look) {
	while (look != NULL) {
		cout << "Adress: " << look << " Value: " << look->x<<"\n";
		look = look->next;
	}
}

void Add(node* r, int x) {
	while (r->next != NULL) {
		r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}

int main() {
	node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 50;
	root->next = NULL;
	node* iter = root;
	for (int i = 0; i < 5; i++) {
		Add(iter, iter->x + 10);
		iter = iter->next;
	}

	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->x = 11;
	temp->next = iter->next;
	iter->next = temp;
	iter = iter->next;
	for (int i = 0; i < 5; i++) {
		Add(iter, iter->x + 10);
		iter = iter->next;
	}
	iter = root;
	look(root);
	return 0;
}
