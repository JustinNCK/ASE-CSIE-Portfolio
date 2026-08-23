public class Pacienti {
    private long CNP;
    private String nume;
    private int varsta;
    private int cod_sectie;

    public Pacienti(long CNP, String nume, int varsta, int cod_sectie) {
        this.CNP = CNP;
        this.nume = nume;
        this.varsta = varsta;
        this.cod_sectie = cod_sectie;
    }

    public long getCNP() {
        return CNP;
    }

    public void setCNP(long CNP) {
        this.CNP = CNP;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public int getVarsta() {
        return varsta;
    }

    public void setVarsta(int varsta) {
        this.varsta = varsta;
    }

    public int getCod_sectie() {
        return cod_sectie;
    }

    public void setCod_sectie(int cod_sectie) {
        this.cod_sectie = cod_sectie;
    }
}
