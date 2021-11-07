package Espaco;

import java.util.Random;
import java.util.Scanner;

public class AmbienteEspacial {
    
    public static void main(String a[]) {
        
        Random aleatorio = new Random();
        Scanner sc = new Scanner(System.in);
        NaveEspacial[] frota = new NaveEspacial[10];
        
        int op = 0;
        int maxNaves = 7;
        
        do {
            System.out.println("=== AMBIENTE ESPACIAL ===");
            System.out.println("1) Inserir nave");
            System.out.println("2) Mostrar naves");
            System.out.println("3) Mostrar naves mais rápidas.");
            System.out.println("4) Verificar se o combustível das naves é suficiente.");
            System.out.println("5) Verificar quanta carga precisa ser jogada fora para chegar ao destino.");
            System.out.println("6) Verificar o combustivel a mais necessário para completar a viagem.");
            System.out.println("7) Sair");
            System.out.print("OPCAO: ");
            op = sc.nextInt();
            sc.nextLine();
            
            switch (op) {
                case 1:
                    int p = NaveEspacial.getQtd();
                    NaveEspacial novo;
                    
                    if(NaveEspacial.getQtd() == 10)
                    {
                        System.out.println("Máximo atingido!");
                        break;
                    }
                    
                    if (NaveEspacial.getQtd() >= maxNaves) {
                        System.out.println("Super população de naves!");
                        novo = new NaveEspacial("Nave com defeito", "Desconhecido", 0, 0, 0, 0);
                    }else {
                        System.out.print("- Nome da nave: ");
                        String s = sc.nextLine();
                        System.out.print("- Ponto de Origem: ");
                        String o = sc.nextLine();

                        novo = new NaveEspacial(s,o, aleatorio.nextDouble() * 60, aleatorio.nextInt(6)+5, aleatorio.nextDouble() * 100, aleatorio.nextDouble() * 100);
                    }
                    
                    frota[p] = novo;
                    break;
                case 2:
                    for (int i=0; i<NaveEspacial.getQtd(); i++)
                        frota[i].mostrarNave();
                    break;
                case 3:
                    for (int i=0; i<NaveEspacial.getQtd(); i++)
                        for (int j=0;j<NaveEspacial.getQtd(); j++)
                            if (frota[i].naveMaisRapida(frota[j])) {
                                System.out.println(frota[j].getNome()+" é mais rápida que "+frota[i].getNome());
                            }
                    break;
                case 4:
                    for (int i=0; i < NaveEspacial.getQtd(); i++)
                    {
                        if(frota[i].getVelocidade() == 0)
                            System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") parada ou com defeito.");
                        else
                        {
                            if(frota[i].combustivelSuficiente(1,0.0))
                                System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") possui combustível suficiente para chegar ao destino.");
                            else
                            {
                                System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") não possui combustível suficiente para chegar ao destino.");
                            }
                    
                        }
                    }
                    
                    break;
                case 5:
                    for (int i=0; i < NaveEspacial.getQtd(); i++)
                    {
                        if(frota[i].getVelocidade() == 0)
                            System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") parada ou com defeito.");
                        else
                        {
                            double result = frota[i].despejarCarga();
                            
                            if(result == -1.0)
                                System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") não precisa despejar carga para chegar ao destino.");
                            else if(result == -2.0)
                                System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") não tem combustível suficiente mesmo com a área de carga vazia.");
                            else
                            {
                                System.out.printf("Nave %d (%s) precisa despejar %3.2f %% de sua carga para chegar ao destino.",(i + 1),frota[i].getNome(),result);   
                                System.out.println();
                            }
                    
                        }
                    }
                    
                    break;
                case 6:
                    for (int i=0; i < NaveEspacial.getQtd(); i++)
                    {
                        if(frota[i].getVelocidade() == 0)
                            System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") parada ou com defeito.");
                        else
                        {
                            double result = frota[i].calculaCombustivelAdicional();
                    
                            if(result == -1.0)
                                System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") não precisa de mais combustível.");
                            else if( result == -2.0)
                                System.out.println("Nave "+(i + 1)+" ("+frota[i].getNome()+") não possui capacidade para o combustível requerido.");
                            else
                            {
                                System.out.printf("Nave %d (%s) precisa preencher o reservatório com %3.2f %% de combustivel para chegar ao destino.",(i + 1),frota[i].getNome(),result);
                                System.out.println();
                            }   
                        
                        }   
                    }
                    break;
            }
        }while (op != 7);   
    }   
}