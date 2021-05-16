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
    srand(time(NULL));
    FILE * arq;
    arq = fopen("tempos_insertion.csv","a+");
    if ( arq==NULL)
        return 0;
    for (tam = 1000; tam <= 50000; tam += 1000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        clock_t begin = clock();

        double time_spent= 0.0;
 
        insertionsort(vet,tam);
 
        clock_t end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
        printf("\tThe elapsed time is %f seconds", time_spent);
        
        // double Tempo = ((Ticks[1] - Ticks[0]) *1000 / CLOCKS_PER_SEC);
        // printf("\tTempo gasto: %f s", Tempo);
        fprintf(arq,"%lld;%f\n",tam,time_spent);
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
    long long int i=1;
    long long int j;
    long long int aux;
    for(i=1;i<=tam-1;i++)
    {
        for (j=i;j>0 && vet[j-1]>vet[j];j++)
        {
            aux = vet[j];
            vet[j]=vet[j-1];
            vet[j-1]=aux;
        }
    }
    
}