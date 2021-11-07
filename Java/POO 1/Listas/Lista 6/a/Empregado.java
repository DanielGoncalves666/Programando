package a;

public class Empregado implements Comparable{

    private String CPF;
    private int idade;
    private double salario;

    public Empregado (String CPF, int idade, double salario) throws RuntimeException
    {
        setCPF(CPF);
        setIdade(idade);
        setSalario(salario);
    }
    
    public String getCPF() {
        return CPF;
    }

    public int getIdade() {
        return idade;
    }

    public double getSalario() {
        return salario;
    }

    public void setCPF(String CPF) {
        if(CPF.isEmpty())
            throw new RuntimeException("Erro: Campo CPF vazio!");
        else
            this.CPF = CPF;
    }

    public void setIdade(int idade) {
        if(getIdade() < 0)
            throw new RuntimeException("Erro: Idade negativa não é válida!");
        else
            this.idade = idade;
    }

    public void setSalario(double salario) {
        if(getSalario() < 0)
            throw new RuntimeException("Erro: Salário negativo não é válido!");
        else
            this.salario = salario;
    }
    
    
    @Override
    public int compareTo(Object arg) {
        
        if(this.getIdade() > ((Empregado)arg).getIdade())
            return 1;//positivo de o objeto que chamou for maior
        else if(this.getIdade() < ((Empregado)arg).getIdade())
            return -1;//negativo se o objeto que chamou for menor
        else
            return 0;//se os objetos forem iguais
    }
    
    public String imprimir()
    {
        return "CPF: "+getCPF()+", Idade: "+getIdade()+", Salario: "+getSalario()+".";
    }
}
