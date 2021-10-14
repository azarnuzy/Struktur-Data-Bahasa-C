#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
    int harga;
    int kode;
}PC;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    PC kontainer;
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

void swap(elemen* x, elemen* y) {
    PC temp = x->kontainer;
    x->kontainer = y->kontainer;
    y->kontainer = temp;
}

void multiDynamicSortingList(list *L, char metode1[], char metode2[]) {
    elemen *tunjuk1 = L->first, *tunjuk2;
    for(tunjuk1 = L->first; tunjuk1 != NULL;tunjuk1 =  tunjuk1 -> next) {
        for(tunjuk2 = tunjuk1 -> next; tunjuk2 != NULL;tunjuk2 =  tunjuk2 -> next) {
            if(strcmp(metode1, "H") == 0) {
                if(strcmp(metode2, "Asc") == 0) {
                    if(tunjuk1->kontainer.harga > tunjuk2->kontainer.harga) {
                        swap(tunjuk1, tunjuk2);
                    }
                }else {
                    if(tunjuk1->kontainer.harga < tunjuk2->kontainer.harga) {
                        swap(tunjuk1, tunjuk2);
                    }
                }
            }else {
                if(strcmp(metode2, "Asc") == 0) {
                    if(tunjuk1->kontainer.kode > tunjuk2->kontainer.kode) {
                        swap(tunjuk1, tunjuk2);
                    }
                }else {
                    if(tunjuk1->kontainer.kode < tunjuk2->kontainer.kode) {
                        swap(tunjuk1, tunjuk2);
                    }
                }
            }
        
        }
    }
}

void addFirst (char nama[], int harga, int kode, list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;
    baru->kontainer.kode = kode;

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

void addAfter(elemen* before, char nama[], int harga, int kode, list *L) {
    if(before != NULL) {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.harga = harga;
        baru->kontainer.kode = kode;

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

void addLast (char nama[], int harga, int kode, list *L) {
    if((*L).first == NULL) {
        /* jika list adalah list kosong */
        addFirst(nama, harga, kode, L);
    }else {
        /* jika list tidak kosong */
        addAfter((*L).tail, nama, harga, kode, L);
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

void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for(i = countElement(*L); i>= 1; i--) {
            /* proses menghapus elemen list */
            delLast(L);
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
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.harga, bantu->kontainer.kode);
            bantu = bantu->next;
            i++;
        }
    }else {
        /* proses jika list kosong */
        printf("=================\n");
        printf(" Loh kok gaada:(\n");
        printf("=================\n");
    }
}
int main(int argc, char const *argv[])
{
    list L;
    char nama[50];
    int harga, kode;
    char metode1[10], metode2[10];

    createList(&L);

    do {
        scanf("%s", &nama);
        if(strcmp(nama, "---") != 0) {
            scanf("%d %d", &harga, &kode);
            if(kode % 2 != 1) {
                addLast(nama, harga, kode, &L);
            }
        }
    }while(strcmp(nama, "---") != 0);

    scanf("%s %s", &metode1, &metode2);

    if(countElement(L) > 0) {
        multiDynamicSortingList(&L, metode1, metode2);
    }

    printElement(L);
    return 0;
}
