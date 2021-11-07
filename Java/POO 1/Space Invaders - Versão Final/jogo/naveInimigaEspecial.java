package jogo;

import static java.lang.Math.ceil;

public class naveInimigaEspecial extends nave{
    private final int valorScore;

    public naveInimigaEspecial() {
        //a nave sempre começa na linha 9, coluna 0
        super(0, 9, 30, 20);
        this.valorScore = 100;
        loadImagem("imagens/Inimigo_100.gif");
    }

    @Override
    public disparo criarDisparo() {
        return new disparo(x + (int) ceil( width / 2) , y + height,1);
    }
    
    public int getScore()
    {
        return valorScore;
    }
    
    // false indicará que a nave deve ser tirada do jogo
    public boolean moverDireita(int qtd)
    {
        if(this.x + qtd >= 510)
            return false;
        
        this.movimento(qtd, true);
        return true;
    }
}
