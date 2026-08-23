public class Autoutilitara extends Vehicul{
    private boolean frigorifica;

    public Autoutilitara(String numarInmatriculare, double capacitateTone, boolean frigorifica) {
        super(numarInmatriculare, capacitateTone);
        this.frigorifica = frigorifica;
    }

    public boolean isFrigorifica() {
        return frigorifica;
    }

    public void setFrigorifica(boolean frigorifica) {
        this.frigorifica = frigorifica;
    }

    @Override
    public void pornireCursa() {
        System.out.print("Autoutilitara ");
        if(!frigorifica)
            System.out.print("nu ");
        System.out.print("este frigorifica");
    }

    @Override
    public double calculeazaEficienta() {
        if(frigorifica)
            return this.getCapacitateTone() * 0.8f;
        else
            return this.getCapacitateTone();
    }
}
