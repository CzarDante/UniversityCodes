#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp; 
    int count = 0;
    char nomearquivo[30]; 
    char c;
    printf("Nome do arquivo: "); 
    scanf("%s", nomearquivo); 
    fp = fopen(nomearquivo, "r"); 
    if (fp == NULL) 
    { 
        printf("\n Problemas na abertura do arquivo"); 
        return 0; 
    } 

    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n')
            count = count + 1;  
    fclose(fp); 
    printf("Oarquivo %s tem %d linhas\n ", nomearquivo, count+1); 
  
    return 0; 
}