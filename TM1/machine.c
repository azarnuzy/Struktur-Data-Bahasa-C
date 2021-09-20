#include "header.h"
/* 
*first sebagai penunjuk kepada elemen yang pertama
*next sebagai penunjuk dari elemen selanjutnya 
** nilai -1 berarti nilai kosong
** nilai -2 berarti elemen tersebut belum terpakai
 */
void createList(list *L) {
    (*L).first = -1;            
    int i;
    for(i=0; i<10; i++) {
        (*L).data[i].next = -2;
    }
}

/* 
*hasil sebagai nilai kembali dari elemen yang tersedia
*hitung sebagai kondisi pengecekan untuk banyaknya elemen
 */
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

/* 
*ketemu sebagai kondisi pengecekan jika ditemukan elemen yang kosong
 */
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

/* 
*baru sebagai index dari nilai yang akan disalin
 */
void addFirst(char merek[], char warna[], int ukuran, list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.merek, merek);
        strcpy((*L).data[baru].kontainer.warna, warna);
        (*L).data[baru].kontainer.ukuran = ukuran;
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

/* 
*prev sebagai index dari nilai sebelum ditambahkan nilai yang baru
 */
void addAfter(int prev, char merek[], char warna[], int ukuran, list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.merek, merek);
        strcpy((*L).data[baru].kontainer.warna, warna);
        (*L).data[baru].kontainer.ukuran = ukuran;
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

void addLast(char merek[], char warna[], int ukuran, list *L) {
    if((*L).first == -1) {
        addFirst(merek, warna, ukuran, L);
    }else{
        if(countElement(*L) < 10) {
            int prev = (*L).first;
            while((*L).data[prev].next != -1) {
                prev = (*L).data[prev].next;
            }
            addAfter(prev,merek,warna, ukuran, L);
        }else {
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

/* 
*hapus sebagai index untuk elemen yang dihapus
 */
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
        printf("List kosong\n");
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
        printf("List kosong\n");
    }
}

void printElement(list L) {
    if(L.first != -1) {
        int tunjuk = L.first;
        int i = 1;

        while(tunjuk != -1) {
            printf("%s %s %d\n", L.data[tunjuk].kontainer.merek, L.data[tunjuk].kontainer.warna, L.data[tunjuk].kontainer.ukuran);
            tunjuk = L.data[tunjuk].next;
            i++;
        }
        printf("========\n");
    }else {
        printf("List kosong\n");
        printf("========\n");
    }
}

void delAll(list *L) {
    int i;
    for(i=countElement(*L); i>=1; i--) {
        delLast(L);
    }
}
