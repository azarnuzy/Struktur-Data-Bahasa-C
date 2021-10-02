#include "header.h"

/* 
*first sebagai penunjuk kepada elemen yang pertama
*next sebagai penunjuk dari elemen selanjutnya 
*NULL sebagai nilai awal dari first
 */
void createList(list *L) {
    (*L).first = NULL;
}

/* 
*hasil sebagai nilai kembali dari elemen yang tersedia
*tunjuk sebagai kondisi pengecekan untuk banyaknya elemen
 */
int countElement(list L) {
    int hasil = 0;
    if(L.first != NULL) {
        elemen* tunjuk;
        tunjuk = L.first;
        while(tunjuk != NULL) {     //perulangan untuk menghitung banyaknya element
            hasil += 1;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

/* 
*ketemu sebagai kondisi pengecekan jika ditemukan elemen yang kosong
*baru sebagai pointer bertipe elemen dan beralokasikan memory dan di paksa menjadi pointer melalui casting dari memory alokasi elemen
 */
void addFirst(char nama[], int harga, float rating, list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru -> kontainer.nama, nama);
    baru -> kontainer.rating = rating;
    baru -> kontainer.harga = harga;
    //kondisi untuk penambahan dengan kondisi list kosong dan banyak elemen
    if((*L).first == NULL) {
        baru -> next = NULL;
    }else {
        baru->next = (*L).first;
    }
    //menjadikan first sebagai nilai baru
    (*L).first = baru;
    baru = NULL;
}

/* 
*prev sebagai index dari nilai sebelum ditambahkan nilai yang baru
 */
void addAfter(elemen* prev, char nama[], int harga, float rating, list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru -> kontainer.nama, nama);
    baru -> kontainer.rating = rating;
    baru -> kontainer.harga = harga;
    //kondisi  dari elemen sebelum adalah terakhir dan elemen sebelum di tengah
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(char nama[], int harga, float rating, list *L) {
    //kondisi jika list kosongdan jika list tidak kosong
    if((*L).first ==NULL) {
        addFirst(nama,harga, rating, L);
    }else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev,nama, harga,rating,L);
    }
}

/* 
* posisi nilai untuk menunjukan pada posisi mana elemen tersebut sedang dibandingkan
* cek sebagai nilai untuk pembatalan looping pada list baru
 */
void sortDinamyc(list L1, list *L2, char urutanMenu[]) {
    elemen* tunjuk1 = L1.first;
    elemen* prev;
    /* memasukan nilai awal ke list baru */
    addFirst(tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);
    /* menggeser penunjuk ke elemen berikutnya */
    tunjuk1 = tunjuk1 -> next;
    /* perulangan untuk list masukan */
    while(tunjuk1 != NULL) {

        int posisi = 1;
        int cek = 0;
        elemen* tunjuk2 = (*L2).first;

        prev = (*L2).first;
        /* perulangan untuk list baru */
        while(tunjuk2 != NULL && cek == 0) {
            /* 
            * kondisi pertama menunjukan bahwa nilai yang paling kecil akan dimasukan ke paling awal list
            * kondisi kedua menunjukan bahwa nilai yang kecil tetapi berada di tengah2 nilai akan dimasukan ke tengah list baru
            * kondisi ketiga nilai paling besar akan dimasukan di akhir list
             */
            /* kondisi untuk urutan secara ascending */
            if(strcmp(urutanMenu, "asc") == 0) {
                if(tunjuk1 -> kontainer.rating < tunjuk2 -> kontainer.rating && posisi == 1) {
                    addFirst(tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);
                    cek = 1;
                }else if(tunjuk1 -> kontainer.rating < tunjuk2 -> kontainer.rating && posisi <= countElement(*L2) ) {
                    addAfter(prev, tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);
                    cek = 1;
                }else if(tunjuk1 -> kontainer.rating > tunjuk2 -> kontainer.rating && posisi == countElement(*L2)  ) {
                    addLast(tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);
                    cek = 1;
                }
            }
            /* kondisi untuk urutan secara descending */
            else {
                if(tunjuk1 -> kontainer.rating > tunjuk2 -> kontainer.rating && posisi == 1) {
                    addFirst(tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);
                    cek = 1;
                }else if(tunjuk1 -> kontainer.rating > tunjuk2 -> kontainer.rating && posisi <= countElement(*L2) ) {
                    addAfter(prev, tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);
                    cek = 1;
                }else if(tunjuk1 -> kontainer.rating < tunjuk2 -> kontainer.rating && posisi == countElement(*L2)  ) {
                    addLast(tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);
                    cek = 1;
                }
            }

            if(posisi > 1) {
                /* sebagai penunjuk untuk elemen yang akan dimasukan di tengah list */
                prev = prev -> next;
            }
                posisi++;
            tunjuk2 = tunjuk2 -> next;
        } 
        tunjuk1 = tunjuk1 -> next;
    }
}

void delFirst(list *L) {
    //kondisi jika terdapat satu elemen dan jika banyak elemen
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
    //kondisi jika yang dihapus paling belakang dan jika yang dihapus di tengah
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
    //kondisi jika banyak elemen dan jika hanya satu elemen
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

void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for(i=countElement(*L); i>=1; i--) {
            //proses menghapus elemen list
            delLast(L);
        }
    }
}

int dapatDibeli(list *L, int banyakUang) {
    elemen* tunjuk;
    tunjuk = (*L).first;

    /* kondisi jika banyak uang kurang dari harga makanan */
    if(banyakUang > tunjuk -> kontainer.harga) {    
        while(tunjuk != NULL) {     // perulangan untuk list
            /* kondisi untuk pengurangan banyakuang dengan harga makanan */
            if(banyakUang >= tunjuk -> kontainer.harga) {
                banyakUang -= tunjuk -> kontainer.harga;
            }
            /* kondisi untuk mengurangi satu persatu makanan yang tidak cukup dibayar */
            else {
                delLast(L);
            }
            tunjuk = tunjuk -> next;
        }
    }else {
        delAll(L);
    }

    delLast(L);
    return banyakUang;
}


void printElement(list L) {
    if(L.first != NULL) {
        elemen* tunjuk = L.first;
        int i = 1;

        while(tunjuk != NULL) {
            printf("%s %d %.1f\n", tunjuk->kontainer.nama, tunjuk-> kontainer.harga, tunjuk->kontainer.rating);
            tunjuk = tunjuk->next;
            i++;
        }
    }else {
        printf("list kosong\n");
    }

}

