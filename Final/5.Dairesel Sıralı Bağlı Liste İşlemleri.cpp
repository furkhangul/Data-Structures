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
    do {
        cout << "Adres: " << iter << " Değer: " << iter->data << endl;
        iter = iter->next;
    } while (iter != r);
}

node* SiraliEkle(node* r, int data) {
    node* yeni = (node*)malloc(sizeof(node));
    yeni->data = data;

    // Eğer liste boşsa
    if (r == NULL) {
        yeni->next = yeni; // Kendine işaret eder
        return yeni;
    }

    // Eğer yeni eleman en başa eklenmesi gerekiyorsa
    if (r->data > data) {
        node* iter = r;
        while (iter->next != r) { // Son düğümü bul
            iter = iter->next;
        }
        yeni->next = r; // Yeni düğüm başa bağlanır
        iter->next = yeni; // Son düğüm yeni düğüme işaret eder
        return yeni; // Yeni eleman başa geçti
    }

    // Listeyi sırayla dolaşarak uygun pozisyonu bul
    node* temp = r;
    while (temp->next != r && temp->next->data < data) {
        temp = temp->next;
    }

    // Yeni düğüm oluştur ve ekle
    yeni->next = temp->next;
    temp->next = yeni;

    return r; // Baş düğüm değişmeden döndürülüyor
}

node* sil(node* r, int data) {
    if (r == NULL) {
        cout << "Liste boş, silinecek eleman yok!" << endl;
        return NULL;
    }

    // Eğer tek düğümlü bir listeyse ve eleman baştaysa
    if (r->next == r && r->data == data) {
        free(r);
        return NULL;
    }

    // Eğer silinecek eleman baştaysa
    if (r->data == data) {
        node* iter = r;
        while (iter->next != r) { // Son düğümü bul
            iter = iter->next;
        }
        node* temp = r;
        iter->next = r->next; // Son düğüm yeni başa bağlanır
        r = r->next; // Baş düğüm güncellenir
        free(temp);
        return r;
    }

    // Listeyi sırayla dolaşarak elemanı bul ve sil
    node* temp = r;
    while (temp->next != r && temp->next->data != data) {
        temp = temp->next;
    }

    // Eleman bulunduysa
    if (temp->next->data == data) {
        node* silinecek = temp->next;
        temp->next = temp->next->next; // Elemanı atla
        free(silinecek);
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
