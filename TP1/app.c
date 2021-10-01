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

void addFirst(char nama[], int harga, float rating, list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru -> kontainer.nama, nama);
    baru -> kontainer.rating = rating;
    baru -> kontainer.harga = harga;
    if((*L).first == NULL) {
        baru -> next = NULL;
    }else {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}


void addAfter(elemen* prev, char nama[], int harga, float rating, list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru -> kontainer.nama, nama);
    baru -> kontainer.rating = rating;
    baru -> kontainer.harga = harga;

    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(char nama[], int harga, float rating, list *L) {
    if((*L).first ==NULL) {
        addFirst(nama,harga, rating, L);
    }else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev,nama, harga,rating,L);
    }
}

void sortDinamycList( char nama[], int harga, float rating,  list *L) {
    if((*L).first != NULL) {
        elemen* tunjuk1 = (*L).first;
        elemen* prev;
        prev = NULL;
        int cek = 0;
        int posisi = 1;
        while(tunjuk1 != NULL && cek == 0) {
            if(tunjuk1 -> kontainer.rating > rating) {
                prev = tunjuk1;
                if(prev == NULL || posisi == 1) {
                    addFirst(nama, harga, rating, L);
                    cek = 1;
                }else {
                    addAfter(prev, nama, harga, rating, L);
                    cek = 1;
                }
            }

            posisi++;
            tunjuk1 = tunjuk1 -> next;
            
        }
        
        if(tunjuk1 == NULL) {
            addLast(nama, harga, rating, L);
        }
    }
}

void readList(list L1, list *L2) {
    elemen* tunjuk = L1.first;

    tunjuk = tunjuk -> next;
    while(tunjuk != NULL) {
        sortDinamycList(tunjuk->kontainer.nama, tunjuk-> kontainer.harga, tunjuk->kontainer.rating, &L2);
        tunjuk = tunjuk -> next;
    }
}

void printElement(list L) {
    if(L.first != NULL) {
        elemen* tunjuk = L.first;
        int i = 1;

        while(tunjuk != NULL) {
            printf("%s %d %s\n", tunjuk->kontainer.nama, tunjuk-> kontainer.harga, tunjuk->kontainer.rating);
            tunjuk = tunjuk->next;
            i++;
        }
    }else {
        printf("list kosong\n");
    }

    printf("======\n");
}


int main(int argc, char const *argv[])
{
    list L1, L2;
    char nama[50];
    float rating;
    int harga;
    int banyakUang;
    char urutanRating[50];

    createList(&L1);
    createList(&L2);

    int cek = 0;

    do {
        scanf("%s", &nama);
        if(strcmp(nama, "*") != 0) {
            scanf("%d %f", &harga, &rating);
            addLast(nama, harga, rating, &L1);
        }
    }while(strcmp(nama, "*") != 0);

    scanf("%d %s", &banyakUang, &urutanRating);

    readList(L1, &L2);
    printElement(L2);
    return 0;
}
