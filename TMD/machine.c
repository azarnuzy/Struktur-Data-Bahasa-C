#include "header.h"

void makeTree(data dataSplit, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->kontainer, dataSplit.nodeChild);
    node->depth = 0;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

data hasilSplit(char input[], int mode)
{
    data hasil;
    int j = 0;
    char *splitInput = strtok(input, "#");
    strcpy(hasil.nodeParent, splitInput);

    while (splitInput != NULL)
    {
        if (j == 1)
        {
            strcpy(hasil.nodeChild, splitInput);
        }
        else if (j == 2)
        {
            if (strcmp(splitInput, "-1") != 0)
            {
                hasil.jumlahKorban = atoi(splitInput);
            }
            else
            {
                hasil.jumlahKorban = 0;
            }
        }
        splitInput = strtok(NULL, "#");

        j++;
    }

    return hasil;
}

void addChildAsc(data dataSplit, simpul *root, simpul *akar)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong, berarti dapat ditambahkan simpul anak*/
        simpul *baru;
        simpul *bantu;
        bantu = findSimpul(dataSplit.nodeParent, akar);

        baru = (simpul *)malloc(sizeof(simpul));
        strcpy(baru->kontainer, dataSplit.nodeChild);
        strcpy(baru->parent, dataSplit.nodeParent);
        baru->jumlahKorban = dataSplit.jumlahKorban;
        baru->depth = bantu->depth + 1;
        tempDepth = baru->depth;
        baru->child = NULL;

        if (root->child == NULL)
        {
            /* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
                simpul *temp = root->child;
                /* kondisi jika angka pertama lebih kecil dengan angka yang dimasukkan */
                if (root->child->jumlahKorban < baru->jumlahKorban)
                {
                    temp = root->child;
                    root->child = baru;
                    root->child->sibling = temp;
                    root->child->sibling->sibling = root->child;
                }
                /* kondisi jika angka pertama lebih besar dengan angka yang dimasukan */
                else
                {
                    baru->sibling = root->child;
                    root->child->sibling = baru;
                }
            }
            else
            {
                simpul *last = root->child;
                simpul *tempNode = NULL;
                int ketemu = 0;
                int count = 0;
                /* mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul anak terakhir yang baru, 
                simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul anak
                 terakhir, penunjuk last akan berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    // printf("%d %d*****\n", last->jumlahKorban, baru->jumlahKorban);
                    if (last->jumlahKorban < baru->jumlahKorban && ketemu == 0)
                    {
                        ketemu = 1;
                    }
                    if (ketemu == 0)
                    {
                        count++;
                        tempNode = last;
                    }

                    last = last->sibling;
                }
                // printf("%d\n", tempNode->jumlahKorban);
                if (last->jumlahKorban < baru->jumlahKorban && ketemu == 0)
                {
                    ketemu = 1;
                };
                //kondisi addLast
                if (ketemu == 0)
                {
                    baru->sibling = root->child;
                    last->sibling = baru;
                }
                //kondisi addFirst
                else if (ketemu == 1 && tempNode == 0)
                {
                    simpul *temp = root->child;
                    root->child = baru;
                    root->child->sibling = temp;
                    last->sibling = baru;
                }
                //kondisi addAfter
                else
                {
                    // printf("*********%s %d\n", tempNode->kontainer, tempNode->jumlahKorban);
                    simpul *temp = tempNode->sibling;
                    tempNode->sibling = baru;
                    baru->sibling = temp;
                }
            }
        }
    }
}

void delAll(simpul **root)
{ //Dilakukan kalo emang siblingnya udah diatur, atau emang gapunya sibling
    if ((*root) != NULL)
    {
        /* jika simpul root tidak kosong */
        if ((*root)->child != NULL)
        {

            if ((*root)->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */

                delAll(&(*root)->child);
                free((*root)->child);
                (*root)->child = NULL;
            }
            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = (*root)->child;
                while (bantu->sibling != (*root)->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(&proses);
                }
                delAll(&bantu);
                free((*root)->child);
                (*root)->child = NULL;
            }
        }
        free(*root);
        *root = NULL;
    }
}

