#include "header.h"

int main() {
    /* 
    **L sebagai variabel untuk tipe data list
    **nama: masukan untuk nama mahasiswa
    **matkul: masukan untuk matkul mahasiswa
    **nilai: masukan untuk nilai mahasiswa
     */
    list L;
    createList(&L);

    char nama[50], matkul[50], nilai[10];

    scanf("%s %s %s", &nama, &matkul, &nilai);
    addFirst(nama, matkul, nilai, &L);
    scanf("%s %s %s", &nama, &matkul, &nilai);
    addAfter(L.first, nama, matkul, nilai, &L);
    scanf("%s %s %s", &nama, &matkul, &nilai);
    addBefore(L.first->next, nama, matkul, nilai, &L);
    printElement(L);
    delAfter(L.first->next->prev, &L);
    scanf("%s %s %s", &nama, &matkul, &nilai);
    addLast(nama, matkul, nilai, &L);
    printElement(L);
    delFirst(&L);
    scanf("%s %s %s", &nama, &matkul, &nilai);
    addLast(nama, matkul, nilai, &L);
    scanf("%s %s %s", &nama, &matkul, &nilai);
    addAfter(L.first->next, nama, matkul, nilai, &L);
    delLast(&L);
    printReverse(L);
    delAll(&L);
    printElement(L);
    return 0;
}