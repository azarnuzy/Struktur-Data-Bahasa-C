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

    // printf("%s\n", T.root->child->child->sibling->sibling->kontainer);
    printTreePostOrder(T.root, &sumJmlKorban);
    jmlSpasi = 0;
    int level = 0;
    int firstLevel;
    tempDepth = 0;
    int branch = 0;
    firstDepth = 0;
    printTreePreOrder(T.root, &level, T.root, &branch, T.root, 1);
    branch = 0;
    printTreePreOrder(T.root, &level, T.root, &branch, T.root, 2);
    //printTreePreOrder(T.root, &level, T.root, &branch, T.root, 2);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", input);
        rootNode = findSimpul(input, T.root);
        branch = 0;
        tempDepth = 0;
        firstDepth = rootNode->depth;
        jmlSpasi = 0;
        printTreePreOrder(rootNode, &level, rootNode, &branch, T.root, 3);
    }
    return 0;
}
