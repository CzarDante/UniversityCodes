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
int inlcuir(lista *l,int x);
int mostrar(lista *l);
int num_primo(int x);
int move_primo(lista *l);

int main()
{
    lista *l;
    registro *aux;
    int n,numero;
    l=aloca_lista();
    
    printf("Insira N: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nDigite o numero %d: ",i+1);
        scanf("%d",&numero);
        incluir(l,numero);
    }

    mostrar(l);
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

int mostrar(lista *l)
{
    registro *aux;
    if(l->inicio==NULL)
    {
        printf("\nLista Vazia\n");
        return 0;
    }

    aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d",aux->valor);
        aux = aux->prox;
    }
}

int inlcuir(lista *l,int x)
{
    registro *novo,*aux;
    novo=aloca_registro();
    novo->valor=x;
    if(l->inicio==NULL){
        l->inicio=novo;
    }
    else{
        aux = l->inicio;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox=novo;
    }
    l->qtd++;
}

int num_primo(int x)
{
    if(x==0|| x==1){
        return 0;
    }
    int div;
    for(div=2;div<x;div++){
        if(x%div==0){
            return 0;
        }
    }
    return 1;
}

int move_primo(lista *l)
{
    registro *aux,*ant;
    aux = l->inicio;
    while (aux !=NULL)
    {
        if(num_primo(aux->valor)){
            ant->prox=aux->prox;
            aux->prox->ant=aux;
            l->inicio->ant=aux;
            aux->prox=l->inicio;
            l->inicio=aux;
        }
        else{
            ant=aux;
            aux=aux->prox;
        }
    }
}
