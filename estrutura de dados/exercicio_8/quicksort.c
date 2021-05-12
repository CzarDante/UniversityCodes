#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void quickSort(long long int *vet, long long int inicio, long long int fim);

int main()
{
    clock_t Ticks[2];
    long long int *vet;
    long long int tam;
    srand(time(NULL));
    FILE * arq;
    clock_t Ticks[2];
    arq = fopen("tempos_quick.csv","a+");
    if ( arq==NULL)
        return 0;

    for (tam = 10000; tam <= 80000; tam = tam + 1000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);     
        Ticks[0] = clock();
        quickSort(vet, 0, (tam-1));
        Ticks[1] = clock();
        double Tempo = ((Ticks[1] - Ticks[0]) *1000 / CLOCKS_PER_SEC);
        printf("\tTempo gasto: %.1g ms.", Tempo);
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

void quickSort(long long int *vet, long long int inicio, long long int fim){ 
	if(inicio < fim){ 
		char pivot = vet[(inicio + fim) / 2];
        char temp;
        long long int i = inicio;
        long long int f = fim;
		while (i <= f) {
            while ((vet[i] < pivot) && (i < fim)) {
                i++;
            }

            while ((vet[f] > pivot) && f > inicio) {
                f--;
            }

            if (i <= f) {
                temp = vet[i];
                vet[i] = vet[f];
                vet[f] = temp;

                i++;
                f--;
            }
        }
        if (inicio < f) {
            quickSort(vet, inicio, f);
        }

        if (i < fim) {
            quickSort(vet, i, fim);
        }
	}
}

