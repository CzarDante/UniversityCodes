/*  1 - Remover Primos
    2 - Remover numeros iguais -feito
    3 - Buscar por numero -feito
    4 - Comparar 2 listas ( falar os numeros iguais e quais sao diferentes)
    5 - incluir de forma ordenada -feito
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void mostrar(lista *l, int inverso);
void menu(lista *l);
void incluir_ordenado(lista *l, int x);
void remove_todos(lista *l);
void busca_numero(lista *l1, int x);
// void remove_primos(lista *l);


int main()
{
    lista *l;  
    l = aloca_lista();
    menu(l);
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
    novo->ant = NULL;
    return novo;
}

void mostrar(lista *l, int inverso)
{
    registro *aux;
    if (l->inicio == NULL || l->fim == NULL)
    {
        printf("\n lista vazia");
        return;
    }

    if (!inverso)
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void menu(lista *l)
{
    int opcao, numero, x;
    do
    {
        printf("\n1 - Mostrar lista");
        printf("\n2 - Remove primos");
        printf("\n3 - Remove iguais");
        printf("\n4 - Busca numero");
        printf("\n5 - Compara 2 listas");
        printf("\n6 - Incluir de forma ordenada");
        printf("\n99 - Parar programa\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            mostrar(l, 0);
            break;
        case 2:
            // remove_primos(l);
            printf("\nNao implementado\n");
            break;
        case 3:
            remove_todos(l);
            break;
        case 4:
            printf("\nDigite o numero que quer buscar: ");
            scanf("%d",&x);
            busca_numero(l,x);
            break;
        case 5:
            //compara 2 listas
            printf("\nNao implementado\n");
            break;
        case 6:
            printf("\n Digite um numero: ");
            scanf("%d", &x);
            incluir_ordenado(l,x);
            break;
        case 99:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 99);
}

void incluir_ordenado(lista *l, int x)
{
    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;
    
    if(l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim =novo;
        printf("Numero: %d adicionado com sucesso\n",novo->valor);
    }else
    {
        aux = l->inicio;
        while (aux->prox != NULL && aux->valor <= x)
        {
            ant = aux;
            aux = aux->prox;
        }
        if (aux->valor >= x)
        {
            if (ant == NULL){
                l->inicio->ant = novo;
                novo->prox=l->inicio;
                l->inicio=novo;
            }else{
                ant->prox = novo;
                aux->ant=novo;
            }
            novo->prox = aux;
        }
        else
        {
            l->fim->prox = novo;
            novo->ant = l->fim;
            l->fim = novo;
        }
    }
    l->qtd++;
}

void remove_todos(lista *l)
{
    if (l->inicio == NULL)
    {
        return 0;
    }
    registro *aux = NULL, *ant = NULL;
    aux = l->inicio;
    while(aux != l->fim)
    {
        if(aux->valor==aux->prox->valor){
            if(ant==NULL){
                printf("removido o numero %d\n",aux->valor);
                l->inicio = aux->prox;
                aux=aux->prox;          
            }else{
                printf("removido o numero %d\n",aux->valor);
                ant->prox=aux->prox;
                aux=aux->prox;
                aux->ant=ant;
            }
        }else
        {
            ant = aux;
            aux = aux->prox;
        }
    }
    return 1;
}

void busca_numero(lista *l1, int x)
{
    if(l1->inicio==NULL){
        printf("\nLista vazio");
        return 0;
    }
    registro *aux, *ant;
    aux = l1->inicio;

    while(aux != NULL)
    {
        if(aux->valor==x){
            printf("\nNumero encontrado:");
            printf("\nNumero: %d",aux->valor);
            if(aux->prox!=NULL){
                printf("\tProximo: %d",aux->prox->valor);
            }else{
                printf("\tProximo: inexistente");
            }
            if(aux->ant!=NULL){
                printf("\tAnterior: %d\n",aux->ant->valor);
            }else{
                printf("\tAnterior: inexistente\n");
            }
            return 1;
        }

        aux=aux->prox;
    }
    printf("\nNumero nao encontrado");
    return 0;
}

// void remove_primos(lista *l)
// {
//     if (l->inicio == NULL)
//     {
//         return 0;
//     }
//     registro *aux = NULL, *ant = NULL;
//     aux = l->inicio;
//     while(aux != l->fim)
//     {   
//         int primo=0;
//         for(int i=0;i<=17;i++){
//             if (aux->valor%i==0)
//             {
//                 primo++;
//             }
//         }if(primo==0){
//             if(ant==NULL){
//                 printf("removido o numero %d\n",aux->valor);
//                 l->inicio = aux->prox;
//                 aux=aux->prox;          
//             }else{
//                 printf("removido o numero %d\n",aux->valor);
//                 ant->prox=aux->prox;
//                 aux=aux->prox;
//                 aux->ant=ant;
//             }
//         }else{
//             ant = aux;
//             aux = aux->prox;
//         }
//     }
// }