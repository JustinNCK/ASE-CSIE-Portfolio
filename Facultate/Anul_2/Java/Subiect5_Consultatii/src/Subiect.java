import org.json.JSONArray;
import org.json.JSONObject;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RezolvareJava {
    public static void main(String[] args) {

        Map<Integer, Integer> cantitati = new HashMap<>();
        Map<Integer, Double> tarifManevre = new HashMap<>();
        Map<String, Double> venituriGenerate = new HashMap<>();

        // Citire fisier text
        try (BufferedReader br = new BufferedReader(new FileReader("date/produse.txt"))) {
            String linie;
            while ((linie = br.readLine()) != null) {
                String[] date = linie.split(",");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Citire fisier json
        try {
            String fisier = Files.readString(Paths.get("date/tranzactii.json"));
            JSONArray tranzactiiArray = new JSONArray(fisier);

            for (int i = 0; i < tranzactiiArray.length(); i++) {
                JSONObject tranzactiiObj = tranzactiiArray.getJSONObject(i);
                int codProdus = tranzactiiObj.getInt("codProdus");
                int cantitate = tranzactiiObj.getInt("cantitate");
                String tip = tranzactiiObj.getString("tip");

                int cantitateInitiala = cantitati.getOrDefault(codProdus, 0);

                if (tip.equals("intrare")) {
                    cantitati.put(codProdus, cantitateInitiala + cantitate);
                } else if (tip.equals("iesire")) {
                    cantitati.put(codProdus, cantitateInitiala - cantitate);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Citire baze de date
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:consultatii.db");
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT Specialitate, CodManevra, Numar FROM Consultatii")) {

            while (rs.next()) {
                String specialitate = rs.getString("Specialitate");
                int cod = rs.getInt("CodManevra");
                int numar = rs.getInt("Numar");

                if (tarifManevre.containsKey(cod)) {
                    double tarif = tarifManevre.get(cod);
                    double venitVechi = venituriGenerate.getOrDefault(specialitate, 0.0);
                    double venitNou = numar * tarif;
                    venituriGenerate.put(specialitate, venitVechi + venitNou);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        // Sortare Map in Lista
        List<Map.Entry<String, Double>> listaOrdonata = new ArrayList<>(venituriGenerate.entrySet());
        listaOrdonata.sort((intrare1, intrare2) -> intrare2.getValue().compareTo(intrare1.getValue()));

        // Scriere fisier text
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("date/lista.txt"))) {
            bw.write("Denumire Produs, Numar tranzactii");
            bw.newLine();

            for (Map.Entry<String, Double> rand : listaOrdonata) {
                bw.write(rand.getKey() + ", " + rand.getValue());
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Scriere baze de date (INSERT / UPDATE)
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:date/consultatii.db");
             PreparedStatement pstmt = conn.prepareStatement("INSERT INTO Consultatii (Specialitate, CodManevra, Numar) VALUES (?, ?, ?)")) {

            pstmt.setString(1, "Chirurgie");
            pstmt.setInt(2, 505);
            pstmt.setInt(3, 10);
            pstmt.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        // Scriere fisier json
        try (FileWriter file = new FileWriter("date/raport.json")) {
            JSONArray arrayFinal = new JSONArray();
            JSONObject clientNou = new JSONObject();

            clientNou.put("codProdus", 101);
            clientNou.put("tip", "intrare");
            clientNou.put("cantitate", 50);

            arrayFinal.put(clientNou);
            file.write(arrayFinal.toString(4));

        } catch (IOException e) {
            e.printStackTrace();
        }

        // Scriere fisier xml
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.newDocument();

            Element radacina = doc.createElement("medicale");
            doc.appendChild(radacina);

            Element spec = doc.createElement("specialitate");
            radacina.appendChild(spec);

            Element denumire = doc.createElement("denumire");
            denumire.setTextContent("Oftalmologie");
            spec.appendChild(denumire);

            Element manevra = doc.createElement("manevra");
            manevra.setAttribute("cod", "102");
            spec.appendChild(manevra);

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            transformer.setOutputProperty(OutputKeys.INDENT, "yes");

            DOMSource sursa = new DOMSource(doc);
            StreamResult fisierFinal = new StreamResult(new File("manevreMedicale.xml"));
            transformer.transform(sursa, fisierFinal);

        } catch (Exception e) {
            e.printStackTrace();
        }

        // Client TCP
        try (Socket socket = new Socket("localhost", 5511);
             ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
             ObjectInputStream in = new ObjectInputStream(socket.getInputStream())) {

            out.writeObject(101);
            double raspuns = (Double) in.readObject();

        } catch (Exception e) {
            e.printStackTrace();
        }

        // Server TCP
        try (ServerSocket serverSocket = new ServerSocket(5511);
             Socket socket = serverSocket.accept();
             ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
             ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream())) {

            int codPrimit = (Integer) in.readObject();
            out.writeObject(150.5);

        } catch (Exception e) {
            e.printStackTrace();
        }

        // Citire fisier XML
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(new File("date/input.xml"));
            doc.getDocumentElement().normalize();

            // Extragem toate tag-urile cu un anumit nume (ex: <manevra>)
            NodeList listaNoduri = doc.getElementsByTagName("manevra");

            for (int i = 0; i < listaNoduri.getLength(); i++) {
                Node nod = listaNoduri.item(i);

                if (nod.getNodeType() == Node.ELEMENT_NODE) {
                    Element element = (Element) nod;

                    // Citirea unui atribut: <manevra cod="102">
                    int cod = Integer.parseInt(element.getAttribute("cod"));

                    // Citirea textului dintre tag-uri: <denumire>Oftalmologie</denumire>
                    // String denumire = element.getElementsByTagName("denumire").item(0).getTextContent();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }


    }
}