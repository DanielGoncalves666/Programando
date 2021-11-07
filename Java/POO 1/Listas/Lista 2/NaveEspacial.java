package lista2;

import java.util.Random;

public class NaveEspacial {

    Random aleatorio = new Random();//objeto da classe random
    
    private String nome;
    private int velocidade;
    private static int qtd = 0;
    
    public NaveEspacial(String s)
    {
        if(s.isEmpty())
            nome = "USS Vazio";
        else
            nome = s;
        
        velocidade = aleatorio.nextInt(6) + 5;
        qtd++;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setVelocidade(int velocidade) {
        if(velocidade >= 0)
            this.velocidade = velocidade;
        else
            this.velocidade = 0;
        //se não estiver na faixa, a velocidade não é alterada.
    }

    public static int getQtd() {
        return qtd;
    }

    public String getNome() {
        return nome;
    }

    public int getVelocidade() {
        return velocidade;
    }
    
    public boolean naveMaisRapida(NaveEspacial dois)
    {
        if(this.velocidade < dois.getVelocidade())
            return true;
        else
            return false;
    }
}
