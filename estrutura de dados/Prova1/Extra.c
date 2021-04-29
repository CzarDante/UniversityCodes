//pilha com conceitos em pilha ligada.
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
}lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
}registro;


registro *aloca_registro();
lista *aloca_lista();
int empty(lista *l);
int push(lista *l,int x);
int pop(lista *l);
int stackpop(lista *l);

int main()
{
    int numero,opcao;
    lista *l;
    l=aloca_lista();
    do
    {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Sair\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);
            push(l,numero);
            break;
        case 2:
            if (empty(l))
            {
                printf("\n pilha vazia");
            }else
            {
                printf("\nNumero que saiu: %d",pop(l));
            }
            break;
        case 3:
            if (empty(l))
            {
                printf("\n pilha vazia");
            }
            else
            {
                printf("\nNumero do topo: %d",stackpop(l));
            }
            break;
        case 4:
            if(empty(l)){
                printf("\n pilha vazia");
            }else{
                printf("\n pilha nao esta vazia");
            }
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao !=5);
    printf("\n");
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->inicio=NULL;
    novo->qtd=0;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro*)malloc(sizeof(registro));
    novo->ant=NULL;
    novo->prox=NULL;
    novo->valor=0;
    return novo;
}

int empty(lista *l){
    if (l->inicio==NULL)
        return 1;
    else
        return 0;
}

int push(lista *l,int x)
{
    registro *novo,*aux=NULL;
    novo=aloca_registro();
    novo->valor=x;
        if(empty(l)){
            l->inicio=novo;
        }
        else{
            aux=novo;
            aux->prox=l->inicio;
            l->inicio=aux;
        }
        l->qtd++;
    return 0;
}

int pop(lista *l)
{
    registro *aux;
    int retorno;
    aux=l->inicio;
    l->inicio=aux->prox;
    retorno = aux->valor;
    free(aux);
    l->qtd--;
    return retorno;
}

int stackpop(lista *l)
{
    if(empty(l))
        return -1;
    else
        return l->inicio->valor;
}