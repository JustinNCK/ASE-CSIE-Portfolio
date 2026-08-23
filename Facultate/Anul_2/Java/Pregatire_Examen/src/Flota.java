import org.json.JSONArray;
import org.json.JSONTokener;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Flota <T extends Vehicul>{
    private List<T> flota = new ArrayList<>();

    public void adaugaVehicul(T vehicul) throws CapacitateDepasitaException {
        if(vehicul.getCapacitateTone() > 40.0f) {
            CapacitateDepasitaException e = new CapacitateDepasitaException("Capacitatea este depasita!!");
            throw e;
        }
        else{
            flota.add(vehicul);
        }
    }

    public void pornireFlota(){
        for(T v: flota)
            v.pornireCursa();
    }

    public Map<String, T> getVehiculeMap(){
        Map<String, T> mapa = flota.stream().
                collect(Collectors.toMap(v -> v.getNumarInmatriculare(), v -> v));
        return mapa;
    }

    public List<T> filtreazaSiSorteazaEficienta(double capacitateMinima) {
        List<T> flota_filtrata = flota.stream().
                filter(t -> t.getCapacitateTone() >= capacitateMinima).
                sorted((t1, t2) -> Double.compare(t2.calculeazaEficienta(), t1.calculeazaEficienta())).toList();

        return flota_filtrata;
    }

    public static List<String> citesteDestinatiiJSON(String caleFisier){
        List<String> destinatii = new ArrayList<>();
        try(FileReader f = new FileReader(caleFisier)) {
            var lista = new JSONArray(new JSONTokener(f));
            for(int i = 0; i < lista.length(); i++){
                var JSONvehicul = lista.getJSONObject(i);
                destinatii.add(JSONvehicul.getString("destinatie"));
            }

        } catch (IOException e) {
            System.out.printf("Fisierul JSON nu s-a putut deschide");
        }

        return destinatii;
    }

    public void exportaFlotaXML(String caleFisier) throws ParserConfigurationException, TransformerException {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        Document document = builder.newDocument();

        Element radacina = document.createElement("raport_flota");
        document.appendChild(radacina);
        for(Vehicul v: flota){
            Element elementVehicul = document.createElement("vehicul");
            elementVehicul.setAttribute("nrInmatriculare", v.getNumarInmatriculare());
            radacina.appendChild(elementVehicul);
        }

        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();

        DOMSource source = new DOMSource(document);

        javax.xml.transform.stream.StreamResult result = new javax.xml.transform.stream.StreamResult(new java.io.File(caleFisier));
        transformer.transform(source, result);
    }
}
