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

void addFirst(int a, int b, int c, list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));    
    baru->kontainer.a = a;
    baru->kontainer.b = b;
    baru->kontainer.c = c;
    if((*L).first == NULL) {
        baru -> next = NULL;
    }else {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* prev, int a, int b, int c, list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    baru->kontainer.a = a;
    baru->kontainer.b = b;
    baru->kontainer.c = c;
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(int a, int b, int c, list *L) {
    if((*L).first ==NULL) {
        addFirst(a, b, c, L);
    }else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev,a, b, c, L);
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
            int a,b,c;
            a = tunjuk->kontainer.a;
            b = tunjuk->kontainer.b;
            c = tunjuk->kontainer.c;
            if(a / 10 > 0) {
                printf("%d:",a);
            }else {
                printf("0%d:", a);
            }
            if(b / 10 > 0) {
                printf("%d:",b);
            }else {
                printf("0%d:", b);
            }
            if(c / 10 > 0) {
                printf("%d\n",c);
            }else {
                printf("0%d\n", c);
            }
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
                int a,b,c;
                int x,y,z;
                a = tunjuk->kontainer.a;
                b = tunjuk->kontainer.b;
                c = tunjuk->kontainer.c;
                int sum1 = a * 3600 + b * 60 + c;
                x = tunjuk2->kontainer.a;
                y = tunjuk2->kontainer.b;
                z = tunjuk2->kontainer.c;
                int sum2 = x * 3600 + y * 60 + z;
                if(sum1 > sum2) {
                    swap(tunjuk, tunjuk2);
                }
                tunjuk2 = tunjuk2->next;
            }
        }

        tunjuk = tunjuk->next;
    }
}