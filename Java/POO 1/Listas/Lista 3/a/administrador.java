package a;

public class administrador extends funcionario {
    private int horasExtras;
    private static int qtd = 0;
    
    public administrador (String nome, String RG, double salario)
    {
        super(nome,RG,salario); 
        horasExtras = 0;
        qtd++;
    }
    
    // adiciona a quantidade de horas ao total
    public void acumularHoras(int qtd)
    {
        if(horasExtras < 0)
            horasExtras = 0;
        else
            horasExtras += qtd;
    }
    
    //calcula o salario final e zera horasExtras
    public double salarioFinal()
    {
        return getSalario() + (getSalario() * 0.01) * horasExtras;
    }

    public static int getQtd() {
        return qtd;
    }

    public int getHorasExtras() {
        return horasExtras;
    }
    
    public void mostrar()
    {
        super.mostrar();
        System.out.println("Horas extras acumuladas: "+horasExtras+" horas.");
    }
}
