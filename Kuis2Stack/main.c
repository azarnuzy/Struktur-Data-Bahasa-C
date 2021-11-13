#include "header.h"

int main()
{
    /* 
    **S1 S2 S3 sebagai variabel untuk tipe data stack
    **nama: masukan untuk nama pakaian
    **merek: masukan untuk merek pakaian
    **input: sebagai batasan masukan dari banyaknya pakaian yg ada pada setiap tumpukan
     */

    //menginisialisasikan semua variabel yang akan digunakan
    int n,m;
    scanf("%d", &n);
    stack S1[n], S2[n], S3[n];
    char nama[50], merek[50];
    char input[50];
    int i,j;

    //membuat stack kosong
    for(i=0; i<n; i++) {
        createEmpty(&S1[i]);
        createEmpty(&S2[i]);
        createEmpty(&S3[i]);
    }
    
    for(i=0; i<n; i++) {
        //memasukan input berupa batas tumpukan
        scanf("%s", input);
        int cek = 0;
        while(cek == 0) {
            //memasukan input berupa tumpukan pakaian
            scanf("%s", nama);
            if(strcmp(nama, "0") == 0) {
                cek = 1;
            }else{
                scanf("%s", merek);
                //menumpukan data ke dalam stack
                push(merek, nama, &S1[i]);
            }
        }
    }

    scanf("%d", &m);
    //perulangan untuk mencari pakaian yang akan di ambil pada stack
    for(i=0; i<m; i++) {
        scanf("%s", nama);
        for(j=0; j<n; j++) {
            findPakaian(&S1[j], &S2[j], nama);
            findTempPakaian(&S2[j], &S3[j], nama);
        }
    }

    //perulangan untuk menampilkan hasil pada stack
    for(i=0; i<n; i++) {
        printStack(S1[i], 1, 1+i);
    }

    for(i=n-1; i>=0; i--) {
        printStack(S2[i], 2, 1+i);
    }
    return 0;
}