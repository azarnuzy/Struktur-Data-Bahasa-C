#include "header.h"

void makeTree(data dataSplit, tree *T)
{
    //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
    simpul *node;
    //menginisialisasi besarnya nilai dari baru
    node = (simpul *)malloc(sizeof(simpul));
    //memasukan nilai masukan terhadap variabel baru
    strcpy(node->kontainer, dataSplit.nodeChild);
    node->depth = 0;
    node->jmlSpace = 0;
    node->jumlahKorban = dataSplit.jumlahKorban;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

data hasilSplit(char input[], int mode)
{
    data hasil;
    int j = 0;
    //sebagai variabel untuk mensplit input yang dipisahkan oleh tanda'#'
    char *splitInput = strtok(input, "#");
    //menyalin parent ke hasil
    strcpy(hasil.nodeParent, splitInput);

    while (splitInput != NULL)
    {
        if (j == 1)
        {
            //menyalin simpul child ke hasil
            strcpy(hasil.nodeChild, splitInput);
        }
        else if (j == 2)
        {
            if (strcmp(splitInput, "-1") != 0)
            {
                //mengubah jumlah korban dari string ke int dan menyalinnya
                hasil.jumlahKorban = atoi(splitInput);
            }
            else
            {
                //menjadikan nilai hasil jumlah korban 0
                hasil.jumlahKorban = 0;
            }
        }
        splitInput = strtok(NULL, "#");

        j++;
    }

    return hasil;
}

void addChildDesc(data dataSplit, simpul *root, simpul *akar)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong, berarti dapat ditambahkan simpul anak*/
        //membuat variabel dari tipe data simpul sebagai masukan dari root nantinya
        simpul *baru;
        //sebagai variabel dari simpul parent
        simpul *bantu;
        //mencari simpul parent pada tree
        bantu = findSimpul(dataSplit.nodeParent, akar);

        //menginisialisasi besarnya nilai dari baru
        baru = (simpul *)malloc(sizeof(simpul));
        //menyalin nilai hasil data split
        strcpy(baru->kontainer, dataSplit.nodeChild);
        strcpy(baru->parent, dataSplit.nodeParent);
        baru->jumlahKorban = dataSplit.jumlahKorban;
        baru->depth = bantu->depth + 1;
        tempDepth = baru->depth;
        baru->jmlSpace = 0;
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
                /* mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul anak terakhir yang baru, 
                simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul anak
                 terakhir, penunjuk last akan berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    /* kondisi untuk menemukan variabel ketemu dan tempNode */
                    if (last->jumlahKorban < baru->jumlahKorban && ketemu == 0)
                    {
                        ketemu = 1;
                    }

                    if (ketemu == 0)
                    {
                        tempNode = last;
                    }

                    last = last->sibling;
                }
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

void resetSpace()
{
    int i = 0;
    //untuk mereset nilai array dan baris menjadi 0
    baris = 0;
    for (i = 0; i < 100; i++)
    {
        levelSpace[i] = 0;
    }
}

void setSpace(simpul *root)
{
    int i, j = 0;
    if (root != NULL)
    {
        //sebagai variabel untuk menghitung banyaknya digit pada jumlah korban
        int sumDigit = 0;
        int digit = root->jumlahKorban;
        //perulangan untuk menghitung digit
        while (digit > 0)
        {
            sumDigit++;
            digit /= 10;
        }
        int i;
        //sebagai tampungan sementara dari banyaknya spasi
        int tempLevelSpace = strlen(root->kontainer) + 4 + sumDigit;
        //sebagai kondisi jika tampungan sementara lebih besar maka akan dimasukan ke dalam levelSpace
        if (tempLevelSpace > levelSpace[root->depth])
        {
            levelSpace[root->depth] = tempLevelSpace;
        }

        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            { /*jika memiliki satu simpul anak*/
                setSpace(bantu);
            }
            else
            { /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    setSpace(bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                setSpace(bantu);
            }
        }
    }
    else
    {
        printf("kosong");
    }
}

void printSpace(int depth)
{
    int i, j = 0;
    //variabel untuk menampung nilai level space untuk nantinya di jadikan batasan untuk keluaran
    int tempSpace = levelSpace[depth - 1];
    int n = 0;
    //menjumlahkan nilai level space sebelumnya
    for (j = depth - 2; j >= 0; j--)
    {
        n += levelSpace[j];
    }
    //menjumlahkan nilai level space sebelumnya
    tempSpace += n;
    //mengeluarkan spasi
    for (i = 0; i < tempSpace; i++)
    {
        printf(" ");
    }
}

void printTreePreOrder(simpul *root)
{
    int i, j = 0;
    if (root != NULL)
    {
        //new line pada setiap baris
        if (baris > 0)
        {
            printf("\n");
        }

        //menampilkan spasi
        if (root->depth != firstDepth)
        {
            printSpace(root->depth);
        }
        //menampilkan hasil dari simpul child dan banyaknya korban
        printf("|%s - %d\n", root->kontainer, root->jumlahKorban);

        baris++;

        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            { /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu);
            }
            else
            { /*jika memiliki banyak simpul anak*/
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
    else
    {
        printf("kosong");
    }
}

void resetJmlSpace(simpul *root)
{
    if (root != NULL)
    {
        root->jmlSpace = 0;
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                resetJmlSpace(root);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    resetJmlSpace(root);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                resetJmlSpace(root);
            }
        }
    }
}

int countJmlKorban(simpul *root)
{
    int hasil = 0;
    if (root != NULL)
    {
        hasil = root->jumlahKorban;
        // printf("%d %s=\n", root->jumlahKorban, root->kontainer);
        simpul *bantu = root->child;

        /* jika simpul tidak kosong */
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                hasil += countJmlKorban(bantu);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    hasil += countJmlKorban(bantu);
                    bantu = bantu->sibling;
                }
                hasil += countJmlKorban(bantu);
            }
        }
    }
    return hasil;
}

void countAllJmlKorban(simpul *root)
{
    if (root != NULL)
    {
        root->jumlahKorban = countJmlKorban(root);
        // printf("%d %d %s-=\n", root->jumlahKorban, countJmlKorban(root), root->kontainer);
        simpul *bantu = root->child;
        //jika simpul tidak kosong
        if (bantu != NULL)
        {
            //jika simpul hanya memiliki satu anak
            if (bantu->sibling == NULL)
            {
                countAllJmlKorban(bantu);
            }
            //jika simpul memiliki banyak anak
            else
            {
                while (bantu->sibling != root->child)
                {
                    countAllJmlKorban(bantu);
                    bantu = bantu->sibling;
                }
                //menghitung nilai anak terakhir
                countAllJmlKorban(bantu);
            }
        }
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
