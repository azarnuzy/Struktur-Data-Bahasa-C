#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UTS 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//membuat tipe data terstruktur untuk menampung data restoran 
typedef struct
{
    char nama[200];
    char menuSwitch[200];
}restoran;
//membuat tipe data terstruktur untuk menampung data menu restoran
typedef struct
{
    char namaMenu[200];
    int harga;
} menuRestoran;
//menginisialisasikan tipe data terstruktur dari next_col
typedef struct eklm *alamatekolom;
//membuat tipe data terstruktur untuk menampung elemen Kolom
typedef struct eklm
{
    menuRestoran kontainer_kol;
    alamatekolom next_kol;
} eKolom;
//menginisialisasikan tipe data terstruktur dari next_col
typedef struct ebr *alamtebaris;
//membuat tipe data terstruktur untuk menampung elemen baris
typedef struct ebr
{
restoran kontainer;
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
** getLatestBaris = fungsi untuk menemukan baris akhir yang nantinya akan dijadikan paramater pada addK
** tunjukBaris = fungsi untuk menemukan baris yang nantinya akan dijadikan parameter pada addK
** switchMenu = prosedur untuk menentukan 
 */
void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(restoran namaRestoran, list *L);
void addFirstK(menuRestoran dataMenu,  eBaris *L);
void addAfterB(eBaris *prev, restoran namaRestoran, list *L);
void addAfterK(eKolom *prev, menuRestoran dataMenu) ;
void addLastB(restoran namaRestoran, list *L);
void addLastK(menuRestoran dataMenu,  eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
eBaris* getLatestBaris(list L, char nama[]);
eBaris *tunjukBaris(list L, char nama[]);
void switchMenu(restoran masukanDari, restoran masukanKe, list *L);