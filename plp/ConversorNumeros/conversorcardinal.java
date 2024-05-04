public class ConversorCardinal extends Conversor {
    public ConversorCardinal(int numero) {
        super(numero);
    }

    @Override
    public String converte() {
        String[] unidades = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
        String[] especiais = {"", "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
        String[] dezenas = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
        int centena = numero / 100;
        int resto = numero % 100;
        String cardinal = "";

        if (centena > 0) {
            if (centena == 1) {
                cardinal += "cento";
            } else if (centena == 2) {
                cardinal += "duzentos";
            } else if (centena == 3) {
                cardinal += "trezentos";
            } else if (centena == 4) {
                cardinal += "quatrocentos";
            } else if (centena == 5) {
                cardinal += "quinhentos";
            } else if (centena == 6) {
                cardinal += "seiscentos";
            } else if (centena == 7) {
                cardinal += "setecentos";
            } else if (centena == 8) {
                cardinal += "oitocentos";
            } else if (centena == 9) {
                cardinal += "novecentos";
            }
        }

        if (resto > 0) {
            if (centena > 0) {
                cardinal += "  ";
            }
            if (resto < 10) {
                cardinal += unidades[resto];
            } else if (resto < 20) {
                cardinal += especiais[resto - 10];
            } else {
                int dezena = resto / 10;
                int unidade = resto % 10;
                cardinal += dezenas[dezena];
                if (unidade > 0) {
                    cardinal += " e " + unidades[unidade];
                }
            }
        }
        return cardinal;
    }
}