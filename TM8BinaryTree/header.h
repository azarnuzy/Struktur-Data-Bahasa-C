#include <stdio.h>
#include <malloc.h>

//sebagai variabel untuk menghitung banyaknya input
char count;

//menginisialisasikan tipe data terstruktur dari right dan left
typedef struct smp *alamatsimpul;
//membuat tipe data tersetruktur untuk menampung elemen
typedef struct smp
{
    char kontainer;
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
void makeTree(char c, tree *T);
void addRight(char c, simpul *root);
void addLeft(char c, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
int countNode(simpul *root);