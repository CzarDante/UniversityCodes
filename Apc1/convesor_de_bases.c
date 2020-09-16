#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dec = 0, bin = 0, binario[50], hexa = 0, oct = 0;
int i = 0, j;
int divisor = 1;
int res[7];

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
    printf("[ 1 ] BINARIO     ->  \n");
    printf("[ 2 ] DECIMAL     ->  \n");
    printf("[ 3 ] HEXADECIMAL ->  DECIMAL\n");
    printf("[ 4 ] HEXADECIMAL ->  OCTAL\n");
    /*printf("[ 9 ] DECIMAL     ->  BASE 3\n");
    printf("[ 10 ] ->  ");
    printf("[ 11 ] -> ");
    printf("[ 12 ] ");
    printf("[ 13 ] ");
*/
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

            printf("Base3: ");
            for(int tri=0; tri < 10; tri++){
                if((dec / divisor) % 3 == 0){
                    res[tri] = 0;
                }else{
                    res[tri] = (dec / divisor) % 3;
                }
                divisor = divisor * 3;             
            }
            for(int tri = 9; tri >= 0; tri--){
                printf("%d", res[tri]);
            }          
            printf("\n");
            printf("Octal: %o\n", dec);
            printf("Dec: %d\n", dec);
            printf("Hexadecimal: %X\n", dec);
            printf("ASCI: %c\n", dec);
            break;
        case 2:
            printf("Decimal: ");
            scanf("%d", &dec);
            int aux = dec;        
            while(aux > 0){
                binario[i] = aux % 2;
                i++;
                aux = aux/2;
            }
            printf("Bin: ");
            for(j=i-1; j>=0; j--){
                printf("%d", binario[j]);
            }
            printf("\n");
            printf("Base3: ");
            for(int tri=0; tri < 10; tri++){
                if((dec / divisor) % 3 == 0){
                    res[tri] = 0;
                }else{
                    res[tri] = (dec / divisor) % 3;
                }
                divisor = divisor * 3;             
            }
            for(int tri = 9; tri >= 0; tri--){
                printf("%d", res[tri]);
            }          
            printf("\n");
            printf("Octal: %o\n", dec);
            printf("Dec: %d\n", dec);
            printf("Hexadecimal: %X\n", dec);
            printf("ASCI: %c\n", dec);
            break;
        case 3:
            printf("Hexadecimal: ");
            scanf("%X", &hexa);
            printf("Decimal: %d", hexa);
            break;
        case 4:
            printf("Hexadecimal: ");
            scanf("%X", &hexa);
            printf("Octal: %o", hexa);
            break;
        /*case 5:
            printf("decimal: ");
            scanf("%d", &dec);
            
            break;*/                                         
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