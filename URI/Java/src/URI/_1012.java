package URI;

import java.util.Scanner;

public class _1012 {
    
    public static final double pi = 3.14159;
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        double A = sc.nextDouble();
        double B = sc.nextDouble();
        double C = sc.nextDouble();
        
        System.out.printf("TRIANGULO: %.3f\n", areaTriangulo(A,C));
        System.out.printf("CIRCULO: %.3f\n", areaCirculo(C));
        System.out.printf("TRAPEZIO: %.3f\n", areaTrapezio(A,B,C));
        System.out.printf("QUADRADO: %.3f\n", areaQuadrado(B));
        System.out.printf("RETANGULO: %.3f\n", areaRetangulo(A,B));
    }
    
    public static double areaTriangulo(double base, double altura)
    {
        return (base * altura) / 2;
    }
    
    public static double areaCirculo(double raio)
    {
        return pi * raio * raio;
    }
    
    public static double areaTrapezio(double baseMenor, double baseMaior, double altura)
    {
        return ((baseMenor + baseMaior) * altura) / 2.0;
    }
    
    public static double areaQuadrado(double lado)
    {
        return lado * lado;
    }
    
    public static double areaRetangulo(double lado1, double lado2)
    {
        return lado1 * lado2;
    }
}