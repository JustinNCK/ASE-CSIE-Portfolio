import java.util.List;

public class SpecialitatiMedicale {
    private String specialitate;
    List<Manevre> manevre;
    private double pret;

    public SpecialitatiMedicale(String specialitate, List<Manevre> manevre) {
        this.specialitate = specialitate;
        this.manevre = manevre;
        pret = 0.0f;
    }

    public String getSpecialitate() {
        return specialitate;
    }

    public void setSpecialitate(String specialitate) {
        this.specialitate = specialitate;
    }

    public List<Manevre> getManevre() {
        return manevre;
    }

    public void setManevre(List<Manevre> manevre) {
        this.manevre = manevre;
    }

    public double getPret() {
        return pret;
    }

    public void setPret(double pret) {
        this.pret = pret;
    }

    public double getTarifCod(int cod){
        for(Manevre m: manevre)
            if(m.getCod() == cod)
                return m.getTarif();
        return 0.0f;
    }
}
