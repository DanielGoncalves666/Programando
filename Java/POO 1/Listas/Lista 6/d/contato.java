package d;

public class contato {
    private String nome;
    private int idade;
    private String sexo;
    private String profissao;
    private String telefone;
    private String email;

    public contato(String nome, int idade, String sexo, String profissao, String telefone, String email) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.profissao = profissao;
        this.telefone = telefone;
        this.email = email;
    }
    
    @Override
    public String toString()
    {
        return nome+", "+idade+" anos, sexo "+sexo+", "+profissao+", telefone nº "+telefone+", email: "+email;
    }

    public int getIdade() {
        return this.idade;
    }
    
    public String getNome()
    {
        return this.nome;
    }
    
}
