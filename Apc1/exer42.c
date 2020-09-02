#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, soma = 0;
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++){
	    if(i % 3 ==0){
            soma = soma + i;
        }
    }
    printf("%d\n", soma);
    return 0;
}