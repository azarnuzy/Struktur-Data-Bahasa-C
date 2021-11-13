#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    char nim[20];
    char nama[50];
} nilaiMatkul;

typedef struct elm *alamatelmt;

typedef struct elm {
    nilaiMatkul kontainer;
    alamatelmt next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nim[], char nama[], queue *Q);
void addPriority(char nim[], char nama[], int priority, queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, char Queue[]);