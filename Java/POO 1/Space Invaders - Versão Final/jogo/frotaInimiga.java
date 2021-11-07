package jogo;

import java.awt.Rectangle;
import java.util.HashMap;

/**
 * Classe que realiza o controle sobre todas as naves inimigas (exceto a nave de evento especial)
 */
public class frotaInimiga extends Rectangle{
    // cada nave inimiga possui dimensões: 30px de largura e 20px de altura
    // 5 fileiras, 9 naves
    
    private HashMap<Integer,naveInimiga> fleet;
    private final int qtdFilas = 5;
    private final int qtdPorFila = 9;
    private int sentido;// 1 para direita, -1 para esquerda        
    
    // 5 fileiras, 9 naves
    public frotaInimiga()
    {
        // cada nave tem 20 de altura, 5 * 20 = 100 e 4 * 15 = 60. Total de 160 px
        super(80,60,390,160);
        this.sentido = 1;
        fleet = new HashMap<>();
        construirFrota();
    }
    
    /*
        550 pixels de largura
    9 naves, cada uma com 30 pixels de largura = 270 px em naves
    15 pixels entre cada nave = 15 * 8 = 120 pixels
        Total = 390 pixels
    Sobra 160 pixels para movimentar no principio
    
    Desse modo, a nave mais à direita começa na coluna 80
    
    */
    private void construirFrota()
    {
        int entreNaves = 15; //define a quantidade de colunas que separam duas naves
        int entreLinhas = 20; // define a quantidade de linhas que separam duas filas
        int linhaInicial = 60; // linha da fila superior de naves
        int colunaInicial = 80; // coluna das naves mais à direita
        
        for(int i = 0; i < qtdFilas; i++)
        {
            // 20 da altura da nave
            int linhaNave = linhaInicial + entreLinhas * i + 20 * i;
            for(int h = 0; h < qtdPorFila; h++)
            {
                // 30 da largura da nave
                int colunaNave = colunaInicial + entreNaves * h + 30 * h;
                           
                adicionarNave(i, h, colunaNave, linhaNave);
            }
        }
    }
    
    public void adicionarNave(int linha, int coluna, int x, int y)
    {                        
        int score;
        String caminho;
        
        switch(linha)
        {
            case 0:
                score = 30;
                caminho = "imagens/Inimigo_30.gif";
                break;
            case 1:
                score = 20;
                caminho = "imagens/Inimigo_20.gif";
                break;                
            case 2:
                score = 20;
                caminho = "imagens/Inimigo_20.gif";
                break;                
            case 3:
                score = 10;
                caminho = "imagens/Inimigo_10.gif";
                break;
            case 4:
                score = 10;
                caminho = "imagens/Inimigo_10.gif";
                break;
            default:
                score = 0;
                caminho = "imagens/Inimigo_10.gif";
        }
        
        naveInimiga n = new naveInimiga(x,y,score,linha,coluna,caminho);
        
        int key = linha* 10 + coluna;
        fleet.put(key, n);
        // no caso de uma nave com mesmo codigo, essa nave é sobreescrita.
    }
    
    public int ColunaNaveAEsquerda()
    {
        for(int h = 0; h < qtdPorFila; h++)
        {
            for(int i = 0; i < qtdFilas; i++)
            {
                int key = i * 10 + h;
                if(fleet.containsKey(key))
                {
                    return fleet.get(key).x;
                    // é retornada a coluna da nave mais à esquerda
                }
            }
        }    
        return -1;// nesse caso já não existe nave inimiga viva
    }
    
    public int ColunaNaveADireita()
    {
        for(int h = qtdPorFila - 1; h >= 0; h--)        
        {
            for(int i = 0; i < qtdFilas; i++)
            {
                int key = i * 10 + h;
                if(fleet.containsKey(key))
                {
                    return fleet.get(key).x;
                    // é retornada a coluna da nave mais à direita (sem considerar o tamanho dela)
                }
            }
        }    
        
        return -1;// nesse caso já não existe nave inimiga viva
    }
    
