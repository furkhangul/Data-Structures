#include<iostream>  // C++'ta giriş/çıkış işlemleri için gerekli olan kütüphane.
#include<stdlib.h>  // Dinamik bellek yönetimi için gerekli kütüphane (malloc gibi fonksiyonlar için).

using namespace std;  // std isim alanını kullanarak, C++ standart fonksiyonlarına std:: ön ekini yazmadan erişmemizi sağlar.

// Düğüm yapısını tanımlıyoruz:
struct n {
	int x;        // Düğümde tutulacak değer.
	n* next;      // Sonraki düğümü işaret edecek pointer.
};
typedef n node;  // 'struct n' yerine sadece 'node' ifadesini kullanmamızı sağlayan kısa ad.

int main()
{
    // Bağlı listenin başlangıç düğümünü oluşturuyoruz:
    node* root;  // İlk düğümü işaret eden pointer.
    root = (node*)malloc(sizeof(node)); // İlk düğüm için bellek ayırıyoruz.
    root->x = 10;  // İlk düğümün x değerine 10 atıyoruz.

    // İkinci düğümü oluşturuyor ve ilk düğüme bağlıyoruz:
    root->next = (node*)malloc(sizeof(node)); // İkinci düğüm için bellek ayırıyoruz.
    root->next->x = 20;  // İkinci düğümün x değerine 20 atıyoruz.

    // Üçüncü düğümü oluşturuyor ve ikinci düğüme bağlıyoruz:
    root->next->next = (node*)malloc(sizeof(node)); // Üçüncü düğüm için bellek ayırıyoruz.
    root->next->next->x = 30;  // Üçüncü düğümün x değerine 30 atıyoruz.

    // Listeyi gezmek için bir işaretçi tanımlıyoruz:
    node* iter = root;  // İteratörü başlangıç düğümüne atıyoruz.

    // Düğümlerdeki x değerlerini sırayla yazdırıyoruz:
    cout << iter->x << " ";  // İlk düğümdeki değeri (10) yazdırır.
    iter = iter->next;       // İteratörü ikinci düğüme geçiriyoruz.
    cout << iter->x << " ";  // İkinci düğümdeki değeri (20) yazdırır.
    iter = iter->next;       // İteratörü üçüncü düğüme geçiriyoruz.
    cout << iter->x << endl; // Üçüncü düğümdeki değeri (30) yazdırır.

    // Bellek sızıntısını önlemek için her düğüm için ayrılan belleği serbest bırakıyoruz:
    free(root->next->next);  // Üçüncü düğümü serbest bırakıyoruz.
    free(root->next);        // İkinci düğümü serbest bırakıyoruz.
    free(root);              // İlk düğümü serbest bırakıyoruz.

    return 0;  // Program başarıyla tamamlandı.
}
