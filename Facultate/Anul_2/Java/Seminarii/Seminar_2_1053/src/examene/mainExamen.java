package examene;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class mainExamen {

//    static Scanner scaner = new Scanner(System.in);

    static Scanner scaner;

    static {
        try {
            scaner = new Scanner(new File("./src/examene.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {

        // creare masiv de 3 subiecte
        Subiect[] s_1 = new Subiect[3];
        for (int i=0; i<s_1.length; i++)
            s_1[i] = new Subiect(10+(i+1), "Enunt " + (i+1));

        Examen e_1 = new Examen("PAW", Tip.ORAL, s_1);
        System.out.println(e_1.toString());

        // preluare continut Examen de la tastatura
//        System.out.print("Introduceti numele disciplinei:");
        String disciplina = scaner.nextLine();
//        System.out.print("Introduceti tipul examenului:");
        Tip tipExamen = Tip.NECUNOSCUT;
//        String stringTip = scaner.nextLine();
//        if (stringTip.equalsIgnoreCase("ORAL"))
//            tipExamen = Tip.ORAL;
        tipExamen = Tip.valueOf(scaner.nextLine().toUpperCase());

//        System.out.print("Introduceti numarul de subiecte:");
        int numarSubiecte = Integer.parseInt(scaner.nextLine());
//        System.out.println("Introduceti subiectele, cate unul pe linie:");
        Subiect[] s_2 = new Subiect[numarSubiecte];
        for (int i=0; i<numarSubiecte; i++)
            s_2[i] = new Subiect(scaner.nextInt(), scaner.nextLine().trim());
        Examen e_2 = new Examen(disciplina, tipExamen, s_2);
        System.out.println(e_2);

        // compare egalitate intre doua obiecte de tip Examen
        if (e_1.equals(e_2))
            System.out.println("Examenele sunt identice!");
        else
            System.out.println("Examenele sunt diferite!");

        // clonam un examen si verificam pentru deep copy
        Examen e_3;
        try {
            e_3 = (Examen) e_2.clone();
            System.out.println(e_3.toString());
        } catch (CloneNotSupportedException e) {
            throw new RuntimeException(e);
        }
        if (e_3.equals(e_2))
            System.out.println("Examenele sunt identice!");
        else
            System.out.println("Examenele sunt diferite!");

    }
}
