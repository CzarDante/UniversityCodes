#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *aloca_vetor(long long int x);
void mostrar_vetor(long long int *vet, long long int tam);
long long int busca_binaria(long long int *vet, long long int inicio, long long int fim, long long int x);

int main()
{
    srand(time(NULL));
    long long int *vet;
    long long tam = 1000;
    long long int buscado = 98, retorno;
    float diff;

    vet= aloca_vetor(tam);
    retorno = busca_binaria(vet, 0, tam - 1, buscado);
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

long long int busca_binaria(long long int *vet, long long int inicio, long long int fim, long long int x)
{
    if (inicio > fim)
        return -1;

    long long int meio;

    meio = (inicio + fim) / 2;

    if (vet[meio] == x)
        return meio;
    else
    {
        if (x < vet[meio])
            return busca_binaria(vet, inicio, meio - 1, x);
        else
            return busca_binaria(vet, meio + 1, fim, x);
    }
}