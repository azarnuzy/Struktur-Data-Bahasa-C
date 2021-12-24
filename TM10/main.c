#include "header.h"

int main(int argc, char const *argv[])
{
    //membuat variabel untuk penamaan graph
    graph G;
    //sebagai masukan dari simpul yang akan dihapus
    int n;
    //menginisialisasi nilai awal dari graph
    createEmpty(&G);
    //menambahkan simpul
    addSimpul(1, &G);
    addSimpul(2, &G);
    addSimpul(3, &G);
    addSimpul(4, &G);
    addSimpul(5, &G);
    addSimpul(6, &G);
    addSimpul(7, &G);
    addSimpul(8, &G);

    //memasukan jalur ke simpul simpul
    simpul *begin = findSimpul(1, G);
    simpul *end = findSimpul(2, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(3, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    begin = findSimpul(4, G);
    end = findSimpul(5, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    begin = findSimpul(6, G);
    end = findSimpul(7, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    begin = findSimpul(7, G);
    end = findSimpul(5, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    begin = findSimpul(8, G);
    end = findSimpul(1, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(4, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(6, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    //menampilkan keluaran graph
    printGraph(G);
    printf("===========\n");
    //masukan dari simpul yang akan dihapus
    scanf("%d", &n);

    begin = findSimpul(n, G);
    if (begin != NULL)
    {
        //prosedur untuk menghapus simpul
        delSimpul(n, &G);
    }
    printGraph(G);
    return 0;
}
