#include "header.h"

int main(int argc, char const *argv[])
{
    list L1, L2;
    char nama[50];
    float rating;
    int harga;
    int banyakUang;
    char urutanMenu[50];

    createList(&L1);
    createList(&L2);

    int cek = 0;

    do {
        scanf("%s", &nama);
        if(strcmp(nama, "*") != 0) {
            scanf("%d %f", &harga, &rating);
            addLast(nama, harga, rating, &L1);
        }
    }while(strcmp(nama, "*") != 0);

    scanf("%d %s", &banyakUang, &urutanMenu);

    sortDinamyc(L1, &L2, urutanMenu);

    printf("=== Menu Terurut ===\n");
    printElement(L2);

    printf("\n=== Dapat Dibeli ===\n");

    int sisaUang;
    sisaUang = dapatDibeli(&L2, banyakUang);

    if(countElement(L2) != 0) {
        printElement(L2);
    }else {
        printf("Tidak ada yang dapat dibeli\n");
    }

    printf("\nSisa uang: %d\n", sisaUang);
    return 0;
}
