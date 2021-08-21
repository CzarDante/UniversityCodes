#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro
{
    int valor;
    struct registro *prox; 
}registro;

void incluir(lista *l, int x);
registro *aloca_registro();
lista *aloca_lista();
long long int ligada_to_vet(lista *l);
void quicksort(long long int *vet, long long int inicio, long long int fim);

int main()
{
    long long int *vet;
    int n,numero;
    lista *l;
    l = aloca_lista();
    printf("Digite N: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&numero);
        incluir(l,numero);
    }
    vet = ligada_to_vet(l);
    quicksort(vet,0,(l->qtd-1));
    for(int i = 0;i < l->qtd; i++)
    {
        printf("%lld ",vet[i]);
    }
    free(vet);
    printf("\n");
    return 0;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro*)calloc(1,sizeof(registro));
    return novo;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista*)calloc(1,sizeof(lista));
    return novo;
}

void incluir(lista *l, int x)
{
    registro *novo,*aux=NULL;
    novo= aloca_registro();
    novo->valor=x;
    if(l->inicio==NULL){
        l->inicio=novo;
        l->fim=novo;
    }
    else{
        aux=l->inicio;
        while (aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        l->fim->prox=novo;
        l->fim=novo;
    }
    l->qtd++;
}

long long int ligada_to_vet(lista *l)
{
    if (l->inicio==NULL)
    {
        printf("\nlista sem elementos\n");
    }
    else{
        long long int *vet;
        int tam;
        registro *aux;
        aux = l->inicio;
        tam = l->qtd;
        vet = (int*)calloc(tam,sizeof(int));
        for(int i=0;i<tam;i++)
        {
            vet[i]=aux->valor;
            aux=aux->prox;
        }
        return vet;
    }
}

void quicksort(long long int *vet, long long int inicio, long long int fim)
{
    if(inicio>=fim)
    {
        return 0;
    }
    long long int pivo, aux, troca;

    pivo=inicio;
    aux= fim;
    while (pivo!=aux)
    {
        if(pivo<aux)
        {
            if(vet[pivo]>vet[aux]){
                troca=vet[pivo];
                vet[pivo]= vet[aux];
                vet[aux]= troca;
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }
        else
        {
            if(vet[pivo]<vet[aux])
            {
                troca=vet[pivo];
                vet[pivo]= vet[aux];
                vet[aux]= troca;
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }
        if(pivo<aux)
        {
            aux--;
        }
        else
        {
            aux++;
        }
        quicksort(vet,inicio,pivo-1);
        quicksort(vet,pivo+1,fim);
    }
    
}
