#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i, bil[100000];
    int max = 0;
    for(i=0; i<n; i++) {
        scanf("%d", &bil[i]);
        if(max < bil[i]) {
            max = bil[i];
        }
    }
    int count = 0;
    for(i=0; i<n; i++) {
        if(max == bil[i]) {
            count++;
        }
    }

    printf("%d %d\n", max, count);
    return 0;
}
