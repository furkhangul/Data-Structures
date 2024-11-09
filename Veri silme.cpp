#include<iostream>
using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;

void look(node* r) {
	while (r != NULL) {
		cout << "Adress: " << r << " Value: " << r->x << "\n";
		r = r->next;
	}
}

node* SirayaEkle(n* root, int x) {
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->x = x;
	temp->next = NULL;
	if (root == NULL || root->x > x) 
	{
		temp->next = root;
		root = temp;
	}
	else {
		node* iter;
		iter = root;
		while (iter->next != NULL && iter->next->x < x) {
			iter = iter->next;
		}
		temp->next = iter->next;
		iter->next = temp;
	}
	return root;
}

node* Sil(node* root, int x) {
	if (root == NULL) {
		return NULL;
	}

	else if (root->x == x) {
		node* r = root;
		root = root->next;
		free(r);
		return root;
	}
	else {
		node* iter = root;
		node* temp;
		while (iter->next != NULL && iter->next->x != x) {
			iter = iter->next;
		}
		temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
	}


	return root;
}

int main() 
{
	node* root;
	root = NULL;
	root = SirayaEkle(root, 15);
	root = SirayaEkle(root, 20);
	root = SirayaEkle(root, 10);
	root = SirayaEkle(root, 50);
	root = Sil(root, 20);
	look(root);
	return 0;
}
