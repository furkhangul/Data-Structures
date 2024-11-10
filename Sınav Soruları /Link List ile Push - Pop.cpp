#include<iostream>
using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;


node* push(node* root,int x) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->x = x;
		root->next = NULL;
		return root;
	}
	node* iter = root;
	while (iter->next != NULL) {
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->x = x;
	temp->next =NULL;
	iter->next = temp;
	return root;
}

int pop(node* root) {
	if (root == NULL) {
		cout << "Stack Boş" << "\n";
		return  -1;
	}
	node* iter = root;
	while (iter->next->next != NULL) {
		iter = iter->next;
	}
	node* temp = iter->next;
	int gecicideger = temp->x;
	free(temp);
	iter->next = NULL;
	return gecicideger;

}


void oku(node* root) {
	node* iter = root;
	while (iter != NULL) {
		cout << "Adress: " << iter << " Value: " << iter->x << "\n";
		iter = iter->next;
	}
}

int main() {
	node* root = NULL;
	root = push(root, 10);
	root = push(root, 20);
	root = push(root, 30);
	root = push(root, 15);
	oku(root);
	pop(root);
	pop(root);
	oku(root);


	return 0;
}
