#include "header.h"

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

void addFirst (char nama[], list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);

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

void addAfter(elemen* before, char nama[], list *L) {
    if(before != NULL) {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        strcpy(baru->kontainer.nama, nama);

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

void addLast (char nama[], list *L) {
    if((*L).first == NULL) {
        /* jika list adalah list kosong */
        addFirst(nama, L);
    }else {
        /* jika list tidak kosong */
        addAfter((*L).tail, nama, L);
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
        //kondisi jika yang dihapus paling belakang dan jika yang dihapus di tengah
        if(hapus != NULL) {
            if(hapus->next == NULL) {
                before->next = NULL;
                (*L).tail = before;
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
            delFirst(L);
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
        elemen* bantuZ = L.tail;
        int space = 0;
        while(bantu != NULL) {
            for(int i=0; i<space; i++) {
                printf(" ");
            }
            printf("%s %s\n", bantu->kontainer.nama, bantuZ->kontainer.nama);
            space += strlen(bantu->kontainer.nama);
            bantuZ = bantuZ->prev;
            bantu = bantu->next;
        }
    }else {
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

void swapDawala(list *L) {
    int len = countElement(*L);
    int i;
    elemen* tengah;
    elemen* tunjuk = L->first;
    for(i=0; i<len; i++) {
        if(len / 2 == i) {
            tengah = tunjuk;
        }
        tunjuk = tunjuk->next;
    }
    elemen* temp;
    tunjuk = L->first;
    int cek = 0;
    while(cek == 0 ) {
        if(strcmp(tunjuk->kontainer.nama, "dawala") == 0) {
            if(len % 2 == 0) {
                addAfter(tengah->prev->prev, tunjuk->kontainer.nama, L);
            }else {
                addAfter(tengah->prev->prev, tunjuk->kontainer.nama, L);
            }
            delAfter(tunjuk->prev, L);
            cek = 1;
        }
        tunjuk = tunjuk->next;
    }

}