package lista1.banco;

import java.util.Scanner;

public class Principal {
    
    static Cliente[] clientes = new Cliente[10];
    
    static Cliente logar(Scanner sc) {
        System.out.print("Usuario: ");
        String usr = sc.nextLine();
        System.out.print("Senha: ");
        String sen = sc.nextLine();
        for (int i=0; i < Cliente.getCt();i++)
            if((clientes[i].getUsr().equals(usr)) && (clientes[i].getSen().equals(sen)))
                return clientes[i];
        return null;
    }
    
    static Conta buscaConta(int num) {
        for (int i=0;i<Cliente.getCt();i++)
            if (clientes[i].getConta().getNum() == num)
                return clientes[i].getConta();
        return null;
    }
    
    static void clientesNegativados()
    {
        int qtd = 0;
        
        System.out.println("---- Lista de Clientes Negativados ----");
        
        for(int i = 0; i < Cliente.getCt(); i++)
        {
            if(clientes[i].getConta().ehNegativo())
            {
                System.out.println("O cliente "+clientes[i].getNome()+" está negativado.");
                
                qtd++;
            }
        }
        
        if(qtd == 0)
            System.out.println("Nenhum cliente está negativado.");
    }
    
    static void clientesFaixaEtaria(int min, int max)
    {
        if(min < 0 || max > 130 || min > max)
            System.out.println("Faixa etária impossível.");
        else
        {
            int qtd = 0;
            
            System.out.println("---- Lista de Clientes com idade entre "+min+" e "+max+":");
            for(int i = 0; i < Cliente.getCt(); i++)
            {
                if(clientes[i].getIdade() >= min && clientes[i].getIdade() <=max)
                {
                    System.out.println(clientes[i].getNome());
                    
                    qtd++;
                }
            }
            
            if(qtd == 0)
                System.out.println("Nenhum cliente nessa faixa etária.");
        }
    }
    
    public static void main(String a[]) {
        Scanner sc = new Scanner(System.in);
        int op = -1;
        
        while (op != 9) {
            System.out.println("=== MENU ===");
            System.out.println("1 - Cadastrar");
            System.out.println("2 - Saldo");
            System.out.println("3 - Sacar");
            System.out.println("4 - Depositar");
            System.out.println("5 - Transferir");
            System.out.println("6 - Relatorio");
            System.out.println("7 - Lista de Clientes Negativados");
            System.out.println("8 - Clientes na faixa etária.");
            System.out.println("9 - Sair");
            op = sc.nextInt();
            sc.nextLine();
            String tipo;
            float saldo;
            String nome, CPF, telefone;
            int idade;
            String usr,sen;
            Cliente c;
            
            switch(op) {
                case 1:
                    System.out.print("Tipo da Conta: ");
                    tipo = sc.nextLine();
                    System.out.print("Saldo inicial: ");
                    saldo = sc.nextFloat();
                    sc.nextLine();                    
                    System.out.print("Nome: ");
                    nome = sc.nextLine();
                    System.out.print("CPF: ");
                    CPF = sc.nextLine();
                    System.out.print("Telefone: ");
                    telefone = sc.nextLine();
                    System.out.print("Idade: ");
                    idade = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Usuario: ");
                    usr = sc.nextLine();
                    System.out.print("Senha: ");
                    sen = sc.nextLine();
                    Conta c1 = new Conta();
                    c1.cadastraConta(tipo, saldo);
                    Cliente cli1 = new Cliente();
                    clientes[Cliente.getCt()] = cli1;
                    cli1.cadastraCliente(nome, CPF, telefone, idade, usr, sen, c1);
                    break;
                case 2:
                    c = logar(sc);
                    if (c != null) {
                        System.out.println(c.getConta().mostraSaldo());
                    }else
                        System.out.println("Acesso negado.");
                    break;
                case 3:
                    c = logar(sc);
                    if (c != null) {
                        System.out.print("Valor: ");
                        Float valor = sc.nextFloat();
                        if (c.getConta().sacar(valor))
                            System.out.println("Saque realizado com sucesso.");
                        else
                            System.out.println("Erro ao realizar o saque.");
                    }
                    break;
                case 4:
                    c = logar(sc);
                    if (c != null) {
                        System.out.print("Valor: ");
                        Float valor = sc.nextFloat();
                        if (c.getConta().depositar(valor))
                            System.out.println("Deposito realizado com sucesso.");
                        else
                            System.out.println("Erro ao realizar o saque.");
                    }
                    break;
                case 5:
                    c = logar(sc);
                    if (c != null) {
                        System.out.print("Num: ");
                        int n = sc.nextInt();
                        System.out.print("Valor: ");
                        Float valor = sc.nextFloat();
                        Conta temp = buscaConta(n);
                        if (temp != null)
                            c.getConta().transferir(valor,temp);
                    }
                    break;
                case 6:
                    for (int i=0;i<Cliente.getCt();i++) {
                        System.out.print(clientes[i].getConta().getNum()+" ");
                        System.out.print(clientes[i].getNome()+" ");
                        System.out.println(clientes[i].getConta().getSaldo());
                    }
                    break;
                case 7:
                    clientesNegativados();
                    break;
                case 8:
                    int min, max;
                    
                    System.out.println("Entre com o valor minimo:");
                    min = sc.nextInt();
                    sc.nextLine();
                    System.out.println("Entre com o valor máximo:");
                    max = sc.nextInt();
                    sc.nextLine();
                    
                    clientesFaixaEtaria(min,max);
                    break;
            }
        }
    }
}