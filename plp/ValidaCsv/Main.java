import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.println("Digite o nome do arquivo CSV:");
        try {
            String arquivoCSV = reader.readLine();

            ValidarCSV.validar(arquivoCSV);
            System.out.println("O arquivo CSV está válido.");
        } catch (IOException e) {
            System.out.println("Ocorreu um erro ao ler o arquivo CSV.");
            e.printStackTrace();
        } catch (ValidarCSV.CSVValidationException e) {
            System.out.println("Foram encontradas as seguintes inconsistências:");
            for (String mensagem : e.getMensagens()) {
                System.out.println(mensagem);
            }
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
