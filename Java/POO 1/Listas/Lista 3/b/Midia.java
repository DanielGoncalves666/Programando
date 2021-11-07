package b;

public class Midia {
    private String nome;
    private boolean tipo; // true - aúdio / false -vídeo
    private String genero;
    private int ano;
    private int copias;
    private double preco;
    
    public Midia (String nome, boolean tipo, String genero, int ano, int copias, double preco)
    {
        this.nome = nome;
        this.tipo = tipo;
        this.genero = genero;
        this.ano = ano;
        setCopias(copias);
        setPreco(preco);
    }

    public void setCopias(int copias) {
        if(copias < 0)
            this.copias = 0;
        else
            this.copias = copias;
    }

    public void setPreco(double preco) {
        if(preco < 0.0)
            this.preco = 0.0;
        else
            this.preco = preco;
    }

    public String getNome() {
        return nome;
    }

    public boolean getTipo() {
        return tipo;
    }

    public String getGenero() {
        return genero;
    }

    public int getAno() {
        return ano;
    }

    public int getCopias() {
        return copias;
    }

    public double getPreco() {
        return preco;
    }
    
    public void mostra()
    {
        System.out.println("Nome: "+nome);
        System.out.println("Genero: "+genero);
        System.out.print("Tipo: ");
        if(tipo)
            System.out.println("audio.");
        else
            System.out.println("video.");
        System.out.println("Ano: "+ano);
        System.out.println("Cópias: "+copias);
        System.out.println("Preõ: "+preco);
  
    }
}
