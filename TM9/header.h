#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[100];
    int nilai;
} data;
//menginisialisasikan tipe data terstruktur dari alamat simpul
typedef struct smp *alamatsimpul;
//membuat tipe data tersetruktur untuk menampung elemen
typedef struct smp
{
    char kontainer[100];
    int nilai;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;
//membuat tipe data tersetruktur untuk menampung tree
typedef struct
{
    simpul *root;
} tree;
/* 
**makeTree = prosedur untuk membuat root dari tree
**addChild = prosedur untuk membuat node kanan dan kiri dari tree
**deAll, delChild = prosedur untuk menghapus semua node, node kanan dan node kiri
**printTreePreOrder, printTreePostOrder = prosedur untuk menampilkan tree secara preoreder, inorder, postorder
**copyTree = prosedur untuk menyalin dari satu tree ke tree lain
**isEqual = prosedur untuk membandingkan tree satu dan tree yang lain
**findSimpul = fungsi untuk mendapatkan simpul 
 */
void makeTree(data dataSplit, tree *T);
void addChild(data dataSplit, simpul *root);
void delAll(simpul **root);
void delChild(simpul *c, simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root, int *n);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);