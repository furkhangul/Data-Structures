#include <iostream>
#include <stdlib.h>
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
	root->next = (node*)malloc(sizeof(node));
	root->next->x = 20;
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->x = 30;
	root->next->next->next = (node*)malloc(sizeof(node));
	root->next->next->next->x = 40;
	root->next->next->next->next = NULL;

	node* iter = root;

	//while döngüsübü direkt null değerine atayamayız daha doğrusu atayabiliriz fakat daha sonra iş işten geçer
	// ve null ifadesinden sonra geriye dönüş sağlayamayız.
	//Bunun için null değerinden bir önceki iteri çekmemiz gerekemektedir.
	while (iter != NULL) {
		cout << "Address: " << iter << ", Value: " << iter->x << "\n";
		iter = iter->next;
	}

	// iter'i son düğüme getir
	iter = root;
	while (iter->next != NULL) {
		iter = iter->next;
	}

	// for döngüsü ile yeni düğümler ekle
	for (int i = 1; i <= 5; i++) {
		iter->next = (node*)malloc(sizeof(node));
		iter = iter->next;
		iter->x = (i + 1) * 2; // x değerini i + 1'in karesi olarak değiştirildi
		iter->next = NULL;
		cout << "Address: " << iter << ", Value: " << iter->x << "\n";
	}

	return 0;
}
