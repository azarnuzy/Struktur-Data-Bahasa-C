#include <stdio.h>
#include <string.h>

typedef struct{
    char kata[50];
}polaString;

typedef struct {
    polaString kontainer;
    int prev;
    int next;
}elemen;

typedef struct {
    int first;
    int tail;
    elemen data[100];
}list;

void createList(list *L) {
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for(i=0; i<100; i++) {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int countElement(list L) {
    int hasil = 0;
    if(L.first != -1) {
        /* list tidak kosong */
        int bantu;
        
        /* inisialisasi */
        bantu = L.first;
        while(bantu != -1) {
            /* proses */
            hasil += 1;

            /* iterasi */
            bantu = L.data[bantu].next;
        }
    }

    return hasil;
}

int emptyElement(list L) {
    int hasil = -1;

    if(countElement(L) < 100) {
        int ketemu = 0;

        int i = 0;
        while((ketemu == 0) && (i < 10)) {
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

void addFirst(char kata[], list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kata, kata);

        if((*L).first == -1) {
            /* jika list kosong */
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }else {
            /* jika list tidak kosong */
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }

        (*L).first = baru;
    }else {
        /* proses jika array penuh */
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char kata[], list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kata, kata);

        if((*L).data[before].next != -1) {
            /* jika baru bukan menjadi elemen terakhir */
            (*L).data[baru].prev = before;
            (*L).data[baru].next = (*L).data[before].next;
            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].prev = baru;
        }else {
            /* jika baru menajdi elemen terakhir */
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    }else {
        /* proses jika array penuh */
        printf("sudah tidak dapat ditambah\n");
    }
}

void addLast(char kata[], list *L) {
    if((*L).first == -1) {
        /* proses jika list masih kosong */
        addFirst(kata, L);
    }else {
        /* prses jika list telah berisi elemen */
        addAfter((*L).tail, kata, L);
    }
}

void printElement(list L) {

    if(L.first != -1) {
        /* inisialisasi */
        int bantu = L.first;
        int i = 1;
        while(bantu != -1) {
            /* proses */
            printf("%s\n", L.data[bantu].kontainer.kata);
            bantu = L.data[bantu].next;
            i++;
        }
    }else {
        /* proses jika List kosong */
        printf("List kosong\n");
    }

    printf("========\n");
}

void polaList2(list L, int n) {
    int i,j;

    int bantuAwal = L.first;
    int bantuAkhir = L.tail;
    int spaceFirst = 0;
    for(i=0; i<n; i++) {
        int temp1 = L.data[bantuAwal].next;
        int temp2 = L.data[bantuAkhir].prev;
        int count = 0;
        for(j=0; j<spaceFirst; j++) {
            printf(" ");
        }
        spaceFirst += strlen(L.data[bantuAkhir].kontainer.kata);
        
        printf("%s", L.data[bantuAkhir].kontainer.kata);
        for(j = i+1; j<n; j++) {
            count += strlen(L.data[temp1].kontainer.kata) + strlen(L.data[temp2].kontainer.kata);
            temp1 = L.data[temp1].next;
            temp2 = L.data[temp2].prev;
        }

        for(j=0; j<count; j++) {
            printf(" ");
        }
        
        printf("%s\n", L.data[bantuAwal].kontainer.kata);
        bantuAwal = L.data[bantuAwal].next;
        bantuAkhir = L.data[bantuAkhir].prev;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    list L1;
    createList(&L1);
    scanf("%d", &n);
    int i;
    char kata[50];
    for(i=0; i<n; i++) {
        scanf("%s", kata);
        addLast(kata, &L1);
    }

    if(n % 2 == 1) {
        n += 1;
    }
    n /= 2;
    polaList2(L1, n);

    return 0;
}
