#include <stdio.h>

int i;
typedef struct coordenada
{
    int x,y;
}coordenada;
void preenche_cordenada(coordenada * x){
    printf("\nQual a cordenada x: ");
    scanf("%d",&x->x);
    printf("\n");
    printf("Qual a coordenada y: ");
    scanf("%d",&x->y);
    printf("\n");
}
void mostra_tudo(coordenada *lista1_coordenadas, coordenada * lista2_coordenadas){
    int somaxlista1 =0;
    int somaxlista2 =0;
    int somaylista1 =0;
    int somaylista2 =0;
    int lista1quadrante1 =0;
    int lista1quadrante2 =0;
    int lista1quadrante3 =0;
    int lista1quadrante4 =0;
    int lista2quadrante1 =0;
    int lista2quadrante2 =0;
    int lista2quadrante3 =0;
    int lista2quadrante4 =0;
    for(i=0;i<3;i++){
        somaxlista1 += lista1_coordenadas[i].x;
        somaylista1 += lista1_coordenadas[i].y;
        somaxlista2 += lista2_coordenadas[i].x;
        somaylista2 += lista2_coordenadas[i].y;
        if(i==3){
            if(somaxlista1>somaxlista2){
                printf("lista 1 tem maior ocorencia em x\n");
            }
            if(somaxlista1==somaxlista2){
                printf("as listas tem a mesma ocorrencia em x\n");
            }
            if(somaxlista1<somaxlista2){
                printf("lista 2 tem maior ocorencia em x\n");
            }
            if(somaylista1>somaylista2){
                printf("lista 1 tem maior ocorencia em y\n");
            }
            if(somaylista1==somaylista2){
                printf("as listas tem a mesma ocorrencia em y\n");
            }
            if(somaylista1<somaylista2){
                printf("lista 2 tem maior ocorencia em y\n");
            }
        }
    }
    for(i=0;i<3;i++){
        if(lista1_coordenadas[i].x >0 && lista1_coordenadas[i].y >0 ){
            lista1quadrante1++;
        }if(lista1_coordenadas[i].x <0 && lista1_coordenadas[i].y >0 ){
            lista1quadrante2++;
        }if(lista1_coordenadas[i].x <0 && lista1_coordenadas[i].y <0 ){
            lista1quadrante3++;
        }if(lista1_coordenadas[i].x >0 && lista1_coordenadas[i].y <0 ){
            lista1quadrante4++;
        }
        if(lista2_coordenadas[i].x >0 && lista2_coordenadas[i].y >0 ){
            lista2quadrante1++;
        }if(lista2_coordenadas[i].x <0 && lista2_coordenadas[i].y >0 ){
            lista2quadrante2++;
        }if(lista2_coordenadas[i].x <0 && lista2_coordenadas[i].y <0 ){
            lista2quadrante3++;
        }if(lista2_coordenadas[i].x >0 && lista2_coordenadas[i].y <0 ){
            lista2quadrante4++;
        }
    }
    if(lista1quadrante1>lista2quadrante1){
            printf("Lista 1 tem maior ocorrenciano 1 quadrante \n");
    }
    if(lista1quadrante1==lista2quadrante1){
        printf("As listas tem a mesma ocorrencia no 1 quadrante \n");
    }
    if(lista1quadrante1<lista2quadrante1){
        printf("Lista 2 tem maior ocorrenciano 1 quadrante \n");
    }
    if(lista1quadrante2>lista2quadrante2){
        printf("Lista 1 tem maior ocorrenciano 2 quadrante \n");
    }
    if(lista1quadrante2==lista2quadrante2){
        printf("As listas tem a mesma ocorrencia no 2 quadrante \n");
    }
    if(lista1quadrante2<lista2quadrante2){
        printf("Lista 2 tem maior ocorrenciano 2 quadrante \n");
    }
    if(lista1quadrante3>lista2quadrante3){
        printf("Lista 1 tem maior ocorrenciano 3 quadrante \n");
    }
    if(lista1quadrante3==lista2quadrante3){
        printf("As listas tem a mesma ocorrencia no 3 quadrante \n");
    }
    if(lista1quadrante3<lista2quadrante3){
        printf("Lista 2 tem maior ocorrenciano 3 quadrante \n");
    }
    if(lista1quadrante4>lista2quadrante4){
        printf("Lista 1 tem maior ocorrenciano 4 quadrante \n");
    }
    if(lista1quadrante4==lista2quadrante4){
        printf("As listas tem a mesma ocorrencia no 4 quadrante \n");
    }
    if(lista1quadrante4<lista2quadrante4){
        printf("Lista 2 tem maior ocorrenciano 4 quadrante \n");
    }
}
int main()
{
    coordenada lista1_coordenadas[3];
    coordenada lista2_coordenadas[3];
    for(i=0;i<3;i++){
        printf("Coordenada %d da lista 1: ", i+1);
        preenche_cordenada(&lista1_coordenadas[i]);
    }
    for(i=0;i<3;i++){
        printf("Coordenada %d da lista 2: ", i+1);
        preenche_cordenada(&lista2_coordenadas[i]);
    }
    mostra_tudo(lista1_coordenadas, lista2_coordenadas);
}