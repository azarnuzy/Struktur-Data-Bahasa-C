#include <stdio.h>

int main()
{
    int jenis, banyak;
    scanf("%d %d", &jenis, &banyak);
    int bayarAwal, bayarDiskon, tambahDiskon = 0;

    bayarAwal = banyak * 10000;

    if(jenis == 1) {
        bayarDiskon = bayarAwal / 10;
    }else if(jenis == 2) {
        bayarDiskon = bayarAwal / 5;
    }else if(jenis == 3) {
        bayarDiskon = bayarAwal / 2;
    }

    if(bayarAwal >= 100000) {
        tambahDiskon = bayarAwal / 10;
    }

    int total = bayarAwal - bayarDiskon - tambahDiskon;

    printf("%d\n%d\n%d\n", bayarAwal, bayarDiskon + tambahDiskon, total);
    return 0;
}
