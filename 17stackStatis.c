#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatKul;

typedef struct
{
    int top;
    nilaiMatKul data[10];
} stack;

void createEmpty(stack *S)
{
    (*S).top = -1;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S)
{
    int hasil = 0;
    if (S.top == 9)
    {
        hasil = 1;
    }
    return hasil;
}

void push(char nim[], char nama[], float nilai, stack *S)
{

    if (isFull(*S) == 1)
    {
        /*jika stack penuh*/
        printf("stack penuh\n");
    }
    else
    {
        if (isEmpty(*S) == 1)
        {
            /* jika stack kosong */
            (*S).top = 0;
            strcpy((*S).data[0].nim, nim);
            strcpy((*S).data[0].nama, nama);
            (*S).data[0].nilai = nilai;
        }
        else
        {
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].nim, nim);
            strcpy((*S).data[(*S).top].nama, nama);
            (*S).data[(*S).top].nilai = nilai;
        }
    }
}

void pop(stack *S)
{

    if ((*S).top == 0)
    {
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1)
        {
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}

void printStack(stack S)
{
    if (S.top != -1)
    {
        printf("------isi stack------\n");
        int i;
        for (i = S.top; i >= 0; i--)
        {
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", S.data[i].nim);
            printf("nama : %s\n", S.data[i].nama);
            printf("nilai : %f\n", S.data[i].nilai);
        }
        printf("---------------------\n");
    }
    else
    {
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}

int main()
{
    stack S;
    createEmpty(&S);
    printStack(S);
    printf("=================\n");
    push("13507701", "Nana", 64.75, &S);
    push("13507702", "Rudi", 75.11, &S);
    push("13507703", "Dea", 84.63, &S);
    printStack(S);
    printf("=================\n");
    pop(&S);
    pop(&S);
    printStack(S);
    printf("=================\n");
    return 0;
}