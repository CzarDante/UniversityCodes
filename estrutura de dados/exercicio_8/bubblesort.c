#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void bubblesort(long long int *vet, long long int tam);

int main()
{
    long long int *vet;
    long long int tam;
    srand(time(NULL));
    double t1,t2;
    FILE * arq;
    clock_t Ticks[2];
    arq = fopen("tempos_bubblesort.csv","a+");
    if ( arq==NULL)
        return 0;

    for (tam = 10000; tam <= 200000; tam = tam + 10000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        // printf("\n Vetor desordenado: ");
        // mostrar_vetor(vet, tam);
        Ticks[0] = clock();
        bubblesort(vet, tam);
        Ticks[1] = clock();
        double Tempo = ((Ticks[1] - Ticks[0]) *1000 / CLOCKS_PER_SEC);
        printf("\tTempo gasto: %.1g ms.", Tempo);
        fprintf(arq,"%lld;%.1f\n",tam,Tempo);
        // printf("\n Vetor Ordenado: ");
        // mostrar_vetor(vet, tam);
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

void bubblesort(long long int *vet, long long int tam)
{
    long long int pass, i, aux;
    int trocou = 1;

    for (pass = 0; pass < tam - 1 && trocou; pass++)
    {
        trocou = 0;
        for (i = 0; i < tam - 1 - pass; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                trocou = 1;
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}