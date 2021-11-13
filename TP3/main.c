#include "header.h"

int main()
{
    /* 
    **S1 S2 sebagai variabel untuk tipe data stack
    **judul: masukan untuk merek makanan
    **harga: masukan untuk tipe makanan
     */
    stack S1, S2, S3;
    int n, i;
    char judul[50], tahun[50], band[50];
    createEmpty(&S1);
    createEmpty(&S2);
    createEmpty(&S3);

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%s%s%s", tahun, judul, band);
        push(judul, tahun, band, &S1);
    }

    for(i=S1.top; i>=0; i--) {
        if(countASCII(S1.data[i].judul) % 2 == 0) {
            push(S1.data[i].judul, S1.data[i].tahun, S1.data[i].band, &S2);
        }else {
            push(S1.data[i].judul, S1.data[i].tahun, S1.data[i].band, &S3);
        }
    }
 
    printStack(S2, 1);
    printStack(S3, 2);

    return 0;
}