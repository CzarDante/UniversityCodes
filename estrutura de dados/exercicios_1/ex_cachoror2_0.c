/*Faça um programa que receba do usuário um número N inteiro positivo e aloque um vetor de cachorros.
Cada cachorro posssui: Nome, Idade, raça, cor, peso e altura.
Solicite ao usuário que preencha os dados dos N cachorros e mostre na tela:
A) Quais cachorros tem o nome iniciado pela letra M.
B) Qual o peso médio dos cachorros
C) Qual é o cachorro mais alto
D) Qual o cachorro mais velho.
E) Quantos cachorros são maiores do que 30 cm.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cachorro
{
    char nome[30];
    char raca[30];
    char cor[30];
    int idade;
    double peso;
    double altura;
}cachorro;

void preenche_vet(cachorro * c);

int main()
{
    int N;
    printf("Digite quantos cachorros deseja alocar: ");
    scanf("%d", &N);
    cachorro * cachorros;
    int opcao;
    double media=0;
    int maisq=0,maior=0,velho=0;
    cachorros = (cachorro*)calloc(N,sizeof(cachorro));
    for(int i=0;i<N;i++)
    {
        preenche_vet(&cachorros[i]);
    }
    printf("Cachorros iniciados com A letra M: \n");
    for(int i=0;i<N;i++){
        //Nome começa com M
        if(cachorros[i].nome[0]=='M' || cachorros[i].nome[0]=='m'){
            printf("%s\n",cachorros[i].nome);
        }
        //Peso medio
        media+=cachorros[i].peso;
        //Cachorro mais alto
        if(cachorros[i].altura>cachorros[maior].altura){
            maior=i;
        }
        //Mais velho
        if(cachorros[i].idade>cachorros[velho].idade){
            velho=i;
        }
        //Quantos sao maiores que 30cm.
        if(cachorros[i].altura>30){
            maisq++;
        }  
    }
    printf("\nA media de peso e %.2lf",media/N);
    printf("\nO cachorro mais alto e o %s",cachorros[maior].nome);
    printf("\nO cachorro mais velho e o %s",cachorros[velho].nome);
    printf("\n%d cachorros sao maiores que 30cm", maisq);
    return 0;
    printf("\n");
    return 0;
}
void preenche_vet(cachorro * c)
{
    printf("\nDigite o nome do cachorro: ");
    fflush(stdin);
    fgets(c->nome,30,stdin);
    c->nome[strlen(c->nome)-1] = '\0';
    printf("\nDigite a idade: ");
    scanf("%d",&c->idade);
    printf("\ndigite a raca :");
    fflush(stdin);
    fgets(c->raca,20,stdin);
    c->raca[strlen(c->raca)-1] = '\0';
    printf("\ndigite a cor: ");
    fflush(stdin);
    fgets(c->cor,20,stdin);
    c->cor[strlen(c->cor)-1] = '\0';
    printf("\ndigite o peso: ");
    scanf("%lf",&c->peso);
    printf("\nDigite a altura: ");
    scanf("%lf",&c->altura); 
}