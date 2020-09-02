#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero, i, res = 0;
    scanf("%d", &numero);
 
    for (i = 2; i <= numero / 2; i++) {
        if (numero % i == 0) {
            res++;
            break;
        }
    }
    if (numero ==1){
        printf("não é um numero primo\n");
    }
    else if (res == 0){
        printf("é um número primo\n");
    }
    else{
        printf("não é um número primo\n");
    }
    return 0;
}
