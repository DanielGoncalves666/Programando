package lista1;

public class cliente {
    private String Nome;
    private String Cpf;
    private int idade;
    private String Telefone;
    
    public void CadastrarCliente(String nome, String cpf, int idade, String telefone)
    {
        this.Nome = nome;
        this.Cpf = cpf;
        this.idade = idade;
        this.Telefone = telefone;
    }
    
    public void MostrarDadosCliente()
    {
        System.out.println();
        System.out.println("Nome: "+this.Nome);
        System.out.println("Cpf: "+this.Cpf);
        System.out.println("Idade: "+this.idade);
        System.out.println("Telefone: "+Telefone);
    }
}
