#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi KUIS 1 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//membuat tipe data terstruktur untuk menampung data menu warung dan  namamenuTukar
typedef struct {
    char nama[50];
    char harga[50];
}menuWarung;
typedef struct {
    char nama1[50], nama2[50];
}namaMenuTukar;
//menginisialisasikan tipe data terstruktur dari next
typedef struct elmt *alamatelmt;
//membuat tipe data terstruktur untuk menampung elemen
typedef struct elmt {
    menuWarung kontainer;
    alamatelmt next;
}elemen;
//membuat tipe data terstruktur untuk menampung list
typedef struct {
    elemen *first;
}list;
/* 
** createList= prosedur untuk menetapkan nilai awal dari list
** countElement = fungsi untuk menghitung jumlah list yang ada
** emptyElement = fungsi untuk menetapkan elemen mana yang kosong
** addfirst, addafter, addlast = prosedur untuk menambahkan nilai
**  delFirst, delAfter, delLast = prosedur untuk menghapus nilai
** printElement = prosedur untuk menampilkan hasil
** searchMenu = prosedur untuk mengurutkan nilai 
 */
void createList (list *L);
int countElement(list L);
void addFirst(char nama[], char harga[], list *L);
void addAfter(elemen* prev, char nama[], char harga[], list *L);
void addLast(char nama[], char harga[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void searchMenu(list *L1, list *L2, namaMenuTukar menuTukar[], int m, char lastMenu1[], char lastMenu2[]);