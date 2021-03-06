/*Implemente o algoritmo SelectionSort e calcule seu tempo de execução para diversos tamanhos de vetores.
Monte um gráfico demonstrando a curva de aumento de tempo em relação ao aumento de N ( tamanho do vetor.)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void selectionsort(long long int *vet, long long int tam);

int main()
{
    clock_t Ticks[2];
    long long int *vet;
    long long int tam;
    srand(time(NULL));
    FILE * arq;
    arq = fopen("tempos_selection.csv","a+");
    if ( arq==NULL)
        return 0;
    for (tam = 1000; tam <= 50000; tam = tam + 1000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        // mostrar_vetor(vet,tam);     
        Ticks[0] = clock();
        selectionsort(vet,tam);
        Ticks[1] = clock();
        // mostrar_vetor(vet,tam); 
        double Tempo = ((Ticks[1] - Ticks[0]) *1000 / CLOCKS_PER_SEC);
        printf("\tTempo gasto: %g ms.", Tempo);
        fprintf(arq,"%lld;%.1f\n",tam,Tempo);
        free(vet);
    }
    fclose(arq);
    printf("\n");
    return 0;
}

long long int *cria_vetor(long long int n)
{
    long long int *vet, i, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        sorteio = rand() % n;
        aux = vet[i];
        vet[i] = vet[sorteio];
        vet[sorteio] = aux;
    }
    return vet;
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

void selectionsort(long long int * vet, long long int tam)
{
    long long int i,j,ind_menor,aux;

    for(i=0;i<tam-1;i++)
    {
        ind_menor = i;
        for(j=i+1;j<tam;j++)
        {
            if (vet[j]<vet[ind_menor])
            {
                ind_menor = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[ind_menor];
        vet[ind_menor] = aux;
    }
}