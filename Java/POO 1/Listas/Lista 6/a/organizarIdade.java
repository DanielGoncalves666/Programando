package a;

import java.util.Comparator;

public class organizarIdade implements Comparator<Empregado> {
    
    @Override
    public int compare(Empregado arg0, Empregado arg1) 
    {
        return arg0.compareTo(arg1);
    }
}
