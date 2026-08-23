import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args){
        Map<String, Trotineta> mapTrotineta = new HashMap<>();
        try(BufferedReader br = new BufferedReader(new FileReader("trotinete.txt"))){
            String linie;
            while((linie = br.readLine()) != null){
                String[]valori = linie.split("\t");
                if(valori.length == 4){
                    String id = valori[0];
                    float distanta_totala = Float.parseFloat(valori[1]);
                    float viteza_medie = Float.parseFloat(valori[2]);
                    float viteza_max = Float.parseFloat(valori[3]);

                    Trotineta t = new Trotineta(id, distanta_totala, viteza_medie, viteza_max);
                    mapTrotineta.put(id, t);
                }
            }
        }catch (IOException e){
            System.err.println("Eroare la citirea fisierului");
        }
        System.out.println("Trotinete cu viteza mai mare de 50km/h: ");
        mapTrotineta.values().stream()
                .filter(t -> t.getViteza_max() > 50)
                .forEach(System.out::println);

        Map<Float, List<Trotineta>> grupareViteza = mapTrotineta.values().stream()
                .collect(Collectors.groupingBy(Trotineta::getViteza_medie));

        System.out.println("\nGrupate dupa viteza medie:");
        grupareViteza.forEach((vitezaMedie, lista) ->{
            int nrTrotinete = lista.size();
            double sumaDistante = lista.stream().mapToDouble(Trotineta::getDistanta_totala).sum();

            System.out.printf("viteza medie %.0f km/h -> %d trotinete, suma distanțelor parcurse %.0f km\n",
                    vitezaMedie, nrTrotinete, sumaDistante);
        });

    }
}
