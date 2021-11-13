#include "header.h"

void createEmpty(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q) {
    int hasil = 0;
    if(Q.first == NULL) {
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q) {
    int hasil = 0;
    if(Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;
        while(bantu != NULL) {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(char nim[], char nama[], queue *Q) {
    elemen *baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->next = NULL;
    if((*Q).first == NULL) {
        (*Q).first = baru;
    } else {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void addPriority(char nim[], char nama[], int priority, queue *Q) {
    elemen *baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->next = NULL;
    if((*Q).first == NULL) {
        (*Q).first = baru;
        (*Q).last = baru;
    } else {
        if(priority == 1) {
            baru->next = (*Q).first;
            (*Q).first = baru;
        } else if(priority > countElement(*Q)) {
            add(nim, nama, Q);
        } else {
            elemen *bantu = (*Q).first;
            int i = 1;
            while(bantu != NULL) {
                if(i == priority - 1) {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                bantu = bantu->next;
                i++;
            }
        }
    }
    baru = NULL;
}

/* void addPriority2(queue *Q, int number, bantuan data) 
{
    elemen *baru;
    baru = (elemen*)malloc(sizeof (elemen));

    strcpy(baru->kontainer.nama, data.nama);
    strcpy(baru->kontainer.kota, data.kota);
    baru->kontainer.noPrioritas = data.noPrioritas;
    strcpy(baru->kontainer.uang, data.uang);
    
    baru->next = NULL;

    if((*Q).first == NULL) {
        (*Q).first = baru;
        (*Q).last = baru;
    } else {
        if(number == 1) {
            baru->next = ((*Q).first);
            (Q)->first = baru;
        }else if(number > countElement(*Q)) {
            add(data, Q);
        }else {
            elemen *bantu = (*Q).first;
            int i = 1;
            int cek = 0;
            while(bantu != NULL && cek == 0) {
                if(i == number-1) {
                    baru->next = bantu->next;
                    bantu->next = baru;
                    cek = 1;
                }

                if(i == bantu->kontainer.noPrioritas) {
                    if(bantu->next->kontainer.noPrioritas < number) {
                        bantu = bantu->next;
                    }
                }
                i++;
            }
        }
    }
    baru = NULL;
} */

void del(queue *Q1, queue *Q2) {
    if((*Q1).first != NULL) {
        elemen *hapus = (*Q1).first;
        add(hapus->kontainer.nim, hapus->kontainer.nama, Q2);
        if(countElement(*Q1) == 1) {
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        } else {
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void printQueue(queue Q, char Queue[]) {
    printf("******************\n");
    printf("Queue %s\n", Queue);
    if(Q.first != NULL) {
        elemen *bantu = Q.first;
        int i = 1;
        while(bantu != NULL) {
            printf("%s %s\n", bantu->kontainer.nama, bantu->kontainer.nim);
            bantu = bantu->next;
            i++;
        }
    } else {
        printf("queue kosong\n");
    }
}