#include <stdio.h>
#include <string.h>

typedef struct nome
{
    char nome[30];
}nome;
typedef struct funcionario
{
    long int matricula;
    float salario_bruto;
    int carga_horaria;

}funcionario;
void preenche_cadastro(funcionario * f){
    printf("\nDigite a matricula da pessoa: ");
    scanf("%ld",&f->matricula);
    printf("\nDigite o salario bruto: ");
    scanf("%f", &f->salario_bruto);
    printf("\nDigite a carga horaria: ");
    scanf("%d",&f->carga_horaria);
}
void mostra_cadastro(funcionario f){
    printf("\nNome: Jack \nMatricula: %ld\nSalario bruto: %0.2f\nCarga horaria: %d\n",f.matricula,f.salario_bruto,f.carga_horaria);
}
void Opcoes()
{
    printf("\n 1 - Incluir funcionario");
    printf("\n 2 - Remover Funcionario");
    printf("\n 3 - Mostrar Folha de pagamento");
    printf("\n 4 - Sair\n");   
}
void ImprimeTodasAsPessoas(funcionario * funcionarios, int qtd_funcionarios)
{
    int i;
    float somasalario =0 ;
    long int somacargahora = 0;
    float valor_hora=0;
    if (qtd_funcionarios == 0)
    {
        printf("\n Lista vazia\n");
        return 0;
    }
    for(i=0;i<qtd_funcionarios;i++)
    {
        printf("\nMatricula: %ld\n Salario Bruto: %0.2f\n Carga Horaria: %d\n", funcionarios[i].matricula, funcionarios[i].salario_bruto, funcionarios[i].carga_horaria);   
        somasalario += funcionarios[i].salario_bruto;
        somacargahora += funcionarios[i].carga_horaria;
        valor_hora += funcionarios[i].salario_bruto/funcionarios[i].carga_horaria;
        if(i == qtd_funcionarios-1){
            printf("\nSoma de todos os salarios brutos: %0.2f\n media de cargas horarias: %ld\n", somasalario, somacargahora/qtd_funcionarios);
            printf("Valor por hora da empresa: %0.3f\n", valor_hora/qtd_funcionarios);
        }
    }
}
void AdicionaPessoa(funcionario * funcionarios, funcionario f, int qtd_funcionarios)
{
    funcionarios[qtd_funcionarios] = f;
}
int buscar(funcionario *funcinarios, int qtd_funcionarios, int matricula_procurada)
{
    int i;
    if (qtd_funcionarios == 0)
    {
        printf("\n Lista vazia\n");
        return 0;
    }
    else
    {
        for (i = 0; i < qtd_funcionarios; i++)
        {
            if (funcinarios[i].matricula == matricula_procurada)
            {      
                for(int j=i;j<qtd_funcionarios; j++){
                    funcinarios[i].matricula = funcinarios[i+1].matricula;
                    funcinarios[i].carga_horaria = funcinarios[i+1].carga_horaria;
                    funcinarios[i].salario_bruto = funcinarios[i+1].salario_bruto;
                }
            }
        }    
    }
    return 0;
}
int main(){
    int qtd_funcionarios=0;
    funcionario funcionarios[10];
    funcionario f;
    int opcao;
    long int matricula_procurada;
    do
    {
        Opcoes();
        scanf("%d", &opcao); 
        if (opcao == 1)
        {
            preenche_cadastro(&f);
            AdicionaPessoa(funcionarios, f, qtd_funcionarios);
            qtd_funcionarios++;   
        }
        if (opcao == 2)
        {
            printf("Qual a matricula procurada: ");
            scanf("%ld", &matricula_procurada);
            buscar(funcionarios, qtd_funcionarios, matricula_procurada);
            qtd_funcionarios--;
        }
        if (opcao == 3)
        {
            ImprimeTodasAsPessoas(funcionarios, qtd_funcionarios);
        }
    } while (opcao != 4);    
    return 0;
}