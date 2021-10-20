#include "header.h"
/* 
*first sebagai penunjuk kepada elemen yang pertama
*NULL sebagai nilai awal dari first
 */
void createList(list *L)
{
    (*L).first = NULL;
}
/* 
*hasil sebagai nilai kembali dari elemen yang tersedia di dalam list baris
*bantu sebagai kondisi dari banyaknya elemen yang ada pada list baris
 */
int countElementB(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        /* list tidak kosong */
        eBaris *bantu;
        /* inisialisasi */
        bantu = L.first;

        while (bantu != NULL)   //perulangan untuk menghitung banyaknya element
        {
            /* proses */
            hasil += 1;
            /* iterasi */
            bantu = bantu->next;
        }
    }

    return hasil;
}
/* 
*hasil sebagai nilai kembali dari elemen yang tersedia di dalam list kolom
*bantu sebagai kondisi dari banyaknya elemen yang ada pada list kolom
 */
int countElementK(eBaris L)
{
    int hasil = 0;
    if (L.col != NULL)
    {
        /* list tidak kosong */
        eKolom *bantu;
        /* inisialisasi */
        bantu = L.col;

        while (bantu != NULL) //perulangan untuk menghitung banyaknya element
        {
            /* proses */
            hasil += 1;
            /* iterasi */
            bantu = bantu->next_kol;
        }
    }

    return hasil;
}
/* 
*baru sebagai pointer bertipe elemen dan beralokasikan memory dan di paksa menjadi pointer melalui casting dari memory alokasi elemen
 */
void addFirstB(char nama[], int tahun, list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.tahun = tahun;
    baru->col = NULL;
    //kondisi untuk penambahan dengan kondisi baris kosong dan banyak elemen
    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    //menjadikan first sebagai nilai baru
    (*L).first = baru;
    baru = NULL;
}
/* 
*baru sebagai pointer bertipe elemen dan beralokasikan memory dan di paksa menjadi pointer melalui casting dari memory alokasi elemen
 */
void addFirstK(char namaPemain[], eBaris *L)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    //memasukan nilai dari input
    strcpy(baru->kontainer_kol.namaPemain, namaPemain);
    //kondisi untuk penambahan dengan kondisi kolom kosong dan banyak elemen
    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }
    //menjadikan col  sebagai nilai baru
    (*L).col = baru;
    baru = NULL;
}
/* 
*prev sebagai index dari nilai sebelum ditambahkan nilai yang baru
 */
