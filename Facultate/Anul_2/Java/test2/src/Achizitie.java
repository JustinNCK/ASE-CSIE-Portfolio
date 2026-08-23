public class Achizitie implements Comparable<Achizitie> {
    String cod;
    int an, luna, zi;
    int cantitate;
    float pret;

    public Achizitie(String cod, int an, int luna, int zi, int cantitate, float pret) {
        this.cod = cod;
        this.an = an;
        this.luna = luna;
        this.zi = zi;
        this.cantitate = cantitate;
        this.pret = pret;
    }

    public Achizitie(){
    }

    public String getCod() {
        return cod;
    }

    public void setCod(String cod) {
        this.cod = cod;
    }

    public int getAn() {
        return an;
    }

    public void setAn(int an) {
        this.an = an;
    }

    public int getLuna() {
        return luna;
    }

    public void setLuna(int luna) {
        this.luna = luna;
    }

    public int getZi() {
        return zi;
    }

    public void setZi(int zi) {
        this.zi = zi;
    }

    public int getCantitate() {
        return cantitate;
    }

    public void setCantitate(int cantitate) {
        this.cantitate = cantitate;
    }

    public float getPret() {
        return pret;
    }

    public void setPret(float pret) {
        this.pret = pret;
    }

    @Override
    public String toString() {
        return "Achizitie{" +
                "cod='" + cod + '\'' +
                ", an=" + an +
                ", luna=" + luna +
                ", zi=" + zi +
                ", cantitate=" + cantitate +
                ", pret=" + pret +
                '}';
    }

    float Valoare(){
        return this.pret * this.cantitate;
    }

    @Override
    public int compareTo(Achizitie o) {
        if (o == this)
            return 0;
        return Float.compare(this.Valoare(), o.Valoare());
    }
}
