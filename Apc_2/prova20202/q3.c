#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
}data;

typedef struct carro
{
    int ano;
    char modelo[30];
    char marca[30];
    data * revisoes;
    int qtd_revisoes;
}carro;

void preenche_cadastro(carro * f);
void AdicionaCarro(carro * carros, carro f, int qtd_carros);
void ProcuraCarro(carro * carros, int qtd_carros, int revisoes_procurada);

int main(){

    int N;
    int qtd_carros=0;

    printf("quantos carros? ");
    scanf("%d", &N);
    printf("\n");
    carro carros[N];
    carro f;
    for(int i=0;i<N;i++){
        preenche_cadastro(&f);
        AdicionaCarro(carros, f, qtd_carros);
        qtd_carros++;
    }
    int revisoes_procurada;
    printf("Procurar carros com quantas revisoes :");
    scanf("%d", &revisoes_procurada);
    ProcuraCarro(carros, qtd_carros, revisoes_procurada);
    printf("\n");
    return 0;
}

void preenche_cadastro(carro * f){
    printf("\nDigite o ano: ");
    scanf("%d",&f->ano);
    printf("\nDigite o modelo: ");
    fflush(stdin);
    fgets(f->modelo,30,stdin);
    f->modelo[strlen(f->modelo)-1] = '\0';
    printf("\nDigite a marca: ");
    fflush(stdin);
    fgets(f->marca,30,stdin);
    f->marca[strlen(f->marca)-1] = '\0'; 
    printf("\nDigite a quantidade de revisoes: ");
    scanf("%d",&f->qtd_revisoes);
    for(int i=0;i<f->qtd_revisoes;i++){
        printf("\nData da revisao %d \n", i+1);
        printf("Ano :");
        scanf("%d",&f->revisoes->ano);
        printf("\nMes :");
        scanf("%d",&f->revisoes->mes);
        printf("\nDia :");
        scanf("%d",&f->revisoes->dia);
    }
}

void AdicionaCarro(carro * carros, carro f, int qtd_carros)
{
    carros[qtd_carros] = f;
}

void ProcuraCarro(carro * carros, int qtd_carros, int revisoes_procurada){
    int i;

    if (qtd_carros == 0)
    {
        printf("\n Lista vazia\n");
        return 0;
    }
    else
    {
        for (i = 0; i < qtd_carros; i++)
        {
            if (carros[i].qtd_revisoes == revisoes_procurada)
            {
                printf("Carro numero %d ", i);
                printf("\n");
                printf("Ano :%d", carros[i].ano);
                printf("\n");
                printf("Modelo :%s", carros[i].modelo);
                printf("\n");
                printf("Marca :%s", carros[i].marca);
                printf("\n");                
            }
        }    
    }
}

