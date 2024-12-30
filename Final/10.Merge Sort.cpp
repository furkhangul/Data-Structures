#include<iostream>
using namespace std;

int main() {
	//Merge Sort, Böl ve Fethet yöntemini kullanan bir algoritmadır.diziyi ardışık olarak en küçük alt dizilerine kadar yarılayansonra da onları sıraya koyarak
	// bireştiren özyineli bir algoritmadır. Yarılama işlemi en büyük alt dizi en çok iki öğeli olana kadar sürer. Sonra "Merge (Birleştirme)" işlemiyle altdiziler 
	// ikişer ikişer bölünüş sırasıyla sıralı olarak bir üst dizide bireşir. Süreç sonunda en üstte sıralı diziye ulaşılır.

	//Örnek:
	// [38, 27, 43, 3, 9, 82, 10] İfadesini sıralı diziniz.
	//1.adım: [38, 27, 43, 3] ve [9, 82, 10] şeklinde iki gruba ayrılır.
	//2.adım: [38, 27, 43, 3] grubu [38, 27] ve [43, 3] şeklinde iki gruba daha ayrılır.
	//3.adım: [38, 27] grubu [38] ve [27] şeklinde iki gruba ayrılır.
	//4.adım: [43, 3] grubu [43] ve [3] şeklinde iki gruba ayrılır.
	//5.adım:[9, 82, 10] grubu [9, 82] ve [10] şeklinde iki gruba ayrılır.
	//6.adım: [9, 82] grubu [9] ve [82] şeklinde iki gruba ayrılır.
	//Birleştirme Kısmı:
	//7.adım: [38] ve [27] grupları [27, 38] şeklinde grup oluşturur.
	//8.adım: [43] ve [3] grupları [3, 43] şeklinde grup oluşturur.
	//9.adım: [27,38] ve [3,43] grupları [3, 27, 38, 43] şeklinde grup oluşturur.
	//10.adım: [9] ve [82] grubu [9, 82] şeklinde grup oluşturur.
	//11.adım: [9, 82] ve [10] grupları [9, 10, 82] şeklinde grup oluşturur.
	//12.adım: [9, 10, 82] ve [3, 27, 38, 43] grupları [3, 9, 10, 27, 38, 43, 82] şeklinde grup oluşturur.
	//ÇIKTI: [3, 9, 10, 27, 38, 43, 82]

	return 0;
}
