package lista1;


public class triangulo {
    private int[] lado = new int[3];
    
    public boolean setLado(int i, int valor) {
        if(valor <= 0 || i < 0 || i > 2)
        {
            System.out.println("Valor invalido para o lado ou lado inexistente.");
            return false;
        }
        else
        {
            this.lado[i] = valor;
            return true;
        }
    }
        
    public int getLado(int i)
    {
        if(i < 0 || i > 2)
        {
            System.out.println("Lado inexistente");
            return -1;
        }
        else
            return this.lado[i];
    }
    
    public int calcPerimetro()
    {
        return getLado(0) + getLado(1) + getLado(2);
        //seria melhor se eu fizesse um getLado especifico para cada lado.
    }
 
    public boolean ehTriangulo()
    {
        int a = getLado(0);
        int b = getLado(1);
        int c = getLado(2);
        
        if(a > b + c || b > a + c || c > a + b)
            return false;
        else if(Math.abs(b - c) > a || Math.abs(a - c) > b || Math.abs(a - b) > c)
            return false;
        else
            return true;
    }
    
    /**
     * 
     * @return 1, se equilatero, 2, se isosceles, 3, se escaleno, 0 se nao é um triangulo 
     */
    public int tipoTriangulo()
    {
        int a = getLado(0);
        int b = getLado(1);
        int c = getLado(2);
        
        if(!ehTriangulo())
            return 0;
        else if(a == b && b == c)
            return 1;
        else if(a == b || a == c || b == c)
            return 2;
        else
            return 3;
    }
    //talvez seria melhor ter uma variavel que indique o tipo do triangulo invés de ter um método que fica recalculando
    //sempre que chamado
}
