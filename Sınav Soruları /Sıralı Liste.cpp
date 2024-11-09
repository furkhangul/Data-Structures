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

// Sıralı ekleme yapan fonksiyon
node* siraliekle(node* r, int x) {
	// Yeni düğüm oluşturuluyor ve değeri atanıyor
	node* temp = (node*)malloc(sizeof(node));
	temp->x = x;
	temp->next = NULL;

	// Eğer liste boşsa veya ilk düğümden küçük bir değer ekleniyorsa
	if (r == NULL || r->x >= x) {
		temp->next = r;
		r = temp;
	}
	else {
		// Listeyi dolaşıp doğru ekleme noktasını bulmak
		node* iter = r;
		while (iter->next != NULL && iter->next->x < x) {
			iter = iter->next;
		}
		// Yeni düğümü doğru sıraya eklemek
		temp->next = iter->next;
		iter->next = temp;
	}
	return r;  // Fonksiyonun her durumda bir değer döndürmesi sağlanıyor
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
