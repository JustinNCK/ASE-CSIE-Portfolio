public class TableaTitluri {
    private String simbol;
    private String denumire;

    public TableaTitluri(String simbol, String denumire) {
        this.simbol = simbol;
        this.denumire = denumire;
    }

    public String getSimbol() {
        return simbol;
    }

    public void setSimbol(String simbol) {
        this.simbol = simbol;
    }

    public String getDenumire() {
        return denumire;
    }

    public void setDenumire(String denumire) {
        this.denumire = denumire;
    }
}
