//Bağlı Liste Temel 
#include<iostream>
using namespace std;
struct n {
	int x;
	n* next;
};
typedef n node;
int main() {
	node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 10;
	root->next;
	root->next = (node*)malloc(sizeof(node));
	root->next->x = 20;
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->x = 30;
	root->next->next->next = NULL;
	node* iter;
	iter = root;
	while (iter != NULL) {
		cout << "Adress: " << iter << " Value: " << iter->x << "\n";
		iter = iter->next;
	}
	return 0;
}
