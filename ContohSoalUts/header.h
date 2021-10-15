#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    int angkaPembagi;
} mahasiswa;

typedef struct
{
    char kode[10];
    char nilai[2];
    int angkaDibagi;
} matkul;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    matkul kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamtebaris;
typedef struct ebr
{
    mahasiswa kontainer;
    eKolom *col;
    alamtebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(int angkaPembagi, list *L);
void addFirstK(int angkaDibagi, eBaris *L);
void addAfterB(eBaris *prev, int angkaPembagi);
void addAfterK(eKolom *prev, int angkaDibagi);
void addLastB(int angkaPembagi, list *L);
void addLastK(int angkaDibagi, eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
void createRowNumber(list *L);
void groupRowNumber(int angkaDibagi, list *L);
void delEmptyCol(list *L);