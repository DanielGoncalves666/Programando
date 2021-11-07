package b;

import java.util.HashMap;

public class mapa{
    
    private HashMap<String,Empregado> ls = new HashMap<>(5);
    private int quantidade;
    
    public mapa()
    {
        quantidade = 0;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public HashMap<String,Empregado> getLs() {
        return ls;
    }
    
    public void adicionarEmpregado(Empregado novo)
    {
        if(quantidade == 5)
            throw new RuntimeException("Quantidade máxima atingida!");
        else if(ls.containsKey(novo.getCPF()))
            throw new RuntimeException("CPF já existente");
        else
        {
           ls.put(novo.getCPF(), novo);
           quantidade++;
        }
    }
    
    public Empregado encontraCPF(String CPF)
    {
        if(! ls.containsKey(CPF))
            throw new RuntimeException("Empregado não encontrado.");

        return ls.get(CPF);
    }
    
    public Empregado possueSalarioMenor()
    {
        mapa vet = new mapa();
        Object[] keySet = ls.keySet().toArray();
        String menor = new String();
        
        for(int i=0; i<quantidade; i++)
        {
            if(i == 0)
                menor = keySet[i].toString();
            else
            {
                if(ls.get(menor).getSalario() > ls.get(keySet[i].toString()).getSalario())
                {
                    menor = keySet[i].toString();
                }
            }  
        }
        
        return ls.get(menor);
    }
    
    public Empregado possueSalarioMaior()
    {
        mapa vet = new mapa();
        Object[] keySet = ls.keySet().toArray();
        String maior = new String();
        
        for(int i=0; i<quantidade; i++)
        {
            if(i == 0)
                maior = keySet[i].toString();
            else
            {
                if(ls.get(maior).getSalario() < ls.get(keySet[i].toString()).getSalario())
                {
                    maior = keySet[i].toString();
                }
            }  
        }
        
        return ls.get(maior);
    }
}
