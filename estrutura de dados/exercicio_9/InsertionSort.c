/*Implemente o algoritmo InsertionSort e calcule seu tempo de execução para diversos tamanhos de vetores.
Monte um gráfico demonstrando a curva de aumento de tempo em relação ao aumento de N ( tamanho do vetor.)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void insertionsort(long long int *vet, long long int tam);

int main()
{
    long long int *vet;
    long long int tam;
    clock_t begin, end;
    srand(time(NULL));
    FILE * arq;
    arq = fopen("tempos_insertion.csv","w");
    if ( arq==NULL)
        return 0;
    for (tam = 10000; tam <= 90000; tam += 1000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        begin = clock();
 
        insertionsort(vet,tam);
 
        end = clock();
        float time_spent = (((float)end - (float)begin) / 1000000.0F); 
        printf("\tTempo gasto: %lf ms", time_spent);
        
        fprintf(arq,"%lld;%lf\n",tam,time_spent);
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

void insertionsort(long long int * vet, long long int tam)
{
    long long int i,j,aux;

    for(i=1;i<tam;i++)
    {
        aux = vet[i];
        for(j=i-1;j>=0 && vet[j]>aux;j--)
        {
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
}