package jogo;

import static java.lang.Math.ceil;

public class naveInimiga extends nave{

    private int valorScore;
    private int linhaInimiga; // armazena qual linha a nave faz parte
    private int colunaInimiga; // armazena qual coluna a nave faz parte
    
    //30 de comprimeto, 20 de altura
    public naveInimiga(int x, int y, int valorScore, int linhaInimiga, int colunaInimiga, String caminho) {
        super(x, y, 30, 20);
        loadImagem(caminho);
        this.valorScore = valorScore;
        this.linhaInimiga = linhaInimiga;
        this.colunaInimiga = colunaInimiga;
    }

    @Override
    public disparo criarDisparo() {
        return new disparo(x + (int) ceil( width / 2) , y + height,1);
    }
    
    public int getScore()
    {
        return valorScore;
    }
}