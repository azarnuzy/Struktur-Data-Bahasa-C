#include <stdio.h>
#include <string.h>

//membuat tipe data terstruktur untuk menampung data sepatu
typedef struct
{
    char merek[50];
    char warna[50];
    int ukuran;
}dataSepatu;

//membuat tipe data terstruktur untuk menampung elemen
typedef struct 
{
    dataSepatu kontainer;
    int next;
}elemen;

//membuat tipe data terstruktur untuk menampung list
typedef struct{
    int first;
    elemen data[10];
}list;

/* 
*createList= prosedur untuk menetapkan nilai awal dari list
*countElement = fungsi untuk menghitung jumlah list yang ada
*emptyElement = fungsi untuk menetapkan elemen mana yang kosong
*addfirst, addafter, addlast = prosedur untuk menambahkan nilai
* delFirst, delAfter, delLast = prosedur untuk menghapus nilai
*printElement = prosedur untuk menampilkan hasil
 */
void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char merek[], char warna[], int ukuran, list *L);
void addAfter(int prev, char merek[], char warna[], int ukuran, list *L);
void addLast(char merek[], char warna[], int ukuran, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);