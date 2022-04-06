package URI;

import java.util.Scanner;
import java.math.RoundingMode;
import java.text.DecimalFormat;

public class _1009 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");
        df.setRoundingMode(RoundingMode.HALF_DOWN);
        
        sc.nextLine();
        double fixo = sc.nextDouble();
        double vendas = sc.nextDouble();
        double salario = fixo + vendas * 0.1500;
        
        System.out.println("TOTAL = R$ " + df.format(salario));
    }
}
