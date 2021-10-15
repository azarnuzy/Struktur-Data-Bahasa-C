#include "header.h"

int main(int argc, char const *argv[])
{
    list L;
    char nama[50];
    int n;
    createList(&L);
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%s", nama);
        addLast(nama, &L);
    }

    swapDawala(&L);
    printElement(L);
    return 0;
}