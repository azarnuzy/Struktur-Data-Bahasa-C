#include<stdio.h>


typedef struct {
    float nilai;
}baris;

typedef struct {
    baris kontainer;
    int next;
}elemen;

typedef struct{
    int first;
    elemen data[100];
}list;

void createList(list *L) {
    (*L).first = -1;
    int i;
    for(i=0; i<100; i++) {
        (*L).data[i].next = -2;
    }
}

int countElement(list L) {
    int hasil = 0;
    if(L.first != -1) {
        int hitung;
        hitung = L.first;
        while(hitung != -1) {
            hasil  += 1;
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

int emptyElement(list L) {
    int hasil = -1;
    if(countElement(L) < 100) {
        int ketemu = 0;
        int i = 0;
        while(ketemu == 0 && i < 100) {
            if(L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            }else {
                i += 1;
            }
        }
    }
    return hasil;
}


void addFirst(float nilai, list *L) {
    if(countElement(*L) < 100) {
        int baru = emptyElement(*L);
        (*L).data[baru].kontainer.nilai = nilai;
        if((*L).first == -1){
            (*L).data[baru].next = -1;
        }else {
            (*L).data[baru].next = (*L).first;
        }
        (*L).first = baru;
    }else {
        printf("sudah tidak dapat ditambah\n");
    }
} 

void printElement(list L) {
    if(L.first != -1) {
        int tunjuk = L.first;
        int i = 1;

        while(tunjuk != -1) {
            printf("elemen ke: %d\n", i);
            printf("%.2f\n", L.data[tunjuk].kontainer.nilai);
            printf("next: %d\n", L.data[tunjuk].next);
            printf("----------------\n");
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    }else {
        printf("list kosong\n");
    }
}

int main(int argc, char const *argv[])
{
    int n;
    list L;

    createList(&L);
    scanf("%d", &n);
    int i;
    float nilai;
    for(i=0; i<n; i++) {
        scanf("%f", &nilai);
        addFirst(nilai, &L);
    }

    printElement(L);
    return 0;
}
