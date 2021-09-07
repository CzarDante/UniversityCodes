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
/**
 * @author CzarDante
 * @version 1.0
 */

public class Simpletron {
    int acc =0;
    int mem[] = new int [100];
    int instructions = 0;
    int QtdInstructions = 0;
    int operationCode;
    int operand;
    int registe;
    int counter = 0;
    private boolean run = true;

    public void starta(){
        Message();
        program();
    }

    public void Message()
    {
        System.out.println("***              Bem Vindo ao Simpletron!             ***");
        System.out.println("***   Por favor insira uma instrução (ou data word)   ***");
        System.out.println("*** o número de alocação e o ponto de interrogação(?).***");
        System.out.println("***   Então você digita a palavra para a alocação.    ***");
        System.out.println("*** Digite o número -9999 para parar/indicar o fim do ***");
        System.out.println("***                  seu programa.                    ***");
    }

    public void program()
    {
        Scanner input = new Scanner(System.in);
        do
        {
            System.out.printf("%02d ?", QtdInstructions);
            instructions = input.nextInt();
            mem[QtdInstructions] = instructions;
            QtdInstructions++;
        }while(instructions != -9999);
        System.out.println("***          Programa carregado    ***");
        System.out.println("***Iniciando a execução do programa***");

        while (run){
            loadCode();
            operation(operationCode,operand);
        }
        System.exit(0);
    }
    void loadCode(){
        register = mem[counter];
        operationCode = register / 100;
		operand = register % 100;
        counter++;
        if(register == (-9999) ){
            System.out.println("Exit Code\n");
            System.exit(0);
        }
    }
    void operation(int operationCode, int operand){
        switch (operationCode) {
            case 10:
                Scanner input = new Scanner (System.in);
                int dado = input.nextInt();
                input.close();
                mem[operand] = dado;
                break;
            case 11:
                System.out.println(mem[operand]);
                break;
            case 20:
                acc = mem[operand];
                break;
            case 21:
                mem[operand] = acc;
                break;
            case 30:
                acc += mem[operand];
                break;
            case 31:
                acc -= mem[operand];
                break;
            case 32:
                acc = mem[operand]/acc;
                break;
            case 33:
                acc = mem[operand] * acc;
                break;
            case 40:
                counter = operand;
                break;
            case 41:
                if(acc < 0){
                    counter = operand;
                };
                break;
            case 42:
                if(acc==0){
                    counter = operand;
                };
                break;
            case 43:
                System.out.println("Saindo do Programa\n");
                run=false;
                System.exit(0);
                break;
            default:
                System.out.println("Operation Code invalido\n");
                break;
        }
    }
}