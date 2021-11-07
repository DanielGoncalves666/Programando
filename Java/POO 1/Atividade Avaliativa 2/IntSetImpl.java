package exercicioavaliativo2;

public abstract class IntSetImpl implements IntSet{
    
    protected int[] vetor;
    private int qtd;
    
    //construtor
    public IntSetImpl (int tamanho)
    {
        vetor = new int[tamanho];
        qtd = 0;
    }
    
    @Override
    public void insert (int x)
    {
        if(isln(x))
            System.out.println("Número "+ x +" já existente no conjunto!");
        else if(size() == vetor.length)
            System.out.println("Quantidade máxima de elementos atingida! "+ x + " não pôde ser inserido.");
        else
        {
            vetor[qtd] = x;
            qtd++;
            System.out.println("Número "+ x +" inserido!");
        }
    }
    
    @Override
    public void insertAll (int[] v)   
    {   
        for(int i = 0; i < v.length; i++)
        {
            insert(v[i]);
        }
    }
    
    @Override
    public void remove (int x)        
    {
        if(isln(x))
        {
            int posicao = -1;
            
            for(int i = 0; i < size(); i++)
            {
                if(vetor[i] == x)
                {
                    posicao = i;
                    break;
                }
            }
            
            for(int i = posicao; i < size() - 1; i++)
            {
                vetor[i] = vetor[i + 1];
            }
            
            qtd--;
            
            System.out.println("Remoção do elemento "+ x +" bem-sucedida!");
        }
        else
        {
            System.out.println("Impossível Remover! Elemento "+ x +" não presente no conjunto.");
        }
    }
    
    @Override
    public boolean isln(int x)
    {
        for(int i = 0; i < size(); i++)
        {
            if(vetor[i] == x)
                return true;
        }
        
        return false;
    }
    
    @Override
    public int size()                 
    {
        return qtd;
    }
}
