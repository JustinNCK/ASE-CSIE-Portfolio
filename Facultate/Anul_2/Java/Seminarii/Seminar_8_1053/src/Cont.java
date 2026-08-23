/** Sa se implementeze clasa Cont (double sold, boolean inOperare) pentru a oferi operatiuni de:
 * - depunere(double suma, String mesaj)
 * - retragere(double suma, String mesaj)
 * - getSold()
 */

public class Cont {
    private double sold;
    private boolean inOperare;

    public Cont(double sold) {
        this.sold = sold;
    }

    public synchronized double getSold() {
        return this.sold;
    }

    public synchronized double depunere(double suma, String mesaj) {
        while(this.inOperare) {
            try {
                wait();
            } catch (InterruptedException e) {
//                throw new RuntimeException(e);
            }
        }
        this.inOperare = true;
        this.sold += suma;
        System.out.println(mesaj + " depunere efectuata cu succes, suma " +
                suma + ", sold " + getSold());
        notifyAll();
        this.inOperare = false;

        return this.sold;
    }

    public synchronized double retragere(double suma, String mesaj) {
        while (this.inOperare) {
            try {
                wait();
            } catch (InterruptedException e) {
//                throw new RuntimeException(e);
            }
        }
        this.inOperare = true;
        double rezultat = -1;
        if (this.sold < suma) {
            System.out.println(mesaj + " fonduri insuficiente pentru suma " +
                    suma + ", sold " + getSold());
        } else {
            this.sold -= suma;
            System.out.println(mesaj + " retragere efectuata cu succes, suma " +
                    suma + ", sold " + getSold());
            rezultat = getSold();
        }
        notifyAll();
        this.inOperare = false;

        return rezultat;
    }
}
