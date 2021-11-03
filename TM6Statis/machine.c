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

void push(char harga[], char nama[], stack *S)
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
            strcpy((*S).data[0].harga, harga);
            strcpy((*S).data[0].nama, nama);
        }
        else
        {
            /* jika stack tidak kosong */
            // top ditambahkan nilainya satu agar masukan dapat di simpan di stack paling atas
            (*S).top = (*S).top + 1;
            //memasukan nilai dari input
            strcpy((*S).data[(*S).top].harga, harga);
            strcpy((*S).data[(*S).top].nama, nama);
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
        strcpy((*SB).data[(*SB).top].harga, (*SA).data[(*SA).top].harga);
        strcpy((*SB).data[(*SB).top].nama, (*SA).data[(*SA).top].nama);
        (*SA).top = (*SA).top - 1;
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

    if (S.top != -1)
    {
        int i;
        //itr untuk nomor keluaran 
        int itr = 1;
        //pengulangan untuk keluaran
        for (i = S.top; i >= 0; i--)
        {
            printf("%d. %s\n",itr, S.data[i].nama );
            itr++;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Stack Kosong\n");
    }
}