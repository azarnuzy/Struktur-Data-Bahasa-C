#include "header.h"

int main(int argc, char const *argv[])
{
    //membuat variabel untuk penamaan graph
    graph G;
    //sebagai masukan dari simpul yang akan dihapus
    int n, m;
    char awal, tujuan;
    int berat;
    //menginisialisasi nilai awal dari graph
    createEmpty(&G);
    //menambahkan simpul
    simpul *begin, *end, *check;

    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf(" %c %c %d", &awal, &tujuan, &berat);
        check = findSimpul(awal, G);
        //menambahkan simpul jika belum ada
        if (check == NULL)
        {
            addSimpul(awal, &G);
        }

        check = findSimpul(tujuan, G);
        //menambahkan simpul jika belum ada
        if (check == NULL)
        {
            addSimpul(tujuan, &G);
        }

        //membuat jalur
        begin = findSimpul(awal, G);
        end = findSimpul(tujuan, G);
        if (begin != NULL && end != NULL)
        {
            addJalur(begin, end, berat);
        }
    }
    scanf(" %c %c", &awal, &tujuan);
    begin = findSimpul(awal, G);
    max = 999999;
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf(" %c", &cJalurPetani[i]);
    }
    jalurPetani(begin, tujuan, G, 0);
    i = 0;
    if (cJalurPetani[i] != awal)
    {
        printf("salah\n");
        printf("%c %c\n", awal, tujuan);
    }
    else
    {
        printf("benar\n");
        for (i = 0; i < m; i++)
        {
            if (i < m - 1)
            {
                printf("%c ", cJalurPetani[i]);
            }
            else
            {
                printf("%c\n", cJalurPetani[i]);
            }
        }
    }
    return 0;
}
