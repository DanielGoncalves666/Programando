package URI;

import java.util.Scanner;

public class _1017 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int tempo = sc.nextInt();
        int velocidade = sc.nextInt();
        double gasto = (tempo * velocidade) / 12.0;
        
        System.out.printf("%.3f\n", gasto);
    }
}
