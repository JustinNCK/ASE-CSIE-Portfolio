public class Consultatii {
    private String specialitate;
    private int numar;
    private int cod;

    public Consultatii(String specialitate, int numar, int cod) {
        this.specialitate = specialitate;
        this.numar = numar;
        this.cod = cod;
    }

    public String getSpecialitate() {
        return specialitate;
    }

    public void setSpecialitate(String specialitate) {
        this.specialitate = specialitate;
    }

    public int getNumar() {
        return numar;
    }

    public void setNumar(int numar) {
        this.numar = numar;
    }

    public int getCod() {
        return cod;
    }

    public void setCod(int cod) {
        this.cod = cod;
    }
}
