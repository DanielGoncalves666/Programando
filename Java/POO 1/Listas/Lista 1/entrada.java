package lista1;

import java.util.Scanner;

public class entrada {

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int a,b;
        
        System.out.println("Entre com o primeiro número: ");
        a = sc.nextInt();
        sc.nextLine();
        
        System.out.println("Entre com o segundo número: ");
        b = sc.nextInt();
        sc.nextLine();
        
        System.out.println();
        System.out.println("A soma de "+a+" e "+b+" é de "+(a + b));
        
    }
}
