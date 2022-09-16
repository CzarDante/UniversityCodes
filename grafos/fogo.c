#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
}vertice;

int dfs(vertice *vertices, int qtd_vertices, int raiz,int aux);

int main(){
    int qtd_vertices, qtd_arestas, qtd_conections=0;
    vertice * vertices;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    int a,b;
    for(int i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d", &a, &b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj]=a;
        vertices[b].tam_lista_adj++;
    }
    int aux, qtd_combinacoes=1;
    //descobre a qtd de itens ligados
    for(int i=1;i<=qtd_vertices;i++){
        if(vertices[i].visitado==0)
        {
            aux = dfs(vertices,qtd_vertices,i,1);
            qtd_conections++;
            qtd_combinacoes = qtd_combinacoes * aux;
        }
        
    }
    printf("%d %d", qtd_conections,qtd_combinacoes);
    return 0;
}

int dfs(vertice *vertices, int qtd_vertices, int raiz,int aux)
{
    int i;
    int aux2=1;

    if(vertices[raiz].visitado!=0){
        return 1;
    }

    vertices[raiz].visitado=1;

    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        if(vertices[vertices[raiz].lista_adj[i]].visitado==0){
            aux2 += dfs(vertices,qtd_vertices,vertices[raiz].lista_adj[i],aux2);
        }
    }
    return aux2;
}