#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi KUIS 1 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat tipe data terstruktur untuk menampung pola kata
typedef struct{
    char kata[50];
}polaString;
//membuat tipe data terstruktur untuk menampung elemen
typedef struct {
    polaString kontainer;
    int prev;
    int next;
}elemen;
//membuat tipe data terstruktur untuk menampung list
typedef struct {
    int first;
    int tail;
    elemen data[100];
}list;

/* 
** createList= prosedur untuk menetapkan nilai awal dari list
** countElement = fungsi untuk menghitung jumlah list yang ada
** emptyElement = fungsi untuk menetapkan elemen mana yang kosong
** addfirst, addafter, addlast = prosedur untuk menambahkan nilai
** polaList2 = prosedur untuk menampilkan pola list yang diminta
 */
void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char kata[], list *L);
void addAfter(int before, char kata[], list *L);
void addLast(char kata[], list *L);
void polaList2(list L, int n);