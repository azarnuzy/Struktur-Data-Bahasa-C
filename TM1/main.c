#include "header.h"

int main(int argc, char const *argv[])
{
    /* 
    **L sebagai variabel untuk tipe data list
    **merek: masukan untuk merek sepatu
    **warna: masukan untuk warna sepatu
    **ukuran: masukan untuk ukuran sepatu
     */
    list L;
    createList(&L);
    char merek[50], warna[50];
    int ukuran;
    scanf("%s%s%d", &merek, &warna,&ukuran);
    addFirst(merek, warna, ukuran, &L);
    scanf("%s%s%d", &merek, &warna,&ukuran);
    addFirst(merek, warna, ukuran, &L);
    scanf("%s%s%d", &merek, &warna,&ukuran);
    addLast(merek, warna, ukuran, &L);
    printElement(L);
    delLast(&L);
    scanf("%s%s%d", &merek, &warna,&ukuran);
    addLast(merek, warna, ukuran, &L);
    scanf("%s%s%d", &merek, &warna,&ukuran);
    addAfter(L.first, merek, warna, ukuran, &L);
    delFirst(&L);
    printElement(L);
    scanf("%s%s%d", &merek, &warna,&ukuran);
    addAfter(L.data[L.first].next, merek, warna, ukuran, &L);
    delAfter(L.first, &L);
    printElement(L);
    delAll(&L);
    printElement(L);

    return 0;
}
