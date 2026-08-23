package instrumente;

import java.io.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MainInstrumente {

    static void salvarePortofoliu(String caleFisier, PortofoliuGenerics<Instrument> portofoliu)
            throws IOException {
        if (new File(caleFisier).getParentFile() != null) {
            new File(caleFisier).getParentFile().mkdirs();
        }

        try(PrintWriter fisier = new PrintWriter(new BufferedWriter(new FileWriter(caleFisier)))) {
            for(var entry : portofoliu.getPortofoliu().entrySet()) {
                fisier.print(entry.getValue().toString());
            }
        }
    }

    static PortofoliuGenerics<Instrument> incarcarePortofoliu(String caleFisier)
            throws IOException {
        PortofoliuGenerics<Instrument> portofoliu = new PortofoliuGenerics<>();

        try(var scanerFisier = new Scanner(new BufferedReader(new FileReader(caleFisier)))) {
            while (scanerFisier.hasNext()) {
                String linie_1 = scanerFisier.nextLine();
                Scanner scanerLinie = new Scanner(linie_1);
                scanerLinie.useDelimiter("[\\,]+");
                String simbol = scanerLinie.next();
//                double valoare = scanerLinie.nextDouble();  // depinde de loacalizare si codificarea punctului zecimal
                double valoare = Double.parseDouble(scanerLinie.next());
                double dividend = -1.0;
                if (scanerLinie.hasNext()) {
//                    dividend = scanerLinie.nextDouble();
                    dividend = Double.parseDouble(scanerLinie.next());
                }

                String linie_2 = scanerFisier.nextLine();
                scanerLinie = new Scanner(linie_2);
                scanerLinie.useDelimiter("[\\,]+");
                List<Instrument.Operatiune> operatiuni = new ArrayList<>();
                while (scanerLinie.hasNext()) {
                    Instrument.Operatiune op = new Instrument.Operatiune(
                            TipOperatiune.valueOf(scanerLinie.next()),
                            LocalDate.of(scanerLinie.nextInt(), scanerLinie.nextInt(), scanerLinie.nextInt()),
//                            scanerLinie.nextDouble(),
                            Double.parseDouble(scanerLinie.next()),
                            scanerLinie.nextInt());
                    operatiuni.add(op);
                }
                if (dividend < 0) { // avem un Instrument
                   Instrument instrument = new Instrument(simbol, operatiuni);
                   portofoliu.adaugaObiect(simbol, instrument);
                } else { //avem o Actiune
                    Actiune actiune = new Actiune(simbol, operatiuni, dividend);
                    portofoliu.adaugaObiect(simbol, actiune);
                }
            }
        }

        return portofoliu;
    }

    public static void main(String[] args) {

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
        portofoliu.adaugaObiect(i1.getSimbol(), i1);

        Actiune a1 = new Actiune("TLV", listaOperatiuni, 3.5);
        portofoliu.adaugaObiect(a1.getSimbol(), a1);

        // afisare continut portofoliu
        portofoliu.afisare();

        // salvare portofoliu iin fiseir text (CSV)
        try {
            salvarePortofoliu("./portofolii/MyPortfolios/portofoliu.csv", portofoliu);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // incarcare in memorie a unui portofoliu din fisier text
        PortofoliuGenerics<Instrument> portofoliuDinText = new PortofoliuGenerics<>();
        try {
            portofoliuDinText = incarcarePortofoliu("./portofolii/MyPortfolios/portofoliu.csv");
            portofoliuDinText.afisare();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // TODO
        // sa se implemneteze metode de salvare in fisier si incarcare portofoliu din fisier pentru:
        // 1. fisier binar bazat pe DataOutputStream / DataInputStream
        // 2. fisier binar bazat pe ObjectOutputStream / ObjectInputStream
    }
}
