#include <stdio.h>
typedef struct Data
{
    int dia, mes, ano;
}Data;

typedef struct agenda
{
    char nome[30];
    char e_mail[30];
    Data aniversario;
    reg_endereço endereco;
}agenda;

typedef struct endereço
{
    char rua[30], complemento[30], bairro[30];
    char cidade[30], estado[30], pais[03];
    char CEP[10];
    int numero;
}reg_endereço;


void AdicionaPessoa(agenda *nomes, agenda p, int qtdPessoas)
void LeData(Data *d)
void ImprimePessoasPorMes(agenda *pessoas, int qtd, Data d);
void opcoes();
void lepessoa(agenda *p));

int main()
{
    agenda nomes[100];
    agenda p;
    char nome_completo[100];
    char primeiro_nome[30];
    int qtdpessoas = 0;
    Data dia;

    opcoes();
    do
    {
        opcao = EscolheOpcao();
        if(opcao == 0)
        {
            lepessoa(&p)
            if(qtdpessoas==100){
                printf("\n Vetor de pessoas cheio");
            }
            else
            {
                AdicionaPessoa(nomes, p, qtdPessoas);
                qtdPessoas++;
            }
        }
        if (opcao == 1)
        {
            
        }
        if (opcao == 2)
        {
            LeData(&dia)
            ImprimePessoasPorMes(nomes, qtdPessoas);
        }
        if (opcao == 3)
        {
            
        }
    } while (opcao != 6);
    
    printf("");
    return 0;
}
void AdicionaPessoa(agenda *nomes, agenda p, int qtdPessoas)
{
    nomes[qtdPessoas] = p;
}
    void lepessoa(agenda *p)
{
    printf("\n Digite o nome: ");
    scanf("%c", &p->nome);
    printf("\n Digite o email: ");
    scanf("%f", &p->e_mail);
    prinf("\n Digite a data de nascimento: dd/mm/aa ");
    sacanf("%d/%d/%d", &p->aniversario.dia, &p->aniversario.mes, &p->aniversario.ano);
    printf("\n Digite o Pais: ");
    scanf("%s ", &p->endereco.pais);
    printf("\n Digite o CEP: ");
    scanf("%d", &p->endereco.CEP);
    printf("\n Digite o Estado: ");
    scanf("%s", &p->endereco.estado);
    printf("\n Digite o endereço(Cidade, Bairro, Rua, Numero, Complemento");
    scanf("%s, %s, %s, %d, %s", &p->endereco.cidade, &p->endereco.bairro, &p->endereco.rua, &p->endereco.numero, &p->endereco.complemento);
}
void opcoes()
{
    printf("\n 0 - Adiciona pessoa ");
    printf("\n 1 - Buscar por primeiro nome ");
    printf("\n 2 - Buscar por mes de aniversario");
    printf("\n 3 - Buscar por dia e mes de aniversario");
    printf("\n 4 - Retirar pessoa");
    printf("\n 5 - Imprime nome, telefone e e-mail");
    printf("\n 5 - Imprime todos os dados");
    printf("\n 6 - Sair");        
}
char * primeiro_nome(char * nome_completo)
{
    char retorno[30];
    int i;
    for(i=0;i<30 && nome_completo[i] != ' ';i++)
    {
            retorno[i]= nome_completo[i];
    }
    retorno[i] = '\0';
    return retorno;
}
void ImprimePessoasPorMes(agenda *nomes, char * nome)
{
    int i;
    if(qtd == 0)
    {
        printf("\n Nao existem pessoas na agenda");
    }
    else
    {
        for(i=0; i < qtd;i++)
        {
            if(pessoas[i].aniversario.mes == d.mes)
            {
                printf("\nNomes %c e-mail %f Nascimento %d/%d/%d Pais %c Cep %d Estado %c Cidade %c Bairro %c Rua %c Numero %d Complemento %c", pessoas[i].nome, pessoas[i].e_mail, pessoas[i].aniversario.dia, pessoas[i].aniversario.mes, pessoas[i].aniversario.ano, pessoas[i].pais, pessoas[i].CEP, pessoas[i].estado, pessoas[i].cidade, pessoas[i].bairro, pessoas[i].rua, pessoas[i].numero, pessoas[i].complemento);
            }

        }
    }
}
void buscapornome(agenda *nomes, int qtd, )
{
    int i;
    if()

}
void LeData(Data *d)
{
    printf("\n Digite a data DD/MM/AAAA: ");
    scanf("%d/%d/%d", &d->dia, &d->mes, &d->ano);
}