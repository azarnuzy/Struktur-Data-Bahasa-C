#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
} mahasiswa;

typedef struct
{
    char kode[10];
    char nilai[2];
} matkul;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    matkul kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamtebaris;
typedef struct ebr
{
    mahasiswa kontainer;
    eKolom *col;
    alamtebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L)
{
    (*L).first = NULL;
}

int countElementB(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        /* list tidak kosong */
        eBaris *bantu;
        /* inisialisasi */
        bantu = L.first;

        while (bantu != NULL)
        {
            /* proses */
            hasil += 1;
            /* iterasi */
            bantu = bantu->next;
        }
    }

    return hasil;
}

int countElementK(eBaris L)
{
    int hasil = 0;
    if (L.col != NULL)
    {
        /* list tidak kosong */
        eKolom *bantu;
        /* inisialisasi */
        bantu = L.col;

        while (bantu != NULL)
        {
            /* proses */
            hasil += 1;
            /* iterasi */
            bantu = bantu->next_kol;
        }
    }

    return hasil;
}

void addFirstB(char nim[], char nama[], list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->col = NULL;
    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char kode[], char nilai[], eBaris *L)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    strcpy(baru->kontainer_kol.kode, kode);
    strcpy(baru->kontainer_kol.nilai, nilai);
    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }

    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris *prev, char nim[], char nama[])
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->col = NULL;
    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom *prev, char kode[], char nilai[])
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    strcpy(baru->kontainer_kol.kode, kode);
    strcpy(baru->kontainer_kol.nilai, nilai);
    if (prev->next_kol == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = prev->next_kol;
    }

    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char nim[], char nama[], list *L)
{
    if ((*L).first == NULL)
    {
        /* jika list adalah list kosong */
        addFirstB(nim, nama, L);
    }
    else
    {
        /* jika list tidak kosong */
        /* mencari elemen terakhir list */
        eBaris *last = (*L).first;
        while (last->next != NULL)
        {
            last = last->next;
        }

        addAfterB(last, nim, nama);
    }
}

void addLastK(char kode[], char nilai[], eBaris *L)
{
    if ((*L).col == NULL)
    {
        /* jika list adalah list kosong */
        addFirstK(kode, nilai, L);
    }
    else
    {
        /* jika list tidak kosong */
        /* menacri elemen terakhir list */
        eKolom *last = (*L).col;
        while (last->next_kol != NULL)
        {
            /* iterasi */
            last = last->next_kol;
        }
        addAfterK(last, kode, nilai);
    }
}

void delFirstK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /* jika list bukan list kosong */
        eKolom *hapus = (*L).col;
        if (countElementK(*L) == 1)
        {
            (*L).col = NULL;
        }
        else
        {
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delAfterK(eKolom *prev)
{
    eKolom *hapus = prev->next_kol;
    if (hapus != NULL)
    {
        if (hapus->next_kol == NULL)
        {
            prev->next_kol = NULL;
        }
        else
        {
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delLastK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementK(*L) == 1)
        {
            /*list terdiri dari satu elemen*/
            delFirstK(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eKolom *last = (*L).col;
            eKolom *before_last;

            while (last->next_kol != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L)
{
    if (countElementK(*L) != 0)
    {
        int i;
        for (i = countElementK(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastK(L);
        }
    }
}

void delFirstB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        eBaris *hapus = (*L).first;
        if (hapus->col != NULL)
        {
            //menghapus semua elemen kolom jika ada
            delAllK(hapus);
        }
        if (countElementB(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("list kosong");
    }
}

void delAfterB(eBaris *prev)
{
    if (prev != NULL)
    {
        eBaris *hapus = prev->next;
        if (hapus != NULL)
        {
            if (hapus->col != NULL)
            {
                //menghapus semua elemen kolom jika ada
                delAllK(hapus);
            }
            if (hapus->next == NULL)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementB(*L) == 1)
        {
            /*list terdiri dari satu
elemen*/
            delFirstB(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eBaris *last = (*L).first;
            eBaris *before_last;
            while (last->next != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(list *L)
{
    if (countElementB(*L) != 0)
    {
        int i;
        for (i = countElementB(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastB(L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris *bantu = L.first;
        int i = 1;
        while (bantu != NULL)
        {
            /*proses*/
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n",
                   bantu->kontainer.nim);
            printf("nama : %s\n",
                   bantu->kontainer.nama);
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                printf("kode kuliah : %s\n",
                       eCol->kontainer_kol.kode);
                printf("nilai : %s\n",
                       eCol->kontainer_kol.nilai);
                eCol = eCol->next_kol;
            }
            printf("------------\n");
            /*iterasi*/
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

int main()
{
    list L;
    createList(&L);
    printElement(L);
    printf("=================\n");
    addFirstB("1", "Orang_1", &L);
    addFirstK("IF40K1", "A", L.first);
    addAfterK(L.first->col, "IF40Z1", "A");
    addLastK("IF40Z2", "A", L.first);
    addAfterB(L.first, "2", "Orang_2");
    addFirstK("TI5141", "A", L.first->next);
    addLastK("IF5021", "A", L.first->next);
    addLastB("3", "Orang_3", &L);
    addFirstK("IF5321", "A", L.first->next->next);
    printElement(L);
    printf("=================\n");
    delAllB(&L);
    printElement(L);
    printf("=================\n");
    return 0;
}