public class Manevre {
    private int cod;
    private int durata;
    private double tarif;

    public Manevre(int cod, int durata, double tarif) {
        this.cod = cod;
        this.durata = durata;
        this.tarif = tarif;
    }

    public int getCod() {
        return cod;
    }

    public void setCod(int cod) {
        this.cod = cod;
    }

    public int getDurata() {
        return durata;
    }

    public void setDurata(int durata) {
        this.durata = durata;
    }

    public double getTarif() {
        return tarif;
    }

    public void setTarif(double tarif) {
        this.tarif = tarif;
    }
}
