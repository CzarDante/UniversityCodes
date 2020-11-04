#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct aluno
{
    char nome[15];
    int idade;
    float media;
}aluno;

void preenche_alunos(aluno * p)
{
    printf("\nDigite o nome da pessoa: ");
    __fpurge(stdin);
    fgets(p->nome,30,stdin);
    p->nome[strlen(p->nome)-1] = '\0';
    printf("\nDigite a idade da pessoa: ");
    scanf("%d",&p->idade);
    printf("\nDigite a media da pessoa: ");
    scanf("%f",&p->media);
}

void mostrar_alunos(aluno p)
{
    printf("\n Nome: %s Idade = %d Media %f",p.nome,p.idade,p.media);
}

int main(){
    int qtd_alunos;
    int i;
    printf("quantos alunos: ");
    scanf("%d", qtd_alunos);
    aluno * vet;
    vet = malloc(sizeof(aluno)*qtd_alunos);

    for(i=0;i<qtd_alunos;i++){
        preenche_alunos(&vet[i]);
    }

    for(i=0;i<qtd_alunos;i++)
    {
        mostrar_alunos(vet[i]);
    }
    free(vet);
    printf("\n");
    return 0;
}
