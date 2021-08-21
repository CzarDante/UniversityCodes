#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *aloca_vetor(long long int x);
void mostrar_vetor(long long int *vet, long long int tam);
long long int busca_sequencial(long long int *vet, long long int tam, long long int x);

int main()
{
    srand(time(NULL));
    long long int *vet;
    long long tam = 10000;
    long long int buscado = 978, retorno;
    vet = aloca_vetor(tam);
    retorno = busca_sequencial(vet, tam, buscado);
    if (retorno < 0)
        printf("\nNumero nao encontrado");
    else
        printf("\nNumero esta na posicao %lld", retorno);

    return 0;
}
long long int *aloca_vetor(long long int x)
{
    long long int *novo, i;
    novo = (long long int *)calloc(x, sizeof(long long int));

    for (i = 0; i < x; i++)
        novo[i] = i;
    return novo;
}

void mostrar_vetor(long long int *vet, long long int tam)
{
    long long int i;

    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

long long int busca_sequencial(long long int *vet, long long int tam, long long int x)
{ 
    for (long long int i = 0; i < tam; i++)
    {
        if(vet[i]==x){
            return i;
        }
    }
    return -1;
}
