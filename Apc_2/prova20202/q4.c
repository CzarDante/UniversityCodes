#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct endereco
{
    char rua[20];
    char bairro[20];
    char cidade[20];
    char estado[20];
    long int cep;
}endereco;

typedef struct cadastro
{
    char nome[30];
    endereco * casa;
    double salario;
    char id[10];
    char cpf[15];
    char estado_civil[20];
    long int telefone;
    int idade;
    char sexo[10];
}cadastro;

void preenche_pessoa (cadastro * pessoas,int qtdPessoas);
//void menu(cadastro *pessoas, int *qtdPessoas);
//void AdicionaPessoa(cadastro * pessoas, cadastro p, int qtdPessoas);
void mostrar_pessoa(cadastro * pessoas, int qtdPessoas, int z);
void busca_masc(cadastro * pessoas, int qtdPessoas);
void busca_sal(cadastro * pessoas, int qtdPessoas);
void busca_id(cadastro * pessoas, int qtdPessoas);

void Opcoes()
{
    printf("\n 1 - Incluir Pessoa ");
    printf("\n 2 - Encontrar mais velho");
    printf("\n 3 - Encontrar Pessoas do sexo masculino");
    printf("\n 4 - Encontrar pessoas com salario maior que 1000");
    printf("\n 5 - Encontrar por identidade");
    printf("\n 6 - sair\n");   
}

int main()
{  
    cadastro pessoas[5];
    //cadastro p;
    int opcao, qtdPessoas = 0;
    do
    {
        Opcoes();
        scanf("%d", &opcao); 
        if (opcao == 1)
        {
            preenche_pessoa(pessoas,qtdPessoas);
            qtdPessoas++;  
        }
        if (opcao == 2)
        {
            
        }
        if (opcao == 3)
        {
            busca_masc(pessoas, qtdPessoas);
        }
        if (opcao == 4)
        {
            busca_sal(pessoas, qtdPessoas);
        }
        if (opcao == 5)
        {
            busca_id(pessoas, qtdPessoas);
        }
        if(opcao==9)
        {
            for(int i=0;i<=qtdPessoas;i++){
                mostrar_pessoa(pessoas,qtdPessoas,i);
            }
        }
    } while (opcao != 6);
    return 0;
}

void preenche_pessoa (cadastro * pessoas, int qtdPessoas)
{

    printf("\nDigite o nome da pessoa: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].nome,30,stdin);
    pessoas[qtdPessoas].nome[strlen(pessoas[qtdPessoas].nome)-1] = '\0';
    printf("\nDigite o endereco da pessoa: ");
    printf("\nRua: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->rua,20,stdin);
    pessoas[qtdPessoas].casa->rua[strlen(pessoas[qtdPessoas].casa->rua)-1] = '\0';
    printf("\nBairro: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->bairro,20,stdin);
    pessoas[qtdPessoas].casa->bairro[strlen(pessoas[qtdPessoas].casa->bairro)-1] = '\0';
    printf("\nCidade: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->cidade,20,stdin);
    pessoas[qtdPessoas].casa->cidade[strlen(pessoas[qtdPessoas].casa->cidade)-1] = '\0';
    printf("\nEstado: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->estado,20,stdin);
    pessoas[qtdPessoas].casa->estado[strlen(pessoas[qtdPessoas].casa->estado)-1] = '\0';
    printf("\nCep: ");
    scanf("%ld",&pessoas[qtdPessoas].casa->cep);
    printf("\nDigite o salario da pessoa: ");
    scanf("%lf",&pessoas[qtdPessoas].salario); 
    printf("\nDigite a id da pessoa: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].id,10,stdin);
    pessoas[qtdPessoas].id[strlen(pessoas[qtdPessoas].id)-1] = '\0';
    printf("\nDigite o cpf da pessoa: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].cpf,15,stdin);
    pessoas[qtdPessoas].cpf[strlen(pessoas[qtdPessoas].cpf)-1] = '\0';
    printf("\nDigite o estado civil da pessoa: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].estado_civil,20,stdin);
    pessoas[qtdPessoas].estado_civil[strlen(pessoas[qtdPessoas].estado_civil)-1] = '\0';
    printf("\nDigite o telefone da pessoa: ");
    scanf("%ld",&pessoas[qtdPessoas].telefone);
    printf("\nDigite a idade da pessoa: ");
    scanf("%d",&pessoas[qtdPessoas].idade); 
    printf("\nDigite o sexo da pessoa(masc/fem): ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].sexo,10,stdin);
    pessoas[qtdPessoas].sexo[strlen(pessoas[qtdPessoas].sexo)-1] = '\0';
}

void mostrar_pessoa(cadastro * pessoas, int qtdPessoas, int z)
{
    if(qtdPessoas==0){
        printf("Nao a funcionarios\n");
    }
    printf("\nnome: ");   
    printf("%s",pessoas[z].nome);
    printf("\nEndereço: ");
    printf("\nRua: ");
    printf("%s",pessoas[z].casa->rua);
    printf("\nBairro: ");
    printf("%s",pessoas[z].casa->bairro);
    printf("\nCidade: ");
    printf("%s",pessoas[z].casa->cidade);
    printf("\nEstado: ");
    printf("%s",pessoas[z].casa->estado);
    printf("\nCep: ");
    printf("%ld",pessoas[z].casa->cep);
    printf("\nsalario: ");
    printf("%0.2lf",pessoas[z].salario);
    printf("\nid: ");
    printf("%s",pessoas[z].id); 
    printf("\ncpf: ");
    printf("%s",pessoas[z].cpf);
    printf("\nestado civil: ");
    printf("%s",pessoas[z].estado_civil);
    printf("\ntelefone: ");
    printf("%ld",pessoas[z].telefone);
    printf("\nidade: ");
    printf("%d",pessoas[z].idade);
    printf("\nsexo: ");
    printf("%s",pessoas[z].sexo);  
}
void busca_masc(cadastro * pessoas, int qtdPessoas)
{
    char masc[5]="masc";

    for(int z=0;z<qtdPessoas;z++){
        if(strcmp(pessoas[z].sexo,masc)==0){
            mostrar_pessoa(pessoas,qtdPessoas,z);
        }
    }
    
}
void busca_sal(cadastro * pessoas, int qtdPessoas)
{
    for(int z=0;z<qtdPessoas;z++){
        if(pessoas[z].salario>=1000){
            mostrar_pessoa(pessoas,qtdPessoas,z);
        }
    }
    
}

void busca_id(cadastro * pessoas, int qtdPessoas)
{
    char buscaid[10];
    int bid=0;
    printf("qual a id?\n");
    fflush(stdin);
    fgets(buscaid,10,stdin);
    buscaid[strlen(buscaid)-1] = '\0';
    for(bid=0;bid<qtdPessoas;bid++){
        if(strcmp(pessoas[bid].id,buscaid)==0){
            mostrar_pessoa(pessoas,qtdPessoas,bid);
        }
    }   
}