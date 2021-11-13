#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 2 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//membuat tipe data terstruktur untuk menampung data bantuan
typedef struct
{
    char nama[50];
    int noPrioritas;
    char uang[50];
    char kota[50];
} bantuan;
//menginisialisasikan tipe data terstruktur dari next
typedef struct elm *alamatelmt;
//membuat tipe data terstruktur untuk menampung elemen
typedef struct elm
{
    bantuan kontainer;
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
 */
void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(bantuan data, queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int mode);
void addPriority(queue *Q,int number,  bantuan data);