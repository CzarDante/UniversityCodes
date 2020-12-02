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
void preenche_pessoa (cadastro * p);
void menu(cadastro *pessoas, int *qtdPessoas);
void AdicionaPessoa(cadastro * pessoas, cadastro p, int qtdPessoas);
void mostras_pessoa(cadastro * pessoas, cadastro p, int qtdPessoas);
void busca_masc(cadastro * pessoas, cadastro p, int qtdPessoas);
void busca_sal(cadastro * pessoas, cadastro p, int qtdPessoas);
void busca_id(cadastro * pessoas, cadastro p, int qtdPessoas);

int main()
{  
    cadastro pessoas[5];
    cadastro p;
    int opcao, qtdPessoas = 0;
    menu(cadastro * pessoas, qtdPessoas);
    return 0;
}

void preenche_pessoa (cadastro * p)
{
    printf("\nDigite o nome da pessoa: ");
    fflush(stdin);
    fgets(p->nome,30,stdin);
    p->nome[strlen(p->nome)-1] = '\0';
    printf("\nDigite o endereço da pessoa: ");
    printf("\nRua: ");
    fflush(stdin);
    fgets(p->casa->rua,30,stdin);
    p->casa->rua[strlen(p->casa->rua)-1] = '\0';
    printf("\nBairro: ");
    fflush(stdin);
    fgets(p->casa->bairro,30,stdin);
    p->casa->bairro[strlen(p->casa->bairro)-1] = '\0';
    printf("\nCidade: ");
    fflush(stdin);
    fgets(p->casa->cidade,30,stdin);
    p->casa->cidade[strlen(p->casa->cidade)-1] = '\0';
    printf("\nEstado: ");
    fflush(stdin);
    fgets(p->casa->estado,30,stdin);
    p->casa->estado[strlen(p->casa->estado)-1] = '\0';
    printf("\nCep: ");
    scanf("%ld",&p->casa->cep);
    printf("\nDigite o salario da pessoa: ");
    scanf("%lf",&p->salario); 
    printf("\nDigite o cpf da pessoa: ");
    scanf("%ld",&p->cpf);
    printf("\nDigite o estado civil da pessoa: ");
    fflush(stdin);
    fgets(p->estado_civil,30,stdin);
    p->estado_civil[strlen(p->estado_civil)-1] = '\0';
    printf("\nDigite o telefone da pessoa: ");
    scanf("%ld",&p->telefone);
    printf("\nDigite a idade da pessoa: ");
    scanf("%d",&p->idade); 
    printf("\nDigite o sexo da pessoa(masc/fem): ");
    fflush(stdin);
    fgets(p->sexo,30,stdin);
    p->sexo[strlen(p->sexo)-1] = '\0';
}

void menu(cadastro *pessoas, int *qtdPessoas)
{
    int opcao;
    do
    {
        printf("\n 1 - Incluir Pessoa ");
        printf("\n 2 - Encontrar mais velho");
        printf("\n 3 - Encontrar Pessoas do sexo masculino");
        printf("\n 4 - Encontrar pessoas com salario maior que 1000");
        printf("\n 5 - Encontrar por identidade");
        printf("\n 9 - sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            preenche_pessoa(&p);
            AdicionaPessoa(cadastro *pessoas, p, qtdPessoas);
            break;
        case 2:
            
            break;
        case 3:
            busca_masc(cadastro * pessoas, cadastro p, qtdPessoas);
            break;
        case 4:
            busca_sal(cadastro * pessoas, cadastro p, qtdPessoas);
            break;
        case 5:
            busca_id(cadastro * pessoas, cadastro p, qtdPessoas);
            break;
        case 9:
            printf("\n saindo ... \n");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 9);
}

void AdicionaPessoa(cadastro * pessoas, cadastro p, int qtdPessoas)
{
    pessoas[qtdPessoas] = p;
}
void mostras_pessoa(cadastro  pessoas, cadastro p, int qtdPessoas)
{
    printf("\nnome: ");   
    printf("%s",p.nome);
    printf("\nEndereço: ");
    printf("\nRua: ");
    printf("%s",p.casa->rua);
    printf("\nBairro: ");
    printf("%s",p.casa->bairro);
    printf("\nCidade: ");
    printf("%s",p.casa->cidade);
    printf("\nEstado: ");
    printf("%s",p.casa->estado);
    printf("\nCep: ");
    printf("%ld",p.casa->cep);
    printf("\nsalario: ");
    printf("%0.2lf",p.salario); 
    printf("\ncpf: ");
    printf("%ld",p.cpf);
    printf("\nestado civil: ");
    printf("%s",p.estado_civil);
    printf("\ntelefone: ");
    printf("%ld",p.telefone);
    printf("\nidade: ");
    printf("%d",p.idade); 
}
void busca_masc(cadastro * pessoas, cadastro p, int qtdPessoas)
{
    for(int z=0;z<qtdPessoas;z++){
        if(p.sexo=='masc'){
            mostrar_pessoa(pessoas[z]);
        }
    }
    
}
void busca_sal(cadastro * pessoas, cadastro p, int qtdPessoas)
{
    for(int z=0;z<qtdPessoas;z++){
        if(p.salario>=1000){
            mostrar_pessoa(pessoas[z]);
        }
    }
    
}

void busca_id(cadastro * pessoas, cadastro p, int qtdPessoas)
{
    long int id;
    printf("qual a id?\n");
    scanf("%ld",&id);
    for(int z=0;z<qtdPessoas;z++){
        if(p.id==id){
            mostrar_pessoa(pessoas[z]);
        }
    }
    
}