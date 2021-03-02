#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,n;
    printf("\nDigite N: ");
    scanf("%d",&n);
    printf("\nDigite M: ");
    scanf("%d",&m);

    int numeros[n];

    for(int i=0;i<n;i++){
        printf("Digite o %d ° numero:",(i+1));
        scanf("%d",&numeros[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d, ",(numeros[i]-m));

    }


    printf("\n");
    return 0;
}