#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul *first;
} graph;

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addSimpul(char c, graph *G)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;
    if ((*G).first == NULL)
    {
        /*jika graf kosong*/
        (*G).first = baru;
    }
    else
    {
        /*menambahkan simpul baru pada akhir graph*/

        simpul *last = (*G).first;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan, int beban)
{
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    baru->kontainer_jalur = beban;
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;
    if (awal->arc == NULL)
    {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else
    {
        /*menambahkan jalur baru pada akhir list jalur*/

        jalur *last = awal->arc;

        while (last->next_jalur != NULL)
        {
            last = last->next_jalur;
        }

        last->next_jalur = baru;
    }
}

simpul *findSimpul(char c, graph G)
{
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    int ketemu = 0;
    while ((bantu != NULL) && (ketemu == 0))
    {
        if (bantu->kontainer == c)
        {
            hasil = bantu;
            ketemu = 1;
        }
        else
        {
            bantu = bantu->next;
        }
    }
    return hasil;
}

void delJalur(char ctujuan, simpul *awal)
{
    jalur *hapus = awal->arc;
    if (hapus != NULL)
    {
        jalur *prev = NULL;
        /*mencari jalur yang akan dihapus*/
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0))
        {
            if (hapus->tujuan->kontainer == ctujuan)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next_jalur;
            }
        }

        if (ketemu == 1)
        {
            if (prev == NULL)
            {
                /*hapus jalur pertama*/
                awal->arc = hapus->next_jalur;
                hapus->next_jalur = NULL;
            }
            else
            {
                if (hapus->next_jalur == NULL)
                {
                    /*hapus jalur terakhir*/
                    prev->next_jalur = NULL;
                }
                else
                {
                    /*hapus jalur di tengah*/
                    prev->next_jalur = hapus->next_jalur;
                    hapus->next_jalur = NULL;
                }
            }
            free(hapus);
        }
        else
        {
            printf("tidak ada jalur dengan simpul tujuan\n");
        }
    }
    else
    {
        printf("tidak ada jalur dengan simpul tujuan\n");
    }
}

void delAll(simpul *awal)
{

    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next_jalur;
        awal->arc = bantu;
        hapus->next_jalur = NULL;
        free(hapus);
    }
}

void delSimpul(char c, graph *G)
{
    simpul *hapus = (*G).first;
    if (hapus != NULL)
    {
        simpul *prev = NULL;
        /*mencari simpul yang akan dihapus*/
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0))
        {
            if (hapus->kontainer == c)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next;
            }
        }
        if (ketemu == 1)
        {
            /* jika simpul yang akan dihapus ada */
            /* hapus semua jalur dari simpul lain 
            yang mengarah pada simpul yang dihapus */

            simpul *bantu;
            bantu = (*G).first;
            /* memeriksa semua simpul dalam graf */
            while (bantu != NULL)
            {
                /* jika simpul yang ditelusuri tidak sama 
                dengan yang dihapus */
                if (bantu != hapus)
                {
                    /* hapus semua jalur yang mengarah pada 
                    simpul yang dihapus */
                    delJalur(hapus->kontainer, bantu);
                }
                bantu = bantu->next;
            }
            /* hapus semua jalur */
            delAll(hapus);

            if (prev == NULL)
            {
                /*hapus simpul pertama*/
                (*G).first = hapus->next;
                hapus->next = NULL;
            }
            else
            {
                if (hapus->next == NULL)
                {
                    /*hapus simpul terakhir*/
                    prev->next = NULL;
                }
                else
                {
                    /*hapus simpul di tengah*/
                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }
        else
        {
            printf("tidak ada simpul dengan info karakter masukan\n");
        }
    }
    else
    {
        printf("tidak ada simpul dengan info karakter masukan\n");
    }
}

void printGraph(graph G)
{
    simpul *bantu = G.first;
    if (bantu != NULL)
    {
        while (bantu != NULL)
        {
            printf("Node : %c\n", bantu->kontainer);
            jalur *bantu_jalur = bantu->arc;
            while (bantu_jalur != NULL)
            {
                printf(" - ada jalur ke simpul : %c dengan beban : % d\n ", bantu_jalur->tujuan->kontainer, bantu_jalur->kontainer_jalur);
                bantu_jalur = bantu_jalur->next_jalur;
            }
            bantu = bantu->next;
        }
    }
    else
    {
        printf("graf kosong\n");
    }
}

int main()
{
    graph G;
    createEmpty(&G);
    addSimpul('A', &G);
    addSimpul('B', &G);
    addSimpul('C', &G);
    addSimpul('D', &G);
    addSimpul('E', &G);
    addSimpul('F', &G);

    simpul *begin = findSimpul('A', G);
    simpul *end = findSimpul('B', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 3);
    }
    begin = findSimpul('B', G);
    end = findSimpul('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 3);
    }

    end = findSimpul('E', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 7);
    }
    begin = findSimpul('C', G);
    end = findSimpul('A', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 3);
    }
    begin = findSimpul('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 8);
    }
    end = findSimpul('C', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 3);
    }
    begin = findSimpul('E', G);
    end = findSimpul('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 4);
    }
    end = findSimpul('F', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 4);
    }

    begin = findSimpul('F', G);
    end = findSimpul('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 2);
    }

    printf("=================\n");
    printGraph(G);
    printf("\n=================\n");
    begin = findSimpul('A', G);
    if (begin != NULL)
    {
        delJalur('B', begin);
    }

    printf("=================\n");
    printf("setelah dihapus\n");
    printGraph(G);
    printf("\n=================\n");

    return 0;
}