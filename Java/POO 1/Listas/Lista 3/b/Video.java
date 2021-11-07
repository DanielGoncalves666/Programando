package b;

public class Video extends Midia {
    private String[] atores; 
    private String diretor;
    private int tempo;
    private int classificacaoEtaria;
    
    public Video (String nome, boolean tipo, String genero, int ano, int copias, double preco, String[] atores, String diretor, int tempo, int classificacaoEtaria)
    {
        super(nome,tipo,genero,ano,copias,preco);
        this.atores = atores;
        this.diretor = diretor;
        this.tempo = tempo;
        this.classificacaoEtaria = classificacaoEtaria;
    }

    public String[] getAtores() {
        return atores;
    }

    public String getDiretor() {
        return diretor;
    }

    public int getTempo() {
        return tempo;
    }

    public int getClassificacaoEtaria() {
        return classificacaoEtaria;
    }
    
    public void mostra()
    {
        super.mostra();
        
        System.out.println("Atores : [");
        for(String a: atores)//parecido com o for do python
            System.out.println(" "+a+" ");
        
        System.out.println("]");
        System.out.println("Diretor: "+diretor);
        System.out.println("Duracao: "+tempo);
        System.out.println("Classificacao: "+classificacaoEtaria);
    }
}
