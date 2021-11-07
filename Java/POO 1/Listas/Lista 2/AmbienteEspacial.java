package lista2;

import java.util.Scanner;

public class AmbienteEspacial {

    public static Scanner sc = new Scanner(System.in);
    private static NaveEspacial naves[] = new NaveEspacial[5];

    public static void criarNave()
    {
        if(NaveEspacial.getQtd() == 5)
            System.out.println("Quantidade máxima atingida.");
        else
        {                   
            NaveEspacial novo;
                    
            if(NaveEspacial.getQtd() >= 3)
            {
                novo = new NaveEspacial("Nave com defeito");
                novo.setVelocidade(0);
                        
                naves[NaveEspacial.getQtd() - 1] = novo;
            }
            else
            {
                System.out.println("Entre com o nome da nave:");
                        
                novo = new NaveEspacial(sc.nextLine());
                        
                naves[NaveEspacial.getQtd() - 1] = novo;
            }
        }
    }
    
    public static void mostrarNave(int indice)
    {
        if(indice < 0 || indice >= NaveEspacial.getQtd())
            System.out.println("Nave inexistente.");
        else
        {
            System.out.println("---- Nave "+(indice + 1)+" ----");
            System.out.println("Nome: "+naves[indice].getNome());
            System.out.print("Velocidade: "+naves[indice].getVelocidade());
            
            if(naves[indice].getVelocidade() == 0)
                System.out.println(" (Nave inoperante)");
            else
                System.out.println();
        }
    }

    public static void main(String args[])
    {           
        int op;
        
        do
        {
            System.out.println();
            System.out.println("---- Menu ----");
            System.out.println("1 - Criar nova nave.");
            if(NaveEspacial.getQtd() >= 3)
                System.out.println("Superpopulação de Naves");
            System.out.println("2 - Exibir naves existentes.");
            System.out.println("3 - Nave mais rápida.");
            System.out.println("4 - Sair");
            
            op = sc.nextInt();
            sc.nextLine();
            
            switch(op)
            {
                case 1:
                    criarNave();
                    
                    break;
                case 2:
                    
                    System.out.println();
                    for(int i = 0; i < NaveEspacial.getQtd(); i++)
                    {
                        mostrarNave(i);
                        System.out.println();
                    }
                
                    break;
                
                case 3:
                    System.out.println("Entre com a nave base.");
                    int n = sc.nextInt() - 1;
                    sc.nextLine();
                    
                    if( n < 0 || n >= NaveEspacial.getQtd())
                    {
                        System.out.println("Nave inexistente.");
                        break;
                    }
                    
                    System.out.println("Entre com a nave secundaria.");
                    int m = sc.nextInt() - 1;
                    sc.nextLine();
                    
                    if( m < 0 || m >= NaveEspacial.getQtd())
                    {
                        System.out.println("Nave inexistente.");
                        break;
                    }
                    
                   boolean result = naves[n].naveMaisRapida(naves[m]);
                   
                   if(result)
                       System.out.println("A nave "+(m + 1)+" é mais rápida.");
                   else
                       System.out.println("A nave "+(n + 1)+" é mais rápida.");
            }
                    
        }while(op != 4);    
    }
    
}
