#include <stdio.h>
#include <string.h>

typedef struct pessoa
{
    char nome[50];
    char sexo[20];
    int idade;
}pessoa;

void preenche_pessoa (pessoa * p)
{
    printf("\nDigite o nome da pessoa: ");
    fgets(p->nome,30,stdin);
    p->nome[strlen(p->nome)-1] = '\0';
    printf("\nDigite o sexo da pessoa: ");
    fgets(p->sexo,30,stdin);
    p->sexo[strlen(p->sexo)-1] = '\0';
    printf("\nDigite a idade da pessoa: ");
    scanf("%d",&p->idade);
    
}
void mostrar_pessoa(pessoa p)
{
    if(p.sexo == "fem"){ 
        if(p.idade < 25){
            printf("%s ACEITA", p.nome);
        }else
        {
            printf("NAO ACEITA");
        }
    }else
    {
        printf("NAO ACEITA");
    }
}
    
    
int main(){
    
    pessoa pessoas[1];
    preenche_pessoa(&pessoas[1]);
    mostrar_pessoa(pessoas[1]);
    
    return 0;
}