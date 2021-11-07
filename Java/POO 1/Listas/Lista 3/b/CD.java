package b;

public class CD extends Midia{
    private String cantor;
    private int numeroFaixas;
    
    //sem esse construtor recebemos erro. Isso ocorre pq a classe cd tenta chamar o construtor padrão de midia e este não existe
    public CD (String nome, boolean tipo, String genero, int ano, int copias, double preco, String cantor, int numeroFaixas)
    {
        super(nome,tipo,genero,ano,copias,preco);
        this.cantor = cantor;
        setNumeroFaixas(numeroFaixas);
    }

    public void setNumeroFaixas(int numeroFaixas) {
        if(numeroFaixas < 0)
            this.numeroFaixas = 1;
        else
            this.numeroFaixas = numeroFaixas;
    }

    public String getCantor() {
        return cantor;
    }

    public int getNumeroFaixas() {
        return numeroFaixas;
    }

    public void mostra()
    {
        super.mostra();
        
        System.out.println("Canto: "+cantor);
        System.out.println("Faixas: "+numeroFaixas);
    }
}
