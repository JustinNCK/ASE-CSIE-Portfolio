package instrumente;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Instrument implements Evaluabil, Serializable {

     public static final class  Operatiune implements Serializable {
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
//             return "Operatiune{" +
//                     "tip=" + tip +
//                     ", data=" + data +
//                     ", pret=" + pret +
//                     ", cantitate=" + cantitate +
//                     '}';
             StringBuilder buffer = new StringBuilder();
             String separator = ",";
             buffer.append(this.getTip()); buffer.append(separator);
             buffer.append(this.getData().getYear()); buffer.append(separator);
             buffer.append(this.getData().getMonthValue()); buffer.append(separator);
             buffer.append(this.getData().getDayOfMonth()); buffer.append(separator);
             buffer.append(this.getPret()); buffer.append(separator);
             buffer.append(this.getCantitate()); buffer.append(separator);

             return buffer.toString();
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
//        return "Instrument{" +
//                "simbol='" + simbol + '\'' +
//                ", operatiuni=" + operatiuni +
//                '}';
        StringBuilder buffer = new StringBuilder();
        String separator = ",";
        buffer.append(this.getSimbol()); buffer.append(separator);
        buffer.append(this.valoare());
        buffer.append(System.lineSeparator());
        for (var op : this.operatiuni) {
            buffer.append(op.toString());
        }
        buffer.append(System.lineSeparator());

        return buffer.toString();
    }
}
