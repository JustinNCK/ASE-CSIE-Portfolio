import static java.lang.Math.abs;

public class Trotineta implements  Comparable<Trotineta>{
    String id;
    float distanta_totala;
    float viteza_medie;
    float viteza_max;

    public Trotineta(String id, float distanta_totala, float viteza_medie, float viteza_max) {
        this.id = id;
        this.distanta_totala = distanta_totala;
        this.viteza_medie = viteza_medie;
        this.viteza_max = viteza_max;
    }

    public Trotineta() {
    }

    public String getId() {
        return id;
    }

    public float getDistanta_totala() {
        return distanta_totala;
    }

    public float getViteza_medie() {
        return viteza_medie;
    }

    public float getViteza_max() {
        return viteza_max;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setDistanta_totala(float distanta_totala) {
        this.distanta_totala = distanta_totala;
    }

    public void setViteza_medie(float viteza_medie) {
        this.viteza_medie = viteza_medie;
    }

    public void setViteza_max(float viteza_max) {
        this.viteza_max = viteza_max;
    }

    @Override
    public String toString() {
        return "Trotineta{" +
                "id='" + id + '\'' +
                ", distanta_totala=" + distanta_totala +
                ", viteza_medie=" + viteza_medie +
                ", viteza_max=" + viteza_max +
                '}';
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass() )
            return false;
        Trotineta t = (Trotineta) obj;
        return abs(t.distanta_totala - this.getDistanta_totala()) < 10;
    }


    @Override
    public int compareTo(Trotineta o) {
        if(this.equals(o))
            return 0;

        return Float.compare(this.distanta_totala, o.distanta_totala);
    }
}