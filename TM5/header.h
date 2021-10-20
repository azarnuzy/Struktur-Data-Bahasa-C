#include <stdio.h>
#include <malloc.h>
#include <string.h>
//membuat tipe data terstruktur untuk menampung data Club 
typedef struct
{
    char nama[50];
    int tahun;
} timTahun;
//membuat tipe data terstruktur untuk menampung data Pemain dari club
typedef struct
{
    char namaPemain[50];
} Pemain;
//menginisialisasikan tipe data terstruktur dari next_col
typedef struct eklm *alamatekolom;
//membuat tipe data terstruktur untuk menampung elemen Kolom
typedef struct eklm
{
    Pemain kontainer_kol;
    alamatekolom next_kol;
} eKolom;
//menginisialisasikan tipe data terstruktur dari next_col
typedef struct ebr *alamtebaris;
//membuat tipe data terstruktur untuk menampung elemen baris
typedef struct ebr
{
    timTahun kontainer;
    eKolom *col;
    alamtebaris next;
} eBaris;
//membuat tipe data terstruktur untuk menampung list
typedef struct
{
    eBaris *first;
} list;
/* 
** createList= prosedur untuk menetapkan nilai awal dari list
** countElement = fungsi untuk menghitung jumlah list yang ada
** addfirstB, addafterB, addlastB = prosedur untuk menambahkan nilai baris
** addfirstK, addafterK, addlastK = prosedur untuk menambahkan nilai kolom
**  delFirstB, delAfterB, delLastB = prosedur untuk menghapus nilai baris
**  delFirstK, delAfterK, delLastK = prosedur untuk menghapus nilai kolom
** printElement = prosedur untuk menampilkan hasil
** tunjukBaris = fungsi untuk menemukan baris yang nantinya akan dijadikan parameter pada addK
** sortList = prosedur untuk menentukan 
 */
void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char nama[], int tahun, list *L);
void addFirstK(char namaPemain[],  eBaris *L);
void addAfterB(eBaris *prev, char nama[], int tahun, list *L);
void addAfterK(eKolom *prev, char namaPemain[]) ;
void addLastB(char nama[], int tahun, list *L);
void addLastK(char namaPemain[],  eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
void swap(eBaris *a, eBaris *b);
eBaris *tunjukBaris(list L2, int tahun);
void sortList(list L1,list *L2);