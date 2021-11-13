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
void add(bantuan data, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.nama, data.nama);
    strcpy(baru->kontainer.kota, data.kota);
    baru->kontainer.noPrioritas = data.noPrioritas;
    strcpy(baru->kontainer.uang, data.uang);

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
            add(hapus->kontainer, Q2);
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else
        {
            //menambahkan data ke queue 2 dari data queue 1 yang akan dihapus
            add(hapus->kontainer, Q2);
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
        printf("Antrian berisi:\n");
    }
    //kondisi jika queue2 yang di print
    else {
        printf("Bantuan Tersalurkan:\n");
    }

    if (Q.first != NULL)
    {
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s %d %s %s\n", bantu->kontainer.nama, 
            bantu->kontainer.noPrioritas, bantu->kontainer.kota, bantu->kontainer.uang);

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
    
}

void addPriority(queue *Q, int number, bantuan data) 
{
    elemen *baru;
    baru = (elemen*)malloc(sizeof (elemen));
    //menyalin nilai dari input ke dalam baru 
    strcpy(baru->kontainer.nama, data.nama);
    strcpy(baru->kontainer.kota, data.kota);
    baru->kontainer.noPrioritas = data.noPrioritas;
    strcpy(baru->kontainer.uang, data.uang);
    
    baru->next = NULL;

    //kondisi jika queue masih kosong
    if((*Q).first == NULL) {
        (*Q).first = baru;
        (*Q).last = baru;
    } else {
        //kondisi jika nomor prioritas pertama
        if(number == 1) {
            baru->next = ((*Q).first);
            (Q)->first = baru;
        }
        //kondisi jika nomor prioritas lebih besar dari banyaknya antrian
        else if(number > countElement(*Q)) {
            add(data, Q);
        }
        //kondisi jika nomor prioritas kurang dari banyaknya antrian
        else {
            elemen *bantu = (*Q).first;
            int i = 1;
            while(bantu != NULL) {
                if(i == number - 1) {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                bantu = bantu->next;
                i++;
            }
        }
    }
    baru = NULL;
}