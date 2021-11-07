package jogo;

import java.awt.Image;
import java.awt.Rectangle;
import javax.swing.ImageIcon;


public class barreira extends Rectangle{
    private Image imagem;
    private static final int altura = 50;
    private static final int largura = 50;
    private int intactos;
    private Rectangle[][] mat = new Rectangle[5][5];
    
    
    // 50 por 50 pixels
    // cada seção da barreira vai ter 10x10 pixels
    // ou seja mat[5][5]
    
    public barreira(int x, int y)
    {
        super(x,y,largura,altura);
        construirBarreira(x,y);
        loadImagem();
        intactos = 25;
    }
    
    private void loadImagem()
    {
        ClassLoader cl = this.getClass().getClassLoader(); 
        ImageIcon sprite = new ImageIcon(cl.getResource("imagens/Nuvem.png")); 
        imagem = sprite.getImage();
    }

    public Image getImagem() {
        return imagem;
    }
    
    public void construirBarreira(int x0, int y0)
    {
        int xf;
        int yf;
        
        for(int i = 0; i < 5; i++)
        {
            xf = x0 + i * 10; 
            for(int j = 0; j < 5; j ++)
            {
                yf = y0 + j * 10;
                mat[i][j] = new Rectangle(xf,yf,10,10);
            }
        }
    }
    
    // na classe de jogo verifica se o disparo colide.
    // se colidir, chama esse método para verificar se ocorre realmente uma colisão
    // se sim, destroi o Rectangle que indica aquela parte da barreira(setar coordenadas inválidas)
        // e retorna true, para que o disparo seja eliminado do ambiente de jogo
    public boolean colisao(disparo d)
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {   
                try
                {
                    if(d.intersects(mat[i][j]))
                    {
                        // torna o rectangle nessa posição invalido
                        mat[i][j] = null;
                        intactos--;
                        return true;
                    }
                }
                catch(NullPointerException e){}
                //se ocorrer essa excessão é pq aquela posição ja foi destruída
                // e nesse caso não acontece nada.
                    
            }
        }
        
        return false;
    }
    
    public boolean barreiraTotalmenteDestruida()
    {
        return intactos == 0;
    }
    
    public Rectangle[][] getMatriz()
    {
        return mat;
    }

    public int getQtdBlocosAltura() {
        return altura / 10;
    }

    public int getQtdBlocosLargura() {
        return largura / 10;
    }
}
