#include "header.h"

int main()
{
    /* 
    **T = sebagai variabel untuk tree
    **i,j = sebagai iterasi
    **n,m = sebagai batasan dari banyaknya inputan
    **input, input2 = sebagai inputan 
    **rootNode = sebagai variabel penunjuk node 
    **dataSplit = sebagai variabel untuk kontainer masukan
     */
    tree T;
    int i, j = 0;
    int n, m;
    char input[1000][100], akarSimpul[1000], input2[1000][100];
    simpul *rootNode;
    data dataSplit;
    //memasukan banyaknya inputan1
    scanf("%d", &n);
    //memasukan inputan1
    for (i = 0; i < n; i++)
    {
        scanf("%s", input[i]);
    }
    //memasukan banyaknya inputan2
    scanf("%d", &m);
    //memasukan inputan2
    for (i = 0; i < m; i++)
    {
        scanf("%s", input2[i]);
    }
    //membuat tree
    for (i = 0; i < n; i++)
    {
        //memasukan input ke dalam dataSplit
        dataSplit = hasilSplit(input[i], 0);
        //kondisi ketika berada di root
        if (strcmp(dataSplit.nodeParent, "null") == 0)
        {
            makeTree(dataSplit, &T);
            strcpy(akarSimpul, dataSplit.nodeChild);
        }
        //kondisi ketika berada di child
        else
        {
            //mencari rootNode dari anak yang akan di tambahkan
            rootNode = findSimpul(dataSplit.nodeParent, T.root);
            if (rootNode != NULL)
            {
                //memasukan child ke dalam tree dengan urutan
                addChildDesc(dataSplit, rootNode, T.root);
            }
        }
    }

    int sumJmlKorban = 0;
    //menghitung jumlah korban pada masing masing node
    countAllJmlKorban(T.root);
    // printf("%d %s\n", T.root->jmlSpace, T.root->kontainer);
    printf("pohon lengkap:\n\n");
    //mereset ulang spasi
    resetSpace();
    firstDepth = 0;
    //mengatur banyaknya spasi pada keluaran
    setSpace(T.root);
    //mengeluarkan keluaran
    printTreePreOrder(T.root);

    printf("\nSub-pohon:\n");

    for (i = 0; i < m; i++)
    {
        //mencari rootNode dari anak yang akan dikeluarkan
        rootNode = findSimpul(input2[i], T.root);
        //mereset spasi
        resetSpace();
        //sebagai penanda kedalaman dari node yang akan dikeluarkan
        firstDepth = rootNode->depth;
        printf("\n");
        //mengatur banyaknya spasi pada kelauran
        setSpace(rootNode);
        //mengeluarrkan keluaran
        printTreePreOrder(rootNode);
    }
    return 0;
}
