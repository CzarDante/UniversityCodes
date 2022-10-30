#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[10000];
    int tam_lista_adj;
    int distancia;
}vertice;

void dfs(vertice *vertices, int qtd_vertices, int raiz, int distancia);

int main(){
    int qtd_vertices, qtd_arestas;
    vertice * vertices;
    scanf("%d", &qtd_vertices);
    qtd_arestas=qtd_vertices-1;
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    int a,b;
    for(int i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d", &a, &b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj]=b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj]=a;
        vertices[b].tam_lista_adj++;
    }

    int large_path[2];
    large_path[0]=0; //id
    large_path[1]=0; //distancia

    dfs(vertices,qtd_vertices,1,0);

    for(int i=1;i<=qtd_vertices;i++){
        if(vertices[i].distancia > large_path[1]){
            large_path[0]=i;
            large_path[1]=vertices[i].distancia;
        }
    }

    int aux = large_path[0];

    for(int i=1;i<=qtd_vertices;i++){
        vertices[i].visitado=0;
    }

    dfs(vertices,qtd_vertices,aux,0);


    large_path[0]=0; //id
    large_path[1]=0; //distancia

    for(int i =1;i<=qtd_vertices;i++){
        if(vertices[i].distancia > large_path[1]){
            large_path[0]=i;
            large_path[1]=vertices[i].distancia;
        }
    }

    printf("%d", large_path[1]);
    return 0;
}

void dfs(vertice *vertices, int qtd_vertices, int raiz, int distancia)
{
    int i;

    if(vertices[raiz].visitado!=0){
        return;
    }

    vertices[raiz].visitado=1;
    vertices[raiz].distancia = distancia;

    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado==0)
        {
            dfs(vertices,qtd_vertices,vertices[raiz].lista_adj[i], distancia+1);
        }
    }
}
