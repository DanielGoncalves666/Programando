package lista1;

import java.util.Scanner;

public class clienteMain {

    public static void main(String args[])
    {
        cliente cliente = new cliente();
        Scanner sc = new Scanner(System.in);
        
        String name;
        String cpf;
        int idade;
        String telefone;
        
        System.out.println("Entre com o nome do cliente.");
        name = sc.nextLine();
        System.out.println("Entre com o cpf.");
        cpf = sc.nextLine();
        System.out.println("Entre com a idade.");
        idade = sc.nextInt();
        sc.nextLine();
        System.out.println("Entre com o telefone.");
        telefone = sc.nextLine();
        
        cliente.CadastrarCliente(name,cpf,idade,telefone);
        cliente.MostrarDadosCliente();
        
    }
    
}
