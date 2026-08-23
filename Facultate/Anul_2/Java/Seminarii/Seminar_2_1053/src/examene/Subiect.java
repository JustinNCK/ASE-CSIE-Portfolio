package examene;

public class Subiect {
    private int numar;
    private String enunt;

    public Subiect() {
    }

    public Subiect(int numar, String enunt) {
        this.numar = numar;
        this.enunt = enunt;
    }

    public int getNumar() {
        return numar;
    }

    public void setNumar(int numar) {
        this.numar = numar;
    }

    public String getEnunt() {
        return enunt;
    }

    public void setEnunt(String enunt) {
        this.enunt = enunt;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Subiect subiect)) return false;

        if (getNumar() != subiect.getNumar()) return false;
        return getEnunt().equals(subiect.getEnunt());
    }

    @Override
    public int hashCode() {
        int result = getNumar();
        result = 31 * result + getEnunt().hashCode();
        return result;
    }

    @Override
    public String toString() {
        return "Subiect{" +
                "numar=" + numar +
                ", enunt='" + enunt + '\'' +
                '}';
    }
}
