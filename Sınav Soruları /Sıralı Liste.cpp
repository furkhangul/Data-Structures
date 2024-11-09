#include<iostream>
using namespace std;
struct n {
	int x;
	n* next;
};
typedef n node;
void Add(node* root, int x) {
	node* iter = root;
	while (iter != NULL) {
		iter = iter->next;
	}
	iter = (node*)malloc(sizeof(node));
	iter->x = x;
	iter->next = NULL;
}
void Look(node* r) {
	while (r != NULL) {
		cout << "Adress: " << r << " Value: " << r->x << "\n";
		r = r->next;
	}
}
int main() {
	node* root = (node*)malloc(sizeof(node));
	root->x = 5;
	root->next = NULL;
	node* iter;
	iter = root;
	for (int i = 0; i < 5; i++) {
		Add(iter, iter->x + 5);
		iter = iter->next;
	}
	Look(root);
	return 0;
}
