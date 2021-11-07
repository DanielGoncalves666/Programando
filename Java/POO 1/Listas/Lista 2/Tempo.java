package lista2;


public class Tempo {
    private int hora;
    private int minuto;
    private int segundo;
    
    public Tempo(int h, int m, int s)
    {
        setHora(h);
        setMinuto(m);
        setSegundo(s);
    }

    public void setHora(int h) {
        if(h < 0 || h > 59)
            hora = 0;
        else
            hora = h;;
    }

    public void setMinuto(int m) {
        if(m < 0 || m > 59)
            minuto = 0;
        else
            minuto = m;
    }

    public void setSegundo(int s) {
        if(s < 0 || s > 59)
            segundo = 0;
        else
            segundo = s;
    }
    
    public void incrementarMinuto()
    {
        minuto++;
        
        if(minuto == 60)
        {
            hora++;
            
            if(hora == 24)
                hora = 0;
        }
    }
    
    public void decrementaMinuto()
    {
        minuto--;
        
        if(minuto == -1)
        {
            hora--;
            
            if(hora == -1)
                hora = 23;
        }
    }
    
    public void mostrar24()
    {
        System.out.printf("%02d"+":"+"%02d"+":"+"%02d\n", hora, minuto, segundo);
    }
    
    public void mostrar12()
    {
        if(hora < 12)
            System.out.printf("%02d"+":"+"%02d"+":"+"%02d AM\n", hora, minuto, segundo);
        else
            System.out.printf("%02d"+":"+"%02d"+":"+"%02d PM\n", (hora - 12), minuto, segundo);
    }
}
