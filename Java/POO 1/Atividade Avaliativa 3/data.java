package sistema;

public class data {
    private int horaInicial;
    private int minutoInicial;
    private int diaInicial;
    private int horaFinal;
    private int minutoFinal;
    private int diaFinal;

    public data(int horaInicial, int minutoInicial, int diaInicial,  int horaFinal, int minutoFinal, int diaFinal) {
        this.horaInicial = horaInicial;
        this.minutoInicial = minutoInicial;
        this.diaInicial = diaInicial;
        this.horaFinal = horaFinal;
        this.minutoFinal = minutoFinal;
        this.diaFinal = diaFinal;
    }
    
    public int calculaIntervaloEmHoras()
    {
        int dias = 0, horas = 0, minutos = 0;
        
        if(diaInicial != diaFinal)
            dias = diaFinal - (diaInicial + 1);
	if(diaInicial != diaFinal || horaInicial != horaFinal)
        {
            if(diaInicial == diaFinal)
		horas = horaFinal - (horaInicial + 1);
	    else
		horas = horaFinal + (24 - (horaInicial + 1));
	}
	if(diaInicial != diaFinal || horaInicial != horaFinal || minutoInicial != minutoFinal)
        {
            if(diaInicial == diaFinal && horaInicial == horaFinal)
		minutos = minutoFinal - (minutoInicial + 1);
	    else
		minutos = minutoFinal + (60 - (minutoInicial + 1));
        }   
        
        if(minutos >= 60)
        {
            horas++;
            minutos -= 60;
        }
        
        horas += dias * 24;
        
        // paga por horas incompletas só quando passa de 15 minutos
        if(minutos > 15)
            horas++;
        
        return horas;
    }
    
    // paga por dias incompletos apenas se for maior que 6
    public int calculaIntervaloEmDias()
    {
        int horas = calculaIntervaloEmHoras();
        
        if(horas % 24 >= 6)
            return horas / 24 + 1;
        else
            return horas / 24;
    }
}
