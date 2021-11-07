package c;

import java.util.HashMap;
import java.util.Random;

public class matriz {
    private int mat[][] = new int[20][20];
    private HashMap<Integer,Integer> frequencia = new HashMap<Integer,Integer>();
    private Random aleatorio = new Random(); 
    
    public matriz ()
    {
        for(int i=0; i < 20; i++)
        {
            for(int j=0; j< 20; j++)
            {
                alterarPosicao(i,j,aleatorio.nextInt(256));
            }
        }
    }
    
    public void alterarPosicao(int linha, int coluna, int valor)
    {
        if(valor < 0 || valor > 255)
            throw new RuntimeException("Erro: Valor fora do escopo (0 à 255).");
        else if(linha < 0 || coluna < 0 || linha >= 200 || coluna >= 200)
            throw new RuntimeException("Erro: Coordenadas inválidas");
        else
            mat[linha][coluna] = valor;
    }
    
    public int getPosicao(int linha, int coluna)
    {
        if(linha < 0 || coluna < 0 || linha >= 200 || coluna >= 200)
            throw new RuntimeException("Erro: Coordenadas inválidas");
        else
            return mat[linha][coluna];
    }
    
    public HashMap<Integer,Integer> getListaFrequencia()
    {
        calcularListaFrequencia();
        return frequencia;
    }
    
    private void calcularListaFrequencia()
    {
        int indice;
        
        frequencia.clear();
        for(int i=0; i < 20; i++)
        {
            for(int j=0; j< 20; j++)
            {
                indice = mat[i][j];
                
                if(frequencia.containsKey(indice))//chave já existente
                    frequencia.replace(indice, frequencia.get(indice) + 1);
                else
                    frequencia.put(indice, 1);//primeia ocorrência
            }
        }
    }
    
    public int[][] getMatriz()
    {
        return mat;
    }
}
