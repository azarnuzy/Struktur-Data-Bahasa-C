#include <stdio.h>
#include <malloc.h>
#include <string.h>

//membuat tipe data terstruktur untuk menampung data nama senyawa kimia
typedef struct {
    char nama[50];
    int harga;
    float rating;
}makanan;

//menginisialisasikan tipe data terstruktur dari next
typedef struct elmt *alamatElmt;

//membuat tipe data terstruktur untuk menampung elemen
typedef struct elmt {
    makanan kontainer;
    alamatElmt next;
}elemen;

//membuat tipe data terstruktur untuk menampung list
typedef struct {
    elemen *first;
}list;

/* 
** createList= prosedur untuk menetapkan nilai awal dari list
** countElement = fungsi untuk menghitung jumlah list yang ada
** emptyElement = fungsi untuk menetapkan elemen mana yang kosong
** sortDinamyc = prosedur untuk mengurutkan posisi dari elemen sesuai dengan rating
** addfirst, addafter, addlast = prosedur untuk menambahkan nilai
** delFirst, delAfter, delLast = prosedur untuk menghapus nilai
** dapatDibeli = fungsi untuk menghitung menu yang dapat dibeli sesuai uang yang ada 
** printElement = prosedur untuk menampilkan hasil
 */
void createList(list *L);
int countElement(list L);
void addFirst(char nama[], int harga, float rating, list *L);
void addAfter(elemen* prev, char nama[], int harga, float rating, list *L);
void addLast(char nama[], int harga, float rating, list *L);
void sortDinamyc(list L1, list *L2, char urutanMenu[]);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void delAll(list *L);
int dapatDibeli(list *L, int banyakUang);
void printElement(list L);