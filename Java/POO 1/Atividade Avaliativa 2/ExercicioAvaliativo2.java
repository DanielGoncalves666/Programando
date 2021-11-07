package exercicioavaliativo2;

import java.util.Scanner;

public class ExercicioAvaliativo2 {

    private static void operacaoConjunto(IntSetImpl2 c)
    {
        Scanner sc = new Scanner(System.in);
        int ap, elem, qtd;
        
        do
        {
            System.out.println("1 - Inserir elemento no Conjunto.");
            System.out.println("2 - Inserir múltiplos elementos no Conjunto.");
            System.out.println("3 - Remover elemento do Conjunto.");
            System.out.println("4 - Calcular cardinalidade do conjunto.");
            System.out.println("5 - Verificar se o elemento está no conjunto.");
            System.out.println("6 - Calcular a soma dos elementos do conjunto.");
            System.out.println("7 - Mostrar conjunto.");
            System.out.println("8 - Sair.");
                    
            ap = sc.nextInt();
            sc.nextLine();
                        
            switch(ap)
            {
                case 1:
                    System.out.println("Digite o elemento a ser inserido:");
                    elem = sc.nextInt();
                    sc.nextLine();
                                
                    c.insert(elem);
                                
                    break;
                case 2:
                    System.out.println("Digite a quantidade de elementos:");
                    qtd = sc.nextInt();
                    sc.nextLine();
                                
                    int[] vet = new int[qtd];
                                
                    for(int i = 0; i < qtd; i++)
                    {
                        System.out.println("Digite o elemento: ");
                        elem = sc.nextInt();
                        sc.nextLine();
                                    
                        vet[i] = elem;
                    }
                                
                    c.insertAll(vet);
                                
                    break;
                case 3:
                    System.out.println("Digite o elemento a ser removido:");
                    elem = sc.nextInt();
                    sc.nextLine();
                                
                    c.remove(elem);
                                
                    break;
                case 4:
                    System.out.println("A cardinalidade do conjunto é "+c.size()+".");
                                
                    break;
                case 5:
                    System.out.println("Digite o elemento a ser verificado:");
                    elem = sc.nextInt();
                    sc.nextLine();
                                
                    if(c.isln(elem))
                        System.out.println("Elemento presente.");
                    else
                        System.out.println("Elemento não presente");
                                
                    break;
                case 6:
                    System.out.println("A soma dos elementos do conjunto é "+c.somarConjunto()+".");
                                
                    break;
                case 7:
                    c.mostrarConjunto();
                                
                    break;
            }
                    
        }while(ap != 8);        
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int op;
        
        IntSetImpl2 A = new IntSetImpl2(40);
        IntSetImpl2 B = new IntSetImpl2(40);
        IntSetImpl2 C;
        
        do
        {
            System.out.println(" ----- Menu -----");
            System.out.println("1 - Conjunto A.");
            System.out.println("2 - Conjunto B.");
            System.out.println("3 - União dos conjuntos A e B.");
            System.out.println("4 - Interseção dos conjuntos A e B.");
            System.out.println("5 - Sair");
            
            op = sc.nextInt();
            sc.nextLine();
            
            switch(op)
            {
                case 1:
                    operacaoConjunto(A);
                
                    break;
                case 2:
                    operacaoConjunto(B);
                    
                    break;
                case 3:
                    C = A.uniao(B);
                    
                    System.out.println("União dos conjuntos A e B.");
                    C.mostrarConjunto();
                    break;
                
                case 4:
                    C = A.intersecao(B);
                    
                    System.out.println("Interseção dos conjuntos A e B.");
                    C.mostrarConjunto();
                    
                    break;
            }     
        }while(op != 5);
    }
    
}
