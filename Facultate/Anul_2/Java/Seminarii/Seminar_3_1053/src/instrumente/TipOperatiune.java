package instrumente;

public enum TipOperatiune {
    VANZARE(-1),
    CUMPARARE(1);

    int directie;

    TipOperatiune(int directie) {
        this.directie = directie;
    }
    public int getDirectie(){
        return this.directie;
    }

}
