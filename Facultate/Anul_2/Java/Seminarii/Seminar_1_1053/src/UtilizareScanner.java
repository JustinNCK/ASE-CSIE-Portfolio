import java.util.Scanner;


public class UtilizareScanner {
    public static void main(String[] args) {
        Scanner scaner = new Scanner(System.in);
        // indirectam tastatura catre intanta de Scanner
        scaner.useDelimiter("[\\s, \\,, \\;]+");
        // o lista de separatori care pot aparea
        // de mai multeori in fluxul de intrare
        System.out.println("Introduceti varsta si numele studentului:");
//        int vasta = scaner.nextInt();
        int vasta = Integer.parseInt(scaner.next());
        String nume = scaner.next();
        System.out.println("Varsta: " + vasta + ", Numele: " + nume);

    }
}
