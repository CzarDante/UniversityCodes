#include <stdio.h>
#include <string.h>
typedef struct nome
{
    char nome[30];

}nome;

typedef struct funcionario
{
    long int matricula;
    float salario_bruto;
    int carga_horaria;

}funcionario;

void preenche_cadastro(funcionario * f){
    printf("\nDigite a matricula da pessoa: ");
    scanf("%ld",&f->matricula);
    printf("\nDigite o salario bruto: ");
    scanf("%f", &f->salario_bruto);
    printf("\nDigite a carga horaria: ");
    scanf("%d",&f->carga_horaria);
}
void mostra_cadastro(funcionario f){
    printf("\nNome: Jack \nMatricula: %ld\nSalario bruto: %0.2f\nCarga horaria: %d\n",f.matricula,f.salario_bruto,f.carga_horaria);
}

int main(){
    funcionario funcionarios[1];
    preenche_cadastro(&funcionarios[1]);
    mostra_cadastro(funcionarios[1]);
    
    return 0;
}