package instrumente;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

public class PortofoliuGenerics<T> implements Serializable {
    private Map<String,T> portofoliu;

    public PortofoliuGenerics() {
        this.portofoliu = new HashMap<>();
    }

    public PortofoliuGenerics(Map<String, T> portofoliu) {
        this.portofoliu = portofoliu;
    }

    public Map<String, T> getPortofoliu() {
        return portofoliu;
    }

    public void setPortofoliu(Map<String, T> portofoliu) {
        this.portofoliu = portofoliu;
    }
    public void adaugaObiect(String cheie,T t)
    {
        this.portofoliu.put(cheie,t);
    }
    public T getObiect(String cheie){
        return this.portofoliu.get(cheie);
    }

    public void afisare() {
        for (var entry : portofoliu.entrySet()) {
            System.out.print(entry.getValue().toString());
        }
    }
}
