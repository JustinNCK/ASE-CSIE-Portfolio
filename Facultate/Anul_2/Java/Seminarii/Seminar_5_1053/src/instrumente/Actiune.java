package instrumente;

import java.io.Serializable;
import java.util.List;

public class Actiune extends Instrument implements Evaluabil, Serializable {
    private double procentDividend;
    @Override
    public double valoare() {

        return super.valoare()+super.valoare()*this.procentDividend/100;
    }

    public Actiune(String simbol, List<Operatiune> operatiuni, double procentDividend) {
        super(simbol, operatiuni);
        this.procentDividend = procentDividend;
    }

    public double getProcentDividend() {
        return procentDividend;
    }

    @Override
    public String toString() {
//        return "Actiune{" +
//                super.toString() +
//                "procentDividend=" + procentDividend +
//                '}';
        StringBuilder buffer = new StringBuilder();
        String separator = ",";
        buffer.append(this.getSimbol()); buffer.append(separator);
        buffer.append(this.valoare()); buffer.append(separator);
        buffer.append(this.procentDividend);
        buffer.append(System.lineSeparator());
        for (var op : this.getOperatiuni()) {
            buffer.append(op.toString());
        }
        buffer.append(System.lineSeparator());

        return buffer.toString();
    }
}
