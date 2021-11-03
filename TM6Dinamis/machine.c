#include "header.h"
/* 
** top = sebagai nilai dari stack paling atas
 */
void createEmpty(stack *S)
{
    //menjadikan nilai NULL sebagai penanda bahwa stack tersebut kosong
    (*S).top = NULL;
}

int isEmpty(stack S)
{
    int hasil = 0;
    //kondisi jika stack tersebut kosong
    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S)
{

    int hasil = 0;

    if (S.top != NULL)
    {
        /* stack tidak kosong */

        elemen *bantu;

        /* inisialisasi */
        bantu = S.top;
        while (bantu != NULL)    //perulangan untuk menghitung banyaknya element
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
void push(char harga[], char nama[], stack *S)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    //memasukan nilai dari input
    strcpy(baru->kontainer.harga, harga);
    strcpy(baru->kontainer.nama, nama);
    if ((*S).top == NULL)
    {
        //jika stack kosong
        baru->next = NULL;
    }
    else
    {
        //jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}
/* 
*hapus sebagai penunjuk elemen yang akan di keluarkan
 */
void pop(stack *S)
{
    if ((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        if (countElement(*S) == 1)
        {
            // menjadikan nilai null agar elemen tersebut terhapus
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("- Stack Kosong");
    }
}

void popMove(stack *SA, stack *SB) {
    if ((*SA).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*SA).top;
        /* memasukan nilai yang dikeluarkan ke stack yang kedua */
        push(hapus->kontainer.harga, hapus->kontainer.nama, SB);

        if (countElement(*SA) == 1)
        {
            // menjadikan nilai null agar elemen tersebut terhapus
            (*SA).top = NULL;
        }
        else
        {
            (*SA).top = (*SA).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("- Stack Kosong");
    }
}

void printStack(stack S, int mode)
{
    //kondisi jika stack1 yang di print
    if(mode == 1) {
        printf("S1:\n");
    }
    //kondisi jika stack2 yang di print
    else {
        printf("S2:\n");
    }

    if (S.top != NULL)
    {
        elemen *bantu = S.top;

        int i = 1;
        //i untuk nomor keluaran 
        while (bantu != NULL)       //pengulangan untuk keluaran
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
        
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Stack Kosong\n");
    }
}