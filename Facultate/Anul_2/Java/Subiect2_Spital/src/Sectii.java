import java.util.List;

public class Sectii {
    private int cod_sectie;
    private String denumire;
    private int numar_locuri;
    private double varsta_medie;

    public Sectii(int cod_sectie, String denumire, int numar_locuri) {
        this.cod_sectie = cod_sectie;
        this.denumire = denumire;
        this.numar_locuri = numar_locuri;
        this.varsta_medie = 0;
    }


    public int getCod_sectie() {
        return cod_sectie;
    }

    public void setCod_sectie(int cod_sectie) {
        this.cod_sectie = cod_sectie;
    }

    public String getDenumire() {
        return denumire;
    }

    public void setDenumire(String denumire) {
        this.denumire = denumire;
    }

    public int getNumar_locuri() {
        return numar_locuri;
    }

    public void setNumar_locuri(int numar_locuri) {
        this.numar_locuri = numar_locuri;
    }

    public double getVarsta_medie() {
        return varsta_medie;
    }

    public void setVarsta_medie(double varsta_medie) {
        this.varsta_medie = varsta_medie;
    }
}
