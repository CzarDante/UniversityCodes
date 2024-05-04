public class Main {

    public static class Pilha {
        private Registro topo;
        private int tamanho;

        public Registro getTopo() {
            return topo;
        }

        public void setTopo(Registro topo) {
            this.topo = topo;
        }

        public int getTamanho() {
            return tamanho;
        }

        public void incrementarTamanho() {
            tamanho++;
        }

        public void decrementarTamanho() {
            tamanho--;
        }
    }

    public static class Registro {
        private String palavra;
        private Registro prox;

        public String getPalavra() {
            return palavra;
        }

        public void setPalavra(String palavra) {
            this.palavra = palavra;
        }

        public Registro getProx() {
            return prox;
        }

        public void setProx(Registro prox) {
            this.prox = prox;
        }
    }

    public static Pilha criaPilha() {
        return new Pilha();
    }

    public static Registro criaRegistro() {
        return new Registro();
    }

    public static void push(Pilha p, String palavra) {
        if (palavra.length() != 10) {
            System.out.println("A palavra não 10 caracteres.");
            return;
        }
        Registro novo = criaRegistro();
        novo.setPalavra(palavra);
        if (empty(p)) {
            p.setTopo(novo);
        } else {
            novo.setProx(p.getTopo());
            p.setTopo(novo);
        }
        p.incrementarTamanho();
    }

    public static String pop(Pilha p) {
        if (empty(p)) {
            return null;
        } else {
            String retorno = p.getTopo().getPalavra();
            p.setTopo(p.getTopo().getProx());
            return retorno;
        }
    }

    public static String stackpop(Pilha p) {
        if (empty(p)) {
            return null;
        } else {
            return p.getTopo().getPalavra();
        }
    }

    public static boolean empty(Pilha p) {
        return p.getTopo() == null;
    }

    public static void main(String[] args) {
        Pilha p = criaPilha();

        String[] palavras = {"eduardocpf", "eduardocpa", "eduardocpb", "eduardocpc", "eduardocpd"};

        for (String palavra : palavras) {
            push(p, palavra);
        }

        while (!empty(p)) {
            System.out.println("Saiu do topo: " + pop(p));
        }
    }
}