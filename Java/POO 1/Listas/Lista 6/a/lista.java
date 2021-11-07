package a;

import java.util.ArrayList;
import java.util.Collections;

public class lista{
    
    private ArrayList<Empregado> ls = new ArrayList<Empregado>(5);
    private int quantidade;
    
    public lista()
    {
        quantidade = 0;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public ArrayList<Empregado> getLs() {
        return ls;
    }
    
    public void adicionarEmpregado(Empregado novo)
    {
        if(quantidade == 5)
            throw new RuntimeException("Quantidade máxima atingida!");
        else
        {
           ls.add(novo); 
           quantidade++;
        }
    }
    
    public Empregado encontraCPF(String CPF)
    {
        for(int i=0; i<quantidade; i++)
        {
            Empregado e = ls.get(i);
            
            if((e.getCPF()).equals(CPF))
            {
                return e;
            }
        }
        
        throw new RuntimeException("Empregado não encontrado.");
    }
    
    public lista possuemSalarioMaiorQue(double salario)
    {
        lista vet = new lista();
        
        for(int i=0; i<quantidade; i++)
        {
            Empregado e = ls.get(i);
            
            if(e.getSalario() >= salario)
            {
                vet.adicionarEmpregado(e);
            }
        }
        
        return vet;
    }
    
    
    public void organizar()
    {
        Collections.sort(ls, new organizarIdade());
    }
}
