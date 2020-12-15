#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct endereco
{
    char rua[10];
    char bairro[10];
    char cidade[10];
    char estado[10];
    long int cep;
}endereco;

typedef struct cadastro
{
    char nome[30];
    endereco * casa;
    double salario;
    long int id;
    long int cpf;
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
    printf("\n 6 - sair");   
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
    } while (opcao != 6);
    return 0;
}

void preenche_pessoa (cadastro * pessoas, int qtdPessoas)
{
    printf("\nDigite o nome da pessoa: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].nome,30,stdin);
    pessoas[qtdPessoas].nome[strlen(pessoas[qtdPessoas].nome)-1] = '\0';
    printf("\nDigite o endereço da pessoa: ");
    printf("\nRua: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->rua,30,stdin);
    pessoas[qtdPessoas].casa->rua[strlen(pessoas[qtdPessoas].casa->rua)-1] = '\0';
    printf("\nBairro: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->bairro,30,stdin);
    pessoas[qtdPessoas].casa->bairro[strlen(pessoas[qtdPessoas].casa->bairro)-1] = '\0';
    printf("\nCidade: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->cidade,30,stdin);
    pessoas[qtdPessoas].casa->cidade[strlen(pessoas[qtdPessoas].casa->cidade)-1] = '\0';
    printf("\nEstado: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].casa->estado,30,stdin);
    pessoas[qtdPessoas].casa->estado[strlen(pessoas[qtdPessoas].casa->estado)-1] = '\0';
    printf("\nCep: ");
    scanf("%ld",&pessoas[qtdPessoas].casa->cep);
    printf("\nDigite o salario da pessoa: ");
    scanf("%lf",&pessoas[qtdPessoas].salario); 
    printf("\nDigite o cpf da pessoa: ");
    scanf("%ld",&pessoas[qtdPessoas].cpf);
    printf("\nDigite o estado civil da pessoa: ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].estado_civil,30,stdin);
    pessoas[qtdPessoas].estado_civil[strlen(pessoas[qtdPessoas].estado_civil)-1] = '\0';
    printf("\nDigite o telefone da pessoa: ");
    scanf("%ld",&pessoas[qtdPessoas].telefone);
    printf("\nDigite a idade da pessoa: ");
    scanf("%d",&pessoas[qtdPessoas].idade); 
    printf("\nDigite o sexo da pessoa(masc/fem): ");
    fflush(stdin);
    fgets(pessoas[qtdPessoas].sexo,30,stdin);
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
    printf("%s",pessoas->casa->estado);
    printf("\nCep: ");
    printf("%ld",pessoas->casa->cep);
    printf("\nsalario: ");
    printf("%0.2lf",pessoas->salario); 
    printf("\ncpf: ");
    printf("%ld",pessoas->cpf);
    printf("\nestado civil: ");
    printf("%s",pessoas->estado_civil);
    printf("\ntelefone: ");
    printf("%ld",pessoas->telefone);
    printf("\nidade: ");
    printf("%d",pessoas->idade); 
}
void busca_masc(cadastro * pessoas, int qtdPessoas)
{
    char masc[4]="masc";
    for(int z=0;z<qtdPessoas;z++){
        if(strcmp(pessoas[z].sexo,masc)){
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
    long int id;
    printf("qual a id?\n");
    scanf("%ld",&id);
    for(int z=0;z<qtdPessoas;z++){
        if(pessoas[z].id==id){
            mostrar_pessoa(pessoas,qtdPessoas,z);
        }
    }
    
}