#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[10000];
    int tam_lista_adj;
    int distancia;
}vertice;

void dfs(vertice *vertices,int raiz,int distancia);
void ZeraDfs(vertice *vertices,int qtd_vertices);

int main()
{
    vertice *vertices;
    int qtd_vertices,qtd_arestas;
    scanf("%d",&qtd_vertices);
    scanf("%d",&qtd_arestas);
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    int a,b;
    for (int i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj]=b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj]=a;
        vertices[b].tam_lista_adj++;
    }
    int testes;
    int x,y;
    scanf("%d",&testes);
    int retorno[testes];
    for (int j = 0; j < testes; j++)
    {
        ZeraDfs(vertices,qtd_vertices);
        scanf("%d %d",&x,&y);
        if(x==y){
            retorno[j]=0;
        }

        if (x>y)
        {
            dfs(vertices,y,0);
            retorno[j] = vertices[x].distancia;
        }else
        {
            dfs(vertices,x,0);
            retorno[j] = vertices[y].distancia;
        }   
    }
    for (int z = 0; z < testes; z++)
    {
        printf("%d\n",retorno[z]);
    }
    
    return 0;
}

void dfs(vertice *vertices,int raiz,int distancia)
{
    vertices[raiz].visitado=1;
    vertices[raiz].distancia=distancia;

    for (int i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado==0)
        {
            dfs(vertices,vertices[raiz].lista_adj[i],distancia+1);
        }
    }
}

void ZeraDfs(vertice *vertices,int qtd_vertices)
{
    for (size_t i = 0; i < qtd_vertices; i++)
    {
        vertices[i].visitado=0;
    }
}