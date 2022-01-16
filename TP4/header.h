#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP 4 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//membuat tipe data terstruktur untuk menampung data antrian
typedef struct
{
    char nama[50];
    char member[50];
    int menit;
    int noAntrian;
} antrian;
//menginisialisasikan tipe data terstruktur dari next
typedef struct elm *alamatelmt;
//membuat tipe data terstruktur untuk menampung elemen
typedef struct elm
{
    antrian kontainer;
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
void add(antrian data, queue *Q);
void delMove(queue *Q1, queue *Q2);
void del(queue *Q);
void printQueue(queue Q);
int delQueuePasien(queue Q);
void addPriority(queue *Q, int number, antrian data);