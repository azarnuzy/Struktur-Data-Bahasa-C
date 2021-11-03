#include "header.h"

int main()
{
    /* 
    **S1 S2 sebagai variabel untuk tipe data stack
    **nama: masukan untuk merek makanan
    **harga: masukan untuk tipe makanan
     */
    stack S1, S2;
    char nama[50], harga[50];
    createEmpty(&S1);
    createEmpty(&S2);
    printStack(S1,1);
    printStack(S2,2);
    printf("==================\n");
    scanf("%s%s", nama, harga);
    push(harga, nama, &S1);
    scanf("%s%s", nama, harga);
    push(harga, nama, &S2);
    scanf("%s%s", nama, harga);
    push(harga, nama, &S2);
    printStack(S1,1);
    printStack(S2,2);
    printf("==================\n");
    pop(&S1);
    popMove(&S2, &S1);
    scanf("%s%s", nama, harga);
    push(harga, nama, &S1);
    scanf("%s%s", nama, harga);
    push(harga, nama, &S2);
    scanf("%s%s", nama, harga);
    push(harga, nama, &S1);
    pop(&S2);
    popMove(&S1, &S2);
    printStack(S1,1);
    printStack(S2,2);
    printf("==================\n");
    return 0;
}