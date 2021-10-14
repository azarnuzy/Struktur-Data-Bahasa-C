#include "header.h"

int main(int argc, char const *argv[])
{
    /* 
    **L sebagai variabel untuk tipe data list
    **nama: masukan untuk nama PC
    **haga: masukan untuk harga PC
    **kode: masukan untuk kode PC
     */
    list L;
    char nama[50];
    int harga, kode;
    char metode1[10], metode2[10];

    createList(&L);

    //melakukan masukan nama harga dan kode
    do {
        scanf("%s", &nama);
        if(strcmp(nama, "---") != 0) {
            scanf("%d %d", &harga, &kode);
            //kondisi jika kode ganjil maka tidak akan masuk kedalam list
            if(kode % 2 != 1) {
                addLast(nama, harga, kode, &L);
            }
        }
    }while(strcmp(nama, "---") != 0);

    scanf("%s %s", &metode1, &metode2);

    //kondisi jika list elemen lebih dari 0
    if(countElement(L) > 0) {
        multiDynamicSortingList(&L, metode1, metode2);
    }

    printElement(L);
    return 0;
}