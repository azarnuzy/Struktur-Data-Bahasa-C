#include "header.h"

int main()
{
    /* 
    **Q1 Q2 sebagai variabel untuk tipe data queue
    **nama: masukan untuk nama mahasiswa
    **nim: masukan untuk nim mahasiswa
     */
    queue Q1, Q2;
    char nim[50];
    char nama[50];
    createEmpty(&Q1);
    createEmpty(&Q2);

    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    scanf("%s%s", nama, nim);
    addPriority(&Q1, 2, nim, nama);
    printf("******************\n");
    printQueue(Q1, 1);
    del(&Q1, &Q2);
    printQueue(Q1, 1);
    printQueue(Q2, 2);
    scanf("%s%s", nama, nim);
    addPriority(&Q1, 1, nim, nama);
    scanf("%s%s", nama, nim);
    addPriority(&Q1, 99, nim, nama);
    printQueue(Q1, 1);
    del(&Q1, &Q2);
    del(&Q1, &Q2);
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    printQueue(Q1, 1);
    printQueue(Q2, 2);
    return 0;
}