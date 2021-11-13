#include "header.h"
/* 
** top = sebagai nilai dari stack paling atas
 */
void createEmpty(stack *S)
{
    //menjadikan nilai -1 sebagai penanda bahwa stack tersebut kosong
    (*S).top = -1;
}
/* 
**hasil = sebagai nilai untuk menampilkan kondisi kosong atau penuh
 */
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
    if (S.top == 100)
    {
        hasil = 1;
    }
    return hasil;
}

void push(char merek[], char nama[], stack *S)
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
            strcpy((*S).data[0].merek, merek);
            strcpy((*S).data[0].nama, nama);
        }
        else
        {
            /* jika stack tidak kosong */
            // top ditambahkan nilainya satu agar masukan dapat di simpan di stack paling atas
            (*S).top = (*S).top + 1;
            //memasukan nilai dari input
            strcpy((*S).data[(*S).top].merek, merek);
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
        strcpy((*SB).data[(*SB).top].merek, (*SA).data[(*SA).top].merek);
        strcpy((*SB).data[(*SB).top].nama, (*SA).data[(*SA).top].nama);
        (*SA).top = (*SA).top - 1;
    }
}

/* 
** cek = sebagai variabel untuk melakukan pengecekan pada pencarian tumpukan
** count = sebagai penghitung dari banyaknya tumpukan yang dipindahkan
** countSA = sebagai banyaknya nilai tumpukan awal
 */
void findPakaian(stack *SA, stack *SB, char nama[]) {
    //mengecek kondisi dari stack 
    if((*SA).top != -1) {
        //menginisialisasikan nilai awal dari variabel di bawah
        int cek = 0;
        int count = 0;
        int countSA = (*SA).top;
        //perulangan untuk melakukan pencarian pakaian pada tumpukan
        while(cek == 0 && (*SA).top != -1) {
            //kondisi jika ditemukan pakaian pada tumpukan
            if(strcmp((*SA).data[(*SA).top].nama, nama) == 0) {
                //pakaian yang ditemukan akan di keluarkan dari tumpukan
                pop(SA);
                cek = 1;
            }else{
                //pakaian yang tidak ditemukan akan di pindahkan ke tumpukan sementara
                popMove(SA, SB);
            }
        }

        if(cek != 1) {
            //mengembalikan pakaian dari tumpukan sementara
            while((*SB).top != -1 && count <= countSA) {
                popMove(SB, SA);
                count++;
            }
        }
    }
}

void findTempPakaian(stack *SA, stack *SB, char nama[]) {
    //mengecek kondisi dari stack 
    if((*SA).top != -1) {
        //menginisialisasikan nilai awal dari variabel di bawah
        int cek = 0;
        int count = 0;
        //perulangan untuk melakukan pencarian pakaian pada tumpukan
        while(cek == 0 && (*SA).top != -1) {
            //kondisi jika ditemukan pakaian pada tumpukan
            if(strcmp((*SA).data[(*SA).top].nama, nama) == 0) {
                //pakaian yang ditemukan akan di keluarkan dari tumpukan
                pop(SA);
                cek = 1;
            }else{
                //pakaian yang tidak ditemukan akan di pindahkan ke tumpukan sementara
                popMove(SA, SB);
            }
        }

        while((*SB).top != -1) {
            popMove(SB, SA);
            count++;
        }

    }
}

void printStack(stack S, int mode, int noStack)
{
    //kondisi jika stack utama yang di print
    if(mode == 1) {
        printf("stack %d:\n", noStack);
    }
    //kondisi jika stack sementara yang di print
    else {
        printf("batas stack %d\n", noStack);
    }

    
    if (S.top != -1)
    {
        int i;
        //itr untuk nomor keluaran 
        int itr = 1;
        //pengulangan untuk keluaran
        for (i = S.top; i >= 0; i--)
        {
            printf("%s %s\n", S.data[i].nama, S.data[i].merek);
            itr++;
        }
    }
    else
    {
        /* proses jika stack kosong */
        if(mode == 1) {
            printf("kosong\n");
        }
    }

    if(mode == 1) {
        printf("\n");
    }
}