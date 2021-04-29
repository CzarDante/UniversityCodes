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
void remove_perfeitos(lista *l);
void inlcuir(lista *l,int x);
void mostrar(lista *l);

int main()
{
    int n,numero;
    lista *l;
    l=aloca_lista();
    printf("Digite n\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Digite o numero %d:",i+1);
        scanf("%d",&numero);
        inlcuir(l,numero);
    }
    mostrar(l);
    remove_perfeitos(l);
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

void remove_perfeitos(lista *l)
{
    if(l->inicio==NULL){
        printf("\nLista Vazia\n");
        return 0;
    }
    registro *aux,*ant;
    aux=l->inicio;
    int div,soma;
    for(int i=0;i<l->qtd;i++){
        soma=0;
        for(div=1;i<aux->valor;div++){
            if(aux->valor%div==0){
                soma=soma+div;
            }
        }
        if(soma==aux->valor){
            if(ant==NULL){
                l->inicio=aux->prox;
            }else{
                ant->prox=aux->prox;
                aux=aux->prox;
                aux->ant=ant;
            }
        }
        else{
            ant=aux;
            aux=aux->prox;
        }
    }
}

int inlcuir(lista *l,int x){
    registro *novo,*aux=NULL;
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
void mostrar(lista *l)
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