void delChild(char c[], simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                /*jika hanya mempunyai satu anak*/
                if (strcmp(root->child->kontainer, c))
                {
                    delAll(&root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else
            {
                /*jika memiliki lebih dari satu simpul anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (strcmp(hapus->kontainer, c) == 0)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                if ((ketemu == 0) && (strcmp(hapus->kontainer, c) == 0))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        /*jika simpul yang dihapus anak pertama*/
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child))
                        {
                            /* jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua */

                            root->child->sibling = NULL;
                        }
                        else
                        {
                            /* jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(&hapus);
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul *findSimpul(char c[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer, c) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (strcmp(bantu->kontainer, c) == 0)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(c, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if (strcmp(bantu->kontainer, c) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                            if (hasil != NULL)
                            {
                                ketemu = 1;
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer, c) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void printTreePreOrder(simpul *root)
{
    if (root != NULL)
    {
        printf("|%s - %d - %d\n", root->kontainer, root->jumlahKorban, root->depth);
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/

                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTreePreOrder(bantu);
            }
        }
    }
}

void printTreePostOrder(simpul *root, int *sumJmlKorban)
{
    if (root != NULL)
    {
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePostOrder(bantu, sumJmlKorban);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePostOrder(bantu, sumJmlKorban);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTreePostOrder(bantu, sumJmlKorban);
            }
        }

        simpul *tempNode = root->child;

        if (tempNode != NULL)
        {
            if (tempNode->sibling != NULL)
            {
                while (tempNode->sibling != root->child)
                {
                    *sumJmlKorban = *sumJmlKorban + tempNode->jumlahKorban;
                    // printf("^^^%s-%s-%d-%d\n", tempNode->parent, tempNode->kontainer, tempNode->jumlahKorban, tempNode->depth);
                    tempNode = tempNode->sibling;
                }
                *sumJmlKorban = *sumJmlKorban + tempNode->jumlahKorban;
                root->jumlahKorban = *sumJmlKorban;
            }
            else
            {
                if (root->depth < tempDepth)
                {
                    *sumJmlKorban = 0;
                }
                root->jumlahKorban = root->child->jumlahKorban;
                // printf("^^^%s-%s-%d-%d-%d\n", root->parent, root->kontainer, root->child->jumlahKorban, root->depth, tempDepth);

                tempDepth = root->depth;
            }
        }

        // printf("^^^%s-%s-%d-%d\n", root->parent, root->kontainer, root->jumlahKorban, root->depth);
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        strcpy((*root2)->kontainer, root1->kontainer);
        (*root2)->sibling = NULL;
        (*root2)->child = NULL;
        if (root1->child != NULL)
        {
            if (root1->child->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                copyTree(root1->child, &(*root2)->child);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                simpul *bantu1 = root1->child;
                simpul *bantu2 = (*root2)->child;

                while (bantu1->sibling != root1->child)
                {
                    copyTree(bantu1, &bantu2);
                    bantu1 = bantu1->sibling;
                    bantu2 = bantu2->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                copyTree(bantu1, &bantu2);
            }
        }
    }
}

int isEqual(simpul *root1, simpul *root2)
{
    int hasil = 1;
    if ((root1 != NULL) && (root2 != NULL))
    {
        if (root1->kontainer != root2->kontainer)
        {
            hasil = 0;
        }
        else
        {
            if ((root1->child != NULL) && (root2->child != NULL))
            {
                if (root1->child->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    hasil = isEqual(root1->child, root2->child);
                }
                else
                {
                    /*jika memiliki banyak simpulanak*/
                    simpul *bantu1 = root1->child;
                    simpul *bantu2 = root2->child;

                    while (bantu1->sibling != root1->child)
                    {
                        if ((bantu1 != NULL) && (bantu2 != NULL))
                        {
                            hasil = isEqual(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        }
                        else
                        {
                            hasil = 0;

                            break;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                    hasil = isEqual(bantu1, bantu2);
                }
            }
        }
    }
    else
    {
        if ((root1 != NULL) || (root2 != NULL))
        {
            hasil = 0;
        }
    }
    return hasil;
}
