#include <stdio.h>
#include <string.h>
//membuat tipe data terstruktur untuk menampung makanan
typedef struct
{
    char harga[10];
    char nama[50];
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
void push(char harga[], char nama[], stack *S);
void pop(stack *S);
void popMove(stack *SA, stack *SB);
void printStack(stack S, int mode);