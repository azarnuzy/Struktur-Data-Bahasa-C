#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UAS 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//sebagai variabel untuk menghitung banyaknya input
int count;
//sebagai variabel untuk menampung hasil keluaran
int keluaran[100];
//menginisialisasikan tipe data terstruktur dari right dan left
typedef struct smp *alamatsimpul;
//membuat tipe data tersetruktur untuk menampung elemen
typedef struct smp
{
    int kanan;
    int kiri;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

//membuat tipe data tersetruktur untuk menampung queue
typedef struct
{
    simpul *root;
} tree;

/* 
**makeTree = prosedur untuk membuat root dari tree
**addRight, addLeft = prosedur untuk membuat node kanan dan kiri dari tree
**deAll, delRight, delLeft = prosedur untuk menghapus semua node, node kanan dan node kiri
**printTreeInOrder, printTreePreOrder, printTreePostOrder = prosedur untuk menampilkan tree secara preoreder, inorder, postorder
**copyTree = prosedur untuk menyalin dari satu tree ke tree lain
**isEqual = prosedur untuk membandingkan tree satu dan tree yang lain
 */
void makeTree(int kiri, int kanan, tree *T);
void addRight(int kiri, int kanan, simpul *root);
void addLeft(int kiri, int kanan, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
int countNode(simpul *root);
void inputData(int kiri, int kanan, simpul *root, int done);