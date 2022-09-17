package URI;

import java.util.Scanner;

public class _1005 {
    
    public static void main(String Args[])
    {
        Scanner sc = new Scanner(System.in);
        double A = sc.nextDouble();
        double B = sc.nextDouble();
        double media = (A * 3.5 + B * 7.5) / 11.0;
        
        System.out.printf("MEDIA = %.5f\n",media);
    }
}
