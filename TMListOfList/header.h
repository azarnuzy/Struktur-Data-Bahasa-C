#include <stdio.h>
#include <malloc.h>
#include <string.h>
//definsikan perulangan dengan sintaks singkat forIn
#define forIn(i, b) for(i=0;i<b;i++)

typedef struct{
	char nama[100];
	int tahun;
}tim;
//deklarasikan bungkusan nilai matkul berisikan nama, jenis kelamin dan nilai
typedef struct{
	char nama_pemain[100];
}pemain;

typedef struct elkl* alamatKolom;

typedef struct elkl{
	pemain kontainer_kol;
	alamatKolom next_kol;
}eKolom;

//struct pointer sembarang
typedef struct elbr* alamatBaris;

typedef struct elbr{
	tim kontainer;
	eKolom *col;
	alamatBaris next;
}eBaris;
//deklarasikan bungkusan list berisikan pointer indeks data yang dituju dan datanya sendiri
typedef struct{
	eBaris *first;
}list;

int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(tim dataTim, list *L);
void addFirstK(pemain dataPemain, eBaris *L);
void addAfterB(eBaris* prev, tim dataTim);
void addAfterK(eKolom* prev, pemain dataPemain);
void addPriorityB(tim dataTim, list *L);
void addLastK(pemain dataPemain, eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);
/*tambahkan fungsi ini untuk mendapatkan elemen baris yang terakhir diinputkan*/
eBaris* getLatestBaris(list L, char nama[]);
void createList(list *L);
void printElement(list L);