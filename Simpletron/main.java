public class main{
    private int [] memoria;
    public void Mensagens()
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
        int instrução = 0;
        int QtdInstrucoes = 0;
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

        public void load()
        {
            operationCode = memoria [ instructionCounter ] / 100;
		    operand = memoria [ instructionCounter ] % 100;
        }
    }
}