#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//cria a matriz
void cria_matriz(char matriz[100][100]){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            matriz[i][j] = ' ';
        }
    }
}
//preenche a matriz
void preenche_matriz(char matriz[100][100], int num_elementos, char elemento){
    int coordenada_x,coordenada_y,mais = 0;
    for(int i = 0; i < num_elementos+mais; i++){
        coordenada_x = rand()%100;
        coordenada_y = rand()%100;
        if(matriz[coordenada_x][coordenada_y] == elemento){
            mais += 1;
        }
        matriz[coordenada_x][coordenada_y] = elemento;
    }
}
//troca elemento 1 por elemento 2
void altera_matriz(char matriz[100][100], int num_elementos, char elemento1, char elemento2){
    int coordenada_x,coordenada_y;
    for(int i = 0; i < num_elementos; i++){
        coordenada_x = rand()%100;
        coordenada_y = rand()%100;
        if(matriz[coordenada_x][coordenada_y] == elemento1){
            matriz[coordenada_x][coordenada_y] = elemento2;
        }else{
            num_elementos +=1;
        }
    }
}
//imprime a matriz
void printa_matriz(char matriz[100][100]){
    system("clear");
    for(int a = 0; a < 100; a++){
        for(int b = 0; b < 100; b++){
            if(matriz[a][b] == 'X'){
                printf("\033[0;33m");
            }
            printf("%c ", matriz[a][b]);
            printf("\033[0m");
        }
        printf("\n");
    }
}
//remonta a matriz(troca P por O)
void remonta_matriz(char matriz[100][100],char pessoa){
    for(int a = 0; a < 100; a++){
        for(int b = 0; b < 100; b++){
            if(matriz[a][b] == 'P'){
                matriz[a][b] = pessoa;
            }
        }
    }
}
//movimenta elementos da matriz
void andar(char matriz[100][100], char pessoa, int isolamento){
    if(rand()%2 == 0){
        for(int i = 0; i < 100; i++){
            if(rand()%2 == 0){
                for(int j = 0; j < 100; j++){
                    int flag = 0;
                    int aux = 0, cont = 0, aux2 = 0;
                    aux = rand()%4;
                    while(flag == 0 && cont < 4){
                        aux2 = (rand()%4) + 1;
                        if(matriz[i][j] == pessoa && (rand()%100) >= isolamento){
                            if(i+1 < 100 && i+1 >= 0 && aux == 0 && matriz[i+1][j] == ' '){
                                matriz[i+1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(i-1 >= 0 && i-1 < 100 && aux == 1 && matriz[i-1][j] == ' '){
                                matriz[i-1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j+1 < 100 && j+1 >= 0 && aux == 2 && matriz[i][j+1] == ' '){
                                matriz[i][j+1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j-1 >= 0 && j-1 < 100 && aux == 3 && matriz[i][j-1] == ' '){
                                matriz[i][j-1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }
                            aux += aux2;
                            cont ++;
                            if(aux == 4){
                                aux = 0;
                            }else if(aux == 5){
                                aux = 1;
                            }else if(aux == 6){
                                aux = 2;
                            }else if(aux == 7){
                                aux = 3;
                            }
                        }else{
                            flag = 1;
                        }
                    }
                }
            }else{
                for(int j = 99; j >= 0; j--){
                    int flag = 0;
                    int aux = 0, cont = 0, aux2 = 0;
                    aux = rand()%4;
                    while(flag == 0 && cont < 4){
                        aux2 = (rand()%4) + 1;
                        if(matriz[i][j] == pessoa && (rand()%100) >= isolamento){
                            if(i+1 < 100 && i+1 >= 0 && aux == 0 && matriz[i+1][j] == ' '){
                                matriz[i+1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(i-1 >= 0 && i-1 < 100 && aux == 1 && matriz[i-1][j] == ' '){
                                matriz[i-1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j+1 < 100 && j+1 >= 0 && aux == 2 && matriz[i][j+1] == ' '){
                                matriz[i][j+1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j-1 >= 0 && j-1 < 100 && aux == 3 && matriz[i][j-1] == ' '){
                                matriz[i][j-1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }
                            aux += aux2;
                            cont ++;
                            if(aux == 4){
                                aux = 0;
                            }else if(aux == 5){
                                aux = 1;
                            }else if(aux == 6){
                                aux = 2;
                            }else if(aux == 7){
                                aux = 3;
                            }
                        }else{
                            flag = 1;
                        }
                    }
                }
            }
        }
    }else{
        for(int i = 99; i > 0; i--){
            if(rand()%2 == 0){
                for(int j = 0; j < 100; j++){
                    int flag = 0;
                    int aux = 0, cont = 0, aux2 = 0;
                    aux = rand()%4;
                    while(flag == 0 && cont < 4){
                        aux2 = (rand()%4) + 1;
                        if(matriz[i][j] == pessoa && (rand()%100) >= isolamento){
                            if(i+1 < 100 && i+1 >= 0 && aux == 0 && matriz[i+1][j] == ' '){
                                matriz[i+1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(i-1 >= 0 && i-1 < 100 && aux == 1 && matriz[i-1][j] == ' '){
                                matriz[i-1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j+1 < 100 && j+1 >= 0 && aux == 2 && matriz[i][j+1] == ' '){
                                matriz[i][j+1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j-1 >= 0 && j-1 < 100 && aux == 3 && matriz[i][j-1] == ' '){
                                matriz[i][j-1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }
                            aux += aux2;
                            cont ++;
                            if(aux == 4){
                                aux = 0;
                            }else if(aux == 5){
                                aux = 1;
                            }else if(aux == 6){
                                aux = 2;
                            }else if(aux == 7){
                                aux = 3;
                            }
                        }else{
                            flag = 1;
                        }
                    }
                }
            }else{
                for(int j = 99; j >= 0; j--){
                    int flag = 0;
                    int aux = 0, cont = 0, aux2 = 0;
                    aux = rand()%4;
                    while(flag == 0 && cont < 4){
                        aux2 = (rand()%4) + 1;
                        if(matriz[i][j] == pessoa && (rand()%100) >= isolamento){
                            if(i+1 < 100 && i+1 >= 0 && aux == 0 && matriz[i+1][j] == ' '){
                                matriz[i+1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(i-1 >= 0 && i-1 < 100 && aux == 1 && matriz[i-1][j] == ' '){
                                matriz[i-1][j] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j+1 < 100 && j+1 >= 0 && aux == 2 && matriz[i][j+1] == ' '){
                                matriz[i][j+1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }else if(j-1 >= 0 && j-1 < 100 && aux == 3 && matriz[i][j-1] == ' '){
                                matriz[i][j-1] = 'P';
                                matriz[i][j] = ' ';
                                flag = 1;
                            }
                            aux += aux2;
                            cont ++;
                            if(aux == 4){
                                aux = 0;
                            }else if(aux == 5){
                                aux = 1;
                            }else if(aux == 6){
                                aux = 2;
                            }else if(aux == 7){
                                aux = 3;
                            }
                        }else{
                            flag = 1;
                        }
                    }
                }
            }
        }
    }
    remonta_matriz(matriz,pessoa);
}
//conta os saudaveis e infectados
void contagem(char matriz[100][100]){
    int saudaveis = 0,infectados = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(matriz[i][j] == 'O'){
                saudaveis ++;
            }else if(matriz[i][j] == 'X'){
                infectados ++;
            }
        }
    }
    printf("saudaveis = %d\ninfectados = %d\n", saudaveis, infectados);
}
int main(int argc, char const *argv[]){
    srand(time(0));
    char matriz[100][100];
    int casos = 0;

    //cria a matriz
    cria_matriz(matriz);

    //pra gerar as coordenadas aleatorias
    preenche_matriz(matriz,5000,'O');

    //pessoas contaminadas
    altera_matriz(matriz,5,'O','X');

    //andar
    for(int tempo = 0; tempo < 1800; tempo += 2){
        andar(matriz,'O',0);
        andar(matriz,'X',0);
        printa_matriz(matriz);
        sleep(2);
    }
    //printa matriz
    printa_matriz(matriz);

    //numero de saudaveis e contaminados
    contagem(matriz);
    return 0;
}