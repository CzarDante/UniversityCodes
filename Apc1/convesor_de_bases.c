#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dec = 0, bin = 0, binario[50];
int i = 0, j;

int bin_to_dec(int bin)
{
    int total  = 0;
    int potenc = 1;

    while(bin > 0) {
        total += bin % 10 * potenc;
        bin    = bin / 10;
        potenc = potenc * 2;
    }

    return total;
}
void menu(void) {
    printf("\n===========================================================\n");
    printf("\nBEM-VINDO AO CONVERSOR DE BASES NUMERICAS\n\n");
    printf("QUAL OPERAÇaO DESEJA REALIZAR? \n\n");
    printf("[ 1 ] BINARIO     ->  DECIMAL\n");
    printf("[ 2 ] DECIMAL     ->  BINARIO\n");
    printf("[ 0 ] SAIR\n");
    printf("\n===========================================================\n");
}
void process_calc(int opt) {
    switch(opt) {        
        case 0 :
            printf("CALCULADORA ENCERRADA!\n");
            exit(0);
        case 1 : 
            printf("Binario: ");
            scanf("%d", &bin);
            dec = bin_to_dec(bin);
            printf("Bin: %d = Dec: %d\n", bin, dec);
            break;
        case 2 :
            printf("Decimal: ");
            scanf("%d", &dec);
            int aux = dec;        
            while(aux > 0){
                binario[i] = aux % 2;
                i++;
                aux = aux/2;
            }
            printf("Dec: %d = Bin: ", dec);
            for(j=i-1; j>=0; j--){
                printf("%d", binario[j]);
            }
            printf("\n");
            break;
        default :
            printf("OPÇÃO NÃO PERMITIDA!\nTENTE NOVAMENTE\n");
            break;
    }
    
}

int main(void)
{
    int opcao;
    menu();
    scanf("%d", &opcao);
    process_calc(opcao);
         
    return 0;
}