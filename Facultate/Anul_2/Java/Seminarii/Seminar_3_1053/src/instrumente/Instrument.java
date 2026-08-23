package instrumente;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Instrument implements Evaluabil {

     public static final class  Operatiune{
        private final TipOperatiune tip;
        private final LocalDate data;
        private final double pret;
        private final int cantitate;

         public Operatiune(TipOperatiune tip, LocalDate data, double pret, int cantitate) {
             this.tip = tip;
             this.data = data;
             this.pret = pret;
             this.cantitate = cantitate;
         }

         public TipOperatiune getTip() {
             return tip;
         }

         public LocalDate getData() {
             return data;
         }

         public double getPret() {
             return pret;
         }

         public int getCantitate() {
             return cantitate;
         }

         @Override
         public String toString() {
             return "Operatiune{" +
                     "tip=" + tip +
                     ", data=" + data +
                     ", pret=" + pret +
                     ", cantitate=" + cantitate +
                     '}';
         }

     }
    private String simbol;
    private List<Operatiune> operatiuni;

    public Instrument(String simbol, List<Operatiune> operatiuni) {
        this.simbol = simbol;
        this.operatiuni = operatiuni;
    }

    public Instrument() {
        this.operatiuni = new ArrayList<>();
    }
    public void adaugaOperatiune(Operatiune operatiune){
        this.operatiuni.add(operatiune);
    }

    public String getSimbol() {
        return simbol;
    }

    public List<Operatiune> getOperatiuni() {
        return operatiuni;
    }

    @Override
    public double valoare() {
        double valoare = 0;
        for (var operatiune : this.operatiuni
             ) {
            valoare += operatiune.getPret() * operatiune.getCantitate() * operatiune.getTip().getDirectie();
        }
        return valoare;
    }

    @Override
    public String toString() {
        return "Instrument{" +
                "simbol='" + simbol + '\'' +
                ", operatiuni=" + operatiuni +
                '}';
    }
}
