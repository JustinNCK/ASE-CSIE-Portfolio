public abstract class Vehicul implements Evaluabil{
    private String numarInmatriculare;
    private double capacitateTone;

    public Vehicul(String numarInmatriculare, double capacitateTone) {
        this.numarInmatriculare = numarInmatriculare;
        this.capacitateTone = capacitateTone;
    }

    public Vehicul(){}

    public String getNumarInmatriculare() {
        return numarInmatriculare;
    }

    public double getCapacitateTone() {
        return capacitateTone;
    }

    public abstract void pornireCursa();
}
