#include <stdio.h>
#include <string.h>
//membuat tipe data terstruktur untuk menampung data mahasiswa
typedef struct
{
    char nim[50];
    char nama[50];
} mahasiswa;
//membuat tipe data terstruktur untuk menampung queue
typedef struct
{
    int first;
    int last;
    mahasiswa data[10];
} queue;
/* 
** createEmpty= prosedur untuk menetapkan nilai awal dari list
** isFull = fungsi untuk menetapkan stack penuh
** isEmpty = fungsi untuk menetapkan stack kosong
** add = prosedur untuk menambahkan nilai mulai depan
** del = prosedur untuk menghapus nilai mulai yang pertama masuk
** printQueue = prosedur untuk menampilkan hasil
 */
void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nim[], char nama[], queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int mode);
void addPriority(queue *Q, int number, char nim[], char nama[]) ;