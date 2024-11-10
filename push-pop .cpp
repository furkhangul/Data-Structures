#include<iostream>
using namespace std;
int* dizi;
int boyut = 2;
int tepe = 0;

void oku() {
	for (int i = 0; i < tepe; i++) {
		cout << dizi[i] << "\n";
	}
}
int pop() {
	if (tepe <= 0) {
		cout << "Silinecek veri bulunamadı !";
		return -1;
	}
	if (tepe <= boyut / 4) 
	{
		cout << "Dizi boyutu kucultuldu ! " << "\n";;
		int* dizi2 = (int*)malloc(sizeof(int) * boyut / 4);
		for (int i = 0; i < boyut; i++) {
			dizi2[i] = dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		boyut = boyut / 4;
	}
	dizi[--tepe];
}

void push(int a) {
	if (tepe >= boyut) {
		int* dizi2 = (int*)malloc(sizeof(int) * 2 * boyut);
		for (int i = 0; i < boyut; i++) {
			dizi2[i] = dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		boyut = boyut * 2;
	}
	dizi[tepe++] = a;
}

int main() {
	dizi = (int*)malloc(sizeof(int) * boyut);
	push(10);
	push(20);
	push(30);
	push(40);
	push(60);
	push(70);
	push(50);
	oku();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	oku();
}
