#include <iostream>
using namespace std;

int main() {
	//DiJkstra Algoritması bir grafın ağırlıklı kenarları üzerinde, bir başlangıç düğümünden 
	//diğer tüm düğümlere olan kısa yolları bulan bir algoritmadır.
	

	//Temel Adımları: 
	// 
	//Başlangıç düğümünü seçmek:
	//Algoritma, başlangıç düğümünden başlar. Başlangıç düğününün mesafesi sıfır olarak atanır.
	//diğer düğümlerin mesafesi ise sonsuz kabul edilir.
	//
	//Ziyaret edilen düğümün belirlenmesi:
	//Henüz ziyaret edilmemiş en yakın düğüm seçilir.
	// 
	//Mesafeleri Güncellemek: 
	//Seçilen düğümden komşularına giden yolların ağırlıkları (mesafeleri) gözden
	// geçirilir. Eğer yeni bulunan yol daha kısa ise, komşunun mesafesi güncellenir.
	// 
	//Tekrar Etme : Bu işlem, tüm düğümler ziyaret edilene kadar devam eder.
	// Ziyaret edilen düğümler tekrar ziyaret edilmez.
	// 
	//Sonuç : Algoritma, her düğüm için başlangıç düğümüne olan en 
	// kısa mesafeleri hesaplamış olur.




	return 0;
}
