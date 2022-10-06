#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int inout[2]; //[0]in [1]out
}vertice;

int count=0;

void dfs(vertice *vertices,int raiz);

int main()
{
    vertice *vertices;
    int qtd_vertices,qtd_arestas;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
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

    dfs(vertices,0);
    printf("\nTeste: in,%d out,%d\n",vertices[1].inout[0],vertices[1].inout[1]);
    
    int in=0;
    int out=0;
    for (int j = 0; j < qtd_vertices; j++)
    {
        in = vertices[j].inout[0];
        out = vertices[j].inout[1];
        //printf("%d %d %d",j,in,out);
        printf("Numero: %d, Entrada: %d, Saida: %d\n",j,in,out);
    }
    
}

void dfs(vertice *vertices,int raiz)
{
    vertices[raiz].visitado=1;
    vertices[raiz].inout[0]=count;
    count++;
    
    for (int i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado==0)
        {
            dfs(vertices,vertices[raiz].lista_adj[i]);
            vertices[vertices[raiz].lista_adj[i]].inout[1]=count;
            count++;
        }
        
    }
    vertices[raiz].inout[1]=count;
    return;
}