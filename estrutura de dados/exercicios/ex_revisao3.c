/*Faça um programa que receba do usuario um número N inteiro positivo, e aloque dinamicamente um vetor de N sanduíches.
Cada sanduíche deve armazenara as segunites informações:
    nome
    valor
    peso
    avaliacao
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sanduiche
{
    char nome[15];
    float valor;
    float peso;
    float avaliacao;
}sanduiche;

void preenche_vet(sanduiche * sanduiches, int qtdSanduiches);
void acha_maiorAv(sanduiche * sanduiches, int qtdSanduiches);
void encontraA(sanduiche *sanduiches, int qtdSanduiches);
void media_peso(sanduiche *sanduiches, int qtdSanduiches);
void compra_tres(sanduiche *sanduiches, int qtdSanduiches);

int main()
{
    int N;
    printf("Digite quantos sanduiches deseja alocar: ");
    scanf("%d", &N);
    sanduiche sanduiches[N];
    int qtdSanduiches = 0;
    for(int i=0;i<N;i++)
    {
        printf("Sanduiche %d\n",i+1);
        preenche_vet(sanduiches,qtdSanduiches);
        qtdSanduiches++;
    }
    acha_maiorAv(sanduiches,qtdSanduiches);
    encontraA(sanduiches,qtdSanduiches);
    media_peso(sanduiches,qtdSanduiches);
    compra_tres(sanduiches, qtdSanduiches);
    return 0;
    printf("\n");
    return 0;
}

void preenche_vet(sanduiche * s, int qtdS)
{
    printf("\nDigite o nome do sanduiche: ");
    fflush(stdin);
    fgets(s[qtdS].nome,30,stdin);
    s[qtdS].nome[strlen(s[qtdS].nome)-1] = '\0';
    printf("\ndigite o valor: ");
    scanf("%f",&s[qtdS].valor);
    printf("\ndigite o peso: ");
    scanf("%f",&s[qtdS].peso);
    printf("\nDigite a avaliacao: ");
    scanf("%f",&s[qtdS].avaliacao); 
}
void mostrar_sanduiches(sanduiche * sanduiches, int qtdSanduiches, int z)
{
    if(qtdSanduiches==0){
        printf("Nao a sanduiches\n");
    }
    else{
        printf("\nNome: ");   
        printf("%s",sanduiches[z].nome);
        printf("\nValor: ");
        printf("%.2f",sanduiches[z].valor);
        printf("\nPeso: ");
        printf("%.2f",sanduiches[z].peso);
        printf("\nAvaliacao: ");
        printf("%.2f",sanduiches[z].avaliacao);
        printf("\n");
    }  
}
void acha_maiorAv(sanduiche * sanduiches, int qtdSanduiches)
{
    int maior=0;
    int posicao=0;
    if(qtdSanduiches==0){
        printf("nao ha sanduiches\n");
    }
    else{    
        for(int i=0;i<qtdSanduiches;i++){
            if(sanduiches[i].avaliacao>maior){
                maior=sanduiches[i].avaliacao;
                posicao=i;
            }
        }
        printf("\nSanduiche melhor avaliado: ");
        mostrar_sanduiches(sanduiches,qtdSanduiches,posicao);
    }
}
void encontraA(sanduiche *sanduiches, int qtdSanduiches)
{
    char A[1]="A";
    if(qtdSanduiches==0){
        printf("nao ha sanduiches\n");
    }
    else{    
        printf("\nSanduiche comecado em A: ");
        for(int i=0;i<qtdSanduiches;i++){
            if(sanduiches[i].nome[0]==A[0]){
                mostrar_sanduiches(sanduiches,qtdSanduiches,i);
            }
        }   
    }
}
void media_peso(sanduiche *sanduiches, int qtdSanduiches){
    float media=0;
    if(qtdSanduiches==0){
        printf("nao ha sanduiches\n");
    }
    else{
        for(int i=0;i<qtdSanduiches;i++){
            media+=sanduiches[i].peso;
            if(i==(qtdSanduiches-1)){
                printf("\nA media de peso e: %0.2f",media/qtdSanduiches);
            }
        }
    }

}
void compra_tres(sanduiche *sanduiches, int qtdSanduiches)
{
    float preco=0;
    if(qtdSanduiches==0){
        printf("nao ha sanduiches\n");
    }
    else{
        for(int i=0;i<qtdSanduiches;i++){
            preco+=sanduiches[i].valor*3;
            if(i==(qtdSanduiches-1)){
                printf("\nNo caso da compra de 3 de cada: %0.2f",preco);
            }
        }
    }
}