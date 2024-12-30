#include<iostream>
using namespace std;

int main() {
	//Quick sort da Merge sort gibi parçala ve fethet mantığıyla çalışır. Problemi kendi içerisinde küçük parçalara ayırır ve çözer. Yapılan ilk işlem bir pivot seçmektir. 
	//Bir pivot seçilir ve bu pivottan küçük olanlar pivotun soluna, pivottan büyük olanlar sağına atılır. Bu sebepten performans açısından pivotun seçimi önemlidir.

	//Örnek:
	//[26 , 33 , 35 , 29 , 19 , 12 , 22 ] dizisini küçükten büyüğe doğru sıralayınız.
	//1.adım: Pivot olarak 19 seçtim. (istediğimi seçerim)
	//2.adım: küçük olanlar> [12]
	//3.adım: pivot> [19]
	//4.adım: büyük olanlar> [22,26, 33, 35, 29]
	//5.adım: [12] 19 [22, 26, 33, 35, 29] şeklinde sağ ve sol diziler çıktı.
	//6.adım: Şimdi [22, 26, 33, 35, 29 ] arasından 26'yı pivot olarak ekliyoruz.
	//7.adım: küçük olanlar> [22]
	//8.adım: Pivot> [26]
	//9.adım: büyük olanlar> [33, 35, 29]
	//10.adım: [33, 35, 29] grubundan 33 pivot olarak alınır.
	//11.adım: küçük olanlar> [29]
	//12.adım: pivot> [33]
	//13.adım: büyük olanlar> [35]
	//17.adım: Liste: [12, 19, 22, 26, 29, 33, 35] şeklinde sıralanır.
	return 0;
}
