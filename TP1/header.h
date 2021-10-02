#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
    int harga;
    float rating;
}makanan;

typedef struct elmt *alamatElmt;
typedef struct elmt {
    makanan kontainer;
    alamatElmt next;
}elemen;

typedef struct {
    elemen *first;
}list;

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