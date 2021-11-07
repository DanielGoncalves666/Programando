package a;

import java.util.ArrayList;
import java.util.Scanner;

public class Principal{
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        lista ls = new lista();
        Empregado emp;
        lista vet = new lista();
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
            System.out.println("2 - Empregados com salário superior a um valor.");
            System.out.println("3 - Ordenar lista pela idade. ");
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
                    System.out.println("Entre com o valor do salário:");
                    double d = sc.nextInt();
                    sc.nextLine();
                    
                    vet = ls.possuemSalarioMaiorQue(d);
                    
                    System.out.println("Possuem salário maior que "+d+".");
                    for(int i = 0; i < vet.getQuantidade(); i++)
                    {   
                        try
                        {
                            System.out.println((vet.getLs()).get(i).imprimir());
                    
                        }
                        catch(NullPointerException e)
                        {
                            break;
                        }
                    }
                    
                    break;
                case 3:
                    ls.organizar();
                    
                    break;
                case 4:
                    ArrayList<Empregado> l = ls.getLs();
                    
                    for(int i = 0; i < ls.getQuantidade(); i++)
                    {
                        System.out.println(l.get(i).imprimir());
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
