/**Vamos criar um computador que chamaremos de Simpletron. Como seu nome implica, é uma
 máquina simples, mas como logo veremos também é uma máquina poderosa. O Simpletron executa
 programas escritos na única linguagem que ele entende diretamente, isto é, a Simpletron
 Machine Language ou, abreviadamente, SML.

 Antes de executar um programa de SML, devemos carregar, ou colocar, o programa na memória.
 A primeira instrução de cada programa de SML sempre é colocada na posição 00. O simulador
 começará a executar nessa posição.

 Cada instrução escrita em SML ocupa uma palavra da memória do Simpletron; portanto, as
 instruções são números decimais de quatro dígitos com sinal. Suponha que o sinal de uma
 instrução de SML seja sempre positivo, mas o sinal de uma palavra de dados pode ser
 positivo ou negativo. Cada localização na memória de Simpletron pode conter uma instrução,
 um valor de dados utilizado por um programa ou uma área da memória não-utilizada (e
 portanto indefinida). Os primeiros dois dígitos de cada instrução do SML são o código
 de operação que especifica a operação a ser realizada. Os últimos dois dígitos de uma
 instrução de SML são operandos o endereço da posição da memória contendo a palavra
 à qual a operação se aplica.
 A instrução -9999 indica o final do programa. O programa deve ser carregado na memória
 e após a carga deve-se iniciar a execução.

 Ex.: 1099 ====> Instrução: 10 (READ), Operando: 99 (PARÂMETRO DA OPERAÇÃO)

 Registradores:
 ========================
 acc: registrador de armazenamento temporário das operações realizadas.
 ip   : ponteiro para instrução a ser executada. Quando o Simpletron for ligado esse
         registrador recebe o valor 0 que é a posição da primeira instrução na memória.
         Após a execução de uma instrução esse registrador deve ser incrementado.

 Operações do computador
 =======================
 Código             Operação             Descrição
 10                     READ                    Lê uma palavra do teclado para uma posição específica da memória.
 11                     WRITE                  Escreve na tela uma palavra de uma posição específica da memória.
 20                     LOAD                    Carrega uma palavra de uma posição específica na memória para o acumulador.
 21                     STORE                  Armazena uma palavra do acumulador para uma posição específica na memória.
 30                     ADD                      Adiciona uma palavra de uma posição específica na memória à palavra no acumulador
                                                        (deixa o resultado no acumulador).
 31                     SUBTRACT          Subtrai uma palavra de uma posição específica na memória da palavra no acumulador
                                                        (deixa o resultado no acumulador).
 32                     DIVIDE                  Divide uma palavra de uma posição específica na memória pela palavra no acumulador
                                                        (deixa o resultado no acumulador).
 33                     MULTIPLY            Multiplica uma palavra de uma posição específica na memória pela palavra no acumulador
                                                        (deixa o resultado no acumulador).
 40                     BRANCH              Desvia para uma posição específica na memória.
 41                     BRANCHNEG      Desvia para uma posição específica na memória se o acumulador for negativo.
 42                     BRANCHZERO    Desvia para uma posição específica na memória se o acumulador for zero.
 43                     HALT                    Suspende o programa completou sua tarefa.
*/
package br.iesb.poo;

import java.util.Scanner;

public class Simpletron {
    int ip = 0;
    int acc =0;
    int mem[] = new int [100];
    int instrução = 0;
    int QtdInstrucoes = 0;

    void add(int position){
        acc += mem[position];
    }

    void load(int position)
    {
        acc = mem[position];
    }

    void read(int position){
        Scanner input = new Scanner ( System.in );
        int dado = input.nextInt();
        input.close();
        mem[position] = dado;
    }

    void write(int position){
        System.out.println(mem[position]);
    }

    void store(int position){
        mem[position] = acc;
    }

    public void Mensage()
    {
        System.out.printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                "***Bem Vindo ao Simpletron!***",
                "***Por favor insira uma instrução (ou data word)***",
                "***por vez em seu programa. Eu vou digitar o número***",
                "***o número de alocação e o ponto de interrogação(?).***",
                "***Então você digita a palavra para a alocação.***",
                "***Digite o número -9999 para parar/indicar o fim do***",
                "***seu programa.***");
    }

    public void simpletron()
    {
        Scanner input = new Scanner(System.in);
        do
        {
            System.out.printf("%d %s", QtdInstrucoes, "?");
            instrução = input.nextInt();
            if(instrução != -9999)
                memoria[QtdInstrucoes] = instrução;
            QtdInstrucoes++;
        }while(instrução != -9999);

        System.out.printf("\n%s%s","***Programa carregado***\n",
                "***Iniciando a execução do programa***"
        );
        for(int code:memoria)
        {
            if(code!= 0)
            {

            }
        }
    }
}