#include <stdio.h>

typedef struct Compania
{
    char nome[30];
    char area_de_atuacao[50];
    int val_acao;
    int val_anterior;
    double variacao_da_acao;
}Compania;

printa_tudo(nome, Aa, Va, Vaa, Vac)
{
    printf("%s\n", Dados.nome);
    printf("%s\n", Dados.area_de_atuacao);
    printf("%d\n", Dados.val_acao);
    printf("%d\n", Dados.val_anterior);
    printf("%0.2lf\n", Dados.val_anterior);
}

int main()
{
    Compania Dados;

    printf("Nome da Comapania\n");
    scanf("%s",&Dados.nome);
    printf("Area de atuacaon\n");
    scanf("%s",&Dados.area_de_atuacao);
    printf("Valor da acao\n");
    scanf("%d", &Dados.val_acao);
    printf("Valor da anterior da acao\n");
    scanf("%d", &Dados.val_anterior);

    Dados.variacao_da_acao = (Dados.val_acao/Dados.val_anterior - 1)*100;

    printa_tudo(Dados.nome, Dados.area_de_atuacao, Dados.val_acao, Dados.val_anterior, Dados.variacao_da_acao);
}
