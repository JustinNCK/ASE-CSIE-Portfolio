/** Se se defineasca clasa OperatorBancar, clasa derivata din clasa Thread care sa permita
* operatiuni pe un obiect de tip cont. Clasa OperatorBancar are urmatoarele atribute:
*     private Cont cont;
*     private String nume;
*     private int timpPregatire;
*     private double suma;
*
* Sa se scrie un program care utilizeaza mai multi operatori bancari ce realizeza operatii
* in regim concurential pe o resursa comuna reprezentata de un Cont bancar.
* Programul primeste soldul contului si numarul de operatori ca argumente in linia de comanda.
*/
public class OperatorBancar extends Thread {
    private Cont cont;
    private String nume;
    private int timpPregatire;
    private double suma;

    public OperatorBancar(Cont cont, String nume, int timpPregatire, double suma) {
        this.cont = cont;
        this.nume = nume;
        this.timpPregatire = timpPregatire;
        this.suma = suma;
    }

    @Override
    public void run() {
        while(cont.getSold() >= this.suma) {
            try {
                sleep(this.timpPregatire);
                cont.retragere(this.suma, this.nume);
            } catch (InterruptedException e) {
//                throw new RuntimeException(e);
            }
        }
        System.out.println(this.nume + " a incheiat activitatea!");
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Numar incorect de argumente - utilizare <sold> <operatori>");
            System.exit(-1);
        }
        Cont cont = new Cont(Double.parseDouble(args[0]));
        System.out.println("Sold initial: " + cont.getSold());
        int nrOperatori = Integer.parseInt(args[1]);
        System.out.println("Nr. de operatori bancari: " + nrOperatori);

        Thread[] operatori = new OperatorBancar[nrOperatori];
        for (int i=0; i<nrOperatori; i++) {
            operatori[i] = new OperatorBancar(cont,
                    "Operator " + (i+1),
                    i*10 + 100,
                    i*10 + 50);
            operatori[i].start();
        }
        for (int i=0; i<nrOperatori; i++) {
            try {
                operatori[i].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        System.out.println("Sold final: " + cont.getSold());
    }
}
