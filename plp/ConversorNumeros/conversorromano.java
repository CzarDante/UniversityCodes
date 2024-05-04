public class ConversorRomano extends Conversor {
    public ConversorRomano(int numero) {
        super(numero);
    }

    @Override
    public String converte() {
        String[] romanUnits = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    String[] romanTens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String[] romanHundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    int unit = numero % 10;
    int ten = (numero / 10) % 10;
    int hundred = (numero / 100) % 10;
    StringBuilder sb = new StringBuilder();
    sb.append(romanHundreds[hundred]);
    sb.append(romanTens[ten]);
    sb.append(romanUnits[unit]);
    return sb.toString();
    }
}