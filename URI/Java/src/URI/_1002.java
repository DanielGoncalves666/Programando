package URI;

import java.util.Scanner;

public class _1002 {

    public static final double pi = 3.14159;
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble();
        double area = pi * r * r;
        System.out.printf("A=%.4f\n",area);
    }
}
