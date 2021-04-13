#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    int *inicio;
    int *fim;
}lista;

typedef struct registro
{
    int *valor;
    int *ant;
    int *prox;
}registro;

registro *aloca_registro();
lista *aloca_lista();
void inlcuir(lista *l,int x);
void mostrar(lista *l);
void inverter(lista *a,lista *b);

int main()
{
    lista *a, *b;
    int n,m, numero;
    a=aloca_lista();
    b=aloca_lista();
    printf("\nDigite N: ");
    scanf("%d",&n);
    printf("\nDigite M: \n");
    scanf("%d",&m);
    for(int i=0;i<n;i++)
    {
        printf("Digite o numero %d:",i+1);
        scanf("%d",&numero);
        inlcuir(a,numero);
    }
    for(int i=0;i<m;i++)
    {
        printf("Digite o numero %d:",i+1);
        scanf("%d",&numero);
        inlcuir(b,numero);
    }
    printf("Antes de inverter\n");
    mostra(a);
    mostrar(b);
    inverter(a,b);
    mostra(a);
    mostrar(b);
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

void inlcuir(lista *l,int x){
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

void inverter(lista *a,lista *b)
{
    
}
