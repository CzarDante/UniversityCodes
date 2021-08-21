#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int qtd;
    struct no *raiz;
}arvore;

typedef struct no
{
    int valor;
    int qtd;
    struct no *esquerda; 
    struct no *direita; 
}no;

arvore *aloca_arvore();
no *aloca_no();
void incluir(arvore *a,int x);
int primo(int x);
int soma_primos(no *a);


int main()
{
    arvore *a;
    a= aloca_arvore();
    int n,numero;
    printf("Digite N: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&numero);
        incluir(a,numero);
    }
    //Verifica primos
    //se houver numeros repetidos so contabiliza 1
    //não questão não especificou então achei que podia
    numero = soma_primos(a->raiz);
    printf("%d primos\n",numero);

    printf("\n");
    return 0;
}

arvore *aloca_arvore()
{
    arvore *novo;
    novo = (arvore*)calloc(1,sizeof(arvore));
    return novo;
}

no *aloca_no()
{
    no *novo;
    novo = (no*)calloc(1,sizeof(no));
    return novo;
}

void incluir(arvore *a,int x)
{
    no *novo, *aux;
    novo = aloca_no();
    novo->valor=x;
    novo->qtd=1;
    int inseriu = 0;

    if(a->raiz==NULL)
    {
        a->raiz=novo;
        a->qtd++;
    }
    else
    {
        aux = a->raiz;
        while (!inseriu)
        {
            if(aux->valor==x)
            {
                aux->qtd++;
                printf("Esse numero ja foi inserido, a quantidade desse elemento foi incrementada\n");
                return;
            }
            else
            {
                if(x<aux->valor)
                {
                    if(aux->esquerda ==NULL)
                    {
                        aux->esquerda= novo;
                        inseriu=1;
                        a->qtd++;
                    }
                    else
                    {
                        aux = aux->esquerda;
                    }
                }
                else
                {
                    if(aux->direita==NULL)
                    {
                        aux->direita = novo;
                        inseriu=1;
                        a->qtd++;
                    }
                    else
                    {
                        aux=aux->direita;
                    }
                }
            }
        }
    }
}

int primo(int x)
{
    if(x==0 || x==1)
    {
        return 0;
    }
    int divisor;
    for(divisor=2;divisor<x;divisor++)
    {
        if(x%divisor==0)
        {
            return 0;
        }
    }
    return 1;
}

int soma_primos(no *a)
{
    if(a==NULL)
    {
        return 0;
    }
    int primos =0;
    if(primo(a->valor))
    {
        primos++;
    }
    // soma_primos(a->esquerda);
    // soma_primos(a->direita);
    return primos + (soma_primos(a->esquerda)) + (soma_primos(a->direita));
}