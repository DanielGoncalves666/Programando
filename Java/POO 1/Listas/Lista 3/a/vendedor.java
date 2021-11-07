package a;


public class vendedor extends funcionario {
    private double vendas;
    private static int qtd = 0;
    
    public vendedor (String nome, String RG, double salario)
    {
        super(nome,RG,salario);
        vendas = 0;
        qtd++;
    }
    
    // adiciona o valor da venda
    public void acumularVendas(double valor)
    {
        vendas += valor;
    }
    
    //calcula o salario final e zera vendas
    public double salarioFinal()
    {
        return getSalario() + vendas * 0.05;
    }

    public static int getQtd() {
        return qtd;
    }

    public double getVendas() {
        return vendas;
    }
    
    public void mostrar()
    {
        super.mostrar();
        System.out.printf("Vendas acumuladas: %.2f.",vendas);
        System.out.println();
    }
}
