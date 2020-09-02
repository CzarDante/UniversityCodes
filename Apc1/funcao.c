#include <stdio.h>

int pow2(int base, int expoente){ 
    int potencia = 1;    
    for(int i = 0; i < expoente; i++){
        potencia *= base;
    }
    return potencia;
}
int main(int argc, char const *argv[]){
    int N, B;
    scanf("%d", &B); 
    scanf("%d", &N);        
    int base = B, expoente = N,  potencia = pow2(base, expoente);
    printf("%d\n", potencia);
    return 0;
}