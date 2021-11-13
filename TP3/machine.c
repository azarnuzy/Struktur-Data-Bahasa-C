#include "header.h"
/* 
** top = sebagai nilai dari stack paling atas
 */
void createEmpty(stack *S)
{
    //menjadikan nilai -1 sebagai penanda bahwa stack tersebut kosong
    (*S).top = -1;
}

int isEmpty(stack S)
{
    int hasil = 0;
    //kondisi jika stack tersebut kosong
    if (S.top == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S)
{
    int hasil = 0;
    //kondisi jika stack tersebut penuh nilai 9 bisa disesuaikan dengan banyaknya stack yang disediakan
    if (S.top == 9)
    {
        hasil = 1;
    }
    return hasil;
}

void push(char judul[], char tahun[],char band[], stack *S)
{

    if (isFull(*S) == 1)
    {
        /*jika stack penuh*/
        printf("stack penuh\n");
    }
    else
    {
        if (isEmpty(*S) == 1)
        {
            /* jika stack kosong */
            (*S).top = 0;
            //memasukan nilai dari input
            strcpy((*S).data[0].judul, judul);
            strcpy((*S).data[0].tahun, tahun);
            strcpy((*S).data[0].band, band);
        }
        else
        {
            /* jika stack tidak kosong */
            // top ditambahkan nilainya satu agar masukan dapat di simpan di stack paling atas
            (*S).top = (*S).top + 1;
            //memasukan nilai dari input
            strcpy((*S).data[(*S).top].judul, judul);
            strcpy((*S).data[(*S).top].tahun, tahun);
            strcpy((*S).data[0].band, band);
        }
    }
}

void pop(stack *S)
{

    if ((*S).top == 0)
    {
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1)
        {
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}

void popMove(stack *SA, stack *SB) {
    if ((*SA).top != -1)
    {
        /*jika stack tidak kosong*/
        (*SB).top = (*SB).top + 1;
        // Menyalin nilai stack yang di pop ke dalam stack yang kedua
        strcpy((*SB).data[(*SB).top].judul, (*SA).data[(*SA).top].judul);
        strcpy((*SB).data[(*SB).top].tahun, (*SA).data[(*SA).top].tahun);
        strcpy((*SB).data[(*SB).top].band, (*SA).data[(*SA).top].band);
        (*SA).top = (*SA).top - 1;
    }
}

void printStack(stack S, int mode)
{
    //kondisi jika stack1 yang di print
    if(mode == 1) {
        printf("Playlist Musik Rock:\n");
        printf("===================\n");
    }
    //kondisi jika stack2 yang di print
    else {
        printf("Playlist Musik Pop:\n");
        printf("===================\n");
    }

    if (S.top != -1)
    {
        int i;
        //itr untuk nomor keluaran 
        int itr = 1;
        //pengulangan untuk keluaran
        for (i = S.top; i >= 0; i--)
        {
            printf("%d. %s\n",itr, S.data[i].judul );
            itr++;
        }
        if(mode == 1) {
            printf("\n");
        }
    }
    else
    {
        /* proses jika stack kosong */
        if(mode == 1) {
            printf("BUKAN ANAK ROCK!\n\n");
        }else {
            printf("BUKAN ANAK POP!\n");
        }
    }
}

int countASCII(char judul[]) {
    int i;

    int count = 0;
    for(i=0; i<strlen(judul); i++) {
        count += judul[i];
    }

    return count;
}