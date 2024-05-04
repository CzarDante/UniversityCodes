/******************************************************************************
é declarado um array de tamanho 10 que tem os valores de 1 a 9.
a funcao SOMADOR recebe a referencia do array duas vezes, no C ao passar um array
para uma funcao você está passando ele por referencia.
Os dois arrays são somados armazenando o valor no "segundo"" array passado para a funcao.
Como os dois arrays da funcao fazem referencia para o mesmo array de origem, ao salvar no
Array B, o array A recebe a mesma alteração.
*******************************************************************************/
#include <stdio.h>

int SOMADOR(int A[], int B[], int tam)
{
    for(int i=0;i<tam;i++){
        B[i]=A[i]+B[i];
        //printf("A:%d B:%d\n", A[i],B[i]);
    }
}

int main()
{
    int array[10];
    for(int i=0;i<10;i++)
    {
        array[i]=i+1;
    }
    SOMADOR(array,array,10);
    for(int j=0;j<10;j++)
    {
        printf("%d ",array[j]);
    }
    return 0;
}