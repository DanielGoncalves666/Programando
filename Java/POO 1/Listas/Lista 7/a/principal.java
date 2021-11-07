package a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class principal {

    public static void lerArquivos(String nome, String nome2, mapaFuncionarios mapa)
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
                funcionario f = new funcionario(vetor[0], Double.valueOf(vetor[1]));
                mapa.adicionar(vetor[0], f);
            }
            arquivo.close();
            
            arquivo = new BufferedReader(new FileReader(new File(nome2)));
            while((linha = arquivo.readLine()) !=  null)
            {
                vetor = linha.split(" ");
                
                try
                {
                    mapa.alterar(vetor[0], Double.valueOf(vetor[1]));
                }
                catch(RuntimeException e)
                {
                    System.out.println("Funcionário com esse CPF não teve salário incluído anteriormente.");
                }
            }
            arquivo.close();
            
        }
        catch(java.io.IOException e)
        {
            System.out.println("File error:" + e.getMessage());
        }
    }
    
    public static void escreverArquivo(String nome, mapaFuncionarios mapa)
    {
        Object[] valores = mapa.valores().toArray();
        BufferedWriter arquivo;
        String linha;
        
         try
        {
            arquivo = new BufferedWriter(new FileWriter(new File(nome)));
            
            for (Object valor : valores) {
                double salarioLiquido = mapa.getFuncionario(valor.toString()).salarioLiquido();
                
                linha = valor.toString() + " R$" + salarioLiquido + "\n";
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
    
    public static void main(String args[])
    {
        mapaFuncionarios mapa = new mapaFuncionarios();
        
        lerArquivos("salbruto.dat","desc.dat",mapa);
        escreverArquivo("salliq.txt",mapa);
        
    }
    
}
