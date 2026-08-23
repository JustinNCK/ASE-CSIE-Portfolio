package instrumente;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MainInstrumente {
    public static void main(String[] args){

        PortofoliuGenerics<Instrument> portofoliu = new PortofoliuGenerics<>();
        Instrument.Operatiune o1 = new Instrument.Operatiune(TipOperatiune.CUMPARARE,
                LocalDate.of(2025,11,15),
                12.3,100);
        Instrument.Operatiune o2 = new Instrument.Operatiune(TipOperatiune.CUMPARARE,
                LocalDate.of(2025,11,15),
                12.1,50);
        Instrument.Operatiune o3 = new Instrument.Operatiune(TipOperatiune.VANZARE,
                LocalDate.of(2025,11,16),
                12.7,70);
        List<Instrument.Operatiune> listaOperatiuni = new ArrayList<>();
        Collections.addAll(listaOperatiuni,o1,o2,o3);
        Instrument i1 = new Instrument("BRD",listaOperatiuni);
        portofoliu.adaugaObiect(i1);
    }
}
