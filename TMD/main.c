#include "header.h"

int main()
{
    tree T;
    int i, j = 0;
    int n;
    char input[100], akarSimpul[100];
    simpul *rootNode;
    data dataSplit;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", input);
        dataSplit = hasilSplit(input, 0);

        if (strcmp(dataSplit.nodeParent, "null") == 0)
        {
            makeTree(dataSplit, &T);
            strcpy(akarSimpul, dataSplit.nodeChild);
        }
        else
        {
            rootNode = findSimpul(dataSplit.nodeParent, T.root);
            if (rootNode != NULL)
            {
                addChildAsc(dataSplit, rootNode, T.root);
            }
        }
    }

    int sumJmlKorban = 0;
    int ranting = 0;
    tree T2;

    printTreePostOrder(T.root, &sumJmlKorban);
    printf("pohon lengkap:\n");
    resetSpace();
    setSpace(T.root);
    printTreePreOrder(T.root);
    scanf("%d", &n);
    printf("Sub-pohon:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", input);
        rootNode = findSimpul(input, T.root);
        resetSpace();
        setSpace(rootNode);
        printTreePreOrder(rootNode);
    }
    return 0;
}
