#include <stdio.h>

int pow2(int base, int expoente){  
    if(expoente == 0){
        return 1;
    }else{
    return base * pow2(base, expoente-1);
    }
}
int main(int argc, char const *argv[]){
    int N, B;
    scanf("%d", &B); 
    scanf("%d", &N);        
    int base = B, expoente = N,  potencia = pow2(base, expoente);
    printf("%d\n", potencia);
    return 0;
}