#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[10000];
    int tam_lista_adj;
    int distancia;
    int in;
    int lower;
}vertice;

int count=0;

void dfs(vertice *vertices, int qtd_vertices, int raiz, int distancia, int pai);
int menor(int a, int b);

int main(){
    int qtd_vertices, qtd_arestas;
    vertice * vertices;
    scanf("%d %d",&qtd_vertices,&qtd_arestas);
    vertices = (vertice *)calloc(qtd_vertices+1, sizeof(vertice));
    int a,b;
    for(int i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d", &a, &b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj]=b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj]=a;
        vertices[b].tam_lista_adj++;
    }

    dfs(vertices,qtd_vertices,1,0,0);

    return 0;
}

void dfs(vertice *vertices, int qtd_vertices, int raiz, int distancia,int pai)
{
    int i;

    if(vertices[raiz].visitado!=0){
        return;
    }

    vertices[raiz].visitado=1;
    vertices[raiz].distancia = distancia;
    vertices[raiz].in=count;
    vertices[raiz].lower=count;
    count++;

    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado==0)
        {
            dfs(vertices,qtd_vertices,vertices[raiz].lista_adj[i], distancia+1,raiz);
            if(vertices[raiz].in<vertices[vertices[raiz].lista_adj[i]].lower)
            {
                 printf("Ponte entre: %d %d\n",raiz,vertices[raiz].lista_adj[i]);
            }
            vertices[raiz].lower = menor(vertices[raiz].lower, vertices[vertices[raiz].lista_adj[i]].lower);
        }else if (vertices[raiz].lista_adj[i] != pai)
        {
            vertices[raiz].lower = menor(vertices[raiz].lower, vertices[vertices[raiz].lista_adj[i]].in);
        }
    }
}

int menor(int x, int y)
{
    if (x <= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
