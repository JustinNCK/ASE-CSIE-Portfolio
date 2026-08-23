package instrumente;

import java.util.List;

public class Actiune extends Instrument implements Evaluabil{
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
        return "Actiune{" +
                super.toString() +
                "procentDividend=" + procentDividend +
                '}';
    }
}
