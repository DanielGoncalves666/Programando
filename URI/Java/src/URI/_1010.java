package URI;

import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class _1010 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");
        df.setRoundingMode(RoundingMode.HALF_DOWN);
        
        sc.nextInt();
        int qtd = sc.nextInt();
        double valor = sc.nextDouble();
        double total = qtd * valor;
        
        sc.nextInt();
        qtd = sc.nextInt();
        valor = sc.nextDouble();
        total += qtd * valor;
        
        System.out.println("VALOR A PAGAR: R$ " + df.format(total));
    }
}
