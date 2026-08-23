import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Main {
    static public void main(){
        List<Achizitie> lista = new ArrayList<>();

        try(BufferedReader br = new BufferedReader(new FileReader("achizii.txt"))){
            String linie;
            while((linie = br.readLine()) != null){
                String[]valori =linie.split("\n");
                if(valori.length == 6) {
                    String id = valori[0];
                    int an = Integer.parseInt(valori[1]);
                    int luna = Integer.parseInt(valori[2]);
                    int zi = Integer.parseInt(valori[3]);
                    int cantitate = Integer.parseInt(valori[4]);
                    float pret = Float.parseFloat(valori[5]);

                    Achizitie a = new Achizitie(id, an, luna, zi, cantitate, pret);
                    lista.add(a);
                }
            }
        }catch (IOException e){
            System.out.println("Nu s-a putut deschide fisierul");
        }

        System.out.println("Achiziitile efectuate in prima jumatate a lunii si au o canitate mai mare ca 100:");
        lista.stream().filter(a -> (a.getLuna() < 15 && a.getCantitate() > 100))
                .forEach(System.out::println);

        Map<String, List<Achizitie>> mapaAchzitii = lista.stream()
                .collect(Collectors.groupingBy(Achizitie::getCod));


    }
}
