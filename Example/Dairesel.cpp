#include<iostream>

using namespace std;

struct n {
    int data;
    n* next;
};
typedef n node;

void Listele(node* r) {
    if (r == NULL) {
        cout << "Liste bos!\n";
        return;
    }
    node* temp = r;
    do {
        cout << "Adress:" << temp << " Value: " << temp->data << "\n";
        temp = temp->next;
    } while (temp != r);
}

node* SiraliListele(node* r, int data) {
    node* yeni = (node*)malloc(sizeof(node));
    yeni->data = data;
    if (r == NULL) {
        // Liste bos ise yeni dugum kendisini isaret eder
        yeni->next = yeni;
        return yeni;
    }
    if (r->data > data) {
        // Yeni dugum ilk dugum olacaksa
        node* temp = r;
        while (temp->next != r) {
            temp = temp->next;
        }
        temp->next = yeni;
        yeni->next = r;
        return yeni;
    }
    // Sirali ekleme
    node* temp = r;
    while (temp->next != r && temp->next->data < data) {
        temp = temp->next;
    }
    yeni->next = temp->next;
    temp->next = yeni;
    return r;
}

node* Sil(node* r, int data) {
    if (r == NULL) {
        cout << "Liste bos!" << endl;
        return NULL;
    }

    if (r->data == data) {
        // Ilk dugum siliniyor
        if (r->next == r) {
            free(r);
            return NULL;
        }
        node* temp = r;
        while (temp->next != r) {
            temp = temp->next;
        }
        temp->next = r->next;
        node* sil = r;
        r = r->next;
        free(sil);
        return r;
    }

    node* temp = r;
    while (temp->next != r && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next != r) {
        node* sil = temp->next;
        temp->next = temp->next->next;
        free(sil);
    } else {
        cout << "Eleman bulunamadi!" << endl;
    }
    return r;
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
