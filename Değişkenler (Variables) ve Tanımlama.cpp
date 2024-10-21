#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int a; //tipi, ismi
	a = 10; //değeri
	cout << a;
	//veriable değişkeni
	a = 20; // atama, assigment
	cout << "\nFurkan Gül" << "\n";
	int b = 30;
	int c = 5;
	int d = 50;
	int x = 4, y = 8; //x isminde bir değişken tanımla 4 koy ve y yerine de 8 koy bir tane de z tanımla
	cout << a << "\n";
	cout << b<<"\n";
	cout << c << "\n";
	cout << d << "\n";
	cout << x << "\n";
	cout << y << "\n";
	return 0;
}
