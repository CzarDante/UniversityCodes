#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int distancia;
}vertice;

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemento;

typedef struct fila{
    int tamanho;
    struct elemento *inicio;
    struct elemento *final;
}fila;

void insere(fila *f,int x);
int pop(fila *f);
int empty(fila *f);
void bfs(vertice *vertices, int raiz);

int main()
{
    int i,qtd_vertices,qtd_arestas;
    vertice *vertices;
    scanf("%d %d",&qtd_vertices,&qtd_arestas);
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    int a,b,start;
    for(i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj]=b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj]=a;
        vertices[b].tam_lista_adj++;
    }
    scanf("%d",&start);
    bfs(vertices,start);
    for(i=1;i<=qtd_vertices;i++)
    {
        printf("\n Distancia do vertice %d para a raiz %d = %d",i,start,vertices[i].distancia);
    }
    return 0;
}

void insere(fila *f,int x)
{
    elemento *novo;
    novo = (elemento*)calloc(1,sizeof(elemento));
    novo->valor=x;

    if(f->tamanho==0)
    {
        f->inicio=novo;
        f->final=novo;
    }
    else{
        f->final->prox=novo;
        f->final=novo;
    }
    f->tamanho++;
}

int pop(fila *f)
{
    if(empty(f)){
        return -1;
    }else{
        int aux;
        aux = f->inicio->valor;
        f->inicio= f->inicio->prox;
        f->tamanho--;
        return aux;
    }
}

int empty(fila *f)
{
    if(f->tamanho == 0){
        return 1;
    }else{
        return 0;
    }
}

void bfs(vertice *vertices,int raiz)
{
    fila *f;
    f = calloc(1,sizeof(fila));
    int atual;
    int i,adjacente;

    insere(f,raiz);

    while(!empty(f))
    {
        atual=pop(f);
        vertices[atual].visitado=1;
        for(i=0;i<vertices[atual].tam_lista_adj;i++)
        {
            adjacente=vertices[atual].lista_adj[i];
            if(vertices[adjacente].visitado==0)
            {
                vertices[adjacente].distancia = vertices[atual].distancia + 1;
                insere(f,adjacente);
            }
        }
    }
}
