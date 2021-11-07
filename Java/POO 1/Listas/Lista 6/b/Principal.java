package b;

import java.util.HashMap;
import java.util.Scanner;

public class Principal{
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        mapa ls = new mapa();
        Empregado emp;
        mapa vet = new mapa();
        int op;
        
        for(int i = 0; i < 5;)
        {
            System.out.println("Entre com o Empregado "+(i + 1)+": ");
            
            try
            {
                System.out.print("CPF: ");
                String s = sc.nextLine();

                System.out.print("Idade: ");
                int idade = sc.nextInt();
                sc.nextLine();

                System.out.print("Salario: ");
                double d = sc.nextDouble();
                sc.nextLine();
                
                emp = new Empregado(s,idade,d);
            }
            catch(RuntimeException e)
            {
                System.out.println(e.getMessage());
                continue;
            }
            catch(Exception e1)
            { 
                System.out.println("Erro de entrada.");
                continue;
            }
            
            ls.adicionarEmpregado(emp);
            i++;
        }
        
        do
        {
            System.out.println("---- Menu ---- ");
            System.out.println("1 - Buscar CPF.");
            System.out.println("2 - Empregado com o menor salário.");
            System.out.println("3 - Empregado com o maior salário.");
            System.out.println("4 - Imprimir Lista.");
            System.out.println("5 - Sair.");
            
            op = sc.nextInt();
            sc.nextLine();
            
            switch(op)
            {
                case 1:
                    System.out.println("Entre com o CPF:");
                    String s = sc.nextLine();
                    
                    try
                    {
                        emp = ls.encontraCPF(s);
                    }
                    catch(RuntimeException e)
                    {
                        System.out.println(e.getMessage());
                        break;
                    }
                    
                    System.out.println(emp.imprimir());
                    
                    break;
                case 2:
                    emp = ls.possueSalarioMenor();
                    
                    System.out.println(emp.imprimir());
                    
                    break;
                case 3:
                    emp = ls.possueSalarioMaior();
                    
                    System.out.println(emp.imprimir());
                    
                    break;
                case 4:
                    HashMap<String,Empregado>  l = ls.getLs();
                    Object[] keySet = l.keySet().toArray();

                    
                    for(int i = 0; i < ls.getQuantidade(); i++)
                    {
                        System.out.println(l.get(keySet[i].toString()).imprimir());
                    }

                    break;
                case 5:
                    break;
                default:
                    System.out.println("Opção inválida.");
            }
            
            
        }while(op != 5);
        
        
    }
}
