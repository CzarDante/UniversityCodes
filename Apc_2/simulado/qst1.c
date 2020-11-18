#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct alunos
{
    int matricula;
    char nome[30];
    double media;
}alunos;

void preenche_alunos(alunos * p);
void mostra_alunos(alunos p);

int main()
{
    int n;
    alunos *vet_aluno;
    printf("\n Digite N: ");
    scanf("%d",&n);
    vet_aluno = (int*)malloc(sizeof(int)*n);
    int i;
    
    for(i=0;i<n;i++)
    {
        preenche_alunos(&vet_aluno[i]);
    }
    
    for(i=0;i<n;i++)
    {
        mostra_alunos(vet_aluno[i]);
    }

    printf("\n");
    return 0;
}
void preenche_alunos(alunos * p)
{
    
    int m;
    double notas=0, media=0,media_parcial=0;
    printf("\nDigite o nome da pessoa: ");
    fflush(stdin);
    fgets(p->nome,30,stdin);
    p->nome[strlen(p->nome)-1] = '\0';
    printf("\nDigite a matricula: ");
    scanf("%d",&p->matricula);
	printf("Quantas notas: ");
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		printf("nota %d: ",i);
		scanf("%lf", &notas);
		media_parcial+= notas;
		
	}
	p->media=+media_parcial/m;
    
}
void mostra_alunos(alunos p)
{
    printf("\n Nome: %s \t Matricula: %d \tMedia %0.2lf ",p.nome,p.matricula,p.media);
}