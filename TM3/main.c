#include "header.h"

int main() {
    /* 
    **L sebagai variabel untuk tipe data list
    **merek: masukan untuk merek handphone
    **tipe: masukan untuk tipe handphone
    **jumlah: masukan untuk jumlah handphone
     */

    list L;
    createList(&L);

    char merek[50];
    char tipe[50];
    int jumlah;
   
    scanf("%s %s %d", &merek, &tipe, &jumlah);
    addFirst(merek, tipe, jumlah, &L);
    scanf("%s %s %d", &merek, &tipe, &jumlah);
    addLast(merek, tipe, jumlah, &L);
    scanf("%s %s %d", &merek, &tipe, &jumlah);
    addAfter(L.first, merek, tipe, jumlah, &L);
    printElement(L);
    delAfter(L.data[L.first].next, &L);
    printElement(L);
    scanf("%s %s %d", &merek, &tipe, &jumlah);
    addAfter(L.data[L.first].next, merek, tipe, jumlah, &L);
    scanf("%s %s %d", &merek, &tipe, &jumlah);
    addLast(merek, tipe, jumlah, &L);
    delFirst(&L);
    printElement(L);
    scanf("%s %s %d", &merek, &tipe, &jumlah);
    addFirst(merek, tipe, jumlah, &L);
    delAfter(L.first, &L);
    printReverse(L);
    delAll(&L);
    printElement(L);

    return 0;
}