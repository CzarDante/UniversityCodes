import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ValidarCSV {
    public static void validar(String arquivoCSV) throws IOException, CSVValidationException {
        List<String> inconsistencias = new ArrayList<>();
        String linha;
        int numeroLinha = 0;

        try (BufferedReader leitor = new BufferedReader(new FileReader(arquivoCSV))) {
            while ((linha = leitor.readLine()) != null) {
                numeroLinha++;
                String[] campos = linha.split(";");

                if (campos.length != 20) {
                    inconsistencias.add("Linha " + numeroLinha + ": Número incorreto de colunas.");
                }

                if (!campos[0].trim().matches("[1-9]|[1-4][0-9]|5[0-3]")) {
                    inconsistencias.add("Linha " + numeroLinha + ", Coluna 1: Valor inválido: " + campos[0].trim());
                }

                if (!campos[1].trim().matches("[1-2]")) {
                    inconsistencias.add("Linha " + numeroLinha + ", Coluna 2: Valor inválido: " + campos[1].trim());
                }

                for (int i = 2; i < 19; i++) {
                    if (!campos[i].trim().matches("[1,2,9]")) {
                        inconsistencias.add("Linha " + numeroLinha + ", Coluna " + (i + 1) + ": Valor inválido: " + campos[i].trim());
                    }
                }

                if (!campos[19].trim().matches("[1,5,9]")) {
                    inconsistencias.add("Linha " + numeroLinha + ", Coluna 20: Valor inválido: " + campos[19].trim());
                }
            }
        }

        if (!inconsistencias.isEmpty()) {
            throw new CSVValidationException(inconsistencias);
        }
    }

    static class CSVValidationException extends Exception {
        private List<String> mensagens;

        public CSVValidationException(List<String> mensagens) {
            this.mensagens = mensagens;
        }

        public List<String> getMensagens() {
            return mensagens;
        }
    }
}
