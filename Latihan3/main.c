#include "header.h"

int main(int argc, char const *argv[])
{
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);
    int i;
    float angka;
    int a;
    for(i=0; i<n; i++) {
        scanf(" %f", &angka);
        addFirst(angka, &L);
    }
    printElement(L);
    return 0;
}