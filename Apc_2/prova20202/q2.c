#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define linhas 30

int i, j, k;
const int caracters = 30;

int Pesq_Str ( char **str , char busca[30]){
    printf ( "Digite uma string para pesquisar : " );
    fflush(stdin);
    fgets(busca,30,stdin);
    busca[strlen(busca)-1] = '\0';
    for(i=0;i<linhas;i++){
        for (j=0;j<caracters;j++ ){
            k = 0;
            while ( str [ i ] [ j + k ] == busca [ k ] && busca [ k ] != '\0' && str [ i ] [ j + k ] != '\0' ) {
                k++;
                if ( busca [ k ] == '\0' ) {
                    printf ( "A string %s foi achada\n",busca);
                }
            }
            if(i == (linhas-1) && j == (caracters-1)){
                printf("A string nao foi achada ");
            }
        }
    }
    return 0;
}
int main ( ) {
    FILE *arq;
    char **str;
    char busca [ 30 ] = { '\0' };
    unsigned int i = 0, n;
    char nomearquivo[30];
    printf("nome do arquivo: \n");
    gets(nomearquivo);
    arq = fopen(nomearquivo, "r");
    str = ( char** ) malloc ( caracters * sizeof(char*) );
    if ( arq != NULL ) {
        while ( feof ( arq ) == 0 ) {
            str [ i ] = ( char* ) malloc ( caracters * sizeof(char) );
            fgets ( str [ i ] , caracters , arq );
            i++;
        }
        n = Pesq_Str (str , busca );    
        fclose (arq);
    }else {
        printf ( "Não foi possível abrir o arquivo." );
    }
    return 0;
}
