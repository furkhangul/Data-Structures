#include <iostream>
using namespace std;

int* dizi = NULL;
int sira = 0;
int sirabasi = 0;
int boyut = 2;

int Dequeue() {
	if (sira == sirabasi) {
		cout << "Sırada eleman yok!" << endl;
		return -1;
	}
	int deger = dizi[sirabasi];
	sirabasi++;
	if (sirabasi == sira) {  // Kuyruk tamamen boşaldıysa sıfırla
		sira = 0;
		sirabasi = 0;
	}
	return deger;
}

void Enqueue(int a) {
	if (dizi == NULL) {
		dizi = (int*)malloc(sizeof(int) * boyut);
	}
	if (sira >= boyut) {  // Belleği genişletme
		int* dizi2 = (int*)malloc(sizeof(int) * boyut * 2);
		for (int i = 0; i < boyut; i++) {
			dizi2[i] = dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		boyut *= 2;
	}
	dizi[sira++] = a;
}

void toparla() {
	if (sirabasi == 0) return;

	for (int i = 0; i < sira - sirabasi; i++) {
		dizi[i] = dizi[sirabasi + i];
	}
	sira -= sirabasi;
	sirabasi = 0;
}

void Oku() {
	for (int i = sirabasi; i < sira; i++) {
		cout << dizi[i] << " ";
	}
	cout << endl;
}

int main() {
	for (int i = 0; i < 10; i++) {
		Enqueue(i * 2);
	}
	Oku();

	Dequeue();
	Dequeue();
	toparla();
	Oku();

	return 0;
}
