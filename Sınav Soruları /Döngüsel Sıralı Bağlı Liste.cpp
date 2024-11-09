#include <iostream>
using namespace std;

struct n {
    int x;
    n* next;
};

typedef n node;

// Listenin elemanlarını ve adreslerini ekrana yazdıran fonksiyon
void look(node* r) {
    if (r == NULL) return;  // Liste boşsa işlem yapılmaz
    
    node* start = r;  // Baş düğümü kaydediyoruz
    do {
        cout << "Address: " << r << " Value: " << r->x << "\n";
        r = r->next;
    } while (r != start);  // Baş düğüme dönene kadar devam et
}

// Sıralı ekleme yapan fonksiyon
node* siraliekle(node* r, int x) {
    // Yeni düğüm oluşturuluyor ve değeri atanıyor
    node* temp = (node*)malloc(sizeof(node));
    temp->x = x;

    // Eğer liste boşsa
    if (r == NULL) {
        temp->next = temp;  // Kendisine işaret eder (dairesel yapı)
        return temp;
    }
    
    node* iter = r;
    
    // Eğer ilk düğümden küçük bir değer ekleniyorsa, başa ekle
    if (x <= r->x) {
        temp->next = r;
        node* last = r;
        // Son düğümü bul
        while (last->next != r) {
            last = last->next;
        }
        last->next = temp;  // Son düğümün next işaretçisi yeni düğüme işaret etsin
        return temp;  // Yeni düğüm başa eklendiği için onu döndürüyoruz
    }

    // Doğru sıralama noktasını bulmak için listeyi gez
    while (iter->next != r && iter->next->x < x) {
        iter = iter->next;
    }

    // Yeni düğümü doğru sıraya ekle
    temp->next = iter->next;
    iter->next = temp;

    return r;  // Listenin başı değişmemişse, baş düğümünü döndür
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
