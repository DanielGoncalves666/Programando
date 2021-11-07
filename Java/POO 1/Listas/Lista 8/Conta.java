


public class Conta {

    private String nome;
    private String CPF;
    private String nascimento;
    private char sexo;
    private String NumeroConta;
    private String senha;
    private String email;
    private boolean noticias;
    
    public Conta(String nome, String CPF, String nascimento, int sexo, String NumeroConta, String senha, String email, Boolean noticias){
        this.nome = nome;
        this.CPF = CPF.trim();
        this.nascimento = nascimento;
        this.NumeroConta = NumeroConta.trim();
        this.senha = senha;
        this.email = email;
        this.noticias = noticias;
        
        if(sexo == 0)
            this.sexo = 'M';
        else
            this.sexo = 'F';
       
    }

    public String getCPF() {
        return CPF;
    }

    public String getNome() {
        return nome;
    }

    public String getNascimento() {
        return nascimento;
    }

    public String getSexo() {
        if(sexo == 'M')
            return "MASCULINO";
        else
            return "FEMININO";
    }

    public String getNumeroConta() {
        return NumeroConta;
    }

    public String getSenha() {
        return senha;
    }

    public String getEmail() {
        return email;
    }

    public boolean isNoticias() {
        return noticias;
    }
    
    public void verificaStrings(){
        if(nome.isBlank() || CPF.isBlank() || nascimento.isBlank() || NumeroConta.isBlank() || senha.isBlank() || email.isBlank())
        {
            throw new RuntimeException("Um ou mais campos não foram preenchidos.");
        }
        else
        {
            try
            {
                Integer.valueOf(CPF);
                Integer.valueOf(NumeroConta);
            }
            catch(NumberFormatException e)
            {
                throw new RuntimeException("CPF ou Número da conta não são números.");
            }
        }
    }
    
    public String imprimir()
    {
        String n = noticias ? "T" : "F";
        
        return CPF + ":" + nome + ":" + nascimento + ":" + sexo + ":" + NumeroConta + ":" + senha + ":" + email + ":" + n; 
    }

}
