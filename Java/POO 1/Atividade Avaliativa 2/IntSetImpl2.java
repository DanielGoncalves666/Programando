package exercicioavaliativo2;


public class IntSetImpl2 extends IntSetImpl{
    
    public IntSetImpl2 (int tamanho)
    {
        super(tamanho);
    }
    
    public int somarConjunto()
    {
        int soma = 0;
        
        for(int i=0; i < size(); i++)
        {
            soma += vetor[i];
        }
        
        return soma;
    }
    
    public IntSetImpl2 intersecao(IntSetImpl2 c)
    {
        // é criado um conjunto com um vetor que possui a quantidade mínima de elementos
        IntSetImpl2 intersecao = new IntSetImpl2( (ehMaiorConjunto(c)) ? c.size() :this.size());
    
        for(int i = 0; i < this.size(); i++)
        {
            if(c.isln(vetor[i]))
                intersecao.insert(vetor[i]);
        }
    
        return intersecao;
    }
    
    public IntSetImpl2 uniao(IntSetImpl2 c)
    {
        //no máximo a soma da quantidade de elementos dos dois conjuntos
        IntSetImpl2 uniao = new IntSetImpl2( this.size() + c.size());
        
        for(int i = 0; i < this.size(); i++)
        {
            //adiciona os elementos que estão apenas no conjunto do objeto que chamou
            if(! c.isln(vetor[i]))
            {
                uniao.insert(vetor[i]);
            }
        }
        
        //adiciona os elementos que estão apenas no conjunto c e que estão em ambos
        uniao.insertAll(c.vetor);
        return uniao;
    }
    
    private boolean ehMaiorConjunto(IntSetImpl2 c)
    {
        return (this.size() >= c.size());
    }
    
    public void mostrarConjunto()
    {
        System.out.print("Conjunto: ");
        for(int i = 0; i < this.size(); i++)
        {
            System.out.print(vetor[i]+" ");
        }
        
        System.out.println();
    }
    
    
}
