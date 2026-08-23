class Intreg {
    public int valoare;

    public Intreg(int valoare) {
        this.valoare = valoare;
    }
}

public class TrasferParametri {
    static void interschimb(int a, int b) {
        int aux = a;
        a = b;
        b = aux;
    }

    static void interschimb_2(Integer a, Integer b) {
        int aux = a.intValue();
        a = b;
        b = aux;
    }

    static void interschimb_3(int[] vector) {
        int aux = vector[0];
        vector[0] = vector[1];
        vector[1] = aux;
    }

    static void interschimb_4(Intreg a, Intreg b) {
        Intreg aux = new Intreg(a.valoare);
        a.valoare = b.valoare;
        b.valoare = aux.valoare;
    }

    public static void main(String[] args) {
//        System.out.println("Buna din Java!");
        if (args.length != 2) {
            System.out.println("Numar incorect de argumente! Utilizare: program <arg1> <arg2>");
            System.exit(-1);
        }
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        System.out.println("Inainte de interschimb a=" + a + ", b=" + b);
        interschimb(a, b);
        System.out.println("Dupa interschimb a=" + a + ", b=" + b);

        Integer x = a;
        Integer y = b;
        System.out.println("Inainte de interschimb x=" + x + ", y=" + y);
        interschimb_2(x, y);
        System.out.println("Dupa interschimb x=" + x + ", y=" + y);

        int[] vector = new int[2];
        vector[0] = a;
        vector[1] = b;
        System.out.println("Inainte de interschimb elem.1= " + vector[0] + ", elem.2= " + vector[1]);
        interschimb_3(vector);
        System.out.println("Dupa interschimb elem.1= " + vector[0] + ", elem.2= " + vector[1]);

        Intreg e = new Intreg(a);
        Intreg f = new Intreg(b);
        System.out.println("Inainte de interschimb e=" + e.valoare + ", f=" + f.valoare);
        interschimb_4(e, f);
        System.out.println("Dupa interschimb e=" + e.valoare + ", f=" + f.valoare);
    }
}
