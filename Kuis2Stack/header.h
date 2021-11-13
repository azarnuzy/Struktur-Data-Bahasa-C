#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 2 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat tipe data terstruktur untuk menampung pakaian
typedef struct
{
    char merek[50];
    char nama[50];
} pakaian;
//membuat tipe data terstruktur untuk menampung stack
typedef struct
{
    int top;
    pakaian data[100];
} stack;
/* 
** createEmpty= prosedur untuk menetapkan nilai awal dari list
** isFull = fungsi untuk menetapkan stack penuh
** isEmpty = fungsi untuk menetapkan stack kosong
** push = prosedur untuk menambahkan nilai mulai dari belakang
**  pop = prosedur untuk menghapus nilai mulai dari atas
** findPakain = prosedur untuk mencari pakaain pada tumpukan utama
** findPakaian = prosedur untuk mencari pakaian pada tumpukan sementara
** printStack = prosedur untuk menampilkan hasil
 */
void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char merek[], char nama[], stack *S);
void pop(stack *S);
void popMove(stack *SA, stack *SB);
void findPakaian(stack *SA, stack *SB, char nama[]);
void findTempPakaian(stack *SA, stack *SB, char nama[]);
void printStack(stack S, int mode, int noStack);