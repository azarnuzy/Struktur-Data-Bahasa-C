#include "header.h"

int main(int argc, char const *argv[])
{
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);
    int i,j;
    int a,b,c;
    int panjangA;
    for(i=0; i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        addLast(a,b,c, &L);
    }
    sortingList(&L);
    printElement(L);
    return 0;
}