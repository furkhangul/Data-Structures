#include<iostream>
using namespace std;
int *dizi;
int boyut = 2;
int tepe = 0;
int pop() {
	return dizi[--tepe];
}

void push(int a) {
	if (tepe >= boyut) {
		int* dizi2 = (int*)malloc(sizeof(int) * boyut * 2);
		for (int i = 0; i < boyut; i++) {
			dizi2[i] = dizi[i];
		}
		dizi = dizi2;
		boyut = boyut * 2;
	}

	dizi[tepe++] = a;
}


void bastir() {
	for (int i = 0; i < tepe; i++) {
		cout << dizi[i] << "\n";
	}
}
int main() {
	dizi = (int*)malloc(sizeof(int) * 2);
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	bastir();
	pop();
	pop();
	bastir();
	return 0;
}
