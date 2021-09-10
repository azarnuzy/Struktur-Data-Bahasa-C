#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nilai;
    int n = 0;
    int sum = 0;

    while(nilai != -1) {
        scanf("%d", &nilai);
        n++;
        sum += nilai;
    }
    
    sum += 1;
    n -= 1;
    double rataan;
    rataan = (double)sum / n;

    printf("%d %.2lf\n", n, rataan);
    return 0;
}
