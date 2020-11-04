#include <stdio.h>

typedef struct vetores
{
    int x1;
    int x2;
    int x3;
}vetores;
void preenche_vetorx1(vetores* v);
void preenche_vetorx2(vetores* v);
int main()
{
    int i, n1, n2, qtd;
    
    qtd = n1+n2;
    vetores * vetx1;
    vetores * vetx2;
    vetores * vetx3;
    
    int* uniao(int *vetx1, int *vetx2, int n1, int n2, int* qtd);


    do
    {
        printf("Digite o tamanho de x1: ");
        scanf("%d", n1);
        printf("Digite o tamanho de x2: ");
        scanf("%d", n2);

        if (n1<=0 || n2<=0)
        {
            printf("\n Digite um N valido");
        }
    } while (n1<=0);

    vetx1 = malloc(sizeof(vetores)*n1);
    vetx2 = malloc(sizeof(vetores)*n2);
    vetx3 = malloc(sizeof(vetores)*qtd);

    for(i=0;i<n1;i++)
    {
        printf("Digite o valor %d do vetro x1", i);
        preenche_vetorx1(&vetx1[i]);
    }
    for(i=0;i<n2;i++)
    {
        printf("Digite o valor %d do vetro x2", i);
        preenche_vetorx2(&vetx2[i]);
    }
    
    free(vetx1);
    free(vetx2);

    return 0;
}

void preenche_vetorx1(vetores* v)
{
    scanf("%d", &v->x1);
}
void preenche_vetorx2(vetores* v)
{
    scanf("%d", &v->x2);
}
