#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatkul;

typedef struct 
{
    nilaiMatkul kontainer;
    int next;
}elemen;

typedef struct{
    int first;
    elemen data[10];
}list;

void createList(list *L) {
    (*L).first = -1;
    int i;
    for(i=0; i<10; i++) {
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
    if(countElement(L) < 10) {
        int ketemu = 0;
        int i = 0;
        while(ketemu == 0 && i < 10) {
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

void addFirst(char nim[], char nama[], char nilai[], list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);
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

void addAfter(int prev, char nim[], char nama[], char nilai[], list *L) {
    if(countElement(*L) < 10) {
        printf("%d %d\n", countElement(*L), emptyElement(*L));
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);
        
        if((*L).data[prev].next == -1) {
            (*L).data[baru].next = -1;
        }else{
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    }else {
        printf("sudah tidak dapat ditambah\n");
    }
}

void addLast(char nim[], char nama[], char nilai[], list *L) {
    if((*L).first == -1) {
        addFirst(nim, nama, nilai, L);
    }else{
        if(countElement(*L) < 10) {
            int prev = (*L).first;
            while((*L).data[prev].next != -1) {
                prev = (*L).data[prev].next;
            }
            addAfter(prev,nim,nama, nilai, L);
        }else {
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

void delFirst(list *L) {
    if((*L).first != -1) {
        int hapus = (*L).first;
        if(countElement(*L) == 1) {
            (*L).first = -1;
        }else{
            (*L).first = (*L).data[hapus].next;
        }

        (*L).data[hapus].next = -2;
    }else {
        printf("list kosong\n");
    }
}

void delAfter(int prev, list *L) {
    int hapus = (*L).data[prev].next;
    if(hapus != -1) {
        if((*L).data[hapus].next == -1) {
            (*L).data[prev].next = -1;
        }else {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L) {
    if((*L).first != -1) {
        if(countElement(*L) == 1) {
            delFirst(L);
        }else {
            int hapus = (*L).first;
            int prev;

            while((*L).data[hapus].next != -1) {
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }

            delAfter(prev, L);
        }
    }else {
        printf("list kosong\n");
    }
}

void printElement(list L) {
    if(L.first != -1) {
        int tunjuk = L.first;
        int i = 1;

        while(tunjuk != -1) {
            printf("elemen ke: %d\n", i);
            printf("nim: %s\n", L.data[tunjuk].kontainer.nim);
            printf("nama: %s\n", L.data[tunjuk].kontainer.nama);
            printf("nilai: %s\n", L.data[tunjuk].kontainer.nilai);
            printf("next: %d\n", L.data[tunjuk].next);
            printf("----------------\n");
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    }else {
        printf("list kosong\n");
    }
}

void delAll(list *L) {
    int i;
    for(i=countElement(*L); i>=1; i--) {
        delLast(L);
    }
}

int main(int argc, char const *argv[])
{
    list L;
    createList(&L);
    printElement(L);
    printf("=============\n");
    addFirst("1", "Orang_1", "A", &L);
    addAfter(L.first, "2", "Orang_2", "A", &L);
    addLast("3", "Orang_3", "A", &L);
    printElement(L);
    printf("==============\n");
    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);
    printf("===============\n");
    return 0;
}
