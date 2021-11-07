package sistema;

public class carro {
    private final String marca;
    private final String modelo;
    private final int categoria;    // categoria indica o tamanho da caga necessária
    
    public carro(String marca, String modelo, int categoria)
    {
        this.marca = marca;
        this.modelo = modelo;
        this.categoria = categoria;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }
    
    public String getMarcaModelo()
    {
        return marca + " " + modelo;
    }
       
    public int getCategoria()
    {
        return categoria;
    }
}
