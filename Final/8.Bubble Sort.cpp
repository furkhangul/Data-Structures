#include <iostream>
using namespace std;

int main() {
	//Bubble Sort (Baloncuk sıralama) methodu ise soldan sağa doğru ikişerli gruplar halinde liste elemanlarını alır.
	//Alınan elemalardan büyük olan ile küçük olan  hesaplanır ve eyerleri değiştirilir.
	//En sonda artık grup elemanları doğru konumuunu buluncaya kadar bu işlem devam eder.
	//Kullanım Aşamaları:
	//1-Listenin başından sonuna kadar her iki ardışık öğeyi karşılaştır.
	//2-Eğer ilk öğe ikinci öğeden büyükse, yer değiştir.
	//3-Bir geçişi tamamladıktan sonra, son öğe sıralı olur.
	//4-Kalan öğeler üzerinde aynı işlemi tekrarla.
	//5-Liste tamamen sıralanana kadar bu adımlar tekrarlanır.


	//Kağıt üzerinde bir örnek çözecek olursak:  5, 3, 8, 4, 2
	//1. adım: 3, 5, 8, 4, 2
	//2. adım: 3, 5, 4, 8, 2
	//3. adım: 3, 5, 4, 2, 8
	//4. adım: 3, 4, 5, 2, 8
	//5. adım: 3, 4, 2, 5, 8
	//6. adım: 3, 2, 4, 5, 8
	//7. adım: 2, 3, 4, 5, 8 şeklinde ifade edilir.

	//Kağıt üzerinde başka bir örnek çözecek olursak:  12, 9, 5, 15, 8
	//1. adım: 9, 12, 5, 15, 8
	//2. adım: 9, 5, 12, 15, 8
	//3. adım: 9, 5, 12, 8, 15
	//4. adım: 5, 9, 12, 8, 15
	//5. adım: 5, 9, 8, 12, 15 
	//6. adım: 5, 8, 9, 12, 15 şeklinde çözülebilir.

	//Kod üzerinde bubble sort methodunu inceleyecek olursak:
	int dizi[] = { 12, 9, 5, 15, 8 };
	int uzunluk = sizeof(dizi) / sizeof(dizi[0]); //dizi boyutunu bulmamızı sağlar.

	// Bubble Sort işlemi için dış döngü
	for (int i = 0; i < uzunluk - 1; i++) {
		// İç döngü, her geçişte en büyük öğeyi sona taşıyacak
		for (int j = 0; j < uzunluk - i - 1; j++) {
			if (dizi[j] > dizi[j + 1]) {
				// Yer değiştirme işlemi
				int gecici = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = gecici;
			}
		}
	}
	
	for (int i = 0; i < uzunluk; i++) {
		cout << dizi[i] << " ";
	}
	return 0;
}
