#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
    int matriz[100][100];
    int vetor_checa_x[4] = {0,0,1,-1};
    int vetor_checa_y[4] = {1,-1,0,0};
    int coordenada_x,coordenada_y,saudaveis = 0,infectados = 0,mais = 0;
    int casos = 0;

    //cria a matriz
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            matriz[i][j] = ' ';
        }
    }

    //pra gerar as coordenadas aleatorias
    srand(time(0));
    for(int i = 0; i < 5000+mais; i++){
        coordenada_x = rand()%100;
        coordenada_y = rand()%100;
        if(matriz[coordenada_x][coordenada_y] == 'O'){
            mais += 1;
        }
        matriz[coordenada_x][coordenada_y] = 'O';
    }

    //pessoas contaminadas
    srand(time(0));
    for(int i = 0; i < 5; i++){
        coordenada_x = rand()%100;
        coordenada_y = rand()%100;
        if(matriz[coordenada_x][coordenada_y] == 'O'){
            matriz[coordenada_x][coordenada_y] = 'X';
        }
    }

    //printa a matriz
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(matriz[i][j] == 'O'){
                saudaveis +=1;
            }
            if(matriz[i][j] == 'X'){
                infectados +=1;
            }
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    //andar
    for(int i  = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            int aux = 0;
            while(aux == 0){
                if(matriz[i][j] == 'O'){
                    int direcao;
                    srand(time(0));
                    direcao = rand()%4;
                    if(matriz[i-1][j] == ' ' && direcao == 1){
                        aux = 1;
                    }
                    if(matriz[i+1][j] == ' ' && direcao == 2){
                        aux = 1;
                    }
                    if(matriz[i][j-1] == ' ' && direcao == 3){
                        aux = 1;
                    }
                    if(matriz[i][j+1] == ' ' && direcao == 4){
                        aux = 1;
                    }
                }
            }
        }
    }

    printf("saudaveis = %d\ninfectados = %d\n", saudaveis, infectados);

    return 0;
}