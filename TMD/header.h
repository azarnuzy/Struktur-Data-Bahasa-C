#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int spaceCount[100];

typedef struct
{
    char nodeParent[100];
    char nodeChild[100];
    int jumlahKorban;
} data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer[100];
    int jumlahKorban;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char c[], tree *T);
data hasilSplit(char input[], int mode);
void addChild(char c[], int jumlahKorban, simpul *root);
void delAll(simpul *root);
void delChild(char c[], simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);