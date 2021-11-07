package lista1;

public class ponto {
    private float x;
    private float y;

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public void setX(float x) {
        if(x < 0.0)
            this.x = 0;
        else
            this.x = x;
    }

    public void setY(float y) {
        if(y < 0.0)
            this.y = 0;
        else
            this.y = y;
    }
    
    public void inicializar(float x, float y)
    {
        this.setX(x);
        this.setY(y);
    }
    
    public float distanciaEuclidiana(ponto point)
    {
        return (float) Math.sqrt(Math.pow(this.getX() - point.getX(),2) + Math.pow(this.getY() - point.getY(),2));
    }
    
}
