#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UTS 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
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
void addFirstB(restoran namaRestoran, list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, namaRestoran.nama);
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
void addFirstK(menuRestoran dataMenu, eBaris *L)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    //memasukan nilai dari input
    strcpy(baru->kontainer_kol.namaMenu, dataMenu.namaMenu);
    baru->kontainer_kol.harga = dataMenu.harga;
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
void addAfterB(eBaris *prev, restoran namaRestoran, list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, namaRestoran.nama);
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

void addAfterK(eKolom *prev, menuRestoran dataMenu)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));
    //memasukan nilai dari input
    strcpy(baru->kontainer_kol.namaMenu, dataMenu.namaMenu);
    baru->kontainer_kol.harga = dataMenu.harga;
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

void addLastB(restoran namaRestoran, list *L)
{
    if ((*L).first == NULL)
    {
        /* jika list adalah list kosong */
        addFirstB(namaRestoran, L);
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

        addAfterB(last, namaRestoran, L);
    }
}

void addLastK(menuRestoran dataMenu, eBaris *L)
{
    if ((*L).col == NULL)
    {
        /* jika list adalah list kosong */
        addFirstK(dataMenu, L);
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
        addAfterK(last, dataMenu);
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
            printf("%s:\n", bantu->kontainer.nama);
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                printf("- %s %d\n",eCol->kontainer_kol.namaMenu, eCol->kontainer_kol.harga);
                eCol = eCol->next_kol;
            }

            if(i < countElementB(L)) {
                printf("\n");
            }
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

eBaris* getLatestBaris(list L, char nama[]){
	/*inisialisasi dan cek jika listnya tidak kosong, nilai tunjuk jadi elemen baris pertama*/
	eBaris* tunjuk = NULL;
	if (L.first != NULL)
	{
		tunjuk = L.first;
		/*perulangan selama bukan null dan bukan nama yang dicari*/
		while((tunjuk != NULL) && (strcmp(tunjuk->kontainer.nama, nama) != 0)) {
		    tunjuk = tunjuk->next;
		}
	}

	return tunjuk;
}

eBaris *tunjukBaris(list L, char nama[]) {
    eBaris *bantu;
    bantu = L.first;
    int cek = 0;
    /* kondisi untuk perulangan sampai List baris terakhir */
    while (bantu != NULL && cek == 0)
    {
        /* kondisi jika tahun yang ada pda parameter == tahun yang ada pada list baris */
        if(strcmp(bantu->kontainer.nama,nama) == 0) {
            cek = 1;
            return bantu;
        }
        bantu = bantu->next;
    }
    
    return NULL;
}

void switchMenu(restoran masukanDari, restoran masukanKe, list *L) {
    /* 
    **rowDari sebagai variabel untuk mendapatkan nilai dari baris restoran yang akan dipindahkan makanananya pada list 
    **rowKe sebagai variabel untuk mendapatkan nilai dari baris restoran yang akan menerima menu baru
    **colDari sebagai variabel untuk menunjuk setiap kolom pada baris atau menu
    **prev sebagai variabel untuk menunjuk kolom sebelum colDari
     */
    eBaris *rowDari = tunjukBaris(*L, masukanDari.nama);
    eBaris *rowKe = tunjukBaris(*L, masukanKe.nama);
    eKolom *colDari = rowDari->col;
    eKolom *prev = rowDari->col;
    int itr = 1;
    int cek = 0;

    //perualangan 
    while(colDari != NULL && cek == 0) {
        //kondisi jika menu yang akan dipindah terletak di awal kolom
        if(itr==1 && strcmp(colDari->kontainer_kol.namaMenu, masukanDari.menuSwitch) == 0 ) {
            addLastK(colDari->kontainer_kol, rowKe);
            delFirstK(rowDari);
            cek = 1;
        } 
        //kondisi jika menu yang akan dipindah terletak bukan di awal kolom
        else if(strcmp(colDari->kontainer_kol.namaMenu, masukanDari.menuSwitch) == 0 && itr != 1) {
            addLastK(colDari->kontainer_kol, rowKe);
            delAfterK(prev);
            cek = 1;
        }
        //memasukan nilai prev dan colDari yang baru
        prev = colDari;
        colDari = colDari->next_kol;
        itr++;
    }
}