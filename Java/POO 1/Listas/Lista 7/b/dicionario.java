package b;

import java.util.HashMap;
import java.util.Set;

public class dicionario {
    HashMap<String,Integer> dic = new HashMap<>();
    private int total;
    
    public dicionario()
    {
        total = 0;
    }

    public int getTotal() {
        return total;
    }
    
    public void adicionar(String palavra)
    {
        palavra = palavra.toLowerCase();//estaremos desconsiderando a diferença entre maiúsculas e minúsculas
        
        if(dic.containsKey(palavra)) // caso a palavra já exista
        {
            dic.replace(palavra, dic.get(palavra) + 1);
        }
        else
        {
            dic.put(palavra, 1);
        }
        
        total++;
    }
    
    public void adicionarVarios(String[] vetor)
    {
        for(int i = 0; i < vetor.length; i++)
        {
            if(vetor[i].isEmpty())
                continue;
            
            vetor[i] = vetor[i].replace('.', ' ').replace(',', ' ').replace('?', ' ').trim();//remove pontos e vírgulas, algo bem básico
            
            adicionar(vetor[i]);
        }
    }
    
    public void remover(String palavra, int valor)
    {
        if(dic.containsKey(palavra))
        {
            // valores negativos indicam que queremos remover a palvra do dicionário
            if(valor < -1 || dic.get(palavra) - valor <= 0)
            {
                dic.remove(palavra);
            }
            else
            {
                dic.replace(palavra, dic.get(palavra) - valor);
            }
            
            total--;
        }
        else
        {
            throw new RuntimeException("Palavra não listada.");
        }
    }
    
    public String getPorcentagem(String palavra)
    {
        if(dic.containsKey(palavra))
        {
            float porcentagem = (dic.get(palavra) * 100) / getTotal();
            
            return palavra + ": " + porcentagem + "%.";
        }
        else
        {
            throw new RuntimeException("Palavra não listada.");
        }
    }
    
    public Set valores()
    {
        return dic.keySet();
    }
}
