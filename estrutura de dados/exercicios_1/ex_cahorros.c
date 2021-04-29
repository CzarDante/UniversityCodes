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
    float peso;
    float altura;
}cachorro;

void Opcoes()
{
    printf("\n 1 - Incluir Cachorro ");
    printf("\n 2 - Encontrar cachorros Com nome iniciado em M");
    printf("\n 3 - Calcula peso medio dos cachorros");
    printf("\n 4 - Encontra cachorro mais alto");
    printf("\n 5 - Encontrar cachorro mais velho");
    printf("\n 6 - Conta quantos cachorros sao maiores do que 30cm");
    printf("\n 7 - sair\n");
    //9 - Mostra todos os cachorros;   
}

void preenche_vet(cachorro * c, int qtdC);
void acha_alto(cachorro * cachorros, int qtdCachorros);
void acha_vei(cachorro * cachorros, int qtdCachorros);
void acha_maiorq(cachorro * cachorros,int qtdCachorros);
void encontraM(cachorro *cachorros, int qtdCachorros);
void media_peso(cachorro *cachorros, int qtdCachorros);

int main()
{
    int N;
    printf("Digite quantos cachorros deseja alocar: ");
    scanf("%d", &N);
    cachorro cachorros[N];
    int opcao, qtdCachorros = 0;
    do
    {
        Opcoes();
        scanf("%d", &opcao); 
        if (opcao == 1)
        {
            preenche_vet(cachorros,qtdCachorros);
            qtdCachorros++;  
        }
        if (opcao == 2)
        {
            encontraM(cachorros,qtdCachorros);
        }
        if (opcao == 3)
        {
            media_peso(cachorros,qtdCachorros);
        }
        if (opcao == 4)
        {
            acha_alto(cachorros,qtdCachorros);
        }
        if (opcao == 5)
        {
            acha_vei(cachorros,qtdCachorros);
        }
        if(opcao==6)
        {
            acha_maiorq(cachorros,qtdCachorros);
        }
        if(opcao==9)
        {
            for(int i=0;i<qtdCachorros;i++){
                mostrar_cachorros(cachorros,qtdCachorros,i);
            }
        }
    } while (opcao != 7);
    return 0;

    printf("\n");
    return 0;
}

void preenche_vet(cachorro * c, int qtdC)
{
    printf("\nDigite o nome do cachorro: ");
    fflush(stdin);
    fgets(c[qtdC].nome,30,stdin);
    c[qtdC].nome[strlen(c[qtdC].nome)-1] = '\0';
    printf("\nDigite a idade: ");
    scanf("%d",&c[qtdC].idade);
    printf("\ndigite a raca :");
    fflush(stdin);
    fgets(c[qtdC].raca,20,stdin);
    c[qtdC].raca[strlen(c[qtdC].raca)-1] = '\0';
    printf("\ndigite a cor: ");
    fflush(stdin);
    fgets(c[qtdC].cor,20,stdin);
    c[qtdC].cor[strlen(c[qtdC].cor)-1] = '\0';
    printf("\ndigite o peso: ");
    scanf("%f",&c[qtdC].peso);
    printf("\nDigite a altura: ");
    scanf("%f",&c[qtdC].altura); 
}

void mostrar_cachorros(cachorro * cachorros, int qtdCachorros, int z)
{
    if(qtdCachorros==0){
        printf("Nao a cachorros\n");
    }
    else{
        printf("\nNome: ");   
        printf("%s",cachorros[z].nome);
        printf("\nIdade: ");
        printf("%d",cachorros[z].idade);
        printf("\nraca: ");
        printf("%s",cachorros[z].raca);
        printf("\nCor: ");
        printf("%s",cachorros[z].cor);
        printf("\nPeso: ");
        printf("%.2f",cachorros[z].peso);
        printf("\nAltura: ");
        printf("%.2f",cachorros[z].altura);
        printf("\n");
    }  
}

void acha_vei(cachorro * cachorros, int qtdCachorros)
{
    int maior=0;
    int posicao=0;
    if(qtdCachorros==0){
        printf("nao ha cachorros\n");
    }
    else{    
        for(int i=0;i<qtdCachorros;i++){
            if(cachorros[i].idade>maior){
                maior=cachorros[i].idade;
                posicao=i;
            }
        }
        mostrar_cachorros(cachorros,qtdCachorros,posicao);
    }
}
void acha_alto(cachorro * cachorros, int qtdCachorros)
{
    int maior=0;
    int posicao=0;
    if(qtdCachorros==0){
        printf("nao ha cachorros\n");
    }
    else{    
        for(int i=0;i<qtdCachorros;i++){
            if(cachorros[i].altura>maior){
                maior=cachorros[i].altura;
                posicao=i;
            }
        }
        mostrar_cachorros(cachorros,qtdCachorros,posicao);
    }
}
void acha_maiorq(cachorro * cachorros,int qtdCachorros)
{
    for(int z=0;z<qtdCachorros;z++){
        if(cachorros[z].altura>30){
            mostrar_cachorros(cachorros,qtdCachorros,z);
        }
    }
}
void encontraM(cachorro *cachorros, int qtdCachorros)
{
    char M[1]="M";
    if(qtdCachorros==0){
        printf("nao ha cachorros\n");
    }
    else{    
        for(int i=0;i<qtdCachorros;i++){
            if(cachorros[i].nome[0]==M[0]){
                mostrar_cachorros(cachorros,qtdCachorros,i);
            }
        }   
    }
}
void media_peso(cachorro *cachorros, int qtdCachorros){
    float media=0;
    if(qtdCachorros==0){
        printf("nao ha cachorros\n");
    }
    else{
        for(int i=0;i<qtdCachorros;i++){
            media+=cachorros[i].peso;
            if(i==(qtdCachorros-1)){
                printf("\nA media de peso é: %0.2f",media/qtdCachorros);
            }
        }
    }

}