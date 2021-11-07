package c;

import java.util.HashMap;
import java.util.Scanner;

public class Principal3 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        matriz m = new matriz();
        
        int op;
        
        do
        {
            System.out.println("---- Menu ----");
            System.out.println("1 - Mostrar Matriz.");
            System.out.println("2 - Mostras Lista de Frequências.");
            System.out.println("3 - Alterar Posição da matriz.");
            System.out.println("4 - Sair");
            
            op = sc.nextInt();
            sc.nextLine();
            
            switch(op)
            {
                case 1:
                    int[][] mat = m.getMatriz();
                    
                    System.out.println();
                    for(int i = 0; i < 20; i++)
                    {
                        for(int j = 0; j < 20; j++)
                        {
                            System.out.print(mat[i][j] + "\t");
                        }
                        System.out.println();
                    }
                    System.out.println();
                    
                    break;
                case 2:
                    HashMap<Integer,Integer> ls = m.getListaFrequencia();
                    
                    System.out.println("---- Lista de Frequência ----");                    
                    for(int i = 0; i < 256; i++)
                    {
                        if(ls.containsKey(i))
                            System.out.println("Valor "+i+": "+ls.get(i)+".");
                        else
                            System.out.println("Valor "+i+": 0.");
                    }
                    System.out.println();                    
                    
                    break;
                case 3:
                    try
                    {
                        System.out.println("Entre com a linha:");
                        int linha = sc.nextInt();
                        sc.nextLine();

                        System.out.println("Entre com a coluna:");
                        int coluna = sc.nextInt();
                        sc.nextLine();

                        System.out.println("Entre com o valor:");
                        int valor = sc.nextInt();
                        sc.nextLine();
                        
                        m.alterarPosicao(linha, coluna, valor);
                    }
                    catch(RuntimeException e)
                    {
                        System.out.println(e.getMessage());
                    }
                    catch(Exception e1)
                    {
                        System.out.println("Erro.");
                    }
                    
                    break;
                default:
                    if(op != 4)
                        System.out.println("Opção inválida.");
            }
            
        }while(op != 4);
    }
}
