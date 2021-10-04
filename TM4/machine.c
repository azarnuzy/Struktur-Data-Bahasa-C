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
*baru sebagai pointer bertipe elemen dan beralokasikan memory dan di paksa menjadi pointer melalui casting dari memory alokasi elemen
 */
void addFirst (char nama[], char matkul[], char nilai[], list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.matkul, matkul);
    strcpy(baru->kontainer.nilai, nilai);
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
/* 

*prev sebagai index dari nilai sebelum ditambahkan nilai yang baru
*before sebagai elemen yang terletak sebelum elemen baru ditambahkan
 */
void addAfter(elemen* before, char nama[], char matkul[], char nilai[], list *L) {
    if(before != NULL) {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        //memasukan nilai dari input
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.matkul, matkul);
        strcpy(baru->kontainer.nilai, nilai);
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

void addBefore(elemen* after, char nama[], char matkul[], char nilai[], list *L) {
    if(after != NULL) {
        addAfter(after->prev, nama, matkul, nilai, L);
    }
}

void addLast (char nama[], char matkul[], char nilai[], list *L) {
    if((*L).first == NULL) {
        /* jika list adalah list kosong */
        addFirst(nama, matkul, nilai, L);
    }else {
        /* jika list tidak kosong */
        addAfter((*L).tail, nama, matkul, nilai, L);
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
                (*L).tail = before;
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
            delFirst(L);
        }else {
            /* jika list terdiri dari banyak elemen */
            delAfter((*L).tail->prev, L);
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
            printf("%s %s %s\n", bantu->kontainer.nama, bantu-> kontainer.matkul, bantu->kontainer.nilai); 
            bantu = bantu->next;
            i++;
        }
    }else {
        /* proses jika list kosong */
        printf("List Kosong\n");
    }
    printf("========\n");
}

void printReverse(list L) {
    if(L.first != NULL) {
        /* inisialisasi */
        elemen* bantu = L.tail;
        int i = 1;
        while(bantu != NULL) {
            /* proses */
            printf("%s %s %s\n", bantu->kontainer.nama, bantu-> kontainer.matkul, bantu->kontainer.nilai); 
            bantu = bantu->prev;
            i++;
        }
    }else {
        /* proses jika List kosong */
        printf("List Kosong\n");
    }

    printf("========\n");
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