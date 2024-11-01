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

int main() {
	node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 50;
	root->next = NULL;
	node* iter = root;
	for (int i = 0; i < 10; i++) {
		iter->next = (node*)malloc(sizeof(node));
		iter = iter->next;
		iter->x = (i + 3) * 12;
		iter->next = NULL;
	}
	look(root);
	return 0;
}
