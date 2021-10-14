#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
}mahasiswa;

typedef struct {
    char kode[10];
    char nilai[2];
}matkul;

typedef struct eklm *alamatekolom;
typedef struct eklm {
    matkul kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamtebaris;
typedef struct ebr {
    mahasiswa kontainer;
    eKolom *col;
    alamtebaris next;
}eBaris;

typedef struct {
    eBaris *first;
}list;

void createList(list *L) {
    (*L).first = NULL;
}

int countElementB(list L) {
    int hasil = 0;
    if(L.first != NULL) {
        /* list tidak kosong */ 
        eBaris* bantu;
        /* inisialisasi */
        bantu = L.first;

        while(bantu != NULL) {
            /* proses */
            hasil += 1;
            /* iterasi */
            bantu = bantu->next;
        }
    }

    return hasil;
}

int countElementK(eBaris L) {
    int hasil = 0;
    if(L.col != NULL) {
        /* list tidak kosong */
        eKolom *bantu;
        /* inisialisasi */
        bantu = L.col;

        while(bantu != NULL) {
            /* proses */
            hasil += 1;
            /* iterasi */
            bantu = bantu->next_kol;
        }
    }
    
    return hasil;
}

void addFirstB(char nim[], char nama[], list *L) {
    eBaris *baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->col = NULL;
    if((*L).first == NULL) {
        baru->next = NULL;
    }else {
        baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char kode[], char nilai[], eBaris *L) {
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.kode, kode);
    strcpy(baru->kontainer_kol.nilai, nilai);
    if((*L).col == NULL) {
        baru->next_kol = NULL;
    }else {
        baru->next_kol = (*L).col;
    }

    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris* prev, char nim[], char nama[]) {
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->col = NULL;
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom* prev, char kode[], char nilai[]) {
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.kode, kode);
    strpcy(baru->kontainer_kol.nilai, nilai);
    if(prev->next_kol == NULL) {
        baru->next_kol = NULL;
    }else {
        baru->next_kol = prev->next_kol;
    }

    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char nim[], char nama[], list *L) {
    if((*L).first == NULL) {
        
    }
}