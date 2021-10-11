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

    for(i=0; i<100; i++) {
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
        while(bantu != -1) {         //perulangan untuk menghitung banyaknya element
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

    if(countElement(L) < 100) {
        int ketemu = 0;

        int i = 0;
        while((ketemu == 0) && (i < 10)) {  //perulangan untuk mengecek elemen yang belum terpakai 
            if(L.data[i].next == -2) {  //kondisi jika terdapat elemen belum terpakai
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
void addFirst(char kata[], list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        //memasukan nilai dari input
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
void addAfter(int before, char kata[], list *L) {
    if(countElement(*L) < 10) {
        int baru = emptyElement(*L);
        //memasukan nilai dari input
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

/* 
*bantuawal sebagai variabel untuk menampung list awal
*bantuAkhir sebagai variabel untuk menampung list akhir
*spacefirst seabgai variabel untuk menampung banyaknya spasi pada setiap baris
*temp1, temp2 sebagai variabel untuk menampung list awal dan akhir lebih 1 langkah di depan
 */
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