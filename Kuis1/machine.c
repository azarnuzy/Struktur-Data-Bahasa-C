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
        while(tunjuk != NULL) { //perulangan untuk menghitung banyaknya element
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
void addFirst(char nama[], char harga[], list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru -> kontainer.nama, nama);
    strcpy(baru -> kontainer.harga, harga);
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
void addAfter(elemen* prev, char nama[], char harga[], list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.harga, harga);
    //kondisi  dari elemen sebelum adalah terakhir dan elemen sebelum di tengah
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(char nama[], char harga[], list *L) {
    //kondisi jika list kosongdan jika list tidak kosong
    if((*L).first ==NULL) {
        addFirst(nama,harga, L);
    }else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev,nama, harga,L);
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
            printf("%s %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga);
            tunjuk = tunjuk->next;
            i++;
        }
    }else {
        printf("list kosong\n");
    }
}

void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for(i=countElement(*L); i>=1; i--) {
            delLast(L);
        }
    }
}

void searchMenu(list *L1, list *L2, namaMenuTukar menuTukar[], int m, char lastMenu1[], char lastMenu2[]) {
    /* 
    *i, j = sebagai variabel untuk menunjukan dari setiap list menu 1 dan menu 2 dan juga sebagai iterator
    *prev1, prev2 sebagai variabel untuk menunjukan elemen sebelum current elemen sehingga nantinya dapat dihapus
    *cek1, cek2, cek3, cek4 sebagai variabel untuk menampung nilai dari kondisi apakah masukan dengan menu yang ada di list sama
     */
    elemen *i = L1->first, *j = L2->first;
    elemen *prev1, *prev2;
    int itr;
    for(itr =0 ;itr <m; itr++) {
        int count1 = 0, count2;
        for(i=L1->first; i != NULL; i = i->next) {
            int cek1 = strcmp(menuTukar[itr].nama1, i->kontainer.nama);
            int cek2 = strcmp(menuTukar[itr].nama2, i->kontainer.nama);
            if(count1 > 0) {
                prev1 = L1->first; 
            }

            if(cek1 == 0 || cek2 == 0) {
                count2 = 0;
                for(j=L2->first; j != NULL; j = j->next) {
                    int cek3 = strcmp(menuTukar[itr].nama1, j->kontainer.nama);
                    int cek4 = strcmp(menuTukar[itr].nama2, j->kontainer.nama);
                    if(count2 > 0) {
                        prev2 = L2->first;
                    }

                    if(cek3 == 0 || cek4 == 0 ) {

                        addLast(j->kontainer.nama, j->kontainer.harga, L1);
                        addLast(i->kontainer.nama, i->kontainer.harga, L2);
                        
                        if(count1 == 0) {
                            delFirst(L1);
                        }else if(count1 > 0 && i->next != NULL){
                            delAfter(prev1, L1);
                        }else {
                            delAfter(prev1->next, L1);
                        }

                        if(count2 == 0) {
                            delFirst(L2);
                        }else if(count2 > 0 && j->next != NULL){
                            delAfter(prev2, L2);
                        }else {
                            delAfter(prev2->next, L2);
                        }
                        break;
                    }
                    if(count2 > 0) {
                        prev2 = prev2->next;
                    }
                    count2++;
                }
            }

            if(count1 > 0) {
                prev1 = prev1->next;
            }
            count1++;
        }
    }
}