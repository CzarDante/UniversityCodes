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
void incluir(lista *l,int x);
void pop(lista *l);

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
            incluir(l,numero);
            break;
        case 2:
            if (l->inicio!=NULL)
            {
                pop(l);
            }else
            {
                printf("\n pilha vazia");
            }
            break;
        case 3:
            if (l->inicio!=NULL)
            {
                int topo =l->inicio->valor;
                printf("\n numero que esta no topo da pilha: %d ", topo);
            }
            else
            {
                printf("\n pilha vazia");
            }
            break;
        case 4:
            if (l->inicio==NULL)
                printf("\n Pilha vazia");
            else
                printf("\n pilha nao esta vazia");
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


void incluir(lista *l,int x)
{
    registro *novo,*aux=NULL;
    novo=aloca_registro();
    novo->valor=x;
        if(l->inicio==NULL){
            l->inicio=novo;
        }
        else{
            aux=novo;
            aux->prox=l->inicio;
            l->inicio=aux;
        }
        l->qtd++;
    return;
}

void pop(lista *l)
{
    registro *aux=NULL;
    aux=l->inicio;
    l->inicio=aux->prox;
    l->qtd--;
}