#include <iostream>
using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;

// Listenin elemanlarını ve adreslerini ekrana yazdıran fonksiyon
void look(node* r) {
	while (r != NULL) {
		cout << "Adres: " << r << " Değer: " << r->x << "\n";
		r = r->next;
	}
}

node* siraliekle(node* root, int x) {
	node* temp;
	temp = root;
	temp = (node*)malloc(sizeof(node));
	temp->x = x;
	temp->next = NULL;
	if (root == NULL || root->x > x) 
	{
		temp->next = root;
		root = temp;
	}

	else 
	{
		node* iter;
		iter = root;
		while (iter->next == NULL && iter->next->x < x) {
			iter = iter->next;
		}
		temp->next = iter->next;
		iter->next = temp;

	}




	return root;
}

int main() {
	node* root = NULL;
	root = siraliekle(root, 15);
	root = siraliekle(root, 10);
	root = siraliekle(root, 20);
	root = siraliekle(root, 5);

	look(root);
	return 0;
}
