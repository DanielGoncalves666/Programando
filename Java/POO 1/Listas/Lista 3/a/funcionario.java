package a;


public class funcionario {
    private String nome; 
    private String RG;
    private double salario;
    
    public funcionario(String nome, String RG, double salario)
    {
        this.nome = nome;
        this.RG = RG;
        setSalario(salario);
    }

    public String getNome() {
        return nome;
    }

    public String getRG() {
        return RG;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        if(salario < 0.0)
            this.salario = 0.0;
        else
            this.salario = salario;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setRG(String RG) {
        this.RG = RG;
    } 
    
    public void mostrar()
    {
        System.out.printf("%s, RG: %s, Salário: %.2f.", nome, RG, salario);
        System.out.println();
    }
}






