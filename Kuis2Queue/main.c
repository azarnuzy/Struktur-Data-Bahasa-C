#include "header.h"

int main()
{
    /* 
    **Q1 Q2 sebagai variabel untuk tipe data queue
    **data sebgai tipe data terstruktur yang di dalamnya terdapat nama, noPrioritas, kota, dan uang
    **n = banyaknya orang yang berhak menerima bantuan sosial
    **m = banyaknya orang yang sudah mendapat bantuan dan sudah keluar dari antrian
     */
    
    //menginisialisasikan variable yang akan digunakan
    queue Q1, Q2;
    bantuan data;
    int n,m,i;

    //membuat Queue kosong
    createEmpty(&Q1);
    createEmpty(&Q2);
    scanf("%d", &n);

    //perulangna untuk masukan 
    for(i=0; i<n; i++) {
        scanf("%s %d %s %s", &data.nama, &data.noPrioritas, &data.kota, &data.uang);
        addPriority(&Q1,data.noPrioritas,data);
    }

    //mmasukan dari input m
    scanf("%d", &m);
    
    //menghapus nilai dari queue sesuai dengan m
    for(i=0; i<m; i++) {
        del(&Q1, &Q2);
    }

    //menampilkan hasil dari queue
    printQueue(Q2, 2);
    printf("\n");
    printQueue(Q1, 1);
    return 0;
}