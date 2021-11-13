#include "header.h"

int main() {
    queue Q1, Q2;
    createEmpty(&Q1);
    createEmpty(&Q2);
    char nama[50], nim[20];
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    scanf("%s%s", nama, nim);
    addPriority(nim, nama, 2, &Q1);
    printQueue(Q1, "1");
    del(&Q1, &Q2);
    printQueue(Q1, "1");
    printQueue(Q2, "2");
    scanf("%s%s", nama, nim);
    addPriority(nim, nama, 1, &Q1);
    scanf("%s%s", nama, nim);
    addPriority(nim, nama, 99, &Q1);
    printQueue(Q1, "1");
    del(&Q1, &Q2);
    del(&Q1, &Q2);
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    printQueue(Q1, "1");
    printQueue(Q2, "2");
    printf("******************\n");
    return 0;
}