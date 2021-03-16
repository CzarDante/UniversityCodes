/*
Faça um programa que receba do usuário dois números N e M positivos inteiros. Aloque um vetor de N números inteiros, 
preencha os N números. Para cada um dos N números mostre a diferença em relação a M:
Ex:
    N = 5
    m = 5
    Vetor de N números:
    1, 2, 3,4,5
    Resultado:
    4, 3, 2, 1, 0;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,n,i;
    printf("\nDigite N: ");
    scanf("%d",&n);
    printf("\nDigite M: ");
    scanf("%d",&m);
    int * numeros;
    numeros = (int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        printf("Digite o %d numero:",(i+1));
        scanf("%d",&numeros[i]);
        numeros[i]=m-numeros[i];
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d, ",(numeros[i]));
    }
    printf("\n");
    return 0;
}