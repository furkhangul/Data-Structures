#include<iostream>

using namespace std;

struct n {
	int data;
	n* next;
};
typedef n node;
void Listele(node* r) {
	while (r != NULL) {
		cout << "Adress:" << r << " Value: " << r->data << "\n";
		r = r->next;
	}
}

node* SiraliListele(node* r, int data) {
	if (r == NULL) {
		r = (node*)malloc(sizeof(node));
		r->data = data;
		r->next = NULL;
		return r;
	}
	if (r->data > data) {
		node* yeni = (node*)malloc(sizeof(node));
		yeni->data = data;
		yeni->next = r;
		return yeni;
	}
	node* temp = r;
	while (temp->next != NULL && temp->next->data < data) {
		temp = temp->next;
	}
	node* yeni = (node*)malloc(sizeof(node));
	yeni->data = data;
	yeni->next = temp->next;
	temp->next = yeni;
	return r;
}

node* Sil(node* r, int data) {
	if (r == NULL) {
		cout << "Liste boş ! ";
		return NULL;
	}
	node* temp = r;
	while (temp->next != NULL && temp->next->data != data) {
		temp = temp->next;
	}
	if (temp->next != NULL) {
		node* Sil = temp->next;
		temp->next = temp->next->next;
		free(Sil);
		return r;
	}
}
int main() {
	node* root = NULL;
	root = SiraliListele(root, 1);
	root = SiraliListele(root, 15);
	root = SiraliListele(root, 5);
	Listele(root);
	root = Sil(root, 5);
	Listele(root);
}
