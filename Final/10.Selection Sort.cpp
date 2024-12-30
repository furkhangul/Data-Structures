#include <iostream>

using namespace std;

int main() {
	//Seçerek sıralama (selection sort) methodunun mantığı 5 elemanlı bir liste düşünürsek bu listede sıra ile tarama yapıyor
	//tarama sırasında bulduğu en küçük ifade ile listenin başındaki elemanın yerlerini değişitiryor. Bu sayede listenin en başına
	//en küçük değerli ifade geçmiş oluyor.


	// Örnek olarak 5,7,3,2,9,8,4,1 ifadesini çözecek olursak:
	// 1. kavram: 1,7,3,2,9,8,4,5
	// 2. kavram: 1,2,3,7,9,8,4,5
	// 3. kavram: 1,2,3,4,9,8,7,5
	// 4. kavram: 1,2,3,4,5,8,7,9
	// 5. kavram: 1,2,3,4,5,7,8,9 şeklinde sıralanır

	// Veya başka bir örnek çözecek olursak: 1,2,3,7,9,5,6
	// 1. kavram: 1,2,3,5,9,7,6
	// 2. kavram: 1,2,3,5,6,7,9 şeklinde çözülebilir.



	// Kod mantığı üzerinde çözecek olursak ise: 

	int dizi[] = { 7,1,9,8,6,5,3,4,0,2 };
	int diziuzunluk = sizeof(dizi) / sizeof(dizi[0]); // dizinin eleman sayısını bulamamıza yardımcı olur.
	
	for (int i = 0; i < diziuzunluk; i++) {

		int enkucuk = i; // dizinin en küçük elemanını 1. eleman olarak alıyoruz.

		//1. ifadeden sonrasını taramaya başlıyoruz
		for (int j = i + 1; j < diziuzunluk; j++) {
			if (dizi[j] < dizi[enkucuk]) {
				enkucuk = j;
			}
		}
		if (enkucuk != i) {
			swap(dizi[i], dizi[enkucuk]);
		}
	}
	for (int i = 0; i < diziuzunluk; i++) {
		cout << dizi[i] << " ";
	}
	return 0;
}
