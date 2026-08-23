import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.Buffer;
import java.sql.*;
import java.util.*;

public class Main {
    public Main() throws SQLException {
    }

    public static void main(String[] args) {
        List<PretVolum> preturi = new ArrayList<>();

        // 1. Citirea din fișier
        try (BufferedReader bf = new BufferedReader(new FileReader("src\\PretVolum.txt"))) {
            String linie;
            // Sărim peste capul de tabel dacă fișierul are unul, altfel prima linie va fi ignorată!
            linie = bf.readLine();
            while ((linie = bf.readLine()) != null) {
                String[] valori = linie.split(",");
                if (valori.length == 6) {
                    String simbol = valori[0];
                    double pret_deschidere = Double.parseDouble(valori[1].trim());
                    double pret_max = Double.parseDouble(valori[2].trim());
                    double pret_min = Double.parseDouble(valori[3].trim());
                    double pret_inchidere = Double.parseDouble(valori[4].trim());
                    long volum = Long.parseLong(valori[5].trim()); // Folosit Long.parseLong pentru volum (long)

                    PretVolum pv = new PretVolum(simbol, pret_deschidere, pret_max, pret_min, pret_inchidere, volum);
                    preturi.add(pv);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // Prima cerință: Sortare crescătoare după valoare
        List<PretVolum> preturi_soratet = preturi.stream()
                .sorted((p1, p2) -> Double.compare(p1.valoare(), p2.valoare()))
                .toList();

        System.out.println("-------prima cerinta-------");
        System.out.printf("%-30s %-30s\n", "Simbol", "Valoare");
        if (!preturi_soratet.isEmpty()) {
            System.out.printf("%-30s %-30.1f\n", preturi_soratet.getFirst().getSimbol(), preturi_soratet.getFirst().valoare());
            System.out.printf("%-30s %-30.1f\n", preturi_soratet.getLast().getSimbol(), preturi_soratet.getLast().valoare());
        }

        Map<String, String> tabeleTitluri = new HashMap<>();

        try (Connection con = DriverManager.getConnection("jdbc:sqlite:D:/de toate/Facultate/An II/SEM 2/Java/Subiect1/src/Titluri.db")) {
            Statement stnt = con.createStatement();
            ResultSet rs = stnt.executeQuery("SELECT Simbol, Denumire FROM Titluri");

            while (rs.next()) {
                String simbol = rs.getString("Simbol");
                String denumire = rs.getString("Denumire");

                tabeleTitluri.put(simbol, denumire);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        List<PretVolum> lista_descrescator = preturi.stream()
                .sorted((p1, p2) -> Long.compare(p2.getVolum(), p1.getVolum()))
                .toList();

        System.out.println("-------a doua cerinta-------");
        System.out.printf("%-30s %-30s %-30s\n", "Simbol", "Denumire", "Volum");
        for(PretVolum pv: lista_descrescator){
            System.out.printf("%-30s %-30s %-30d\n", pv.getSimbol(), tabeleTitluri.get(pv.getSimbol()), pv.getVolum());
        }


        List<PretVolum> lista_descrescator_pret = preturi.stream()
                .sorted((p1, p2) -> Double.compare((p2.getPret_max() - p2.getPret_min()), (p1.getPret_max() - p1.getPret_min())))
                .toList();

        System.out.println("-------a trei cerinta-------");
        System.out.printf("%-30s %-30s %-30s\n", "Simbol", "Denumire", "Diferenta");
        for(PretVolum pv: lista_descrescator_pret){
            if((pv.getPret_max() - pv.getPret_min()) > (pv.getPret_inchidere() * 0.01))
                System.out.printf("%-30s %-30s %-30.1f\n", pv.getSimbol(), tabeleTitluri.get(pv.getSimbol()), (pv.getPret_max() - pv.getPret_min()));
        }

        new Thread(() -> {
            try (ServerSocket serverSocket = new ServerSocket(8080)) {
                while(true){
                    try (Socket serverClient = serverSocket.accept()) {
                        BufferedReader bfi = new BufferedReader(new InputStreamReader(serverClient.getInputStream()));
                        String simbol;
                        while((simbol = bfi.readLine()) != null) {
                            String sim = simbol;
                            PretVolum pv = preturi.stream().filter(v -> (sim.equals(v.getSimbol()))).findFirst().orElse(null);

                            PrintWriter pr = new PrintWriter(serverClient.getOutputStream(), true);
                            if (pv != null)
                                pr.println(tabeleTitluri.get(simbol) + " " + pv.getPret_inchidere() + " " + pv.getVolum());
                        }
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                }
            } catch (IOException e) {
                System.out.println("Serverul nu s-a putut deschide");
            }
        }).start();

        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        try (Socket socket = new Socket("localhost", 8080)) {
            PrintWriter pr = new PrintWriter(socket.getOutputStream(), true);
            pr.println("AADR");
            pr.println("AAME");

            BufferedReader bfi = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            String ceva = bfi.readLine();
            String ceva1 = bfi.readLine();

            System.out.println(ceva);
            System.out.println(ceva1);

        } catch (IOException e) {
            System.out.println("Clientul nu s-a putut deschide");
        }
    }
}