#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
    int harga;
    float rating;
}makanan;

typedef struct elmt *alamatElmt;
typedef struct elmt {
    makanan kontainer;
    alamatElmt next;
}elemen;

typedef struct {
    elemen *first;
}list;

void createList(list *L) {
    (*L).first = NULL;
}

int countElement(list L) {
    int hasil = 0;
    if(L.first != NULL) {
        elemen* tunjuk;
        tunjuk = L.first;
        while(tunjuk != NULL) {
            hasil += 1;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}