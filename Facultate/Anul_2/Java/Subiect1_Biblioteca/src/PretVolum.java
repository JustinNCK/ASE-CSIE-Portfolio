public class PretVolum {
    private String simbol;
    private double pret_deschidere;
    private double pret_max;
    private double pret_min;
    private double pret_inchidere;
    private long volum;

    public PretVolum(String simbol, double pret_deschidere, double pret_max, double pret_min, double pret_inchidere, long volum) {
        this.simbol = simbol;
        this.pret_deschidere = pret_deschidere;
        this.pret_max = pret_max;
        this.pret_min = pret_min;
        this.pret_inchidere = pret_inchidere;
        this.volum = volum;
    }

    public String getSimbol() {
        return simbol;
    }

    public void setSimbol(String simbol) {
        this.simbol = simbol;
    }

    public double getPret_deschidere() {
        return pret_deschidere;
    }

    public void setPret_deschidere(double pret_deschidere) {
        this.pret_deschidere = pret_deschidere;
    }

    public double getPret_max() {
        return pret_max;
    }

    public void setPret_max(double pret_max) {
        this.pret_max = pret_max;
    }

    public double getPret_min() {
        return pret_min;
    }

    public void setPret_min(double pret_min) {
        this.pret_min = pret_min;
    }

    public long getVolum() {
        return volum;
    }

    public void setVolum(long volum) {
        this.volum = volum;
    }

    public double getPret_inchidere() {
        return pret_inchidere;
    }

    public void setPret_inchidere(double pret_inchidere) {
        this.pret_inchidere = pret_inchidere;
    }

    public double valoare(){
        return pret_inchidere * volum;
    }

    @Override
    public String toString() {
        return "PretVolum{" +
                "simbol='" + simbol + '\'' +
                ", pret_deschidere=" + pret_deschidere +
                ", pret_max=" + pret_max +
                ", pret_min=" + pret_min +
                ", pret_inchidere=" + pret_inchidere +
                ", volum=" + volum +
                '}';
    }
}
