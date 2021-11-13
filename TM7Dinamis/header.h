#include <stdio.h>
#include <malloc.h>
#include <string.h>
//membuat tipe data terstruktur untuk menampung data mahasiswa
typedef struct
{
    char nim[50];
    char nama[50];
} mahasiswa;
//menginisialisasikan tipe data terstruktur dari next
typedef struct elm *alamatelmt;
//membuat tipe data terstruktur untuk menampung elemen
typedef struct elm
{
    mahasiswa kontainer;
    alamatelmt next;
} elemen;

//membuat tipe data terstruktur untuk menampung queue
typedef struct
{
    elemen *first;
    elemen *last;
} queue;

/* 
** createEmpty= prosedur untuk menetapkan nilai awal dari list
** isFull = fungsi untuk menetapkan stack penuh
** isEmpty = fungsi untuk menetapkan stack kosong
** add = prosedur untuk menambahkan nilai mulai depan
** del = prosedur untuk menghapus nilai mulai yang pertama masuk
** printQueue = prosedur untuk menampilkan hasil
** addPriority = prosedur untuk menempatkan masukan sesuai dengan prioritas posisinya
** addAfter = prosedur untuk menambahkan masukan setelah nilai yang ada di parameter
** addFirst = prosedur untuk emmasukan nilai di awal
 */
void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nim[], char nama[], queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int mode);
void addAfter(elemen* prev, char nama[], char nim[], queue *Q);
void addFirst(char nama[], char nim[], queue *Q);
void addPriority(queue *Q, int number, char nim[], char nama[]);