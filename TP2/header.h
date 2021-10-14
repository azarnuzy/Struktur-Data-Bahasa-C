#include <stdio.h>
#include <malloc.h>
#include <string.h>

//membuat tipe data terstruktur untuk menampung data PC
typedef struct {
    char nama[50];
    int harga;
    int kode;
}PC;

//menginisialisasikan tipe data terstruktur dari next
typedef struct elmt *alamatelmt;

//membuat tipe data terstruktur untuk menampung elemen
typedef struct elmt {
    PC kontainer;
    alamatelmt prev;
    alamatelmt next;
}elemen;
//membuat tipe data terstruktur untuk menampung list
typedef struct {
    elemen *first;
    elemen *tail;
}list;

/* 
** createList= prosedur untuk menetapkan nilai awal dari list
** countElement = fungsi untuk menghitung jumlah list yang ada
** swap = prosedur untuk menukar kontainer
** multiDynamicSortingList = prosedur untuk mengurutkan list 
** addfirst, addafter, addlast = prosedur untuk menambahkan nilai
**  delFirst, delAfter, delLast = prosedur untuk menghapus nilai
** printElement = prosedur untuk menampilkan hasil
 */
void createList (list *L);
int countElement (list L);
void swap(elemen* x, elemen* y);
void multiDynamicSortingList(list *L, char metode1[], char metode2[]);
void addFirst (char nama[], int harga, int kode, list *L);
void addAfter(elemen* before, char nama[], int harga, int kode, list *L);
void addLast (char nama[], int harga, int kode, list *L);
void delFirst (list *L);
void delAfter(elemen* before, list *L);
void delLast (list *L);
void delAll(list *L);
void printElement(list L);