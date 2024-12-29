#include<iostream>
#include <cstdlib>
using namespace std;

struct n {
    int x;
    n* next;
};
typedef n node;

void bastir(node* r) {
    while (r != NULL) {
        cout << "Adress: " << r << " Value: " << r->x << "\n";
        r = r->next;
    }
}

node* SiraliEkle(node* r, int x) {
    node* yeni = (node*)malloc(sizeof(node));
    yeni->x = x;
    yeni->next = NULL;

    if (r == NULL) {
        return yeni;  // Eğer liste boşsa yeni eleman başa eklenir.
    }

    if (r->x >= x) {
        yeni->next = r;
        return yeni;  // Yeni eleman en başa eklenir
    }

    node* iter = r;
    while (iter->next != NULL && iter->next->x < x) {
        iter = iter->next;
    }

    yeni->next = iter->next;
    iter->next = yeni;  // Yeni eleman uygun yere eklenir

    return r;  // Başta kalan root'ı geri döndür
}

int main() {
    node* root = NULL;

    root = SiraliEkle(root, 10);
    root = SiraliEkle(root, 15);
    root = SiraliEkle(root, 5);  // Başka bir değer ekleyelim

    bastir(root);
    return 0;
}
