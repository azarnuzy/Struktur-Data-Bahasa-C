#include "header.h"

int main(int argc, char const *argv[])
{
    //membuat variabel untuk penamaan graph
    graph G;
    //sebagai masukan dari simpul yang akan dihapus
    int n;
    char x, y, z;
    //menginisialisasi nilai awal dari graph
    createEmpty(&G);
    //menambahkan simpul
    do
    {
        scanf(" %c", &x);
        if (x != '0')
        {
            scanf(" %c", &y);
            if (findSimpul(x, G) == NULL)
            {
                addSimpul(x, &G);
            }
            if (findSimpul(y, G) == NULL)
            {
                addSimpul(y, &G);
            }

            simpul *begin = findSimpul(x, G);
            simpul *end = findSimpul(y, G);
            if ((begin != NULL) && (end != NULL))
            {
                addJalur(begin, end, 0);
            }
        }
    } while (x != '0');

    cekRoute(G, G.first);
    return 0;
}
