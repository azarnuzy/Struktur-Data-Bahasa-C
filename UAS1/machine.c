#include "header.h"

void makeTree(int kiri, int kanan, tree *T)
{
    //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
    simpul *baru;
    //menginisialisasi besarnya nilai dari baru
    baru = (simpul *)malloc(sizeof(simpul));
    //memasukan nilai karakter terhadap variabel baru

    baru->kanan = kanan;
    baru->kiri = kiri;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    //membuat nilai baru menjadi null
    baru = NULL;
}

void addRight(int kiri, int kanan, simpul *root)
{
    if (root->right == NULL)
    {
        /*jika sub pohon kanan kosong*/
        //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
        simpul *baru;
        //menginisialisasi besarnya nilai dari baru
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kanan = kanan;
        baru->kiri = kiri;
        // printf("kanan %d %d\n", kiri, kanan);
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

void addLeft(int kiri, int kanan, simpul *root)
{
    if (root->left == NULL)
    {
        /*jika sub pohon kiri kosong*/
        //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
        simpul *baru;
        //menginisialisasi besarnya nilai dari baru
        baru = (simpul *)malloc(sizeof(simpul));
        // printf("kiri %d %d\n", kiri, kanan);
        baru->kanan = kanan;
        baru->kiri = kiri;
        baru->right = NULL;
        baru->left = NULL;
        //memasukan nilai baru ke root branch kanan
        root->left = baru;
    }
}

void inputData(int kiri, int kanan, simpul *root, int done)
{
    //kondisi dimana simpul  bisa dibagi sebanyak lebih dari satu kali lagi
    if (kiri / 4 != 0 && kanan / 4 != 0)
    {
        //menambahkan simpul pada bagian kiri
        addLeft(kiri / 2, kanan, root);
        //rekursif dengan kondisi nilai kiri dibagi 2
        inputData(root->kiri / 2, kanan, root->left, 0);
        //menambahkan simpul pada bagian kanan
        addRight(kiri, kanan / 2, root);
        //rekursif dengan kondisi nilai kanan dibagi 2
        inputData(root->kiri, root->kanan / 2, root->right, 0);
    }
    //kondisi dimana simpul bisa dibagi hanya satu kali lagi
    else
    {
        //kondisi dimana simpul bisa dibagi 2
        if (kiri / 2 != 0 && kanan / 2 != 0)
        {
            //menambahkan simpul pada bagian kiri
            addLeft(kiri / 2, kanan, root);
            //menampung nilai dari keluaran
            keluaran[count] = kiri / 2;
            keluaran[count + 1] = kanan;
            count += 2;
        }
        //kondisi dimana simpul bisa dibagi 2
        if (kanan / 2 != 0 && kiri / 2 != 0)
        {
            //menambahkan simpul pada bagian kanan
            addRight(kiri, kanan / 2, root);
            //menampung nilai dari keluaran
            keluaran[count] = kiri;
            keluaran[count + 1] = kanan / 2;
            count += 2;
        }
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
            printf("%d %d", root->kiri, root->kanan);
        }
        else if (count == 0)
        {
            printf("%d %d\n", root->kiri, root->kanan);
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
            printf("%d - ", root->kanan);
        }
        else if (count == 0)
        {
            printf("%d\n", root->kanan);
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
            printf("%d %d ", root->kiri, root->kanan);
        }
        else if (count == 0)
        {
            printf("%d %d\n", root->kiri, root->kanan);
        }
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kanan = root1->kanan;

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

    if ((root1 != NULL) && (root2 != NULL))
    {
        /* jika simpul pohon 1 dan pohon 2 sama sama tidak NULL */
        if (root1->kanan != root2->kanan)
        {
            /* jika isi kanan simpul pohon 1 dan pohon 2 tidak sama */
            hasil = 0;
        }
        else
        {
            /* jika isi kanan simpul pohon 1 dan simpul pohon 2 sama, maka telusuri simpul selanjutnya */
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }
    else
    {
        if ((root1 != NULL) || (root2 != NULL))
        {
            /* jika salah satu simpul ada yang NULL */
            hasil = 0;
        }
    }

    return hasil;
}
