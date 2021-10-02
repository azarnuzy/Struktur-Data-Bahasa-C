#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
    int harga;
    float rating;
}makanan;

typedef struct elmt *alamatElmt;
typedef struct elmt {
    makanan kontainer;
    alamatElmt next;
}elemen;

typedef struct {
    elemen *first;
}list;

void createList(list *L) {
    (*L).first = NULL;
}

int countElement(list L) {
    int hasil = 0;
    if(L.first != NULL) {
        elemen* tunjuk;
        tunjuk = L.first;
        while(tunjuk != NULL) {
            hasil += 1;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(char nama[], int harga, float rating, list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru -> kontainer.nama, nama);
    baru -> kontainer.rating = rating;
    baru -> kontainer.harga = harga;
    if((*L).first == NULL) {
        baru -> next = NULL;
    }else {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}


void addAfter(elemen* prev, char nama[], int harga, float rating, list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru -> kontainer.nama, nama);
    baru -> kontainer.rating = rating;
    baru -> kontainer.harga = harga;

    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(char nama[], int harga, float rating, list *L) {
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

void sortDinamyc(list L1, list *L2, char urutanMenu[]) {
    elemen* tunjuk1 = L1.first;
    elemen* prev;
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));

    addFirst(tunjuk1 -> kontainer.nama, tunjuk1 -> kontainer.harga, tunjuk1 -> kontainer.rating, L2);

    tunjuk1 = tunjuk1 -> next;
    
    while(tunjuk1 != NULL) {

        int posisi = 1;
        int cek = 0;
        elemen* tunjuk2 = (*L2).first;

        prev = (*L2).first;

        while(tunjuk2 != NULL && cek == 0) {
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
            }else {
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

    if(banyakUang > tunjuk -> kontainer.harga) {    
        while(tunjuk != NULL) {
            if(banyakUang >= tunjuk -> kontainer.harga) {
                banyakUang -= tunjuk -> kontainer.harga;
            }else {
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


int main(int argc, char const *argv[])
{
    list L1, L2;
    char nama[50];
    float rating;
    int harga;
    int banyakUang;
    char urutanMenu[50];

    createList(&L1);
    createList(&L2);

    int cek = 0;

    do {
        scanf("%s", &nama);
        if(strcmp(nama, "*") != 0) {
            scanf("%d %f", &harga, &rating);
            addLast(nama, harga, rating, &L1);
        }
    }while(strcmp(nama, "*") != 0);

    scanf("%d %s", &banyakUang, &urutanMenu);

    sortDinamyc(L1, &L2, urutanMenu);

    printf("=== Menu Terurut ===\n");
    printElement(L2);

    printf("\n=== Dapat Dibeli ===\n");

    int sisaUang;
    sisaUang = dapatDibeli(&L2, banyakUang);

    if(countElement(L2) != 0) {
        printElement(L2);
    }else {
        printf("Tidak ada yang dapat dibeli\n");
    }

    printf("\nSisa uang: %d\n", sisaUang);
    return 0;
}
