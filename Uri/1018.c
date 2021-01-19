#include <stdio.h>

int main(){
    int num, n50, n20, n10, n5, n2, n1;
    scanf("%d", & num);
    printf("%d\n", num);
    printf("%d nota(s) de R$ 100,00\n", num / 100);
    n50 = num % 100;
    printf("%d nota(s) de R$ 50,00\n", n50 / 50);
    n20 = n50 % 50;
    printf("%d nota(s) de R$ 20,00\n", n20 / 20);
    n10 = n20 % 20;
    printf("%d nota(s) de R$ 10,00\n", n10 / 10);
    n5 = n10 % 10;
    printf("%d nota(s) de R$ 5,00\n", n5 / 5);
    n2 = n5 % 5;
    printf("%d nota(s) de R$ 2,00\n", n2 / 2);
    n1 = n2 % 2;
    printf("%d nota(s) de R$ 1,00\n", n1);
    return 0;
}