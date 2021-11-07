package sistema;

public class usuario {
    private final String nome;
    private final String CPF;
    private final boolean VIP;
    private final String[] carros;
    private int indiceVagaOcupada;
    private String indiceCarroEstacionado;

    public usuario(String nome, String CPF, boolean VIP, String[] cars) {
        this.nome = nome;
        this.CPF = CPF;
        this.VIP = VIP;
        this.indiceVagaOcupada = -1;
        this.carros = cars;
    }

    public String getNome() {
        return nome;
    }

    public String getCPF() {
        return CPF;
    }

    public boolean isVIP() {
        return VIP;
    }

    public int getIndiceVagaOcupada() {
        return indiceVagaOcupada;
    }
    
    public String getCarroEstacionado()
    {
        return indiceCarroEstacionado;
    }
    
    public void setCarroEstacionado(String index)
    {
        indiceCarroEstacionado = index;
    }

    public void setIndiceVagaOcupada(int indiceVagaOcupada) {
        this.indiceVagaOcupada = indiceVagaOcupada;
    }
    
    public boolean possuiCarro(String c)
    {
        for(String car : carros)
        {
            if(car.equalsIgnoreCase(c))
                return true;
        }
        
        return false;
    }
    
    public String[] getCarros()
    {
        return carros;
    }
}
