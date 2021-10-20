#include "header.h"

int main()
{
    /* 
    **L1 & L2 sebagai variabel untuk tipe data list
    **nama: masukan untuk nama club
    **tahun: masukan untuk tahun club
    **namaPemain: masukan untuk namaPemain pemain club pada tahun tertentu
    **n: masukan untuk menentukan banyaknya club yang ada
     */
    list L1,L2;
    
    createList(&L1);
    createList(&L2);
    int n;
    scanf("%d", &n);
    int i;
    char nama[50];
    int tahun;

    for(i=0; i<n; i++) {
        scanf("%s %d", nama, &tahun);
        char namaPemain[50];
        addFirstB(nama, tahun, &L1);
        eBaris *elmt = L1.first;
        scanf("%s", namaPemain);
        addLastK(namaPemain, L1.first);
        scanf("%s", namaPemain);
        addFirstK(namaPemain, L1.first);
        scanf("%s", namaPemain);
        addAfterK(elmt->col,namaPemain);
        scanf("%s", namaPemain);
        addLastK(namaPemain, L1.first);
    }

    sortList(L1, &L2);
    delAfterK(L2.first->next->col->next_kol);
    delLastB(&L2);
    delFirstK(L2.first);
    printElement(L2);
    return 0;
}