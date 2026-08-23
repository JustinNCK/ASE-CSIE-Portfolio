import org.json.JSONArray;
import org.json.JSONTokener;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.*;
import java.time.chrono.ThaiBuddhistChronology;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    static void main(String[] args){
        System.out.println("-------------exercitiul 1-------------");
        List<Sectii> sectii = new ArrayList<>();

        try(FileReader fr = new FileReader("src\\sectii.json")){
            var jsonSectii = new JSONArray(new JSONTokener(fr));
            for(int i = 0; i < jsonSectii.length(); i++){
                var jsonSectie =jsonSectii.getJSONObject(i);
                var sectie = new Sectii(
                        jsonSectie.getInt("cod_sectie"),
                        jsonSectie.getString("denumire"),
                        jsonSectie.getInt("numar_locuri"));
                sectii.add(sectie);
            }
        } catch (IOException e) {
            System.out.println("Nu s-a putut deschide fisierul JSON");
            throw new RuntimeException(e);
        }

        List<Sectii> sectii_locuri = sectii.stream().filter(s -> (s.getNumar_locuri() > 5)).toList();

        System.out.printf("%-20s\n", "Sectii");
        for(Sectii s: sectii_locuri)
            System.out.printf("%-20s\n", s.getDenumire());

        List<Pacienti> pacienti = new ArrayList<>();

        try (Connection con = DriverManager.getConnection("jdbc:sqlite:src/spital.db")){
            Statement stnt = con.createStatement();
            ResultSet rs = stnt.executeQuery("SELECT CNP, NumePacient, VarstaPacient, CodSectie FROM Pacienti");
            while(rs.next()){
                Pacienti p = new Pacienti(rs.getLong("CNP"), rs.getString("NumePacient"), rs.getInt("VarstaPacient"), rs.getInt("CodSectie"));

                pacienti.add(p);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        System.out.println("-------------exercitiul 2-------------");
        System.out.printf("%-20s %-20s %-20s\n", "Sectii", "Denumire Sectie", "Numar pacienti");
        for(Sectii s: sectii){
            long nr_pacienti = pacienti.stream().filter(p -> String.valueOf(p.getCod_sectie()).equals(String.valueOf(s.getCod_sectie()))).count();
            System.out.printf("%-20d %-20s %-20d\n", s.getCod_sectie(), s.getDenumire(), nr_pacienti);
        }

        System.out.println("-------------exercitiul 3-------------");
        try (PrintWriter pr = new PrintWriter(new FileWriter("src\\situatie.txt"))){
            pr.printf("%-20s %-20s %-20s %-20s\n", "Cod sectie", "Denumire Sectie", "Numar locuri", "Varsta medie");
            for(Sectii s: sectii){
                List<Pacienti> pacienti_varsta = pacienti.stream().filter(p -> String.valueOf(p.getCod_sectie()).equals(String.valueOf(s.getCod_sectie()))).toList();
                double varsta_medie = 0.0f;
                for(Pacienti p: pacienti_varsta)
                    varsta_medie += p.getVarsta();

                if(varsta_medie != 0)
                    s.setVarsta_medie(varsta_medie / pacienti_varsta.size());
            }

            List<Sectii> lista_sectii_varsta_medie = sectii.stream().sorted((s1, s2) -> Double.compare(s2.getVarsta_medie(), s1.getVarsta_medie())).toList();
            for(Sectii s: lista_sectii_varsta_medie)

                pr.printf("%-20d %-20s %-20d %-20.1f\n", s.getCod_sectie(), s.getDenumire(), s.getNumar_locuri(), s.getVarsta_medie());

        } catch (IOException e) {
            throw new RuntimeException(e);
        }


        System.out.println("-------------exercitiul 4-------------");
        new Thread(() -> {
            try(ServerSocket serverSocket = new ServerSocket(8088)){
                try (Socket socket = serverSocket.accept()) {
                    BufferedReader bf = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    int cod_sectie = Integer.parseInt(bf.readLine());
                    PrintWriter pr = new PrintWriter(socket.getOutputStream(), true);
                    for(Sectii s: sectii)
                        if(s.getCod_sectie() == cod_sectie) {
                            long nr_pacienti = pacienti.stream().filter(p -> String.valueOf(p.getCod_sectie()).equals(String.valueOf(s.getCod_sectie()))).count();
                            pr.println(s.getNumar_locuri() - nr_pacienti);
                        }

                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                } catch(IOException e){
                    throw new RuntimeException(e);
                }
        }).start();

        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        try (Socket client = new Socket("localhost", 8088)){
            PrintWriter pr = new PrintWriter(client.getOutputStream(), true);
            pr.println("2");

            BufferedReader bf = new BufferedReader(new InputStreamReader(client.getInputStream()));
            System.out.println(bf.readLine());

        } catch (IOException e) {
            throw new RuntimeException(e);
        }


    }
}
