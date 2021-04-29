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
int remove(fila *f);
int empty(fila *f);
int size(fila *f);
int front(fila *f);

int main()
{
    fila *f;
    f = aloca_fila();
    int opcao, numero;
    do
    {
        printf("\n 1 - Insert");
        printf("\n 2 - Remove");
        printf("\n 3 - Empty");
        printf("\n 4 - Size");
        printf("\n 5 - Front");
        printf("\n 6 - Sair\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o numero: ");
            scanf("%d",&numero);
            insert(f,numero);
            break;
        case 2:
            if(empty(f)){
                printf("\nFila Vazia");                
            }else{
                numero = remove(f);
                printf("\nNumero retirado: %d ",numero);
            }
            break;
        case 3:
            if(empty(f)){
                printf("\nFila Vazia");                   
            }else{
                printf("\nFila nao esta vazia");
            }
            break;
        case 4:
            if(empty(f)){
                printf("\nPilha Vazia");                
            }else{
                numero = size(f);
                printf("\nTamnho: %d", numero); 
            }
            break;
        case 5:
            if(empty(f)){
                printf("\nPilha Vazia");                
            }else{
                numero = front(f);
                printf("\nFront: %d", numero);
            }
            break;
        case 6:
            printf("\nSaindo do Programa\n");
            break;
        default:
            printf("\nOpcao invalida");
            break;
        }
    } while (opcao!=6); 
    printf("\n");
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
        f->final = novo;
    }
    else
    {
        f->final->prox = novo;
        f->final = novo;
    }
    f->tamanho++;
}

int remove(fila *f)
{
    elemento *aux=NULL;
    aux=f->inicio;    
    f->inicio = aux->prox;
    f->tamanho--;
    return aux->valor;
}

int empty(fila *f)
{
    if(f->inicio==NULL && f->final==NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

int size(fila *f)
{
    return f->tamanho;
}

int front(fila *f)
{
    return f->inicio->valor;
}