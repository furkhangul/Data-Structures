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

void add(node* r, int x) {
    while (r->next != NULL) {
        r = r->next;
    }
    r->next = (node*)malloc(sizeof(node));
    r->next->x = x + 10;
    r->next->next = NULL;
}

int main() {
    node* root = (node*)malloc(sizeof(node));
    root->x = 10;
    root->next = NULL;
    add(root, 10);
    bastir(root);
    return 0;
}
