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

void preenche_vet(sanduiche * sanduiches);

int main()
{
    int N;
    printf("Digite quantos sanduiches deseja alocar: ");
    scanf("%d", &N);
    sanduiche * sanduiches;
    sanduiches = (sanduiche*)calloc(N,sizeof(sanduiche));
    for(int i=0;i<N;i++)
    {
        printf("Sanduiche %d\n",i+1);
        preenche_vet(&sanduiches[i]);
    }
    int maior=0,posicao=0;
    printf("Sanduiches iniciados com a letra A:\n");
    for(int i=0;i<N;i++){
            if(sanduiches[i].nome[0]=='A'||sanduiches[i].nome[0]=='a'){
                printf("%s",sanduiches[i].nome);
            }
            if(sanduiches[i].avaliacao>maior){
                maior=sanduiches[i].avaliacao;
                posicao=i;
            }
            
            
    }
    printf("sanduiche melhor avaliado: %s",sanduiches[posicao].nome);
    return 0;
    printf("\n");
    return 0;
}

void preenche_vet(sanduiche * s)
{
    printf("\nDigite o nome do sanduiche: ");
    fflush(stdin);
    fgets(s->nome,30,stdin);
    s->nome[strlen(s->nome)-1] = '\0';
    printf("\ndigite o valor: ");
    scanf("%f",&s->valor);
    printf("\ndigite o peso: ");
    scanf("%f",&s->peso);
    printf("\nDigite a avaliacao: ");
    scanf("%f",&s->avaliacao); 
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