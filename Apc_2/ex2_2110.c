#include <stdio.h>
#include <string.h>

int main(){
    char nome[50];
    char sexo[20];
    int idade = 0;
    char fem[5]="fem";
    //printf("Digite o nome: ");
    fgets(nome,50,stdin);
   // printf("\nDigite o sexo(masc/fem): ");
    fgets(sexo,20,stdin);
    //printf("\nDigite a idade: ");
    scanf("%d", idade);
    printf("%s", sexo);

    
    if(strcmp(sexo,fem)){
        if(idade < 25){
            printf("%s ", nome);
            printf("ACEITA");
        }else{
            printf("NAO ACEITA");
        }    
    }else{
        printf("NAO ACEITA");
    }
    
    return 0;
}