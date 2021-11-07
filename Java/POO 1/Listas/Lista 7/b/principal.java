package b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class principal {
    
    public static void lerArquivo(String nome, dicionario dic)
    {
        BufferedReader arquivo;
        String linha;
        String vetor[];
        
        try
        {
            arquivo = new BufferedReader(new FileReader(new File(nome)));
            while((linha = arquivo.readLine()) !=  null)
            {
                vetor = linha.split(" ");
                dic.adicionarVarios(vetor);
            }
            arquivo.close();
        }
        catch(java.io.IOException e)
        {
            System.out.println("File error:" + e.getMessage());
        }
    }
    
    public static void escreverArquivo(String nome, dicionario dic)
    {
        Object[] valores = dic.valores().toArray();
        BufferedWriter arquivo;
        String linha;
        
         try
        {
            arquivo = new BufferedWriter(new FileWriter(new File(nome)));
            
            for (Object valor : valores) {
                linha = dic.getPorcentagem(valor.toString()) + "\n";
                arquivo.append(linha);
                arquivo.flush();
            }
            arquivo.close();
        }
        catch(java.io.IOException e)
        {
            System.out.println("Error of write:" + e.getMessage());
        }
    }
    
    public static void main (String args[])
    {
        dicionario dic = new dicionario();
        String nome = "arquivo.txt";
                
        lerArquivo(nome, dic);
        escreverArquivo("resultado.txt",dic);            
    }
}
