#include <iostream>
#include <cstdlib>
using namespace std;

struct n {
    int data;
    n* next;
};
typedef n node;

void Bastir(node* r) {
    if (r == NULL) {
        cout << "Liste boş!" << endl;
        return;
    }

    node* iter = r;
    while (iter != NULL) {
        cout << "Adres: " << iter << " Değer: " << iter->data << endl;
        iter = iter->next;
    }
}

node* SiraliEkle(node* r, int data) {
    // Eğer liste boşsa, yeni bir düğüm oluştur ve başa ekle
    if (r == NULL) {
        r = (node*)malloc(sizeof(node));
        r->data = data;
        r->next = NULL;
        return r;
    }

    // Eğer yeni eleman en başa eklenmesi gerekiyorsa
    if (r->data > data) {
        node* yeni = (node*)malloc(sizeof(node));
        yeni->data = data;
        yeni->next = r;
        return yeni; // Yeni eleman başa geçti, bunu döndürüyoruz
    }

    // Listeyi sırayla dolaşarak uygun pozisyonu bul
    node* temp = r;
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    // Yeni düğüm oluştur ve ekle
    node* yeni = (node*)malloc(sizeof(node));
    yeni->data = data;
    yeni->next = temp->next;
    temp->next = yeni;

    return r; // Baş düğüm değişmeden döndürülüyor
}

node* sil(node* r, int data) {
    // Liste boşsa
    if (r == NULL) {
        cout << "Liste boş, silinecek eleman yok!" << endl;
        return NULL;
    }

    // Eğer silinecek eleman baştaysa
    if (r->data == data) {
        node* temp = r;
        r = r->next; // Başı güncelle
        free(temp);  // Eski baş düğümü sil
        return r;
    }

    // Listeyi sırayla dolaşarak elemanı bul ve sil
    node* temp = r;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    // Eleman bulunduysa
    if (temp->next != NULL) {
        node* silinecek = temp->next;
        temp->next = temp->next->next;
        free(silinecek); // Bulunan düğümü sil
    } else {
        cout << "Silinecek eleman bulunamadı!" << endl;
    }

    return r;
}

int main() {
    node* root = NULL;

    // Sıralı ekleme
    root = SiraliEkle(root, 20);
    root = SiraliEkle(root, 10);
    root = SiraliEkle(root, 30);
    root = SiraliEkle(root, 15);

    // Listeyi yazdır
    cout << "Liste elemanları:" << endl;
    Bastir(root);

    // Eleman silme
    cout << "\nEleman siliniyor: 20" << endl;
    root = sil(root, 20);
    Bastir(root);

    cout << "\nEleman siliniyor: 10" << endl;
    root = sil(root, 10);
    Bastir(root);

    cout << "\nEleman siliniyor: 50 (olmayan eleman)" << endl;
    root = sil(root, 50);
    Bastir(root);

    return 0;
}
