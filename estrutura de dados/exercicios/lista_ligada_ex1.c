#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void mostrar_lista(lista *l);
void mostra_pares(lista *l);
void opcoes()
{
    printf("\nSelecione a opcao desejada\n");
    printf("1-Adiciona um numero\n");
    printf("2-Mostra a lista completa\n");
    printf("3-Mostra os pares da lista\n");
    printf("4-Sair\n");
}

int main()
{
    lista *List;
    int x = 0,opcao;
    List =aloca_lista();
    do
    {
        opcoes();
        scanf("%d",&opcao);
        if(opcao==1){
            printf("\n Qual numero deseja inserir?");
            scanf("%d", &x);
            incluir_no_final(List, x);
        }
        if(opcao==2){
            mostrar_lista(List);
            printf("\n");
        }
        if(opcao==3){
            mostra_pares(List);
            printf("\n");
        }
    } while(opcao!=4);
    printf("\n");
    return 0;
}
lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}
registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}
void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;
    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\nValor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}
void mostra_pares(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aux->valor % 2 == 0)
            {
                printf("\nValor = %d", aux->valor);
            }
            aux = aux->prox;
        }
    }
}