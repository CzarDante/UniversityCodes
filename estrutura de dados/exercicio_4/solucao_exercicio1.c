#include <stdio.h>
#include <stdlib.h>

int push(int x);
int pop();
int stackpop();
int empty();
int topo = 0;
int pilha[100];
int inverte();
int invertida[100];
int debug_pilha();

int main()
{
    int opcao, numero;

    do
    {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Inverter");
        printf("\n 6 - Sair\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o numero: ");
            scanf("%d",&numero);
            push(numero);
            break;
        case 2:
            if(empty()){
                printf("\nPilha Vazia");                
            }else{
                numero = pop();
                printf("\nNumero retirado: %d ",numero);
            }
            break;
        case 3:
            if(empty()){
                printf("\nPilha Vazia");                
            }else{
                numero = stackpop();
                printf("\nNumero no topo: %d ",numero);
            }
            break;
        case 4:
            if(empty()){
                printf("\nPilha Vazia");                
            }else{
                printf("\nPilha nao esta vazia"); 
            }
            break;
        case 5:
            if(empty()){
                printf("\nPilha Vazia");                
            }else{
                inverte();
            }
            break;
        case 6:
            printf("\nSaindo do Programa\n");
            break;
        case 99:
            debug_pilha();
            break;
        default:
            printf("\nOpcao invalida");
            break;
        }
    } while (opcao!=6); 
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
        printf("\nPilha cheia\n");
    }else{
        pilha[topo] = x;
        topo++;
    }
}

int pop()
{
    if(empty()){
        printf("\nPilha Vazia\n");
        return -1;
    }else{
        topo--;
        return pilha[topo];
    }
}

int inverte()
{
    if(topo==0){
        printf("\nPilha Vazia");
    }else{
        int aux=topo-1;
        for(int i=0;i<topo;i++){
            invertida[i]=pilha[aux];
            aux--;
        }
        for (int i = 0; i < topo; i++)
        {
            pilha[i]=invertida[i];
        }

        
    }
}

int stackpop()
{
    if (empty())
    {
        printf("\nPilha vazia");
        return 0;
    }
    else
    {
        return pilha[topo - 1];
    }
}

int debug_pilha()
{
    int z=topo;
    for (int i = 0; i <= topo; i++)
            {
                printf("%d\n",pilha[z]);
                z--;
            }
}