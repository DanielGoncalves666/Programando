package jogo;

import java.awt.Image;
import java.awt.Rectangle;
import javax.swing.ImageIcon;

public class disparo extends Rectangle{
    private Image imagem;
    private int modificadorDeDirecao; // +1 para baixo, -1 para cima
    private static final int altura = 20;
    private static final int largura = 3;
    
    public disparo(int x, int y, int direcao)
    {
        super(x,y,largura,altura);
        if(direcao < 0)
        {
            modificadorDeDirecao = -1;
            loadImagem(-1);
        }
        else
        {
            loadImagem(1);
            modificadorDeDirecao = 1;
        }
    }
    
    private void loadImagem(int dir)
    {
        ClassLoader cl = this.getClass().getClassLoader();                
        ImageIcon sprite;
        
        if(dir == -1)
        {
            sprite = new ImageIcon(cl.getResource("imagens/disparoCima.png"));
        }
        else
        {
            sprite = new ImageIcon(cl.getResource("imagens/disparoBaixo.png"));
        } 
        imagem = sprite.getImage();
    }

    public Image getImagem() {
        return imagem;
    }
    
    /**
     * Retorna true se o disparo deve ser destruido por ter atingido o fim do tabuleiro.
     * @return 
     */
    public boolean movimentarVertical(int qtd)
    {
       int novoY = y + qtd * modificadorDeDirecao;
       
       if(novoY <= -20 || novoY >= 499)
           return true;
       else
       {
            y = novoY;
            return false;
       }       
    }

    public int getModificadorDeDirecao() {
        return modificadorDeDirecao;
    }
}
