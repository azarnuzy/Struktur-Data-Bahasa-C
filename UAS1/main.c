#include "header.h"

int main(int argc, char const *argv[])
{
    int kiri, kanan;
    scanf("%d %d", &kiri, &kanan);
    tree T;
    makeTree(kiri, kanan, &T);

    count = 0;
    inputData(kiri, kanan, T.root, 0);

    // printf("%d\n", count);
    // printTreePostOrder(T.root);
    int i;
    for (i = 0; i < count; i++)
    {
        if (i == count - 1)
        {
            printf("%d\n", keluaran[i]);
        }
        else
        {
            printf("%d ", keluaran[i]);
        }
    }

    if (count == 0)
    {
        printf("%d %d\n", kiri, kanan);
    }
    return 0;
}
