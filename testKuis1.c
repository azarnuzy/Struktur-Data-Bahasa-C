#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
    char harga[50];
}menuWarung;

typedef struct {
    char nama1[50], nama2[50];
}namaMenuTukar;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    menuWarung kontainer;
    alamatelmt next;
}elemen;

typedef struct {
    elemen *first;
}list;

void createList (list *L) {
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

void addFirst(char nama[], char harga[], list *L) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru -> kontainer.nama, nama);
    strcpy(baru -> kontainer.harga, harga);
    if((*L).first == NULL) {
        baru -> next = NULL;
    }else {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* prev, char nama[], char harga[], list *L) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.harga, harga);
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(char nama[], char harga[], list *L) {
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

void delFirst(list *L) {
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
    printf("=======%s\n", hapus->kontainer.nama);
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

int main(int argc, char const *argv[])
{
    list L1, L2;
    namaMenuTukar menuTukar[101];
    createList(&L1);
    createList(&L2);

    int i;
    int n1, n2, m;
    char lastMenu1[50], lastMenu2[50];
    char nama[50];
    char harga[50];

    scanf("%d", &n1);
    for(i=0; i<n1; i++) {
        scanf("%s %s", &nama, &harga);
        if(i == n1-1) {
            strcpy(lastMenu1, nama);
        }
        addLast(nama, harga, &L1);
    }
    scanf("%d", &n2);
    for(i=0; i<n2; i++) {
        scanf("%s %s", &nama, &harga);
        if(i == n2-1) {
            strcpy(lastMenu2, nama);
        }
        addLast(nama, harga, &L2);
    }
    scanf("%d", &m);
    for(i=0; i<m; i++) {
        scanf("%s %s", menuTukar[i].nama1, menuTukar[i].nama2);
    }
    
    searchMenu(&L1, &L2, menuTukar, m, lastMenu1, lastMenu2);
    printElement(L1);
    printf("=============\n");
    printElement(L2);
    return 0;
}
