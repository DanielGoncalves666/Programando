package d;

import java.util.ArrayList;

//como regra de negócio estaremos considerando dois contatos iguais como aqueles q possuem mesmo nome.
public class GestaoContatos {
    ArrayList<contato> familia = new ArrayList<>();
    ArrayList<contato> amigos = new ArrayList<>();
    ArrayList<contato> profissional = new ArrayList<>();

    public ArrayList<contato> getFamilia() {
        return familia;
    }

    public ArrayList<contato> getAmigos() {
        return amigos;
    }

    public ArrayList<contato> getProfissional() {
        return profissional;
    }
    
    public void adicionaContato(ArrayList<contato> ls, contato c)
    {
        if(existe(ls,c.getNome()))
            throw new RuntimeException("Contato já existe na lista.");
        else
            ls.add(c);
    }
    
    private boolean existe(ArrayList<contato> ls, String nome)
    {
        contato c;
        
        for(int i = 0; i < ls.size(); i++)
        {
            c = ls.get(i);
            
            if(c.getNome().equals(nome));
                return true;
        }
        
        return false;
    }
    
    public void eliminaContato(String nome)
    {
        boolean f, a, p;
        
        f = eliminaContatoLista(familia,nome);
        a = eliminaContatoLista(amigos,nome);
        p = eliminaContatoLista(profissional,nome);
        
        if(! f && a && p)
            throw new ContatoNaoEncontradoException();
        
    }
    
    private boolean eliminaContatoLista(ArrayList<contato> ls, String nome)
    {
        contato c;
        
        for(int i = 0; i < ls.size(); i++)
        {
            c = ls.get(i);
            
            if(c.getNome().equals(nome))
            {
                ls.remove(i);
                return true;
            }
        }
        
        return false;
    }
    
    public void listaContatos(ArrayList<contato> ls)
    {
        for(int i = 0; i < ls.size(); i++)
        {
            System.out.println(ls.get(i).toString());
        }
    }
    
    public void tostring()
    {
        System.out.println("Contatos -- Família:");
        listaContatos(familia);
        
        System.out.println("Contatos -- Amigos:");
        listaContatos(amigos);
        
        System.out.println("Contatos -- Profissional:");        
        listaContatos(profissional);
    }
    
    public contato maisVelho(ArrayList<contato> ls)
    {
        int maior = 0;
        
        for(int i = 0; i < ls.size(); i++)
        {            
            if(i == 0)
                maior = 0;
            else if(ls.get(maior).getIdade() < ls.get(i).getIdade())
                maior = i;
        }
        
        return ls.get(maior);
    }
    
    public contato maisNovo(ArrayList<contato> ls)
    {
        int menor = 0;
        
        for(int i = 0; i < ls.size(); i++)
        {            
            if(i == 0)
                menor = 0;
            else if(ls.get(menor).getIdade() > ls.get(i).getIdade())
                menor = i;
        }
        
        return ls.get(menor);
    }
}
