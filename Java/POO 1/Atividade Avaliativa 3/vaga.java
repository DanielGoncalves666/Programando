package sistema;

public class vaga {
    private final int categoria;
    /*
        largura altura categoria
        1.75    1.7     1
        2.00    1.7     2
        1.75    2.0     3
        2.00    2.0     4
        1.75    2.3     5
        2.00    2.3     6
    */
    private final boolean VIP;
    private final char tipo;  // d --> diária ; h --> hora
    private final double valor;
    private boolean ocupada;
    private data periodo;

    public vaga(int categoria, boolean VIP, char tipo, double valor) {
        this.categoria = categoria;
        this.VIP = VIP;
        this.tipo = tipo;
        this.valor = valor;
        this.ocupada = false;
    }

    public data getData()
    {
        return periodo;
    }
    
    public int getCategoria()
    {
        return categoria;
    }

    public boolean isVIP() {
        return VIP;
    }

    public String getTipo() {
        if(tipo == 'd')
            return "Diaria";
        else
            return "Hora";
    }

    public double getValor() {
        return valor;
    }

    public boolean isOcupada() {
        return ocupada;
    }
    
    public void setOcupada(boolean ocupada)
    {
        this.ocupada = ocupada;
    }
    
    public void setData(data d)
    {
        periodo = d;
    }
    
    public String getVisualizacao()
    {
        String vip = VIP? "VIP" : "NORMAL";
        
        
        return " - " + vip + ", Valor de R$" + valor + " por " + getTipo();  
    }
}
