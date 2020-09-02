#include <stdio.h>

int prod1(int inicio, int final){
    float funcao = 0, produtorio = 1;
    for(float i = inicio; i<=final; i++){
        funcao = (-1*(((i*i)-4)/(i+3)));   
        produtorio = produtorio * funcao;
    }
    return produtorio;
}
int main(int argc, char const *argv[]){
    int M, N;
    scanf("%d %d", &M, &N);
    int inicio = M, final = N;
    float produtorio = prod1(inicio, final), funcao;
    printf("%0.1f\n", produtorio);
    return 0;
}