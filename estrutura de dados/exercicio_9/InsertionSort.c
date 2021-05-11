/*Implemente o algoritmo InsertionSort e calcule seu tempo de execução para diversos tamanhos de vetores.
Monte um gráfico demonstrando a curva de aumento de tempo em relação ao aumento de N ( tamanho do vetor.)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void insertionsort(long long int *vet, long long int tam);

int main()
{
    clock_t Ticks[2];
    long long int *vet;
    long long int tam;
    srand(time(NULL));
    FILE * arq;

    arq = fopen("tempos.csv","a+");
    if ( arq==NULL)
        return 0;

    for (tam = 100; tam <= 10000; tam = tam + 100)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        // mostrar_vetor(vet,tam);     
        Ticks[0] = clock();
        insertionsort(vet,tam);
        Ticks[1] = clock();
        // mostrar_vetor(vet,tam); 
        double Tempo = ((Ticks[1] - Ticks[0]) *1000 / CLOCKS_PER_SEC)/1000000.0;
        printf("\tTempo gasto: %g ms.", Tempo);
        fprintf(arq,"%lld;%.9f\n",tam,Tempo);
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

void insertionsort(long long int *vet, long long int tam)
{
    int i=1;
    int j;
    long long int aux;
    while (i<tam)
    {
        j=i;
        while (j>0 && vet[j-1]>vet[j])
        {
            aux = vet[j];
            vet[j]=vet[j-1];
            vet[j-1]=aux;
            j--;
        }
        i++;
    }
    
}