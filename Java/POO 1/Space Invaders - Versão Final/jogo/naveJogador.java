package jogo;

import static java.lang.Math.ceil;

public class naveJogador extends nave{
    // 40 de comprimento, 30 de altura
    public naveJogador(int x, int y, int width, int height) {
        super(x, y, width, height);
        loadImagem("imagens/Jogador.gif");
    }

    @Override
    public disparo criarDisparo() {
        return new disparo(x + (int) ceil( width / 2) , y , 1);
    }
    
    public void setImagem(String caminho)
    {
        loadImagem(caminho);
    }
    
    
}
