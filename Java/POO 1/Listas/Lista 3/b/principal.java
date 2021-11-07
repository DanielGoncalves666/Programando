package b;

import java.util.Scanner;

public class principal {
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Video[] dvds = new Video[5];
        CD[] cds = new CD[5];
        VHS[] vhs = new VHS[5];
        
        int qtdCD = 0, qtdDVD = 0, qtdVHS = 0;
        int op;
               
        do
        {
            System.out.println();
            System.out.println("---- Menu ----");
            System.out.println("1 - Criar CD.");
            System.out.println("2 - Criar DVD.");
            System.out.println("3 - Criar VHS.");
            System.out.println("4 - Mostrar.");
            System.out.println("5 - Sair");
        
            op = sc.nextInt();
            sc.nextLine();
            
            String nome, genero, diretor,Atores[];
            boolean t;
            int anoProducao, numCopias, duracao, classificacao, totalAtores;
            double preco;
            
            switch(op)
            {
                case 1:
                    nome = sc.nextLine();
                    genero = sc.nextLine();
                    t = true;
                    anoProducao = sc.nextInt();
                    sc.nextLine();
                    numCopias = sc.nextInt();
                    sc.nextLine();
                    preco = sc.nextDouble();
                    sc.nextLine();
                    String cantor = sc.nextLine();
                    int numFaixas = sc.nextInt();
                    sc.nextLine();
                    
                    CD cd = new CD(nome, t, genero, anoProducao,numCopias,preco,cantor,numFaixas);
                    
                    cds[qtdCD] = cd;
                    qtdCD++;
                    
                    break;
                case 2:
                    nome = sc.nextLine();
                    genero = sc.nextLine();
                    t = false;
                    anoProducao = sc.nextInt();
                    sc.nextLine();
                    numCopias = sc.nextInt();
                    sc.nextLine();
                    preco = sc.nextDouble();
                    sc.nextLine();
                    diretor = sc.nextLine();
                    duracao = sc.nextInt();
                    sc.nextLine();
                    classificacao = sc.nextInt();
                    sc.nextLine();
                    
                    System.out.println("Número de atores:");
                    totalAtores = sc.nextInt();
                    sc.nextLine();
                    Atores = new String[totalAtores];
                    System.out.println("Informe os atores:");
                    
                    for(int i=0; i< totalAtores; i++)
                        Atores[i] = sc.nextLine();
                    
                    Video v = new Video(nome, t, genero, anoProducao,numCopias,preco,Atores,diretor,duracao,classificacao);      
                    
                    dvds[qtdDVD] = v;
                    qtdDVD++;
                    
                    break;
                case 3:
                    nome = sc.nextLine();
                    genero = sc.nextLine();
                    t = false;
                    anoProducao = sc.nextInt();
                    sc.nextLine();
                    numCopias = sc.nextInt();
                    sc.nextLine();
                    preco = sc.nextDouble();
                    sc.nextLine();
                    diretor = sc.nextLine();
                    duracao = sc.nextInt();
                    sc.nextLine();
                    classificacao = sc.nextInt();
                    sc.nextLine();
                    
                    System.out.println("Número de atores:");
                    totalAtores = sc.nextInt();
                    sc.nextLine();
                    Atores = new String[totalAtores];
                    System.out.println("Informe os atores:");
                    
                    for(int i=0; i< totalAtores; i++)
                        Atores[i] = sc.nextLine();
                    
                    System.out.println("A fita está rebobinada? (sim/ não)");
                    String r = sc.nextLine();
                    boolean reb = false;
                    if(r.equalsIgnoreCase("sim"))
                        reb = true;
                    
                    VHS vh = new VHS(nome,t,genero,anoProducao,numCopias, preco,Atores,diretor,duracao,classificacao,reb);
                    
                    vhs[qtdVHS] = vh;
                    qtdVHS++;
                    break;
                    
                case 4:
                    System.out.println("CDS:");
                    for(int i = 0; i < qtdCD; i++)
                    {
                        cds[i].mostra();
                        System.out.println("----------------------");
                    }
                    
                    System.out.println("DVDs:");
                    for(int i = 0; i < qtdDVD; i++)
                    {
                        dvds[i].mostra();
                        System.out.println("----------------------");
                    }
                    
                    System.out.println("VHS':");
                    for(int i = 0; i < qtdVHS; i++)
                    {
                        vhs[i].mostra();
                        System.out.println("----------------------");                    
                    } 
                    break;
            }
        }while(op != 5);

    }
}
