#include "header.h"
/* 
** first = sebagai nilai dari queue paling pertama masuk dan pertama keluar
** last = sebgai nilai dari queue paling terakhir keluar dan masuk
 */
void createEmpty(queue *Q)
{
    //menjadikan nilai NULL sebagai penanda bahwa queue tersebut kosong
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q)
{
    //kondisi jika queue tersebut kosong
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil = 1;
    }
    return hasil;
}
/* 
*hasil sebagai nilai kembali dari elemen yang tersedia
*bantu sebagai kondisi pengecekan untuk banyaknya elemen
*next sebagai penunjuk dari elemen selanjutnya 
 */
int countElement(queue Q)
{
    int hasil = 0;
    if (Q.first != NULL)
    {
        /* queue tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = Q.first;
        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }

    return hasil;
}
/* 
*baru sebagai pointer bertipe elemen dan beralokasikan memory dan di paksa menjadi pointer melalui casting dari memory alokasi elemen
 */
void add(char nim[], char nama[], queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);

    baru->next = NULL;
    //kondisi untuk penambahan dengan kondisi queue kosong dan banyak elemen
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void del(queue *Q1, queue *Q2)
{
    if ((*Q1).first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *hapus = (*Q1).first;
        if (countElement(*Q1) == 1)
        {
            //menambahkan data ke queue 2 dari data queue 1 yang akan dihapus
            add(hapus->kontainer.nim, hapus->kontainer.nama, Q2);
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else
        {
            //menambahkan data ke queue 2 dari data queue 1 yang akan dihapus
            add(hapus->kontainer.nim, hapus->kontainer.nama, Q2);
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void printQueue(queue Q, int mode)
{
    //kondisi jika queue1 yang di print
    if(mode == 1) {
        printf("Queue 1\n");
    }
    //kondisi jika queue2 yang di print
    else {
        printf("Queue 2\n");
    }

    if (Q.first != NULL)
    {
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s %s\n", bantu->kontainer.nama, bantu->kontainer.nim);

            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
    printf("******************\n");
}

void addAfter(elemen* prev, char nama[], char nim[], queue *Q) {
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nim, nim);
    //kondisi  dari elemen sebelum adalah terakhir dan elemen sebelum di tengah
    if(prev->next == NULL) {
        baru->next = NULL;
    }else {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addFirst(char nama[], char nim[], queue *Q) {
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    //memasukan nilai dari input
    strcpy(baru -> kontainer.nama, nama);
    strcpy(baru -> kontainer.nim, nim);
    //kondisi untuk penambahan dengan kondisi queue kosong dan banyak elemen
    if((*Q).first == NULL) {
        baru -> next = NULL;
    }else {
        baru->next = (*Q).first;
    }
    //menjadikan first sebagai nilai baru
    (*Q).first = baru;
    baru = NULL;
}

void addPriority(queue *Q, int number, char nim[], char nama[]) 
{
    int i = 1;
    // kondisi jika nomor priority lebih besar dari banyaknya data pada queue
    if(number > countElement(*Q)) {
        add(nim, nama, Q);
    }
    // kondisi jika nomor priority lebih kecil dari banyaknya data pada queue
    else {
        // kondisi jika number priority adalah 1
        if(number == 1) {
            addFirst(nama, nim, Q);
        }
        // kondisi jika number priority di atas 1
        else {
            elemen *bantu = (*Q).first;
            while(i < number-1) {
                bantu = bantu->next;
                i++;
            }
            addAfter(bantu, nama, nim, Q);
        }
    }
}