#include "header.h"

int main(int argc, char const *argv[])
{   
    /* 
    **n sebagai banyaknya masukan
    **L sebagai variabel untuk tipe data list
    **kata: masukan untuk kata pola
     */
    int n;
    list L1;
    createList(&L1);
    scanf("%d", &n);
    int i;
    char kata[50];
    for(i=0; i<n; i++) {
        scanf("%s", kata);
        addLast(kata, &L1);
    }

    /* sebagai kondisi jika n = ganjil */
    if(n % 2 == 1) {
        n += 1;
    }
    n /= 2;
    polaList2(L1, n);

    return 0;
}