void addAfterB(eBaris *prev, char nama[], int tahun, list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.tahun = tahun;
    baru->col = NULL;
    //kondisi  dari elemen sebelum adalah terakhir dan elemen sebelum di tengah
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

void addAfterK(eKolom *prev, char namaPemain[])
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    //memasukan nilai dari input
    strcpy(baru->kontainer_kol.namaPemain, namaPemain);
    //kondisi  dari elemen sebelum adalah terakhir dan elemen sebelum di tengah
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

void addLastB(char nama[], int tahun, list *L)
{
    if ((*L).first == NULL)
    {
        /* jika list adalah list kosong */
        addFirstB(nama, tahun, L);
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

        addAfterB(last, nama, tahun, L);
    }
}

void addLastK(char namaPemain[], eBaris *L)
{
    if ((*L).col == NULL)
    {
        /* jika list adalah list kosong */
        addFirstK(namaPemain, L);
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
        addAfterK(last, namaPemain);
    }
}
/* 
*hapus sebagai index untuk elemen yang dihapus
 */
void delFirstK(eBaris *L)
{
    //kondisi jika terdapat satu elemen dan jika banyak elemen
    if ((*L).col != NULL)
    {
        /*jika list bukan list kosong*/
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
    //kondisi jika terdapat satu elemen dan jika banyak elemen
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
            /*list terdiri dari satu elemen*/
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
            printf("%s %d\n", bantu->kontainer.nama,  bantu->kontainer.tahun);
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                printf("- %s\n",eCol->kontainer_kol.namaPemain);
                eCol = eCol->next_kol;
            }
            printf("==================\n");
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


eBaris *tunjukBaris(list L2, int tahun) {
    eBaris *bantu;
    bantu = L2.first;
    int cek = 0;
    /* kondisi untuk perulangan sampai List baris terakhir */
    while (bantu != NULL && cek == 0)
    {
        /* kondisi jika tahun yang ada pda parameter == tahun yang ada pada list baris */
        if(bantu->kontainer.tahun == tahun) {
            cek = 1;
            return bantu;
        }
        bantu = bantu->next;
    }
    
    return NULL;
}

/* 
* posisi nilai untuk menunjukan pada posisi mana elemen tersebut sedang dibandingkan
* cek sebagai nilai untuk pembatalan looping pada list baru
 */
void sortList(list L1,list *L2) {
    eBaris* tunjuk1 = L1.first;
    eBaris* prev;
     /* memasukan nilai awal ke baris baru */
    addFirstB(tunjuk1->kontainer.nama, tunjuk1->kontainer.tahun, L2);
    eBaris* bantuTunjuk = tunjukBaris(*L2, tunjuk1->kontainer.tahun);
    eKolom* bantu1 = tunjuk1->col;
     /* memasukan nilai awal ke kolom baru */
    for(int i=0; i<4; i++) {
        addLastK(bantu1->kontainer_kol.namaPemain, bantuTunjuk);
        bantu1 = bantu1->next_kol;
    }
    /* menggeser penunjuk ke elemen berikutnya */
    tunjuk1 = tunjuk1->next;
    /* perulangan untuk baris masukan */
    while(tunjuk1 != NULL) {
        bantu1 = tunjuk1->col;
        int posisi = 1;
        int cek = 0;
        eBaris* tunjuk2 = L2->first;
        /* perulangan untuk baris baru */
        while(tunjuk2 != NULL && cek == 0) {
            /* 
            * kondisi pertama menunjukan bahwa nilai yang paling kecil akan dimasukan ke paling awal list
            * kondisi kedua menunjukan bahwa nilai yang kecil tetapi berada di tengah2 nilai akan dimasukan ke tengah list baru
            * kondisi ketiga nilai paling besar akan dimasukan di akhir list
             */
            /* kondisi untuk urutan secara ascending */
            if(tunjuk1->kontainer.tahun < tunjuk2->kontainer.tahun && posisi == 1) {
                addFirstB(tunjuk1->kontainer.nama, tunjuk1->kontainer.tahun, L2);
                bantuTunjuk = tunjukBaris(*L2, tunjuk1->kontainer.tahun);
                for(int i=0; i<4; i++) {
                    addLastK(bantu1->kontainer_kol.namaPemain, bantuTunjuk);
                    bantu1 = bantu1->next_kol;
                }
                cek = 1;
            }else if(tunjuk1->kontainer.tahun < tunjuk2->kontainer.tahun && posisi <= countElementB(*L2)) {
                addAfterB(prev, tunjuk1->kontainer.nama, tunjuk1->kontainer.tahun, L2);
                bantuTunjuk = tunjukBaris(*L2, tunjuk1->kontainer.tahun);
                for(int i=0; i<4; i++) {
                    addLastK(bantu1->kontainer_kol.namaPemain, bantuTunjuk);
                    bantu1 = bantu1->next_kol;
                }
                cek = 1;
            }else if(tunjuk1->kontainer.tahun > tunjuk2->kontainer.tahun && posisi == countElementB(*L2)) {
                addLastB(tunjuk1->kontainer.nama, tunjuk1->kontainer.tahun, L2);
                bantuTunjuk = tunjukBaris(*L2, tunjuk1->kontainer.tahun);
                for(int i=0; i<4; i++) {
                    addLastK(bantu1->kontainer_kol.namaPemain, bantuTunjuk);
                    bantu1 = bantu1->next_kol;
                }
                cek = 1;
            }
            prev = tunjuk2;
            tunjuk2 = tunjuk2->next;
            posisi++;
        } 
        tunjuk1 = tunjuk1->next;
    }
}

