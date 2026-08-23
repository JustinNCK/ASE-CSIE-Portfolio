package instrumente;

import java.io.Serializable;

public enum TipOperatiune implements Serializable {
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
