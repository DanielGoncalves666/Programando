package e;

import java.util.HashMap;


//como regra de negócio estaremos considerando dois contatos iguais como aqueles q possuem mesmo nome.
public class GestaoContatos {
    HashMap<String,contato> contatos = new HashMap<>();
    
    public void adicionaContato(contato c, String chave)
    {
        if(chave.equalsIgnoreCase("familia") || chave.equalsIgnoreCase("amigos") || chave.equalsIgnoreCase("profissional"))
        {    
            contatos.put(chave, c);
        
        }else 
            throw new RuntimeException("Lista de contatos inexistente.");
        
    }
    
    private boolean existe(String chave, String nome)
    {
        return true;
    }
    
    public void eliminaContato(String chave, String nome)
    {

    }
    
    public void listaContatos(HashMap<String,contato> hs)
    {
        Object[] keySet = hs.keySet().toArray();
        
        for(int i = 0; i < hs.size(); i++)
        {
            System.out.println(hs.get(keySet[i].toString()).toString());
        }
    }
    
    public void tostring()
    {
        System.out.println("Contatos -- Família:");
        
        System.out.println("Contatos -- Amigos:");
        
        System.out.println("Contatos -- Profissional:");        
    }
    

}
