package lista2;

import java.util.Scanner;

public class TempoPrincipal {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        Tempo t = new Tempo(0,0,0);
        int op;
        int h,m,s;
        
        do
        {
            System.out.println("---- Menu ----");
            System.out.println("1 - Setar Relogio.");
            System.out.println("2 - Imcrementar em um minuto.");
            System.out.println("3 - Decrementar em um minuto.");
            System.out.println("4 - Mostrar hora no formato 24hrs.");
            System.out.println("5 - Mostrar hora no formato 12hrs.");
            System.out.println("6 - Sair.");
            System.out.println("Entre com a opção desejada:");
            
            op = sc.nextInt();
            sc.nextLine();
            
            switch(op)
            {
                case 1:
                    System.out.println("Entre com as horas (valores inválidos são setados em zero):");
                    h = sc.nextInt();
                    sc.nextLine();
                    
                    System.out.println("Entre com os minutos (valores inválidos são setados em zero):");
                    m = sc.nextInt();
                    sc.nextLine();
                    
                    System.out.println("Entre com os segundos (valores inválidos são setados em zero):");
                    s = sc.nextInt();
                    sc.nextLine();
                    
                    t.setHora(h);
                    t.setMinuto(m);
                    t.setSegundo(s);
                    
                    break;
                case 2:
                    t.incrementarMinuto();
                    
                    break;
                case 3:
                    t.decrementaMinuto();
                    
                    break;
                case 4:
                    t.mostrar24();
                    
                    break;
                case 5:
                    t.mostrar12();
                    
                    break; 
            }
        }while(op != 6);    
    }
}
