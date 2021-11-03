#include <stdio.h>
#include <malloc.h>
#include <string.h>
//membuat tipe data terstruktur untuk menampung makanan
typedef struct
{
    char harga[10];
    char nama[50];
} makanan;
//menginisialisasikan tipe data terstruktur dari next
typedef struct elmt *alamatelmt;
//membuat tipe data terstruktur untuk menampung elemen
typedef struct elmt
{
    makanan kontainer;
    alamatelmt next;
} elemen;
//membuat tipe data terstruktur untuk menampung stack
typedef struct
{
    elemen *top;
} stack;
/* 
** createEmpty= prosedur untuk menetapkan nilai awal dari list
** isFull = fungsi untuk menetapkan stack penuh
** isEmpty = fungsi untuk menetapkan stack kosong
** push = prosedur untuk menambahkan nilai mulai dari belakang
**  pop = prosedur untuk menghapus nilai mulai dari atas
** popMove = prosedur untuk mengeluarkan data stack1 dan memasukannya ke stack2
** printStack = prosedur untuk menampilkan hasil
 */
void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char harga[], char nama[], stack *S);
void pop(stack *S);
void popMove(stack *SA, stack *SB);
void printStack(stack S, int mode);