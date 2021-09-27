#include "header.h"

/* 
*first sebagai penunjuk kepada elemen yang pertama
*tail sebagai penunjuk kepada elemen yang diakhir
*next sebagai penunjuk dari elemen selanjutnya 
*prev sebagai penunjuk dari elemen sebelumnya
**nilai -1 berarti nilai kosong
**nilai -2 berarti elemen tersebut belum terpakai
 */
void createList(list *L) {
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for(i=0; i<10; i++) {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

/* 
*hasil sebagai nilai kembali dari elemen yang tersedia di dalam list
*bantu sebagai kondisi dari banyaknya elemen yang ada pada list
 */
int countElement(list L) {
    int hasil = 0;
    if(L.first != -1) {
        /* list tidak kosong */
        int bantu;
        
        /* inisialisasi */
        bantu = L.first;
        while(bantu != -1) {        //perulangan untuk menghitung banyaknya element
            /* proses */
            hasil += 1;

            /* iterasi */
            bantu = L.data[bantu].next;
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
        while((ketemu == 0) && (i < 10)) {      //perulangan untuk mengecek elemen yang belum terpakai 
            if(L.data[i].next == -2) {      //kondisi jika terdapat elemen belum terpakai
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
*baru sebagai nilai untuk memasukan ke elemen yang belum terpakai
 */
void addFirst(char merek[], char tipe[], int jumlah, list *L) {

    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        //memasukan nilai dari input
        strcpy((*L).data[baru].kontainer.merek, merek);
        strcpy((*L).data[baru].kontainer.tipe, tipe);
        (*L).data[baru].kontainer.jumlah = jumlah;

        if((*L).first == -1) {
            /* jika List kosong */
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }else {
            /* jika list tidak kosong */
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }
        //menjadikan first di nilai yang baru
        (*L).first = baru;
    }else {
        /* proses jika array penuh */
        printf("sudah tidak dapat ditambah\n");
    }
}

/* 
*before sebagai nilai elemen yang di tunjuk oleh prev yaitu elemen sebelumnya
 */
void addAfter(int before, char merek[], char tipe[], int jumlah, list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        //memasukan nilai dari input
        strcpy((*L).data[baru].kontainer.merek, merek);
        strcpy((*L).data[baru].kontainer.tipe, tipe);
        (*L).data[baru].kontainer.jumlah = jumlah;

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

void addLast(char merek[], char tipe[], int jumlah, list *L) {
    if((*L).first == -1) {
        /* proses jika list masih kosong */
        addFirst(merek, tipe, jumlah, L);
    }else {
        /* prses jika list telah berisi elemen */
        addAfter((*L).tail, merek, tipe, jumlah, L);
    }
}

/* 
*hapus sebagai index untuk elemen yang dihapus
 */
void delFirst(list *L) {
    if((*L).first != -1) {
        int hapus = (*L).first;
        //kondisi jika terdapat satu elemen dan banyak elemen
        if(countElement(*L) == 1) {
            (*L).first = -1;
            (*L).tail = -1;
        }else {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        /* pengosongan elemen */
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }else {
        /* proses jika List kosong */
        printf("List kosong\n");
    }
}

void delAfter(int before, list *L) {
    int hapus = (*L).data[before].next;
    /* kondisi jika yang dihapus di tengah dan paling belakang */
    if(hapus != -1) {
        if((*L).data[hapus].next == -1) {
            (*L).tail = before;
            (*L).data[before].next = -1;
        }else {
            (*L).data[before].next = (*L).data[hapus].next;
            (*L).data[(*L).data[hapus].next].prev = before;
        }
        /* pengosongan elemen */
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L) {
    if((*L).first != -1) {
        if(countElement(*L) == 1) {
            /* proses jika list hanya berisi satu elemen */
            delFirst(L);
        }else {
            /* elemen sebelum elemen terakhir menjadi elemen terakhir */
            delAfter((*L).data[(*L).tail].prev, L);
        }
    }else {
        /* proses jika List kosong */
        printf("List kosong\n");
    }
}

void printElement(list L) {

    if(L.first != -1) {
        /* inisialisasi */
        int bantu = L.first;
        int i = 1;
        while(bantu != -1) {
            /* proses */
            printf("%s %s %d\n", L.data[bantu].kontainer.merek, L.data[bantu].kontainer.tipe, L.data[bantu].kontainer.jumlah);
            bantu = L.data[bantu].next;
            i++;
        }
    }else {
        /* proses jika List kosong */
        printf("List kosong\n");
    }

    printf("========\n");
}

void printReverse(list L) {

    if(L.first != -1) {
        /* inisialisasi */
        int bantu = L.tail;
        int i = 1;
        while(bantu != -1) {
            /* proses */
            printf("%s %s %d\n", L.data[bantu].kontainer.merek, L.data[bantu].kontainer.tipe, L.data[bantu].kontainer.jumlah);
            bantu = L.data[bantu].prev;
            i++;
        }
    }else {
        /* proses jika List kosong */
        printf("List kosong\n");
    }

    printf("========\n");
}

void delAll(list *L) {
    int i;
    for(i = countElement(*L); i>= 1; i--) {
        /* proses menghapus elemen list */
        delLast(L);
    }
}
