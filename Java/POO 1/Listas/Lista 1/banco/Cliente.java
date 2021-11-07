package lista1.banco;

public class Cliente {
    private static int ct = 0;
    private String nome, CPF, telefone;
    private int idade;
    private Conta conta;
    private String usr,sen;

    public static int getCt() {
        return ct;
    }

    public static void setCt(int ct) {
        Cliente.ct = ct;
    }

    public String getNome() {
        return nome;
    }

    public String getCPF() {
        return CPF;
    }

    public String getTelefone() {
        return telefone;
    }

    public int getIdade() {
        return idade;
    }

    public Conta getConta() {
        return conta;
    }

    public String getUsr() {
        return usr;
    }

    public String getSen() {
        return sen;
    }
    
    void cadastraCliente(String n, String cpf, String t, int i, String u, String s, Conta c) {
        nome = n;
        CPF = cpf;
        telefone = t;
        idade = i;
        usr = u;
        sen = s;
        conta = c;
        setCt(getCt() + 1);
    }
}