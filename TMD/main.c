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
            makeTree(dataSplit.nodeChild, &T);
            strcpy(akarSimpul, dataSplit.nodeChild);
        }
        else
        {
            rootNode = findSimpul(dataSplit.nodeParent, T.root);
            // printf("%s****%s\n", rootNode->kontainer, dataSplit.nodeParent);
            if (rootNode != NULL)
            {
                addChild(dataSplit.nodeChild, dataSplit.jumlahKorban, rootNode);
            }
        }
    }

    rootNode = findSimpul("Sidoarjo", T.root);
    // printf("%s*****%s\n", rootNode->child, rootNode->child->sibling);
    printTreePreOrder(T.root);
    return 0;
}