package URI;

import java.util.Scanner;

public class _1014 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int distancia = sc.nextInt();
        double gasto = sc.nextDouble();
        double consumo = distancia / gasto;
        
        System.out.printf("%.3f km/l\n",consumo);
    }
}
