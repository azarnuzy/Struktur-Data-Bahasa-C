#include <stdio.h>
#include <string.h>

//membuat tipe data terstruktur untuk menampung data smartphone
typedef struct {
    char merek[10];
    char tipe[50];
    int jumlah;
}smartphone;

//membuat tipe data terstruktur untuk menampung elemen
typedef struct {
    smartphone kontainer;
    int prev;
    int next;
}elemen;

//membuat tipe data terstruktur untuk menampung list
typedef struct {
    int first;
    int tail;
    elemen data[10];
}list;

/* 
** createList= prosedur untuk menetapkan nilai awal dari list
** countElement = fungsi untuk menghitung jumlah list yang ada
** emptyElement = fungsi untuk menetapkan elemen mana yang kosong
** addfirst, addafter, addlast = prosedur untuk menambahkan nilai
**  delFirst, delAfter, delLast = prosedur untuk menghapus nilai
** printElement = prosedur untuk menampilkan hasil
** printReverse = prosedur untuk menampilkan hasil dengan urutan yang dibalik
 */
void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char merek[], char tipe[], int jumlah, list *L);
void addAfter(int before, char merek[], char tipe[], int jumlah, list *L);
void addLast(char merek[], char tipe[], int jumlah, list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void printReverse(list L);
void delAll(list *L);