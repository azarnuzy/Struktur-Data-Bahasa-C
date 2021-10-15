#include "header.h"

void createList (list *L) {
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

void addFirst(float angka, list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    baru->kontainer.angka = angka;
    if((*L).first == NULL) {
        baru -> next = NULL;
    }else {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* prev, float angka, list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    baru->kontainer.angka = angka;
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(float angka, list *L) {
    if((*L).first ==NULL) {
        addFirst(angka, L);
    }else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev,angka, L);
    }
}

void delFirst(list *L) {
    if((*L).first != NULL) {
        elemen* hapus = (*L).first;
        if(countElement(*L) == 1) {
            (*L).first = NULL;
        }else {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* prev, list *L) {
    elemen* hapus = prev->next;
    if(hapus != NULL) {
        if(hapus->next ==NULL) {
            prev->next = NULL;
        }else {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delLast(list *L) {
    if((*L).first != NULL) {
        if(countElement(*L) == 1) {
            delFirst(L);
        }else {
            elemen* last = (*L).first;
            elemen* prev;

            while(last->next != NULL) {
                prev = last;
                last = last->next;
            }
            delAfter(prev,L);
        }
    }
}

void printElement(list L) {
    if(L.first != NULL) {
        elemen* tunjuk = L.first;
        int i = 1;

        while(tunjuk != NULL) {
            printf("%.2f\n",tunjuk->kontainer.angka);
            tunjuk = tunjuk->next;
            i++;
        }
    }else {
        printf("list kosong\n");
    }
}

void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for(i=countElement(*L); i>=1; i--) {
            delLast(L);
        }
    }
}

void swap(elemen* a, elemen* b ) {
    stringHuruf temp = a->kontainer;
    a->kontainer = b->kontainer;
    b->kontainer = temp;
}

void sortingList(list *L) {
    elemen *tunjuk = L->first;
    while(tunjuk != NULL) {
        elemen* tunjuk2 = tunjuk->next;
        if(tunjuk2 != NULL) {
            while(tunjuk2 != NULL) {
                int bil1, bil2;
                int bagi1, bagi2;
                bil1 = (tunjuk->kontainer.angka * 100); 
                bagi1 = bil1 / 100;
                bil1 = bil1 % (bagi1 * 100);
                bil2 = (tunjuk2->kontainer.angka * 100); 
                bagi2 = bil2 / 100;
                bil2 = bil2 % (bagi2 * 100);
                if(bil1 > bil2) {
                    swap(tunjuk, tunjuk2);
                }
                tunjuk2 = tunjuk2->next;
            }
        }

        tunjuk = tunjuk->next;
    }
}