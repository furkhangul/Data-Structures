#include<iostream>
using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;
node* Push(node* root, int x) {
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
	temp->next = NULL;
	iter->next = temp;
	return root;
}


int Pop(node* root) {
	if (root == NULL) {
		cout << "Silinecek veri yok !" << "\n";
		return -1;
	}
	node* iter = root;
	while (iter->next->next != NULL) {
		iter = iter->next;
	}
	node* temp = iter->next;
	int deger = temp->x;
	free(temp);
	iter->next = NULL;
	return deger;

}
void Oku(node* r) {
	while (r != NULL) {
		cout << "Adress: " << r << " Value: " << r->x << "\n";
		r = r->next;
	}
}

int main() {
	node* root = NULL;
	root = Push(root, 10);
	root = Push(root, 20);
	root = Push(root, 30);
	Oku(root);
	Pop(root);
	Oku(root);
	return 0;
}
