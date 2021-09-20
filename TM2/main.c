#include "header.h"

int main(int argc, char const *argv[])
{
    /* 
    **L sebagai variabel untuk tipe data list
    **nama: masukan untuk nama senyawa
    **rumus: masukan untuk rumus senyawa
    **konsentrasi: masukan untuk konsentrasi senyawa
     */

    list L;
    createList(&L);

    char nama[50];
    char rumus[50];
    char konsentrasi[10];

    scanf("%s %s %s", &nama, &rumus, &konsentrasi);
    addFirst(nama, rumus, konsentrasi, &L);
    scanf("%s %s %s", &nama, &rumus, &konsentrasi);
    addLast(nama, rumus, konsentrasi, &L);
    scanf("%s %s %s", &nama, &rumus, &konsentrasi);
    addAfter(L.first->next, nama, rumus, konsentrasi, &L);
    printf("======\n");
    printElement(L);
    delFirst(&L);
    scanf("%s %s %s", &nama, &rumus, &konsentrasi);
    addLast(nama, rumus, konsentrasi, &L);
    delAfter(L.first->next, &L);
    printElement(L);
    delLast(&L);
    scanf("%s %s %s", &nama, &rumus, &konsentrasi);
    addFirst(nama, rumus, konsentrasi, &L);
    printElement(L);
    delAll(&L);
    printElement(L);
    scanf("%s %s %s", &nama, &rumus, &konsentrasi);
    addLast(nama, rumus, konsentrasi, &L);
    printElement(L);
    
    return 0;
}