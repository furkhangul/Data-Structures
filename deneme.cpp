#include<iostream>
#include <cstdlib>
using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;

void look(node * r ) {
	while (r != NULL) {
		cout << "Adress: " << r << " Value: " << r->x << "\n";
		r = r -> next;
	}
};

int main() {

	node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 10;
	root->next = NULL;
	node* iter;
	iter = root;
	cout << "Uzunluk gir:";
	int uzunluk;
	cin >> uzunluk;
	for (int i = 0; i < uzunluk; i++) {
		iter->next = (node*)malloc(sizeof(node));
		iter = iter->next;
		iter-> x = (i +1)*10 ;
		iter->next = NULL;
	}
	iter = root;
	look(iter);
	return 0;
}
