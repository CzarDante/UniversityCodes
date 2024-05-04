/**
 O codigo é executado da esquerda para a direita porem verificando se o operador é uma função
 caso seja ele é executado com prioridade, assim, caso a funcao esteja entre dois outros operadores
 ele é executado primeiro, alterando o valor dos dois outros operadores.
 O efeito colateral é justamente a funcao executar primeiro.
 
 Executar com o compilador Language: C
 **/

#include <stdio.h>

int sub1(int *x, int *y)
{
    *x = *x + 1;
    *y = *y + 2;
    int result = *x + *y;
    return result;
}

int main()
{
    int x = 2, y = 4;
    int z;

    z = x + y + sub1(&x, &y); //2 + 4 + 9 = 15
    printf("%d\n",z);
    //verificando
    x = 2, y = 4;
    z = sub1(&x, &y) + x -y; // (3+6) + 3 - 6= 6
    printf("%d\n",z);
    
    x = 2, y = 4;
    z = x + sub1(&x, &y)-y; // 3 + (3+6) - 6= 6
    printf("%d\n",z);
    
    
    return 0;
}