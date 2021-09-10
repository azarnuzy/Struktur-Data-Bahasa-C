#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    int angka;
 
    scanf("%d", &n);//5
    n -= 1;
    scanf("%d", &angka);//100 | n = 4

    int min = angka; //min = 100

    while(n > 0) {
        scanf("%d", &angka); //angka2 = 50
        //min = 100 | angka2 = 50
        //min = 50 | angka3 = 30
        //min = 30 | angka4 = 20
        //min = 20 | angka5 = 40
        if(min > angka) {
            min = angka;//min = 50
            //min = 30
            //min = 20
        }
        n--;  
    }
    //min = 20
    printf("%d\n", min);
    return 0;
}
