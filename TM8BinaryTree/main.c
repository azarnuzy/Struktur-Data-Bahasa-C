#include "header.h"

int main(int argc, char const *argv[])
{
    //membuat variabel tipe data tree
    tree T;
    //variabel untuk karakter masukan
    char c;
    //inisialisasi nilai awal dari count
    count = 0;
    //input serta iterasi dari count
    scanf(" %c", &c);
    count++;
    makeTree(c, &T);
    scanf(" %c", &c);
    count++;
    addLeft(c, T.root);
    scanf(" %c", &c);
    count++;
    addRight(c, T.root);
    scanf(" %c", &c);
    count++;
    addLeft(c, T.root->right);
    scanf(" %c", &c);
    count++;
    addRight(c, T.root->left);
    scanf(" %c", &c);
    count++;
    addRight(c, T.root->right);
    scanf(" %c", &c);
    count++;
    addLeft(c, T.root->left->right);
    scanf(" %c", &c);
    count++;
    addRight(c, T.root->right->left);
    scanf(" %c", &c);
    count++;
    addRight(c, T.root->left->right);
    scanf(" %c", &c);
    count++;
    addRight(c, T.root->right->right);
    scanf(" %c", &c);
    count++;
    addLeft(c, T.root->right->right);
    scanf(" %c", &c);
    count++;
    addLeft(c, T.root->left->right->left);
    scanf(" %c", &c);
    count++;
    addLeft(c, T.root->right->left->right);
    scanf(" %c", &c);
    count++;
    addRight(c, T.root->right->left->right);
    //variabel untuk menampung banyaknya masukan secara sementara
    int tempCount = count;

    //keluaran dari hasil tree
    printf("Pre Order:\n");
    printTreePreOrder(T.root);
    //kondisi count ketika akan di delet node nya
    count = tempCount - 1;

    delLeft(T.root->left->right->left); //L Hilang

    printf("In Order:\n");
    printTreeInOrder(T.root);
    //kondisi count ketika akan di delet node nya
    count = tempCount - 2;

    delRight(T.root->right->right); //J Terhapus

    printf("Post Order:\n");
    printTreePostOrder(T.root);

    return 0;
}
