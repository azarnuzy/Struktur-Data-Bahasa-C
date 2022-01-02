#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal TMD 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

/* 
** tempDept = variabel untuk menyimpan kedalaman sementara dari tree
** firstDepth = variabel untuk menyimpan kedalaman pertama yang akan diproses
** levelSpace = array untuk menyimpan banyaknya spasi pada setiap level tree
** baris = variabel untuk menunjukan baris mana yang sedang di proses
 */
int tempDepth;
int firstDepth;
int levelSpace[1000];
int baris;

/* 
** type struct data: berisi mengenai variabel yang nanti dijadikan sebagai informasi dari input
 */
typedef struct
{
    char nodeParent[100]; // sebagai node parent
    char nodeChild[100];  // sebagai node child
    int jumlahKorban;     // sebagai jumlah korban
} data;

//menginisialisasikan tipe data terstruktur dari alamat simpul
typedef struct smp *alamatsimpul;
//membuat tipe data tersetruktur untuk menampung elemen
typedef struct smp
{
    char kontainer[100];  // sebagai kata dari simpul anak
    char parent[100];     // sebagai kata dari simpul parent
    int jumlahKorban;     // sebagai jumlah korban
    int jmlSpace;         // sebagai jumlah spasi pada simpul tersebut
    int depth;            // sebagai kedalaman dari simpul tersebut
    alamatsimpul sibling; // sebagai sodara dari simpul tersebut
    alamatsimpul child;   // sebagai anak dari simpul tersebut
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
**printTreePreOrder = prosedur untuk menampilkan tree secara preoreder
**sumJmlKorban = prosedur untuk menghitung jumlah korban dimulai dari anak paling bawah
**setSpace = prosedur untuk menghitung jumlah spasi pada setiap level
**resetSpace = prosedur untuk mereset spasi 
**printSpace = prosedur untuk menampilkan spasi 
**copyTree = prosedur untuk menyalin dari satu tree ke tree lain
**isEqual = prosedur untuk membandingkan tree satu dan tree yang lain
**findSimpul = fungsi untuk mendapatkan simpul 
*/
void makeTree(data dataSplit, tree *T);
data hasilSplit(char input[], int mode);
void addChild(data dataSplit, simpul *root, simpul *akar);
void addChildDesc(data dataSplit, simpul *root, simpul *akar);
void delAll(simpul **root);
void delChild(char c[], simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root);
int countJmlKorban(simpul *root);
void countAllJmlKorban(simpul *root);
void setSpace(simpul *root);
void resetSpace();
void printSpace(int depth);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);