#include <stdio.h>
#include <malloc.h>
#include <string.h>

//membuat tipe data terstruktur untuk menampung data mahasiswa
typedef struct {
    char nama[10];
    char matkul[50];
    char nilai[2];
}mahasiswa;

//menginisialisasikan tipe data terstruktur dari next
typedef struct elmt *alamatelmt;

//membuat tipe data terstruktur untuk menampung elemen
typedef struct elmt {
    mahasiswa kontainer;
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
** addfirst, addafter, addlast = prosedur untuk menambahkan nilai
**  delFirst, delAfter, delLast = prosedur untuk menghapus nilai
** printElement = prosedur untuk menampilkan hasil
** printReverse = prosedur untuk menampilkan hasil dengan urutan terbalik
 */
void createList (list *L);
int countElement (list L);
void addFirst (char nama[], char matkul[], char nilai[], list *L);
void addAfter(elemen* before, char nama[], char matkul[], char nilai[], list *L);
void addBefore(elemen* after, char nama[], char matkul[], char nilai[], list *L);
void addLast (char nama[], char matkul[], char nilai[], list *L);
void delFirst (list *L);
void delAfter(elemen* before, list *L);
void delLast (list *L);
void printElement(list L);
void printReverse(list L);
void delAll(list *L);