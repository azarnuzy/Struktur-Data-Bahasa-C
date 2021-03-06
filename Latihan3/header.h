#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int angka;
}stringHuruf;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    stringHuruf kontainer;
    alamatelmt next;
}elemen;

typedef struct {
    elemen *first;
}list;

void createList (list *L);
int countElement(list L);
void addFirst(int angka, list *L);
void addAfter(elemen* prev, int angka, list *L);
void addLast(int angka, list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);