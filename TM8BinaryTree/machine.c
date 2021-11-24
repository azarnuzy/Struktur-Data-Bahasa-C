#include "header.h"

void makeTree(char c, tree *T)
{
    //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
    simpul *baru;
    //menginisialisasi besarnya nilai dari baru
    baru = (simpul *)malloc(sizeof(simpul));
    //memasukan nilai karakter terhadap variabel baru
    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    //membuat nilai baru menjadi null
    baru = NULL;
}

void addRight(char c, simpul *root)
{
    if (root->right == NULL)
    {
        /*jika sub pohon kanan kosong*/
        //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
        simpul *baru;
        //menginisialisasi besarnya nilai dari baru
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
        //memasukan nilai baru ke root branch kanan
        root->right = baru;
    }
    else
    {
        printf("sub pohon kanan telah terisi \n");
    }
}

void addLeft(char c, simpul *root)
{
    if (root->left == NULL)
    {
        /*jika sub pohon kiri kosong*/
        //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
        simpul *baru;
        //menginisialisasi besarnya nilai dari baru
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
        //memasukan nilai baru ke root branch kanan
        root->left = baru;
    }
    else
    {
        printf("sub pohon kiri telah terisi \n");
    }
}

void delAll(simpul *root)
{

    if (root != NULL)
    {
        //menghapus node secara rekursif
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(simpul *root)
{

    if (root != NULL)
    {
        if (root->right != NULL)
        {
            //menghapus node kanan secara rekursif
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(simpul *root)
{

    if (root != NULL)
    {
        if (root->left != NULL)
        {
            //menghapus node kiri secara rekursif
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *root)
{
    if (root != NULL)
    {
        //iterasi untuk kondisi dari keluaran
        count--;
        if (count > 0)
        {
            printf("%c - ", root->kontainer);
        }
        else if (count == 0)
        {
            printf("%c\n", root->kontainer);
        }
        //menelusuri node secara pre order
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(simpul *root)
{

    if (root != NULL)
    {
        //menelusuri node secara in order
        printTreeInOrder(root->left);
        //iterasi untuk kondisi new line pada keluaran
        count--;
        if (count > 0)
        {
            printf("%c - ", root->kontainer);
        }
        else if (count == 0)
        {
            printf("%c\n", root->kontainer);
        }
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root)
{

    if (root != NULL)
    {
        //menelusuri node secara post order
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        //iterasi untuk kondisi new line pada keluaran
        count--;
        if (count > 0)
        {
            printf("%c - ", root->kontainer);
        }
        else if (count == 0)
        {
            printf("%c\n", root->kontainer);
        }
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        if (root1->left != NULL)
        {
            copyTree(root1->left, &(*root2)->left);
        }
        if (root1->right != NULL)
        {
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

int isEqual(simpul *root1, simpul *root2)
{

    int hasil = 1;

    if ((root1 != NULL) &&
        (root2 != NULL))
    {
        /* jika simpul pohon 1 dan pohon 2 sama sama tidak NULL */
        if (root1->kontainer != root2->kontainer)
        {
            /* jika isi kontainer simpul pohon 1 dan pohon 2 tidak sama */
            hasil = 0;
        }
        else
        {
            /* jika isi kontainer simpul pohon 1 dan simpul pohon 2 sama, maka telusuri simpul selanjutnya */
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }
    else
    {
        if ((root1 != NULL) ||
            (root2 != NULL))
        {
            /* jika salah satu simpul ada yang NULL */
            hasil = 0;
        }
    }

    return hasil;
}