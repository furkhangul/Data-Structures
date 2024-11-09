#include<iostream>
using namespace std;

struct n {
    int x;
    n* next;
};

typedef n node;

// Listeyi ekrana yazdırma fonksiyonu
void look(node* r)
{
    node* start = r; // İlk düğümü kaydet
    do {
        cout << "Adress: " << r << " Value: " << r->x << "\n";
        r = r->next;
    } while (r != start); // Başa dönene kadar devam et
}

// Düğüm ekleme fonksiyonu
void Add(node* r, int x)
{
    node* start = r; // İlk düğümü kaydet
    while (r->next != start) { // Son düğümü bulana kadar ilerle
        r = r->next;
    }
    r->next = (node*)malloc(sizeof(node)); // Yeni düğüm oluştur
    r->next->x = x;
    r->next->next = start; // Yeni düğümün next işaretçisi ilk düğüme işaret etsin
}

int main() {
    node* root = (node*)malloc(sizeof(node));
    root->x = 10;
    root->next = root; // Kendisini işaret ediyor (dairesel bağlantı)

    node* iter = root;
    for (int i = 0; i < 5; i++) {
        Add(iter, iter->x + 7);
        iter = iter->next;
    }

    // Yeni bir düğüm ekleyip dairesel yapıyı koruma
    node* temp = (node*)malloc(sizeof(node));
    temp->x = 11;
    temp->next = iter->next;
    iter->next = temp;

    // Yeniden birkaç düğüm daha ekle ve listeyi güncelle
    for (int i = 0; i < 5; i++) {
        Add(iter, iter->x + 7);
        iter = iter->next;
    }

    // Listeyi yazdır
    iter = root;
    look(iter);

    return 0;
}
