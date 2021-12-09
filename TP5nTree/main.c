#include "header.h"

int main(int argc, char const *argv[])
{
    tree T;
    data inputData;
    simpul *rootNode;
    int i = 1;
    do
    {
        scanf("%s", inputData.query);
        if (strcmp(inputData.query, "MAKETREE") == 0)
        {
            scanf("%s", inputData.child);
            char *temp = strtok(inputData.child, ";");
            makeTree(inputData, &T);
        }
        else if (strcmp(inputData.query, "CHILD") == 0)
        {
            scanf("%s %s", inputData.child, inputData.parent);
            char *temp = strtok(inputData.parent, ";");
            strcpy(inputData.parent, temp);
            rootNode = findSimpul(inputData.parent, T.root);
            addChild(inputData, rootNode);
        }
        else if (strcmp(inputData.query, "PREORDER;") == 0)
        {
            printf("Output %d:\n=========\n", i);
            printTreePreOrder(T.root);
            i++;
        }
        else if (strcmp(inputData.query, "DELLCHILD") == 0)
        {
            simpul *temp;
            scanf("%s %s", inputData.child, inputData.parent);
            char *sTemp = strtok(inputData.parent, ";");
            temp = findSimpul(sTemp, T.root);
            delChild(inputData.child, temp);
        }
    } while (strcmp(inputData.query, "DONE;") != 0);
    printf("=========\n");
    return 0;
}
