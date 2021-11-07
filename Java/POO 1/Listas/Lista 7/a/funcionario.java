package a;

public class funcionario {
    private String CPF;
    private double salario;
    private double descontos;
    
    public funcionario(String CPF)
    {
        this.CPF = CPF;
        this.salario = 0.0;
        this.descontos = 0.0;
    }
    
    public funcionario(String CPF, double salario)
    {
        this(CPF);
        this.salario = salario;
    }
    
    public funcionario(String CPF, double salario, double descontos)
    {
        this(CPF,salario);
        this.descontos = descontos;
    }

    public String getCPF() {
        return CPF;
    }

    public double getSalario() {
        return salario;
    }

    public double getDescontos() {
        return descontos;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void setDescontos(double descontos) {
        this.descontos = descontos;
    } 
    
    public double salarioLiquido()
    {
        return salario - descontos;
    }
}
