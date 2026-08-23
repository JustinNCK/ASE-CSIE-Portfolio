import org.json.*;
import java.io.FileReader;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;


public class Main {
    static void main(String[] args){
        System.out.println("-------------exercitiul 1-------------");
        List<SpecialitatiMedicale> medicale = new ArrayList<>();
        try(FileReader f = new FileReader("src\\medicale.json")){
            var jsonMedicale = new JSONArray(new JSONTokener(f));
            for(int i = 0; i < jsonMedicale.length(); i++){
                var jsonMedical = jsonMedicale.getJSONObject(i);
                String specialitate = jsonMedical.getString("specialitate");
                var jsonManevre = jsonMedical.getJSONArray("manevre");
                List<Manevre> manevre = new ArrayList<>();
                for(int j = 0; j < jsonManevre.length(); j++){
                    var jsonManevra = jsonManevre.getJSONObject(j);
                    var manevra = new Manevre(
                            jsonManevra.getInt("cod"),
                            jsonManevra.getInt("durata"),
                            jsonManevra.getDouble("tarif")
                    );

                    manevre.add(manevra);
                }
                SpecialitatiMedicale medical = new SpecialitatiMedicale(specialitate, manevre);
                medicale.add(medical);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        System.out.printf("%-20s %-20s %-20s\n", "Specialitate", "Cod manevra", "Durata");
        for(SpecialitatiMedicale sm: medicale){
            List<Manevre> manevre_sortate = sm.getManevre().stream().sorted((m1, m2) -> Integer.compare(m2.getDurata(), m1.getDurata())).toList();
            for(Manevre m: manevre_sortate)
                System.out.printf("%-20s %-20d %-20d\n", sm.getSpecialitate(), m.getCod(), m.getDurata());
        }

        System.out.println("-------------exercitiul 2-------------");
        List<Consultatii> consultatii = new ArrayList<>();
        try(Connection con = DriverManager.getConnection("jdbc:sqlite:src/consultatii.db")){
            Statement stnt = con.createStatement();
            ResultSet rs = stnt.executeQuery("SELECT Specialitate, CodManevra, Numar FROM Consultatii");
            while(rs.next()){
                Consultatii consulatie = new Consultatii(
                        rs.getString("Specialitate"),
                        rs.getInt("Numar"),
                        rs.getInt("CodManevra")
                );
                consultatii.add(consulatie);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        System.out.printf("%-20s %-20s\n", "Specialitate", "Venit generat");
        for(SpecialitatiMedicale sm: medicale){
            List<Consultatii> consultatii_specialitati = consultatii.stream()
                    .filter(cs -> sm.getSpecialitate().trim().equals(cs.getSpecialitate().trim())).toList();
            double suma = 0.0f;
            for(Consultatii cs: consultatii_specialitati){
                suma += sm.getTarifCod(cs.getCod()) * cs.getNumar();
            }
            sm.setPret(suma);
        }
        List<SpecialitatiMedicale> ceva = medicale.stream().sorted((sm1, sm2) -> Double.compare(sm2.getPret(), sm1.getPret())).toList();
        for(SpecialitatiMedicale sm: ceva)
            System.out.printf("%-20s %-20.1f\n", sm.getSpecialitate(), sm.getPret());
    }
}
