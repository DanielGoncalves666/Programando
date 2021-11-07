package lista1.banco;

public class Conta {    
    private static int ct = 0;
    private String tipo;
    private float saldo;
    private int num;

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public void setNum(int num) {
        this.num = num;
    }
    
    public static void setCt(int ct) {
        Conta.ct = ct;
    }

    public String getTipo() {
        return tipo;
    }

    public float getSaldo() {
        return saldo;
    }

    public int getNum() {
        return num;
    }
    
    public static int getCt() {
        return ct;
    }
     
    String mostraSaldo() {
        return "O saldo da conta num "+getNum()+", do tipo ("+getTipo()+") eh "+getSaldo()+" reais.";
    }
    
    void cadastraConta(String t, float s) {
        setTipo(t);
        if (s >= 100)
            setSaldo(s);
        else
            setSaldo(100);
        setNum(getCt());
        setCt(getCt() + 1);
    }
    
    boolean sacar(float valor) {
        if (valor <= (getSaldo()+100)) {
            setSaldo(getSaldo() - valor);
            return true;
        }else
            return false;
    }
    
    boolean depositar(float valor) {
        setSaldo(getSaldo() + valor);
        return true;
    }
    
    boolean ehNegativo() {
        return (getSaldo() < 0);
    }
    
    void transferir(float valor, Conta c) {
        if (this.sacar(valor)) {
            c.depositar(valor);
            System.out.println("Transferencia concluida.");
        } else
            System.out.println("Erro na operacao. Transferencia cancelada.");
    }

}