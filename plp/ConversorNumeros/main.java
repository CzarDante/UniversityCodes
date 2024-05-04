public class Main {
    public static void main(String[] args) {
        int numero = 859;

        Conversor conversorCardinal = new ConversorCardinal(numero);
        Conversor conversorOrdinal = new ConversorOrdinal(numero);
        Conversor conversorRomano = new ConversorRomano(numero);

        System.out.println("Número: " + numero);
        System.out.println("Cardinal: " + conversorCardinal.converte());
        System.out.println("Ordinal: " + conversorOrdinal.converte());
        System.out.println("Romano: " + conversorRomano.converte());
    }
}