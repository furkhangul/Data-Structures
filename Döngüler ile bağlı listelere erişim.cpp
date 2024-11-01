/*#include<iostream>
#include<stdlib.h>
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

	node* iter;
	iter = root;
	while (iter != NULL) {
		cout << iter << "\n";
		cout << iter->x << "\n";
		iter = iter->next;

	}
	*/
	// Eğer bu şekilde yazarsak kodumuzu  beklediğimizden bir fazla değer ile karşılaşırız.
	// Çünkü bu bağlı listenin en sonunda bir pointer daha var ve bu pointierin adresini null değerine eşitlememiz
	// gerekmektedir.
#include<iostream>
#include<stdlib.h>
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
	root->next->next->next->next = NULL; // Bu değeri girdiğimizden dolayı artık eksrad CDDCDCDCDDC adındaki pointer ile karşılaşmayacağız.
	node* iter;
	iter = root;
	while (iter != NULL) {
		cout << iter << "\n";
		cout << iter->x << "\n";
		iter = iter->next;

	}
	return 0;
}
