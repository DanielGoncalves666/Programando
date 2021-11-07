package a;

import java.util.Scanner;

public class principal {
        
    public static void main (String args[])
    {
        int MAX = 5;
        
        Scanner sc = new Scanner(System.in);
        vendedor[] Vendedores = new vendedor[MAX];
        administrador[] Administradores = new administrador[MAX];
        
        int op;
        
        String nome, RG;
        double salario,vendas;
        int horas, escolha;
        
        do
        {
            System.out.println();
            System.out.println("---- Menu ----");
            System.out.println("1 - Entrar com dados de um vendedor.");
            System.out.println("2 - Entrar com dados de um administrador.");
            System.out.println("3 - Adicionar vendas a um vendedor.");
            System.out.println("4 - Adicionar horas extras a um administrador.");
            System.out.println("5 - Pagar salário do funcionário.");
            System.out.println("6 - Mostrar vendedores.");
            System.out.println("7 - Mostrar administradores.");
            System.out.println("8 - Sair");

            op = sc.nextInt();
            sc.nextLine();
            
            
            switch(op)
            {
                case 1:
                    if(vendedor.getQtd() >= MAX)
                    {
                        System.out.println("Máximo de vendedores atingido");
                    }
                    else
                    {
                        System.out.println("Entre com o nome: ");
                        nome = sc.nextLine();

                        System.out.println("Entre com o RG: ");
                        RG = sc.nextLine();

                        System.out.println("Entre com o salario: ");
                        salario = sc.nextDouble();
                        sc.nextLine();

                        vendedor v1 = new vendedor(nome,RG,salario);
                        Vendedores[vendedor.getQtd() - 1] = v1;
                    }
                    
                    break;
                case 2:
                    if(administrador.getQtd() >= MAX)
                    {
                        System.out.println("Máximo de administradores atingido");
                    }
                    else
                    {
                        System.out.println("Entre com o nome: ");
                        nome = sc.nextLine();

                        System.out.println("Entre com o RG: ");
                        RG = sc.nextLine();

                        System.out.println("Entre com o salario: ");
                        salario = sc.nextDouble();
                        sc.nextLine();

                        administrador v2 = new administrador(nome,RG,salario);
                        Administradores[administrador.getQtd() - 1] = v2;
                    }
                    
                    break;
                case 3:
                    
                    System.out.println();
                    System.out.println("Vendedores Registrados:");
                    for(int i=0; i < vendedor.getQtd(); i++)
                    {
                        System.out.print((i + 1)+" - ");
                        Vendedores[i].mostrar();
                        System.out.println();
                    }
                    
                    System.out.println();
                    System.out.println("Digite o número do vendedor:");
                    escolha = sc.nextInt();
                    sc.nextLine();
                    
                    if( escolha - 1 < 0 || escolha - 1 >= vendedor.getQtd())
                    {
                        System.out.println("Vendedor inexistente.");
                    }
                    else
                    {
                        System.out.println("Digite o valor das vendas a ser somado:");
                        vendas = sc.nextDouble();
                        sc.nextLine();
                        
                        Vendedores[escolha - 1].acumularVendas(vendas);
                    }
                   
                    break;
                case 4:
                    System.out.println();
                    System.out.println("Administradores Registrados:");
                    for(int i=0; i < administrador.getQtd(); i++)
                    {
                        System.out.print((i + 1)+" - ");
                        Administradores[i].mostrar();
                        System.out.println();
                    }
                    
                    System.out.println();
                    System.out.println("Digite o número do administrador:");
                    escolha = sc.nextInt();
                    sc.nextLine();
                    
                    if( escolha - 1 < 0 || escolha - 1 >= administrador.getQtd())
                    {
                        System.out.println("Administrador inexistente.");
                    }
                    else
                    {
                        System.out.println("Digite o valor das horas extras a ser somado:");
                        horas = sc.nextInt();
                        sc.nextLine();
                        
                        Administradores[escolha - 1].acumularHoras(horas);
                    }
                   
                    break;
                case 5:
                    System.out.println();
                    do
                    {
                        System.out.println("1 - Vendedor.");
                        System.out.println("2 - Administrador.");
                        escolha = sc.nextInt();
                        sc.nextLine();
                        
                        if(escolha == 1 || escolha == 2)
                            break;
                        else
                            System.out.println("Opção Inválida.");
                                     
                    }while(true);    
                        
                    if(escolha == 1)
                    {
                        System.out.println();
                        System.out.println("Vendedores Registrados:");
                        for(int i=0; i < vendedor.getQtd(); i++)
                        {
                            System.out.print((i + 1)+" - ");
                            Vendedores[i].mostrar();
                            System.out.println();
                        }

                        System.out.println();
                        System.out.println("Digite o número do vendedor:");
                        escolha = sc.nextInt();
                        sc.nextLine();
                    
                        if( escolha - 1 < 0 || escolha - 1 >= vendedor.getQtd())
                        {
                            System.out.println("Vendedor inexistente.");
                        }
                        else
                        {
                            salario = Vendedores[escolha - 1].salarioFinal();
                            
                            System.out.printf("O vendedor %d vai receber um salário de %.2f reais",escolha, salario);
                        }
                    }
                    else
                    {
                        System.out.println();
                        System.out.println("Administradores Registrados:");
                        for(int i=0; i < administrador.getQtd(); i++)
                        {
                            System.out.print((i + 1)+" - ");
                            Administradores[i].mostrar();
                            System.out.println();
                        }

                        System.out.println();
                        System.out.println("Digite o número do administrador:");
                        escolha = sc.nextInt();
                        sc.nextLine();
                    
                        if( escolha - 1 < 0 || escolha - 1 >= administrador.getQtd())
                        {
                            System.out.println("Adminsitrador inexistente.");
                        }
                        else
                        {
                            salario = Administradores[escolha - 1].salarioFinal();
                            
                            System.out.printf("O administrador %d vai receber um salário de %.2f reais",escolha, salario);
                        }
                    }
                     
                    break;
                case 6:
                    System.out.println();
                    System.out.println("Vendedores Registrados:");
                    for(int i=0; i < vendedor.getQtd(); i++)
                    {
                        System.out.print((i + 1)+" - ");
                        Vendedores[i].mostrar();
                        System.out.println();
                    }
                    break;
                case 7:
                    System.out.println();
                    System.out.println("Administradores Registrados:");
                    for(int i=0; i < administrador.getQtd(); i++)
                    {
                        System.out.print((i + 1)+" - ");
                        Administradores[i].mostrar();
                        System.out.println();
                    }
                    break;
            }
            
            
        }while(op != 8);
    }
}
