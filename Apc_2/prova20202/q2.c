#include <stdio.h>
#include <stdlib.h>
#define lin 30

const int TAM = 52;
int Pesq_Str ( char **str , char busca [ 30 ] ) {
    int i, j, k;
    printf ( "Digite uma string para pesquisar : " );
    scanf ( "%30[^\n]s" , busca );
    fflush ( stdin );
    for ( i = 0; i < lin ; i++ ) {
        for ( j = 0; j < TAM ; j++ ) {
            k = 0;
            while ( str [ i ] [ j + k ] == busca [ k ] && busca [ k ] != '\0' && str [ i ] [ j + k ] != '\0' ) {
                k++;
                if ( busca [ k ] == '\0' ) {
                    printf ( "A string %s foi achada",busca);
                }
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
    str = ( char** ) malloc ( TAM * sizeof(char*) );
    if ( arq != NULL ) {
        while ( feof ( arq ) == 0 ) {
            str [ i ] = ( char* ) malloc ( TAM * sizeof(char) );
            fgets ( str [ i ] , TAM , arq );
            i++;
        }
        n = Pesq_Str (str , busca );    
        fclose (arq);
    }else {
        printf ( "Não foi possível abrir o arquivo." );
    }
    return 0;
}
