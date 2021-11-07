package exercicioavaliativo2;

public interface IntSet {
    void insert (int x);        //adiciona um elemento ao conjunto
    void insertAll (int[] v);   //adiciona vários elementos ao conjunto
    void remove (int x);        //remove um elemento do conjunto
    boolean isln(int x);        //testa se x pertence ao conjunto
    int size();                 //retorna a cardinalidade do conjunto
}