    public int LinhaNaveMaisBaixa()
    {
        for(int i = qtdFilas - 1; i >= 0; i--)
        {
            for(int h = 0; h < qtdPorFila; h++)
            {
                int key = i * 10 + h;
                if(fleet.containsKey(key))
                {
                    return fleet.get(key).y;
                    // é retornada a linha da nave mais embaixo (sem considerar o tamanho dela)
                }
            }
        }
        
        return -1; // nesse caso já não existe nave inimiga viva
    }
    
    
    public void moverFrota(int movimentoHorizontal, int movimentoVertical)
    {
        movimentoVertical = Math.abs(movimentoVertical);
        movimentoHorizontal = Math.abs(movimentoHorizontal);
        
        if(sentido == 1)            // direita
        {
            if(ColunaNaveADireita() + 30 + movimentoHorizontal * sentido >= 540)
            {
                sentido = -1;
                //muda o sentido de movimentação
                
                //as naves descem um pouco
                Object keyset[] = fleet.keySet().toArray();
                for(Object obj : keyset)
                {
                    naveInimiga n = fleet.get((Integer) obj);
                    n.movimento(movimentoVertical, false);
                    fleet.replace((Integer)obj, n);
                }
                
                this.y += movimentoVertical;// movimenta o rectangle que engloba todos os inimigos
            }
            else
            {
                //movimenta à direita
                Object keyset[] = fleet.keySet().toArray();
                    
                for(Object obj : keyset)
                {
                    naveInimiga n = fleet.get((Integer) obj);
                    n.movimento(movimentoHorizontal, true);
                    fleet.replace((Integer)obj, n);
                }
                
                this.x += movimentoHorizontal;// movimenta o rectangle que engloba todos os inimigos
            }
        }
        else if(sentido == -1)      // esquerda
        {
            if(ColunaNaveAEsquerda() + movimentoHorizontal * sentido <= 0)
            {
                sentido = 1;
                // muda o sentido de movimentação
                
                //as naves descem um pouco
                Object keyset[] = fleet.keySet().toArray();
                    
                for(Object obj : keyset)
                {
                    naveInimiga n = fleet.get((Integer) obj);
                    n.movimento( movimentoVertical, false);
                    fleet.replace((Integer)obj, n);
                }

                this.y += movimentoVertical;// movimenta o rectangle que engloba todos os inimigos
            }
            else
            {
                //movimenta à esquerda
                Object keyset[] = fleet.keySet().toArray();
                    
                for(Object obj : keyset)
                {
                    naveInimiga n = fleet.get((Integer) obj);
                    n.movimento( -movimentoHorizontal, true);
                    fleet.replace((Integer)obj, n);
                }
                
                this.x -= movimentoHorizontal;// movimenta o rectangle que engloba todos os inimigos
            }
        }
    }
    
    
    // na classe de jogo verifica se o disparo colide.
    // se colidir, chama esse método para verificar se ocorre realmente uma colisão
    // se sim, elimina a nave que foi atingida
        // e retorna 0, se nada tiver sido atingido, ou o score da nave destruida
    public int colisao(disparo d)
    {
        Object[] vet = fleet.keySet().toArray();
        int score = 0;
        
        for(Object key : vet)
        {
            naveInimiga ni = fleet.get( (Integer) key);
            
            if(d.intersects(ni))
            {
                score = ni.getScore();
                fleet.remove( (Integer) key);
                
                return score;
            }
        }
        
        return 0;
    }
    
    public disparo disparar(naveJogador nj)
    {
        int colunaEsquerdaDoJogador = nj.x;
        int colunaDireitaDoJogador = nj.x + 40;
        
        for(int i = qtdFilas - 1; i >= 0; i--)
        {
            for(int h = 0; h < qtdPorFila; h++)
            {
                int key = i * 10 + h;
                if(fleet.containsKey(key))
                {
                    naveInimiga ni = fleet.get(key);

                    if(colunaEsquerdaDoJogador - 15 <= ni.x && ni.x  + 30 <= colunaDireitaDoJogador + 15)
                    
                        return ni.criarDisparo();
                }
            }
        }
        
        return null;// é pq todas as naves foram destruídas
    }
    
    
    public int getTotalVivas()
    {
        return fleet.size();
    }

    public HashMap<Integer, naveInimiga> getFleet() {
        return fleet;
    }
}
