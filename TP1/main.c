#include "header.h"

int main(int argc, char const *argv[])
{
    /* 
    ** L1 sebagai list untuk masukan awal
    ** L2 sebagai list untuk masukan yang baru dan terurut
    ** nama: masukan untuk nama makanan
    ** harga: masukan untuk harga makanan
    ** banyakUang: masukan untuk banyaknya uang yang dibawa untuk membeli makaann
     */
    list L1, L2;
    char nama[50];
    float rating;
    int harga;
    int banyakUang;
    char urutanMenu[50];

    /* membuat nilai awal dari kedua list */
    createList(&L1);
    createList(&L2);

    int cek = 0;
    /* masukan dari makanan */
    do {
        scanf("%s", &nama);
        if(strcmp(nama, "*") != 0) {
            scanf("%d %f", &harga, &rating);
            addLast(nama, harga, rating, &L1);
        }
    }while(strcmp(nama, "*") != 0);

    scanf("%d %s", &banyakUang, &urutanMenu);

    /* untuk mengurutkan makanan berdasarkan rating */
    sortDinamyc(L1, &L2, urutanMenu);

    printf("=== Menu Terurut ===\n");
    printElement(L2);

    printf("\n=== Dapat Dibeli ===\n");

    int sisaUang;
    /* untuk menghitung uang yang dipakai membeli makanan */
    sisaUang = dapatDibeli(&L2, banyakUang);

    if(countElement(L2) != 0) {
        printElement(L2);
    }else {
        printf("Tidak ada yang dapat dibeli\n");
    }

    printf("\nSisa uang: %d\n", sisaUang);
    return 0;
}
