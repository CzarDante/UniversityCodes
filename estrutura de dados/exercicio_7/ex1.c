#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int tamanho;
    struct elemento *inicio;
    struct elemento *final;
} fila;

typedef struct elemento
{
    int valor;
    struct elemento *prox;
} elemento;

fila *aloca_fila()
{
    fila *novo;
    novo = (fila *)malloc(sizeof(fila));
    novo->tamanho = 0;
    novo->inicio = NULL;
    novo->final =NULL;
    return novo;
}

elemento *aloca_elemento()
{
    elemento *novo;
    novo = (elemento *)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void insert(fila *f, int x);
int dequeue(fila *f);
int empty(fila *f);
int size(fila *f);

int main(){

    int n=1, i, last;
    fila *discart;

    discart = aloca_fila();

    while(n!=0)
    {
        scanf("%d", &n);
        if(n){
            
            for(i=1;i<=n;i++){
                insert(discart, i);
            }

            printf("Cartas Descartadas:");

            while(size(discart)>=2){
                printf(" %d", dequeue(discart));
                insert(discart, dequeue(discart));

                // if(size(discart)!=1)
                //     printf(",");
            }

            last = dequeue(discart);
            printf("\nCartas restantes: %d\n", last);
            
            }
    }

    return 0;
}

void insert(fila *f, int x)
{
    elemento *novo;
    novo = aloca_elemento();
    novo->valor = x;

    if (f->inicio == NULL && f->final == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->final->prox = novo;
    }
    f->final = novo;
    f->tamanho++;
}

int dequeue(fila *f)
{
    if (f->inicio == NULL && f->final == NULL)
        return 0;
    int retorno;
    elemento *aux;
    aux = f->inicio;
    f->inicio = aux->prox;
    retorno = aux->valor;
    free(aux);
    f->tamanho--;
    return retorno;
}

int empty(fila *f)
{
    return f->inicio==NULL;
}

int size(fila *f)
{
    return f->tamanho;
}