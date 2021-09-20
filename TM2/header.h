#include <stdio.h>
#include <malloc.h>
#include <string.h>

//membuat tipe data terstruktur untuk menampung data nama senyawa kimia
typedef struct {
    char nama[50];
    char rumus[50];
    char konsentrasi[10];
}senyawaKimia;

//menginisialisasikan tipe data terstruktur dari next
typedef struct elmt *alamatelmt;

//membuat tipe data terstruktur untuk menampung elemen
typedef struct elmt {
    senyawaKimia kontainer;
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
 */
void createList (list *L);
int countElement(list L);
void addFirst(char nama[], char rumus[], char konsentrasi[], list *L);
void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L);
void addLast(char nama[], char rumus[], char konsentrasi[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);