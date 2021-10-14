#include "header.h"

int main(int argc, char const *argv[])
{
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);
    int i;
    char kata[50];
    for(i=0; i<n; i++) {
        scanf("%s", kata);
        addFirst(kata, &L);
    }
    printElement(L);
    return 0;
}