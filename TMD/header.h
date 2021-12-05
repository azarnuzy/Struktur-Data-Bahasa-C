#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int tempDepth;
int itr;
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
    char parent[100];
    int jumlahKorban;
    int jmlSibling;
    int depth;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(data dataSplit, tree *T);
data hasilSplit(char input[], int mode);
void addChild(data dataSplit, simpul *root, simpul *akar);
void addChildAsc(data dataSplit, simpul *root, simpul *akar);
void delAll(simpul **root);
void delChild(char c[], simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root, int *sumJmlKorban);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
void sortingNode(simpul *root, int iterasi);