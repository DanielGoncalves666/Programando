package URI;

import java.util.Scanner;

public class _1006 {
    
    public static void main(String Args[])
    {
        Scanner sc = new Scanner(System.in);
        double A = sc.nextDouble();
        double B = sc.nextDouble();
        double C = sc.nextDouble();
        double media = (A * 2 + B * 3 + C * 5) / 10.0;
        
        System.out.printf("MEDIA = %.1f\n",media);
    }
}