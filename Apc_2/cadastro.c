#include <stdio.h>


typedef struct cadastro
{
    char nome[30];
    int matricula, idade;
    float peso, altura;

}cadastro;

void preenche_cadastro(cadastro * p){
    printf("\nDigite o nome da pesso: ");
    printf("\nDigite a matricula da pessoa: ");
    scanf("%d",&p->matricula);
    printf("\nDigite a idade da pessoa: ");
    scanf("%d", &p->idade);
    printf("\nDigite o peso da pessoa: ");
    scanf("%f",&p->peso);
    printf("\nDigite a altura da pessoa: ");
    scanf("%f",&p->altura);
}
void mostra_cadastro(cadastro p){
    printf("\nNome:  Matricula: %d\nIdade: %d\nPeso: %f Altura %f",p.matricula,p.idade,p.peso,p.altura);
}

int main(){
    cadastro x;
    //cadastro * y;//

    scanf("%f",&x.n1);    
    scanf("%f",&x.n2);
    x.media = media(x.n1, x.n2);
    printf("\n %.2f", x.media);
    return 0;
}
