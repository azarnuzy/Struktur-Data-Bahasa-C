#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
}nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    nilaiMatkul kontainer;
    alamatelmt prev;
    alamatelmt next;
}elemen;

typedef struct {
    elemen *first;
    elemen *tail;
}list;

void createList (list *L);
int countElement (list L);
void addFirst ( char nama[], list *L);
void addAfter(elemen* before,  char nama[], list *L);
void addLast ( char nama[], list *L);
void delFirst (list *L);
void delAfter(elemen* before, list *L);
void delLast (list *L);
void printElement(list L);
void delAll(list *L);
void swapDawala(list *L);