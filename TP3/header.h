#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP 4 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//membuat tipe data terstruktur untuk menampung makanan
typedef struct
{
    char tahun[50];
    char judul[50];
    char band[50];
} makanan;
//membuat tipe data terstruktur untuk menampung stack
typedef struct
{
    int top;
    makanan data[10];
} stack;
/* 
** createEmpty= prosedur untuk menetapkan nilai awal dari list
** isFull = fungsi untuk menetapkan stack penuh
** isEmpty = fungsi untuk menetapkan stack kosong
** push = prosedur untuk menambahkan nilai mulai dari belakang
**  pop = prosedur untuk menghapus nilai mulai dari atas
** printStack = prosedur untuk menampilkan hasil
 */
void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char judul[], char tahun[], char band[], stack *S);
void pop(stack *S);
void popMove(stack *SA, stack *SB);
void printStack(stack S, int mode);
int countASCII(char judul[]);