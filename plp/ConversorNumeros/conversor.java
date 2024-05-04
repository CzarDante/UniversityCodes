public abstract class Conversor {
    protected int numero;

    public Conversor(int numero) {
        this.numero = numero;
    }

    public abstract String converte();
}