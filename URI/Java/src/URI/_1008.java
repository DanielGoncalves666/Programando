package URI;

import java.util.Scanner;

public class _1008 {

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int numero = sc.nextInt();
        int horas = sc.nextInt();
        double valor = sc.nextDouble();
        double salario = valor * horas;
        
        System.out.println("NUMBER = " + numero);
        System.out.printf("SALARY = U$ %.2f\n",salario);
    }
}
