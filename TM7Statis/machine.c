#include "header.h"
/* 
** first = sebagai nilai dari queue paling pertama masuk dan pertama keluar
** last = sebgai nilai dari queue paling terakhir keluar dan masuk
 */
void createEmpty(queue *Q)
{
    //menjadikan nilai -1 sebagai penanda bahwa queue tersebut kosong
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q)
{
    //kondisi jika queue tersebut kosong
    int hasil = 0;
    if (Q.first == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q)
{
    int hasil = 0;
    //kondisi jika queue tersebut penuh nilai 9 bisa disesuaikan dengan banyaknya queue yang disediakan
    if (Q.last == 9)
    {
        hasil = 1;
    }
    return hasil;
}

void add(char nim[], char nama[], queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        //memasukan nilai dari input
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
    }
    else
    {
        /* jika queue tidak kosong */
        if (isFull(*Q) != 1)
        {
            // last ditambahkan nilainya satu agar masukan dapat di simpan di queue yang belakang
            (*Q).last = (*Q).last + 1;
            //memasukan nilai dari input
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
        }
        else
        {
            printf("queue penuh\n");
        }
    }
}

void del(queue *Q1, queue *Q2)
{
    if ((*Q1).last == 0)
    {
        //menambahkan data ke queue 2 dari data queue 1 yang akan dihapus
        add((*Q1).data[0].nim, (*Q1).data[0].nama, Q2 );
        /*jika queue berisi satu elemen*/
        (*Q1).first = -1;
        (*Q1).last = -1;
    }
    else
    {
        int i;
        //menambahkan data ke queue 2 dari data queue 1 yang akan dihapus
        add((*Q1).data[(*Q1).first].nim, (*Q1).data[(*Q1).first].nama, Q2 );
        /*menggeser elemen ke depan*/
        for (i = ((*Q1).first + 1); i <= (*Q1).last; i++)
        {
            strcpy((*Q1).data[i - 1].nim, (*Q1).data[i].nim);
            strcpy((*Q1).data[i - 1].nama, (*Q1).data[i].nama);
        }
        
        (*Q1).last = (*Q1).last - 1;
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

    if (Q.first != -1)
    {
        int i;
        //pengulangan untuk keluaran
        for (i = Q.first; i <= Q.last; i++)
        {
            printf("%s %s\n",Q.data[i].nama, Q.data[i].nim );
        }
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }

    printf("******************\n");
}



void addPriority(queue *Q, int number, char nim[], char nama[]) 
{
    int i;
    // kondisi jika nomor priority lebih besar dari banyaknya data pada queue
    if(number-1 > (*Q).last ) {
        add(nim, nama, Q);
    }
    // kondisi jika nomor priority lebih kecil dari banyaknya data pada queue
    else {
        (*Q).last = (*Q).last + 1;   
        //menjadikan nilai yang di belakang dipindah ke nilai depan 
        for(i=(*Q).last-1; i>=number-1; i--) {
            strcpy((*Q).data[i + 1].nim, (*Q).data[i].nim);
            strcpy((*Q).data[i + 1].nama, (*Q).data[i].nama);         
        }
        //memasukan nilai sesuai dengan urutan priority
        strcpy((*Q).data[number-1].nim, nim);
        strcpy((*Q).data[number-1].nama, nama); 
    }
}
