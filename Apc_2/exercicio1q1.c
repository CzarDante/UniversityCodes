#include <stdio.h>

int i;
typedef struct coordenada
{
    int x,y;
}coordenada;

void preenche_cordenada(coordenada * x){
    printf("\nQual a cordenada x%d: ",i);
    scanf("%d",&x->x);
    printf("\nQual a coordenada y%d: ",i);
    scanf("%d",&x->y);
}
void mostra_cordenada(coordenada x){
    if(x.x == 0 && x.y == 0){
        printf("Coordenada no ponto neutro\n");
    }if(x.x == 0 && x.y != 0){
        printf("Coordenada sobre o eixo Y\n");
    }if(x.y == 0 && x.x != 0){
        printf("Cordenada sobre o eixo X\n");
    }if(x.x > 0 && x.y > 0){
        printf("Coordenada no primeiro quadrante\n");
    }if(x.x < 0 && x.y > 0){
        printf("Coordenada no segundo quadrante\n");
    }if(x.x < 0 && x.y < 0){
        printf("Coordenada no terceiro quadrante\n");
    }if(x.x > 0 && x.y < 0){
        printf("Coordenada no quarto quadrante\n");
    }   
}

int main(){
    coordenada coordenadas[10];
    

    for(i=0;i<10;i++){
        preenche_cordenada(&coordenadas[i]);
    }
    printf("\n");
    for(i=0;i<10;i++){
       mostra_cordenada(coordenadas[i]);
    }

    return 0;
}