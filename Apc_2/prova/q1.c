#include <stdio.h>

void Opcoes()
{
    printf("\n 1 - Opcao 1");
    printf("\n 2 - Opcao 2");
    printf("\n 3 - Opcao 3");
    printf("\n 4 - Opcao 4\n");   
}
int main()
{
    int opcao;
    do
    {
        Opcoes();
        scanf("%d", &opcao); 
        if (opcao == 1)
        {
            printf("Voce escolheu Opcao 1\n");
        }
        if (opcao == 2)
        {
            printf("Voce escolheu Opcao 2\n");
        }
        if (opcao == 3)
        {
            printf("Voce escolheu Opcao 3\n");
        }
        if (opcao == 4)
        {
            printf("Voce escolheu Opcao 4\n");
        }
    } while (opcao != 0);
    return 0;
}