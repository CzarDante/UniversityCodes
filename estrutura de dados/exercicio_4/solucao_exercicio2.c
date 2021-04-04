#include <stdio.h>
#include <stdlib.h>

int push(int x);
int pop();
int stackpop();
int empty();
int topo = 0;
int pilha[100];
int debug_pilha();
int troca();
int trocas[2];

int main()
{
    int opcao,numero;
    do
    {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Troca o primeiro e o ultimo");
        printf("\n 6 - Sair\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);
            push(numero);
            break;
        case 2:
            if (!empty())
            {
                numero = pop();
                printf("\nnumero que saiu da pilha : %d", numero);
            }else
            {
                printf("\n pilha vazia");
            }
            break;
        case 3:
            if (!empty())
            {
                numero = stackpop();
                printf("\n numero que esta no topo da pilha: %d ", numero);
            }
            else
            {
                printf("\n pilha vazia");
            }
            break;
        case 4:
            if (empty())
                printf("\n Pilha vazia");
            else
                printf("\n pilha nao esta vazia");
            break;
        case 5:
            troca();
            break;
        case 6:
            printf("\n Saindo do programa");
            break;
        case 99:
            debug_pilha();
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao !=6);
    
    printf("\n");
    return 0; 
}

int empty()
{
    if(topo==0){
        return 1;
    }else{
        return 0;
    }
}
int push(int x)
{
    if(topo==100){
        printf("\nPilha Cheia ");
    }else{
        pilha[topo]=x;
        topo++;
    }
}
int pop()
{
    if(empty()){
        printf("\nPilha Vazia ");
    }else{
        topo--;
        return pilha[topo-1];
    }
}
int stackpop()
{
    if(empty()){
        printf("\nPilha Vazia");
        return -1;
    }else{
        return pilha[topo-1];
    }
}
int troca()
{
    if(empty()){
        printf("\nPilha Vazia");
    }else{
        trocas[0]=pilha[topo-1];
        trocas[1]=pilha[0];
        pilha[0]=trocas[0];
        pilha[topo-1]=trocas[1];
    }
}
int debug_pilha()
{
    int z=topo-1;
    for (int i = 0; i < topo; i++)
            {
                printf("%d\n",pilha[z]);
                z--;
            }
}