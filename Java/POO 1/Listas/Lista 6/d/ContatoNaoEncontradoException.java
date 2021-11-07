package d;

public class ContatoNaoEncontradoException extends RuntimeException{
    public ContatoNaoEncontradoException()
    {
        super("Contato não encontrado.");
    }
    
    public ContatoNaoEncontradoException(String msg)
    {
        super(msg);
    }
}
