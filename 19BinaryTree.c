#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char c, tree *T)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addRight(char c, simpul *root)
{
    if (root->right == NULL)
    {
        /*jika sub pohon kanan kosong*/
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
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
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
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
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *root)
{
    if (root != NULL)
    {
        printf(" %c ", root->kontainer);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(simpul *root)
{

    if (root != NULL)
    {
        printTreeInOrder(root->left);
        printf(" %c ", root->kontainer);
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root)
{

    if (root != NULL)
    {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        printf(" %c ", root->kontainer);
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

int main()
{
    tree T;
    makeTree('A', &T);
    addLeft('B', T.root);
    addRight('C', T.root);
    addLeft('D', T.root->left);
    addRight('E', T.root->left);
    addRight('F', T.root->right);
    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    printf("inOrder\n");
    printTreeInOrder(T.root);
    printf("\n=================\n");
    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n=================\n");
    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("pohon sama\n");
    }
    else
    {
        printf("pohon tidak sama\n");
    }

    delRight(T.root->left);
    delLeft(T.root->left);
    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printTreePostOrder(T.root);
    printf("\n=================\n");

    return 0;
}