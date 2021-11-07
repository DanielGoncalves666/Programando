package a;

import java.util.HashMap;
import java.util.Set;

public class mapaFuncionarios {
    private HashMap<String,funcionario> mapa = new HashMap<>();
    private int qtd;
    
    public mapaFuncionarios()
    {
        qtd = 0;
    }
    
    public void adicionar(String CPF, funcionario f)
    {  
        mapa.put(CPF, f);
        qtd++;
    }
    
    public void alterar(String CPF, double descontos)
    {
        if(existe(CPF))
        {
            funcionario e = mapa.get(CPF);
            e.setDescontos(descontos);
            
            mapa.put(CPF, e);
        }
        else
        {
            throw new RuntimeException("Funcionário não existe.");
        }
    }
    
    public Set valores()
    {
        return mapa.keySet();
    }
    
    public boolean existe(String CPF)
    {
        return mapa.containsKey(CPF);
    }
    
    public funcionario getFuncionario(String CPF)
    {
        if(existe(CPF))
            return mapa.get(CPF);
        else
            throw new RuntimeException("Funcionário não encontrado.");
    }
}
