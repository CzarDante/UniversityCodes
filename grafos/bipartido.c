#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adjacente[1000];
    int tam_lista_adjavente;
    int cor;
}vertice;

int dfs(vertice *vertices, int qtd_vertices, int raiz, int cor);

int main()
{
    int qtd_vertices, qtd_arestas,a,b;
    vertice *vertices;
    scanf("%d %d",&qtd_vertices,&qtd_arestas);
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));

    for(int i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].lista_adjacente[vertices[a].tam_lista_adjavente]=b;
        vertices[a].tam_lista_adjavente++;
        vertices[b].lista_adjacente[vertices[b].tam_lista_adjavente]=a;
        vertices[b].tam_lista_adjavente++;
    }
    if (dfs(vertices,qtd_vertices,1,1))
        printf("Grafo Bipartido\n");
    else
        printf("Grafo nao bipartido\n");
    
    return 0;
}

int dfs(vertice *vertices, int qtd_vertices, int raiz, int cor)
{
    int i;
    
    vertices[raiz].visitado=1;
    vertices[raiz].cor=cor;
    for (i = 0; i < vertices[raiz].tam_lista_adjavente; i++)
    {
        //se não foi visitado
        if(vertices[vertices[raiz].lista_adjacente[i]].visitado==0)
        {
            //chama recursivamente as adjacencias
            if(!dfs(vertices,qtd_vertices,vertices[raiz].lista_adjacente[i],cor * -1))
            {
                //se a adjacencia estiver errada, retorna falso
                return 0;
            }
        }
        //se ja foi visitado
        else
        {
            //verifica se a adjacencia tem a mesma cor
            if(vertices[raiz].cor == vertices[vertices[raiz].lista_adjacente[i]].cor)
                return 0;
        }
    }
    return 1;

}