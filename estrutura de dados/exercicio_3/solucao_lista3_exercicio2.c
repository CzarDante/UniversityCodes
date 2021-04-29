#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro
{
    char marca[30];
    char modelo[30];
    char chassi[30];
    int ano;
    float preco;
}carro;

void Opcoes()
{
    printf("\n 1 - Incluir Carro ");
    printf("\n 2 - Procura carro");
    printf("\n 3 - Remove carro pelo chassi");
    printf("\n 4 - Mostra carro mais velho");
    printf("\n 5 - Mostra carro mais caro");
    printf("\n 6 - sair\n");
    //9 - Mostra todos os carros;   
}

void OpcaoEncontra()
{
    printf("\n1 - Encontra por Chassi ");
    printf("\n2 - Encontra por marca ");
    printf("\n3 - Encontra por modelo ");
    printf("\n4 - Voltar \n");
}
void preenche_carros(carro * c, int qtdC);
void encontraC(carro *c,int qtdC);
void mostra_carros(carro *c, int qtdC, int z);
void remove_chassi(carro *c,int qtdC);
void acha_antigo(carro *c, int qtdC);
void acha_caro(carro *c, int qtdC);

int main()
{
    carro *carros;
    int opcao, qtdCarros = 0;
    carros = (carro*)calloc(1,sizeof(carro));
    do
    {
        Opcoes();
        scanf("%d", &opcao); 
        if (opcao == 1)
        {
            preenche_carros(carros,qtdCarros);
            qtdCarros++;  
        }
        if (opcao == 2)
        {
            encontraC(carros,qtdCarros);
        }
        if (opcao == 3)
        {
            remove_chassi(carros,qtdCarros);
            qtdCarros--;
        }
        if (opcao == 4)
        {
            acha_antigo(carros,qtdCarros);
        }
        if (opcao == 5)
        {
            acha_caro(carros,qtdCarros);
        }
        if(opcao==9)
        {
            for(int i=0;i<qtdCarros;i++){
                mostra_carros(carros,qtdCarros,i);
            }
        }
    } while (opcao != 6);

}

void preenche_carros(carro * c, int qtdC)
{
    printf("\nDigite a marca: ");
    fflush(stdin);
    fgets(c[qtdC].marca,30,stdin);
    c[qtdC].marca[strlen(c[qtdC].marca)-1] = '\0';

    printf("\nDigite o modelo: ");
    fflush(stdin);
    fgets(c[qtdC].modelo,30,stdin);
    c[qtdC].modelo[strlen(c[qtdC].modelo)-1] = '\0';

    printf("\ndigite o chassi :");
    fflush(stdin);
    fgets(c[qtdC].chassi,20,stdin);
    c[qtdC].chassi[strlen(c[qtdC].chassi)-1] = '\0';

    printf("\ndigite o ano: ");
    scanf("%d",&c[qtdC].ano);

    printf("\ndigite o preco: ");
    scanf("%f",&c[qtdC].preco); 
}

void encontraC(carro *c,int qtdC)
{
    if(qtdC==0){
        printf("nao ha carros\n");
    }
    int opcao=0;
    char chassi1[30],modelo1[30],marca1[30];
    do
    {
        OpcaoEncontra();
        scanf("%d", &opcao); 
        if (opcao == 1)
        {
            printf("\nQual o chassi:");
            fflush(stdin);
            fgets(chassi1,30,stdin);
            chassi1[strlen(chassi1)-1] = '\0';
            for(int i=0;i<qtdC;i++){
                if((strcmp(c[i].chassi,chassi1))==0){
                    mostra_carros(c,qtdC,i);
                }
            } 
        }
        if (opcao == 2)
        {
            printf("\nQual a marca:");
            fflush(stdin);
            fgets(marca1,30,stdin);
            marca1[strlen(marca1)-1] = '\0';   
            for(int i=0;i<qtdC;i++){
                if((strcmp(c[i].marca,marca1))==0){
                    mostra_carros(c,qtdC,i);
                }
            } 
        }
        if (opcao == 3)
        {
            printf("\nQual o modelo:");
            fflush(stdin);
            fgets(modelo1,30,stdin);
            modelo1[strlen(modelo1)-1] = '\0';
            for(int i=0;i<qtdC;i++){
                if((strcmp(c[i].modelo,modelo1))==0){
                    mostra_carros(c,qtdC,i);
                }
            } 
            
        }
    } while (opcao != 4);

}

void mostra_carros(carro *c, int qtdC, int z)
{
    if(qtdC==0){
        printf("Nao ha carros\n");
    }else{
        printf("\nMarca: ");
        printf("%s",c[z].marca);
        printf("\nModelo: ");
        printf("%s",c[z].modelo);
        printf("\nChassi: ");
        printf("%s",c[z].chassi);
        printf("\nAno: ");
        printf("%d",c[z].ano);
        printf("\nPreco: ");
        printf("%.2f",c[z].preco);
        printf("\n");
    }
}

void acha_antigo(carro * c, int qtdC)
{
    int menor=c[0].ano;
    int posicao=0;
    if(qtdC==0){
        printf("Nao ha carros\n");
    }
    else{
        for(int i=0;i<qtdC;i++){
            if(c[i].ano<menor){
                menor=c[i].ano;
                posicao=i;
            }
        }
        mostra_carros(c,qtdC,posicao);
    }
}

void acha_caro(carro *c, int qtdC)
{
    float maior=0.0;
    int posicao=0;
    if(qtdC==0){
        printf("Nao ha carros\n");
    }else{
        for(int i=0;i<qtdC;i++){
            if(c[i].preco>maior){
                maior=c[i].preco;
                posicao=i;
            }
        }
        mostra_carros(c,qtdC,posicao);
    }
}

void remove_chassi(carro *c,int qtdC)
{
    char chassi1[30];
    int posicao=0;
    printf("\nDigite o chassi: ");
    fflush(stdin);
    fgets(chassi1,30,stdin);
    chassi1[strlen(chassi1)-1] = '\0';
    for(int i=0;i<qtdC;i++){
        if((strcmp(c[i].chassi,chassi1))==0){
            for(int z=i;z<qtdC;z++){
                c[z]=c[z+1];
            }
        }
    } 
}
