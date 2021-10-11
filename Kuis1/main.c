#include "header.h"

int main(int argc, char const *argv[])
{
    /* 
    **L sebagai variabel untuk tipe data list
    **menutukar variabel untuk tipe data namaMenuTukar
    *nama sebagai variabel nama menu warung
    *harga sebagai variabel harga menu warung
     */
    list L1, L2;
    namaMenuTukar menuTukar[101];
    createList(&L1);
    createList(&L2);

    int i;
    int n1, n2, m;
    char lastMenu1[50], lastMenu2[50];
    char nama[50];
    char harga[50];

    scanf("%d", &n1);
    for(i=0; i<n1; i++) {
        scanf("%s %s", &nama, &harga);
        if(i == n1-1) {
            strcpy(lastMenu1, nama);
        }
        addLast(nama, harga, &L1);
    }
    scanf("%d", &n2);
    for(i=0; i<n2; i++) {
        scanf("%s %s", &nama, &harga);
        if(i == n2-1) {
            strcpy(lastMenu2, nama);
        }
        addLast(nama, harga, &L2);
    }
    scanf("%d", &m);
    for(i=0; i<m; i++) {
        scanf("%s %s", menuTukar[i].nama1, menuTukar[i].nama2);
    }
    
    searchMenu(&L1, &L2, menuTukar, m, lastMenu1, lastMenu2);
    printf("menu warung pertama:\n");
    printElement(L1);
    printf("\nmenu warung kedua:\n");
    printElement(L2);
    return 0;
}
