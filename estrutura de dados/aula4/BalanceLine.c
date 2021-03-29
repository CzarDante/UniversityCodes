#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void incluir_ordenado(lista *l, int x);
void mostrar_lista(lista *l);
int numeros_comuns(lista *l1, lista *l2);

int main()
{
    int n, meio, i, numero;
    lista *l1, *l2;
    int lista_comum;
    l1 = aloca_lista();
    l2 = aloca_lista();
    srand(time(NULL));
    printf("\n Digite o valor de n: ");
    scanf("%d", &n);
    meio = n / 2;
    for (i = 0; i < n; i++)
    {
        numero = rand()%50;
        incluir_ordenado(l1, numero);
        numero = rand()%50;
        incluir_ordenado(l2, numero);
    }
    lista_comum = numeros_comuns(l1,l2);
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
void incluir_ordenado(lista *l, int x)
{
    registro *novo, *aux = NULL, *ant = NULL;

    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL && aux->valor < x)
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux->valor >= x)
        {
            if (ant == NULL)
            {
                l->inicio = novo;
            }else{
                ant->prox = novo;
            }
            novo->prox = aux;
        }else{
            aux->prox = novo;  
        }
        l->qtd++;
    }
}
void remove_duplicados(lista* l1){
    registro *aux, *prox;
    aux = aloca_registro();
    while (aux)
    {
        /* code */
    }
    
    for(corrente = l1; corrente != NULL; corrente = corrente -> prox ){
        ant = NULL;

        for(prox = corrente -> prox; prox != NULL; ){
            if(0 == strcmp(corrente -> info.nome, prox -> info.nome)){
                if(ant == NULL)
                    corrente -> prox = prox -> prox;
                else
                    ant -> prox = prox -> prox;

                Elemento* remover = prox;
                prox = prox -> prox;
                free(remover);
            }
            else {
                ant = prox;
                prox = prox->prox;
            }
        }
    }
}