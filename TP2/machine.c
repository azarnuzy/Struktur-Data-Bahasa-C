#include "header.h"

/* 
*first sebagai penunjuk kepada elemen yang pertama
*tail sebagai penunjuk kepada elemen paling akhir
*next sebagai penunjuk dari elemen selanjutnya 
*NULL sebagai nilai awal dari first
 */
void createList (list *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
}

/* 
*hasil sebagai nilai kembali dari elemen yang tersedia di dalam list
*bantu sebagai kondisi dari banyaknya elemen yang ada pada list
 */
int countElement (list L) {
    int hasil = 0;
    if(L.first != NULL) {
        /* list tidak kosong */
        elemen* bantu;

        /* inisialisasi */
        bantu = L.first;

        while (bantu != NULL) {     //perulangan untuk menghitung banyaknya element
            /* proses */
            hasil = hasil + 1;
            /* iterasi */
            bantu = bantu -> next;
        }
    }

    return hasil;
}

/* 
*temp sebagai variabel untuk menampung nilai sementara dari kontainer x (kotnainer yang akan ditukar)
*x dan y = kontainer yang akan dilakukan pertukaran 
 */
void swap(elemen* x, elemen* y) {
    PC temp = x->kontainer;
    x->kontainer = y->kontainer;
    y->kontainer = temp;
}

/* 
*metode1 = pengurutan dilihat dari harga atau kode barang
*metode2 = pengurutan dilihat dari yang terbesar atau terkecil
*tunjuk1 = sebagai variabel untuk menunjuk list pada perulangan pertama
*tunjuk2 = sebagai variabel untuk menunjuk list pada perulangan yang kedua
 */
void multiDynamicSortingList(list *L, char metode1[], char metode2[]) {
    elemen *tunjuk1 = L->first, *tunjuk2;
    //perulangan pada list dimulai dari awal
    for(tunjuk1 = L->first; tunjuk1 != NULL;tunjuk1 =  tunjuk1 -> next) {
        //perulangan pada list dimulai dari tunjuk1 sebagai awal
        for(tunjuk2 = tunjuk1 -> next; tunjuk2 != NULL;tunjuk2 =  tunjuk2 -> next) {
            /* 
            *pengkondisian jika pengurutan dilakukan dengan melihat Harga atau kode
            *pengkondisian jika pengurutan dilakukan dengan ascending atau descending
             */
            if(strcmp(metode1, "H") == 0) {
                if(strcmp(metode2, "Asc") == 0) {
                    if(tunjuk1->kontainer.harga > tunjuk2->kontainer.harga) {
                        swap(tunjuk1, tunjuk2);
                    }
                }else {
                    if(tunjuk1->kontainer.harga < tunjuk2->kontainer.harga) {
                        swap(tunjuk1, tunjuk2);
                    }
                }
            }else {
                if(strcmp(metode2, "Asc") == 0) {
                    if(tunjuk1->kontainer.kode > tunjuk2->kontainer.kode) {
                        swap(tunjuk1, tunjuk2);
                    }
                }else {
                    if(tunjuk1->kontainer.kode < tunjuk2->kontainer.kode) {
                        swap(tunjuk1, tunjuk2);
                    }
                }
            }
        
        }
    }
}
/* 
*baru sebagai pointer bertipe elemen dan beralokasikan memory dan di paksa menjadi pointer melalui casting dari memory alokasi elemen
 */
void addFirst (char nama[], int harga, int kode, list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;
    baru->kontainer.kode = kode;
    //kondisi untuk penambahan dengan kondisi list kosong dan banyak elemen
    if((*L).first == NULL) {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }else {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    //menjadikan first sebagai nilai baru
    (*L).first = baru;
    baru = NULL;
}

/* =
*prev sebagai index dari nilai sebelum ditambahkan nilai yang baru
*before sebagai elemen yang terletak sebelum elemen baru ditambahkan
 */
void addAfter(elemen* before, char nama[], int harga, int kode, list *L) {
    if(before != NULL) {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        //memasukan nilai dari input
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.harga = harga;
        baru->kontainer.kode = kode;
        //kondisi  dari elemen sebelum adalah terakhir dan elemen sebelum di tengah
        if(before->next == NULL) {
            baru->next = NULL;
            (*L).tail = baru;
        }else {
            baru->next = before->next;
            baru->next->prev = baru;
        }

        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addLast (char nama[], int harga, int kode, list *L) {
    if((*L).first == NULL) {
        /* jika list adalah list kosong */
        addFirst(nama, harga, kode, L);
    }else {
        /* jika list tidak kosong */
        addAfter((*L).tail, nama, harga, kode, L);
    }
}
/* 
*hapus sebagai index untuk elemen yang dihapus
 */
void delFirst (list *L) {
    //kondisi jika terdapat satu elemen dan jika banyak elemen
    if((*L).first != NULL) {
        elemen* hapus = (*L).first;
        if(countElement(*L) == 1) {
            (*L).first = NULL;
            (*L).tail = NULL;
        }else {
            (*L).first = (*L).first -> next;
            (*L).first -> prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* before, list *L) {
    if(before != NULL) {
        elemen* hapus = before->next;
        //kondisi jika yang dihapus paling belakang dan jika yang dihapus di tengah
        if(hapus != NULL) {
            if(hapus->next == NULL) {
                before->next = NULL;
            }else {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }

            hapus->prev = NULL;
            free(hapus);
        }
    }
}

void delLast (list *L) {
    if((*L).first != NULL) {
        /* jika list tidak kosong */
        if(countElement(*L) == 1) {
            /* list terdiri dari satu elemen */
        }else {
            /* jika list terdiri dari banyak elemen */
            delAfter((*L).tail->prev, L);
        }
    }
}

void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for(i = countElement(*L); i>= 1; i--) {
            /* proses menghapus elemen list */
            delLast(L);
        }
    }
}

void printElement(list L) {
    if(L.first != NULL) {
        /* inisialisasi */
        elemen* bantu = L.first;
        int i = 1;
        while(bantu != NULL) {
            /* proses */
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.harga, bantu->kontainer.kode);
            bantu = bantu->next;
            i++;
        }
    }else {
        /* proses jika list kosong */
        printf("=================\n");
        printf(" Loh kok gaada:(\n");
        printf("=================\n");
    }
}