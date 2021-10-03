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

int countElement (list L) {
    int hasil = 0;
    if(L.first != NULL) {
        /* list tidak kosong */
        elemen* bantu;

        /* inisialisasi */
        bantu = L.first;

        while (bantu != NULL) {
            /* proses */
            hasil = hasil + 1;
            /* iterasi */
            bantu = bantu -> next;
        }
    }

    return hasil;
}

void addFirst (char nim[], char nama[], char nilai[], list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    if((*L).first == NULL) {
        baru->prev = NULL;
        baru->next = NULL;
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

        if(before->next == NULL) {
            baru->next = NULL;
            (*L).tail = baru;
        }else {
            baru->next = before->next;
            baru->next->prev = baru;
        }

        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addLast (char nim[], char nama[], char nilai[], list *L) {
    if((*L).first == NULL) {
        /* jika list adalah list kosong */
        addFirst(nim, nama, nilai, L);
    }else {
        /* jika list tidak kosong */
        addAfter((*L).tail, nim, nama, nilai, L);
    }
}

void delFirst (list *L) {
    if((*L).first != NULL) {
        elemen* hapus = (*L).first;
        if(countElement(*L) == 1) {
            (*L).first = NULL;
            (*L).tail = NULL;
        }else {
            (*L).first = (*L).first -> next;
            (*L).first -> prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* before, list *L) {
    if(before != NULL) {
        elemen* hapus = before->next;
        if(hapus != NULL) {
            if(hapus->next == NULL) {
                before->next = NULL;
            }else {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }

            hapus->prev = NULL;
            free(hapus);
        }
    }
}

void delLast (list *L) {
    if((*L).first != NULL) {
        /* jika list tidak kosong */
        if(countElement(*L) == 1) {
            /* list terdiri dari satu elemen */
        }else {
            /* jika list terdiri dari banyak elemen */
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElement(list L) {
    if(L.first != NULL) {
        /* inisialisasi */
        elemen* bantu = L.first;
        int i = 1;
        while(bantu != NULL) {
            /* proses */
            printf("elemen ke: %d\n", i);
            printf("nim: %s\n", bantu->kontainer.nim);
            printf("nama: %s\n", bantu->kontainer.nama);
            printf("nilai: %s\n", bantu->kontainer.nilai);
            printf("----------------\n");

            bantu = bantu->next;
            i++;
        }
    }else {
        /* proses jika list kosong */
        printf("list kosong\n");
    }
}

void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for(i = countElement(*L); i>= 1; i--) {
            /* proses menghapus elemen list */
            delLast(L);
        }
    }
}

int main() {
    list L;
    createList(&L);
    printElement(L);
    printf("=============\n");

    addFirst("1", "Orang_1", "A", &L);
    addAfter(L.first, "2", "Orang_2", "A", &L);
    addLast("3", "Orang_3", "A", &L);
    printElement(L);
    printf("============\n");

    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);

    printf("============\n");

    return 0;
}