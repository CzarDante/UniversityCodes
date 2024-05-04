public class ConversorOrdinal extends Conversor {
    public ConversorOrdinal(int numero) {
        super(numero);
    }

    @Override
    public String converte() {
        String[] unidades = {"", "primeiro", "segundo", "terceiro", "quarto", "quinto", "sexto", "sétimo", "oitavo", "nono"};
        String[] especiaisDezAdezenove = {"décimo", "décimo primeiro", "décimo segundo", "décimo terceiro", "décimo quarto", "décimo quinto", "décimo sexto", "décimo sétimo", "décimo oitavo", "décimo nono"};
        String[] dezenas = {"", "", "vigésimo", "trigésimo", "quadragésimo", "quinquagésimo", "sexagésimo", "septuagésimo", "octogésimo", "nonagésimo"};
        int centena = numero / 100;
        int resto = numero % 100;
        String ordinal = "";

        if (centena > 0) {
            if (centena == 1) {
                ordinal += "centésimo";
            } else if (centena == 2) {
                ordinal += "ducentésimo";
            } else if (centena == 3) {
                ordinal += "trecentésimo";
            } else if (centena == 4) {
                ordinal += "quadringentésimo";
            } else if (centena == 5) {
                ordinal += "quingentésimo";
            } else if (centena == 6) {
                ordinal += "sexcentésimo";
            } else if (centena == 7) {
                ordinal += "septingentésimo";
            } else if (centena == 8) {
                ordinal += "octingentésimo";
            } else if (centena == 9) {
                ordinal += "nongentésimo";
            }
        }

        if (resto > 0) {
            if (centena > 0) {
                ordinal += " ";
            }
            if (resto < 10) {
                ordinal += unidades[resto];
            } else if (resto < 20) {
                ordinal += especiaisDezAdezenove[resto - 10];
            } else {
                int dezena = resto / 10;
                int unidade = resto % 10;
                ordinal += dezenas[dezena];
                if (unidade > 0) {
                    ordinal += "  " + unidades[unidade];
                }
            }
        }
        return ordinal;
    }
}