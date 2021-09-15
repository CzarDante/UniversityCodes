package br.iesb.poo;

import java.util.Scanner;

public class Simple{
    private static int QtdInstructions = 0;
    private static int instructions = 0;
    private static int[] mem = new int[100];
    private static int operationCode =0;
    private static int acc = 0;
    private static int operand = 0;
    private static int register = 0;
    private static int counter = 0;
    private static boolean run = true;

    public static void main(String[] args){
        Message();
        program();
    }
    public static void Message()
    {
        System.out.println("***              Bem Vindo ao Simpletron!             ***");
        System.out.println("***   Por favor insira uma instrução (ou data word)   ***");
        System.out.println("*** o número de alocação e o ponto de interrogação(?).***");
        System.out.println("***   Então você digita a palavra para a alocação.    ***");
        System.out.println("*** Digite o número -9999 para parar/indicar o fim do ***");
        System.out.println("***                  seu programa.                    ***");
    }

    public static void program()
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

    static void loadCode(){
        register = mem[counter];
        operationCode = register / 100;
        operand = register % 100;
        counter++;
        if(register == (-9999) ){
            System.out.println("Exit Code\n");
            System.exit(0);
        }
    }

    static void operation(int operationCode, int operand){
        int temp;
        switch (operationCode) {
            case 10:
                Scanner input = new Scanner (System.in);
                int dado = input.nextInt();
                mem[operand] = dado;
                break;
            case 11:
                System.out.printf(String.valueOf(mem[operand]));
                System.out.printf("\n");
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
                if(acc!=0){
                    acc /= mem[operand];
                }else{
                    System.out.printf("Inpossivel dividir por 0\nSaindo do programa\n");
                    System.exit(-1);
                }
                break;
            case 33:
                acc *= mem[operand];
                break;
            case 40:
                if(operand>counter){
                    counter = operand;
                }else{
                    System.out.printf("Posicao invalida\n");
                }
                break;
            case 41:
                if(acc < 0){
                    counter = operand;
                }else{
                    System.out.printf("Impossivel mover-se para a posicao indicada\nAcc => 0\n");
                }
                break;
            case 42:
                if(acc==0){
                    counter = operand;
                }else{
                    System.out.printf("Impossivel mover-se para a posicao indicada\nAcc != 0\n");
                }
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
