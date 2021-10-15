#include "header.h"

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

void addFirstB(int angkaPembagi, list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    baru->kontainer.angkaPembagi = angkaPembagi;
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

void addFirstK(int angkaDibagi, eBaris *L)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    baru->kontainer_kol.angkaDibagi = angkaDibagi;
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

void addAfterB(eBaris *prev, int angkaPembagi)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    baru->kontainer.angkaPembagi = angkaPembagi;
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

void addAfterK(eKolom *prev, int angkaDibagi)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    baru->kontainer_kol.angkaDibagi = angkaDibagi;
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

void addLastB(int angkaPembagi, list *L)
{
    if ((*L).first == NULL)
    {
        /* jika list adalah list kosong */
        addFirstB(angkaPembagi, L);
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

        addAfterB(last, angkaPembagi);
    }
}

void addLastK(int angkaDibagi, eBaris *L)
{
    if ((*L).col == NULL)
    {
        /* jika list adalah list kosong */
        addFirstK(angkaDibagi, L);
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
        addAfterK(last, angkaDibagi);
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
            printf("%d\n", bantu->kontainer.angkaPembagi);
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                printf("- %d\n", eCol->kontainer_kol.angkaDibagi);
                eCol = eCol->next_kol;
            }
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

void createRowNumber(list *L) {
    int i;
    for(i=1; i<=9; i++) {
        addLastB(i, L);
    }
}

void groupRowNumber(int angkaDibagi, list *L) {
    int i;
    eBaris *tunjuk = L->first;

    if(angkaDibagi == 1) {
        addLastK(1, tunjuk);
    }

    tunjuk = tunjuk->next;

    for(i=2; i<=9; i++) {
        if(angkaDibagi % i == 0) {
            addLastK(angkaDibagi, tunjuk);
        }

        tunjuk = tunjuk->next;
    }
}

void delEmptyCol(list *L) {
    int i;
    eBaris *tunjuk;
    eBaris *tunjukPrev;
    tunjuk = L->first;
    for(i=1; i<=9; i++) {
        eKolom *bantu;
        bantu = tunjuk->col;
        if(bantu == NULL && i == 1) {
            delFirstB(L);
        }else if(bantu == NULL && i > 1) {
            tunjuk = tunjuk->next;
            delAfterB(tunjukPrev);
        }else{
            tunjukPrev = tunjuk;
            tunjuk = tunjuk->next;
        }
    }
}