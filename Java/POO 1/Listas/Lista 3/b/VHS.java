package b;

public class VHS extends Video{
    private boolean rebobinada;
    
    public VHS (String nome, boolean tipo, String genero, int ano, int copias, double preco, String[] atores, String diretor, int tempo, int classificacaoEtaria, boolean rebobinada)
    {
        super(nome,tipo,genero,ano,copias,preco, atores, diretor, tempo, classificacaoEtaria);
        this.rebobinada = rebobinada;
    }

    public boolean isRebobinada() {
        return rebobinada;
    }
    
    public void VHS()
    {
        super.mostra();
        
        if(rebobinada)
            System.out.println("Rebobinada: Sim.");
        else
            System.out.println("Rebobinada: Não.");
    }
}
