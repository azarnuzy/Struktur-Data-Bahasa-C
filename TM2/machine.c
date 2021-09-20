#include "header.h"

/* 
*first sebagai penunjuk kepada elemen yang pertama
*next sebagai penunjuk dari elemen selanjutnya 
*NULL sebagai nilai awal dari first
 */
void createList (list *L) {
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
void addFirst(char nama[], char rumus[], char konsentrasi[], list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru -> kontainer.nama, nama);
    strcpy(baru -> kontainer.rumus, rumus);
    strcpy(baru -> kontainer.konsentrasi, konsentrasi);
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
void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.rumus, rumus);
    strcpy(baru -> kontainer.konsentrasi, konsentrasi);
    //kondisi  dari elemen sebelum adalah terakhir dan elemen sebelum di tengah
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(char nama[], char rumus[], char konsentrasi[], list *L) {
    //kondisi jika list kosongdan jika list tidak kosong
    if((*L).first ==NULL) {
        addFirst(nama,rumus, konsentrasi, L);
    }else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev,nama, rumus,konsentrasi,L);
    }
}

/* 
*hapus sebagai index untuk elemen yang dihapus
 */
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

void printElement(list L) {
    if(L.first != NULL) {
        elemen* tunjuk = L.first;
        int i = 1;

        while(tunjuk != NULL) {
            printf("%s %s %s\n", tunjuk->kontainer.nama, tunjuk-> kontainer.rumus, tunjuk->kontainer.konsentrasi);
            tunjuk = tunjuk->next;
            i++;
        }
    }else {
        printf("list kosong\n");
    }

    printf("======\n");
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