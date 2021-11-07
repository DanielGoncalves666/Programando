package Espaco;

public class NaveEspacial {
    
    private String nome;
    private String origem;
    private double distanciaAoDestino;
    private int velocidade;
    private double combustivel;
    private double areaDeCarga;
    private static int qtd = 0;
    
    public NaveEspacial(String s, String origem, double distancia, int v, double c, double carga)
    {
        setNome(s);
        setOrigem(origem);
        setDistanciaAoDestino(distancia);
        setVelocidade(v);
        setCombustivel(c);
        setAreaDeCarga(carga);
        
        qtd++;
    }
   
    public void setNome(String nome) {
        if(nome.isEmpty())
            this.nome = "Vazio";
        else
            this.nome = nome;
    }

    public void setOrigem(String origem) {
        if(origem.isEmpty())
            this.origem = "Desconhecida";
        else
            this.origem = origem;
    }

    public void setDistanciaAoDestino(double distancia) {
        if(distancia <= 0)
            distanciaAoDestino = 0;
        else
            distanciaAoDestino = distancia;
    }
    

    public void setVelocidade(int velocidade) {
        if(velocidade <= 0)
            this.velocidade = 0;
        else if(velocidade > 10)
            this.velocidade = 10;
        else
            this.velocidade = velocidade;
    }
    
    public void setCombustivel(double comb)
    {
        if(comb < 0)
            combustivel = 0;
        else if(comb > 100)
            combustivel = 100;
        else    
            combustivel = comb;
    }
    
    public void setAreaDeCarga(double carga)
    {
        if(carga < 0)
            areaDeCarga = 0;
        else if(carga > 100)
            areaDeCarga = 100;
        else
            areaDeCarga = carga;
    }     
       
    public String getNome() {
        return nome;
    }

    public String getOrigem() {
        return origem;
    }

    public double getDistanciaAoDestino() {
        return distanciaAoDestino;
    }
    
    public int getVelocidade() {
        return velocidade;
    }
    
    public double getCombustivel()
    {
        return combustivel;
    }
    
    public double getAreaDeCarga()
    {
        return areaDeCarga;
    }        
    
    public static int getQtd() {
        return qtd;
    }
    
    public void mostrarNave() {
        System.out.print(getNome()+", ");
        if (getVelocidade() == 0)
            System.out.println("nave inoperante.");
        else
        {
            System.out.printf("origem em %s, com velocidade de %2d, distância ao destino de %3.2f unidades, combustível em %3.2f %% e área de carga em %3.2f %%.",getOrigem(),getVelocidade(),getDistanciaAoDestino(),getCombustivel(), getAreaDeCarga());
            System.out.println();   
        }
    }
        
    public boolean naveMaisRapida(NaveEspacial secundaria)
    {
        return this.velocidade < secundaria.getVelocidade();
    }
    //true se a nave secundaria é mais rápida
    
    
    private double calculaGasto(double carga)
    {
        if(carga == 0.0)
            return 1.0;
        else if(carga < 25.0)
            return 1.25;
        else if(carga < 50.0)
            return 1.50;
        else if(carga < 75.0)
            return 1.75;
        else
            return 2.0;
    }
    
     /* 
        Combustivel da nave 0 - 100 %
        AreadeCarga da nave preenchida 0 - 100%
        DistanciaAoDestino é a quantidade que falta em unidades
        O gasto de combustivel por unidade é de acordo com a quantidade de carga:
            0       -> 1% por unidade
            1 a 25  -> 1.25% por unidade
            26 a 50 -> 1.50% por unidade
            51 a 75 -> 1.75% por unidade
            76 a 100-> 2% por unidade
    
        opcao:
            1 - usar a carga que a nave possui
            2 - verificar se o valor passado em 'c' de carga pode ser levado ao destino com o combustivel presente. 
    */
    public boolean combustivelSuficiente(int opcao, double c)
    {
        double total;
        double carga;
        
        if(opcao == 2)
            carga = c;
        else
            carga = getAreaDeCarga();
            
        total = calculaGasto(carga) * getDistanciaAoDestino();  
                  
        return total <= getCombustivel();
    }
    
    /*
        Eliminar carga para ter combustível suficiente para chegar ao destino.
    
        retorna o valor que precisa ser eliminado, ou -1.0, se nao necessario, ou -2.0, se mesmo assim não é suficiente;
    */
    public double despejarCarga()
    {
        if(combustivelSuficiente(1,0.0))
            return -1.0;
        else
        {
            double carga = getAreaDeCarga();
            double eliminar = 0.0;
            double gasto = 0.0;
            
            if(carga > 75.0)
            {
                eliminar += carga - 75.0;
                carga = 75.0;
            }
                
            if(carga > 50.0)
            {
                if(combustivelSuficiente(2,carga))
                    return eliminar;
                else
                {
                    eliminar += carga - 50.0;
                    carga = 50.0;
                }
            }
            
            if(carga > 25.0)
            {
                if(combustivelSuficiente(2,carga))
                    return eliminar;
                else
                {
                    eliminar += carga - 25.0;
                    carga = 25.0;
                }
            }
            
            if(carga > 0.0)
            {
                if(combustivelSuficiente(2,carga))
                    return eliminar;
                else
                {
                    eliminar += carga;
                    carga = 0.0;
                }
            }
            
            if(combustivelSuficiente(2,carga))
                return eliminar;
            else
                return -2.0;
        }
    }
    
    /*
        Calcula a quantidade de combustivel adicional mínimo para que a viagem até o destino seja completada.
        -1.0 se nenhum combustível adicional é necessário, -2.0 se não houver espaço suficiente para a quantidade de combustível requerida
    */
    public double calculaCombustivelAdicional()
    {
        if(combustivelSuficiente(1,0.0))
            return -1.0;
        else
        {
            double necessario = calculaGasto(getAreaDeCarga()) * getDistanciaAoDestino();
            
            if(necessario > 100.00)
                return -2.0;
            else
                return necessario - getCombustivel();
        }
    }
    
}
