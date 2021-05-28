#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *cria_vetor(long long int n);
long long int busca_sequencial(long long int *vet, long long int tam, long long int busca);
long long int busca_binaria(long long int *vet, long long  int inicio, long long int fim, long long int busca);

int main()
{
    long long int *vet;
    long long int tam;
    long long int busca, achou;
    srand(time(NULL));
    clock_t t1,t2;
    printf("\nQual o tamanho do vetor? ");
    scanf("%lld", &tam);
    vet = cria_vetor(tam);
    printf("\nQual numero deseja buscar?");
    scanf("%lld",&busca);
    t1 = clock();
    achou = busca_sequencial(vet, tam,busca);
    t2 = clock();
    float time_spent1 = (((float)t2 - (float)t1) / 1000000.0F);
    printf("\nTempo de execucao sequencial: %f", time_spent1);
    if(achou<0){
        printf("\nnumero n encontrado");
    }
    else{
        printf("\nnumero encontrado");
        printf("\tposicao %lld",achou);
    }
    t1 = clock();
    achou = busca_binaria(vet,0,tam,busca);
    t2 = clock();
    float time_spent2 = (((float)t2 - (float)t1) / 1000000.0F);
    if(achou<0){
        printf("\nnumero n encontrado");
    }
    else{
        printf("\nnumero encontrado");
        printf("\tposicao %lld",achou);
    }
    printf("\nTempo de execucao binaria: %f", time_spent2);
    
    free(vet);
    // printf("\ncrescente");
    // for (tam = 1000; tam <= 90000; tam += 1000)
    // {
    //     busca = (tam/3);
    //     vet = cria_vetor(tam);
    //     printf("\n Tamanho do vetor: %lld",tam);
    //     clock_t begin1 = clock();
    //     achou = busca_sequencial(vet, tam,busca);
    //     clock_t end1 = clock();
    //     float time_spent1 = (((float)end1 - (float)begin1) / 1000000.0F);
    //     printf("\nTempo de execucao sequencial: %lf", time_spent1);
    //     printf("\tposicao %lld",achou);

    //     clock_t begin2 = clock();
    //     achou = busca_binaria(vet,0,tam,busca);
    //     clock_t end2 = clock();
    //     float time_spent2 = (((float)end2 - (float)begin2) / 1000000.0F);
    //     printf("\nTempo de execucao binaria: %lf", time_spent2);
    //     printf("\tposicao %lld",achou);
    //     free(vet);
    // }
}

long long int *cria_vetor(long long int n)
{
    long long int *vet, i, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (i = 0; i < n; i++)
    {
        vet[i] = i + 9;
    }
    return vet;
}

long long int busca_sequencial(long long int *vet, long long int tam, long long int busca)
{
    for (int i = 0; i < tam; i++) {

        if (vet[i] == busca) {
            return i;
        }
    }

    return -1;
}

long long int busca_binaria(long long int *vet, long long  int inicio, long long int fim, long long int busca)
{
    long long int i = (inicio + fim) / 2;

    if (inicio > fim) { 
        return -1;
    }

    if (vet[i] == busca) {
        return i;
    }
    else{
        if (vet[i] < busca) {
            return busca_binaria(vet, i + 1, fim, busca);
        }else { 
            return busca_binaria(vet, inicio, i - 1, busca);
        }
    }
}