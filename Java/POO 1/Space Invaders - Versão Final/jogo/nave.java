package jogo;

import java.awt.Image;
import java.awt.Rectangle;
import javax.swing.ImageIcon;

public abstract class nave extends Rectangle{

    protected Image imagem;
    
    public nave(int x, int y, int width, int height)
    {
        super(x,y,width,height);
    }
    
    public void loadImagem(String caminho)
    {
        ClassLoader cl = this.getClass().getClassLoader();        
        ImageIcon sprite = new ImageIcon(cl.getResource(caminho));
        imagem = sprite.getImage();
    }
    
    public Image getImagem()
    {
        return imagem;
    }
    
    // true pra horizontal, false pra vertical
    public void movimento(int qtd, boolean direcao)
    {
        // qtd negativo vai pra esquerda, qtd positivo pra direita
        if(direcao)
        {
            if(0 <= x + qtd && x + qtd < 510)// 550 - 40 para que não saia da tela
                this.setLocation(x + qtd, y);
        }
        else
        {
            if(y + qtd <= 480) // o valor da direita é o limite mínimo para as naves inimigas
                this.setLocation(x, y + qtd);
        }
    }
    
    
    public abstract disparo criarDisparo();
}
