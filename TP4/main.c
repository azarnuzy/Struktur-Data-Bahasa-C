#include "header.h"

int main()
{
    /* 
    **Q sebagai variabel untuk tipe data queue
    **data sebgai tipe data terstruktur yang di dalamnya terdapat nama, member, menit
    **jumlah waktu sebagai banyaknya waktu yang digunakan untuk mengantri
    **count selesai banyaknya member yang mengantri sebelum 6 jam
    **sebagai iterasi dari banyaknya antrian 
     */

    //menginisialisasikan variable yang akan digunakan
    queue Q[10];

    int i, j;
    for (i = 0; i < 5; i++)
    {
        createEmpty(&Q[i]);
    }
    antrian data;
    //perulangan untuk memasukan data
    do
    {
        scanf("%s", data.nama);
        if (strcmp(data.nama, "stop") != 0)
        {
            scanf("%s %d", data.member, &data.menit);

            //kondisi untuk menentukan urutan
            if (strcmp(data.member, "platinum") == 0)
            {
                add(data, &Q[0]);
            }
            else if (strcmp(data.member, "gold") == 0)
            {
                add(data, &Q[1]);
            }
            else if (strcmp(data.member, "silver") == 0)
            {
                add(data, &Q[2]);
            }
            else
            {
                add(data, &Q[3]);
            }
        }
        //kondisi jika waktu kurang dari 6 jam maka antrian akan keluar
    } while (strcmp(data.nama, "stop") != 0);

    // menyatukan semua data dari queue
    for (i = 0; i < 4; i++)
    {
        int itr = countElement(Q[i]);
        for (j = 0; j < itr; j++)
        {
            delMove(&Q[i], &Q[4]);
        }
    }

    //kondisi ketika antrian kurang dari 6 jam maka akan dihapus dari queue
    int count = delQueuePasien(Q[4]);
    for (i = 0; i < count; i++)
    {
        del(&Q[4]);
    }

    printQueue(Q[4]);
    return 0;
}