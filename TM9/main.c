#include "header.h"

int main(int argc, char const *argv[])
{
    int i;
    //membuat variabel tipe data tree
    tree T;
    //v=membuat variabel tipe datastruct untuk masukan
    data masukan;
    //sebagai kondisi new line pada keluaran
    int n = 6;
    //perintah masukan dari soal
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    makeTree(masukan, &T);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root->child);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root->child);
    printf("Step 1:\n================\n");
    printTreePreOrder(T.root, &n);
    n = 5;
    delChild(T.root->child->child->sibling, T.root->child);
    printTreePreOrder(T.root, &n);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root->child->sibling);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root->child->sibling);
    scanf("%s %d", &masukan.nama, &masukan.nilai);
    addChild(masukan, T.root->child->sibling->sibling);
    n = 8;
    printTreePreOrder(T.root, &n);
    printf("Step 2:\n================\n");
    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("Sama\n");
    }
    else
    {
        printf("Tidak Sama\n");
    }
    printf("Step 3:\n================\n");
    simpul *Gian;
    Gian = findSimpul("Gian", T.root->child->child);
    printGian(Gian);
    Gian = findSimpul("Gian", T.root->child->sibling);
    printGian(Gian);
    Gian = findSimpul("Gian", T.root);
    printGian(Gian);
    return 0;
}
