#include "header.h"

int main(int argc, char const *argv[])
{
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);
    int i,j;
    char kata[50];
    int panjangA;
    for(i=0; i<n; i++) {
        scanf("%s", kata);
        panjangA = 0;
        for(j=0; j<strlen(kata); j++) {
            if(kata[j] == 'a') {
                panjangA++;
            }
        }
        addLast(kata,panjangA, &L);
    }
    sortingList(&L);
    printElement(L);
    return 0;
}