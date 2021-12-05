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
    itr = 0;
    // printf("%s\n", T.root->child->child->sibling->sibling->kontainer);
    printTreePostOrder(T.root, &sumJmlKorban);
    printTreePreOrder(T.root->child);
    // printTreePreOrder(T.root);
    return 0;
}