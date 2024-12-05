#include <iostream>
using namespace std;

int main() {

	//Sokma Sıralaması (Insertion sort) methodu listedeki elemanları sıra ile ekleyerek sıralama işlemini yapmaya çalışan
	//sıralama methodudur.
	//Bu methodda dizinin ilk elemanı grup kabul edilir ve bu grup sol tarafından her defasında birer eleman alır. Yeni eklenen
	//eleman dizi içerisinde sola doğru ilerleyerek kendi yerlerini bulmaya çalışır.

	//Örnek verecek olursak: 5, 3, 12, 4, 6, 8
	// 1.Durumda: 5| 3, 12, 4, 6, 8
	// 2.Durumda: 3, 5| 12, 4, 6, 8
	// 3.Durumda: 3, 5, 12| 4, 6, 8
	// 4.Durumda: 3, 4, 5, 12| 6, 8
	// 5.Durumda: 3, 4, 5, 6, 12| 8
	// 6.Durumda: 3, 4, 5, 6, 8, 12|  şeklinde sıra ile düzenlenerek listeye eklenir.

	//Kod üzerinde gösterecek olursak:
        // Dizi tanımlama
        int dizi[] = { 9, 7, 6, 8, 0, 1, 3, 4, 2, 5 };
        int uzunluk = sizeof(dizi) / sizeof(dizi[0]);  // Uzunluğu buluyoruz.

        // Insertion sort (Sokma sıralaması) algoritması
        for (int i = 1; i < uzunluk; i++) {  // İlk eleman zaten sıralı kabul edilir, ikinci elemandan başlarız
            int kayit = dizi[i];  // Mevcut elemanı "kayit" olarak kaydediyoruz.
            int j = i - 1;

            // Key'i, sağında bulunan sıralı elemanlarla karşılaştırarak uygun yerine yerleştiriyoruz
            while (j >= 0 && dizi[j] > kayit) {
                dizi[j + 1] = dizi[j];  // Elemanları bir pozisyon sağa kaydırıyoruz.
                j--;
            }

            dizi[j + 1] = kayit;  // Kaydı doğru konumuna yerleştiriyoruz.
        }

        // Sıralı diziyi ekrana yazdırıyoruz
        cout << "Sirali Dizi: ";
        for (int i = 0; i < uzunluk; i++) {
            cout << dizi[i] << " ";  // Diziyi ekrana yazdırıyoruz.
        }
        cout << endl;

        return 0;
}
