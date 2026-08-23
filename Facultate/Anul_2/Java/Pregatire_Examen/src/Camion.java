public class Camion extends Vehicul{
    private int numarAxe;

    public Camion(String numarInmatriculare, double capacitateTone, int numarAxe) {
        super(numarInmatriculare, capacitateTone);
        this.numarAxe = numarAxe;
    }

    public int getNumarAxe() {
        return numarAxe;
    }

    public void setNumarAxe(int numarAxe) {
        this.numarAxe = numarAxe;
    }

    @Override
    public void pornireCursa() {
        System.out.println("Camionul " + this.getNumarInmatriculare() + " a pornit la drum.");
    }

    @Override
    public double calculeazaEficienta() {
        return this.getCapacitateTone() / numarAxe;
    }
}
