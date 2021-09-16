#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    nilaiMatkul kontainer;
    alamatelmt prev;
    alamatelmt next;
}elemen;

typedef struct {
    elemen *first;
    elemen *tail;
}list;

void createList (list *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L) {
    int hasil = 0;
    if(L.first != NULL) {
        elemen* bantu;
        bantu = L.first;
        while(bantu != NULL) {
            hasil += 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru -> kontainer.nim, nim);
    strcpy(baru -> kontainer.nama, nama);
    strcpy(baru -> kontainer.nilai, nilai);
    if((*L).first == NULL) {
        baru -> prev = NULL;
        baru -> next = NULL;
        (*L).tail = baru;
    }else {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* before, char nim[], char nama[], char nilai[], list *L) {
    if(before != NULL) {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        strcpy(baru->kontainer.nim, nim);
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.nilai, nilai);
        if(before->next==NULL) {
            baru->next = NULL;
            (*L).tail = baru;
        }else {
            baru->next =before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}