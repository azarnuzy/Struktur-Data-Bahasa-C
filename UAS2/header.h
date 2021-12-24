#include <stdio.h>
#include <malloc.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UAS 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//menginisialisasikan tipe data terstruktur dari alamat simpul
typedef struct smp *alamatsimpul;
//menginisialisasikan tipe data terstruktur dari alamat jalur
typedef struct jlr *alamatjalur;
//membuat tipe data tersetruktur untuk menampung simpul
typedef struct smp
{
    char kontainer;
    int visited;
    alamatsimpul next;
    alamatjalur arc;
} simpul;
//membuat tipe data tersetruktur untuk menampung jalur
typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;
//membuat tipe data tersetruktur untuk menampung graph
typedef struct
{
    simpul *first;
} graph;
/* 
**create = prosedur untuk membuat root dari Graph 
**addSimpul, addJalur = prosedur untuk menambahkan node dan jalur pada Graph 
**deAll, delJalur, delSimpul = prosedur untuk menghapus semua node, node jalur dan node 
**printGraph = prosedur untuk menampilkan Graph  
**findSimpul = fungsi untuk mendapatkan simpul 
 */
void createEmpty(graph *G);
void addSimpul(char c, graph *G);
void addJalur(simpul *awal, simpul *tujuan, int beban);
simpul *findSimpul(char c, graph G);
void delJalur(int ctujuan, simpul *awal);
void delAll(simpul *awal);
void delSimpul(char c, graph *G);
void printGraph(graph G);
void cekRoute(graph G, simpul *node);
void cekVisited(graph G);