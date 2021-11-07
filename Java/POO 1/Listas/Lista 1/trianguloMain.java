package lista1;

import java.util.Scanner;

public class trianguloMain {

    public static triangulo[] vet = new triangulo[10];
    public static int indice = 0;
    
    public static void inserirTriangulo(int a, int b, int c)
    {     
        triangulo aux = new triangulo();
        
        if( aux.setLado(0,a) && aux.setLado(1,b) && aux.setLado(2,c) && aux.ehTriangulo())
        {
            vet[indice] = aux;
            indice++;
        }
        else
            System.out.println("Valores inválidos ou que não formam um triangulo!");
    }
    
    public static void mostrarCadastrados()
    {
        int qtd = 0;
        
        System.out.println("Triângulos Cadastrados:");
        for(int i = 0; i < indice; i++)
            System.out.println("Triangulo "+i+": Lados: "+vet[i].getLado(0)+" "+vet[i].getLado(1)+" "+vet[i].getLado(2));
        
        if(indice == 0)
            System.out.println("Nenhum triângulo cadastrado");
    }
    
    public static int qtdEquilateros()
    {
        int qtd = 0;
        
        for(int i=0; i < indice; i++)
        {
            if(vet[i].tipoTriangulo() == 1)
                qtd++;
        }
        
        return qtd;
    }
    
    public static int maiorPerimetro()
    {
        int maior = 0;
        
        for(int i = 0; i < indice; i++)
        {
            if(i == 0)
                maior = i;
            else if(vet[maior].calcPerimetro() < vet[i].calcPerimetro())
                maior = i;
        }
        
        return maior;
    }
    
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int op = -1;
        
        while(op != 5)
        {
            System.out.println("==================================================");
            System.out.println("1 - Inserir triângulo.");
            System.out.println("2 - Mostrar triângulos cadastrados.");
            System.out.println("3 - Mostrar número de triângulos equiláteros.");
            System.out.println("4 - Triângulo com maior perímetro.");
            System.out.println("5 - Sair.");
            System.out.println("==================================================");
            op = sc.nextInt();
            sc.nextLine();
            
            switch(op)
            {
                case 1:
                    int a, b, c;
                    
                    if(indice == 10)
                    {
                        System.out.println("Maximo atingido!");
                        break;
                    }
                    
                    System.out.println("Entre com os três lados do triângulo.");
                    System.out.print("Primeiro lado: ");
                    a = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Segundo lado: ");
                    b = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Terceiro lado: ");
                    c = sc.nextInt();
                    sc.nextLine();
                    
                    inserirTriangulo(a,b,c);
                    
                    break;
                case 2:
                    mostrarCadastrados();
                    break;
                case 3:
                    System.out.println("A quantidade de triângulos equilateros registrados é de "+qtdEquilateros()+".");
                    break;
                case 4:
                    int maior = maiorPerimetro();
                    System.out.println("O maior triangulo em perimetro é o num "+maior+" com perimetro de "+vet[maior].calcPerimetro());
                    
                    break;
            }
        }
    }
}
