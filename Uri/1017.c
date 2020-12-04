#include <stdio.h>

int main()
{
    float tempo, velocidade;
    float combustivel;
    scanf("%f",&tempo);
    scanf("%f",&velocidade);
    combustivel = (velocidade*tempo);
    printf("%.3f",combustivel/12);
    return 0;
}