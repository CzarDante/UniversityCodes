#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	int f, d, r, g, maior, soma, dp, rp, gp, sobra;
	scanf("%d %d %d %d", &d, &r, &g, &f);
    if (d >= r && d >= g){
        maior = d;   
    }
    else if (r >= d && r >= g){
        maior = r;
    }
    else if (g >= d && g >= r){
        maior = g;  
    }
    dp = maior - d;
    rp = maior - r;
    gp = maior - g;
    soma = dp + rp + gp;
        if (f>soma){
            sobra = soma - f;
            if (sobra%3 == 0){
               printf("consegue\n");
            }else{
                printf("impossivel\n");
            }
        }else{
            printf("Impossivel\n");
            }
	return 0;
}