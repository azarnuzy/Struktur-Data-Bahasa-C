#include "header.h"

int main()
{
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);
    int i;

    createRowNumber(&L);
    for(i=0; i<n; i++) {
        int angkaDibagi;
        scanf("%d", &angkaDibagi);
        groupRowNumber(angkaDibagi, &L);
    }
    delEmptyCol(&L);
    printElement(L);
    return 0;
}