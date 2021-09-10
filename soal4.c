#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d", &a, &b);
    int sum = 0;
    while(a <= b) {
        sum += a * a;
        a++;
    }

    printf("\n%d\n", sum);
    return 0;
}
