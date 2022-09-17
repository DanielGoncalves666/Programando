package URI;

import java.util.Scanner;

public class _1020 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int dias = sc.nextInt();
        int anos = dias / 365;
        dias = dias % 365;
        int meses = dias / 30;
        dias = dias % 30;
        
        System.out.println(anos + " ano(s)");
        System.out.println(meses + " mes(es)");
        System.out.println(dias + " dia(s)");
    }
}
