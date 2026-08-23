import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static java.util.Map.entry;


class Profesor {
    private final int idProfesor;
    private final String prenume;
    private final String nume;
    private final String departament;

    public Profesor(int idProfesor, String prenume, String nume, String departament) {
        this.idProfesor = idProfesor;
        this.prenume = prenume;
        this.nume = nume;
        this.departament = departament;
    }

    public int getIdProfesor() {
        return idProfesor;
    }

    public String getPrenume() {
        return prenume;
    }

    public String getNume() {
        return nume;
    }

    public String getNumeComplet(){
        return getNume() + " " + getPrenume();
    }

    public String getDepartament() {
        return departament;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Profesor{");
        sb.append("idProfesor=").append(idProfesor);
        sb.append(", prenume='").append(prenume).append('\'');
        sb.append(", nume='").append(nume).append('\'');
        sb.append(", departament='").append(departament).append('\'');
        sb.append('}');
        return sb.toString();
    }
}

class Programare {
    private final String ziua;
    private final String interval;
    private final Profesor profesor;
    private final String disciplina;
    private final String sala;
    private final boolean esteCurs;
    private final String formatie;

    public Programare(String ziua, String interval, Profesor profesor, String disciplina, String sala, boolean esteCurs, String formatie) {
        this.ziua = ziua;
        this.interval = interval;
        this.profesor = profesor;
        this.disciplina = disciplina;
        this.sala = sala;
        this.esteCurs = esteCurs;
        this.formatie = formatie;
    }

    public String getZiua() {
        return ziua;
    }

    public String getInterval() {
        return interval;
    }

    public Profesor getProfesor() {
        return profesor;
    }

    public String getDisciplina() {
        return disciplina;
    }

    public String getSala() {
        return sala;
    }

    public boolean esteCurs() {
        return esteCurs;
    }

    public String getFormatie() {
        return formatie;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Programare{");
        sb.append("ziua='").append(ziua).append('\'');
        sb.append(", interval='").append(interval).append('\'');
        sb.append(", profesor=").append(profesor);
        sb.append(", disciplina='").append(disciplina).append('\'');
        sb.append(", sala='").append(sala).append('\'');
        sb.append(", esteCurs=").append(esteCurs);
        sb.append(", formatie='").append(formatie).append('\'');
        sb.append('}');
        return sb.toString();
    }
}

public class Orar {
    public static void afisareOrarGrupa(String grupa, List<Programare> programari,
                                        Map<String, List<String>> componentaSerii) {
//        System.out.println(programari);
//        System.out.println(componentaSerii);

        // Determinarea seriei din care face parte grupa primita ca parametru
        String seria = "";
        for(var entry : componentaSerii.entrySet()) {
            for (var g : entry.getValue())
            {
                if (g.equals(grupa)) {
                    seria = entry.getKey();
                    break;
                }
            }
            if (!seria.isEmpty())
                break;
        }
        System.out.println(seria);

        // Tiparire antet
        System.out.printf("%-10s %-20s %-50s %-10s %-10s%n",
                "Ziua", "Interval orar", "Disciplina", "Sala", "Curs/Seminar");

        // Afisare orar grupa
        // TODO
    }

    public static void main(String[] args) throws Exception {

        // 1. Citire date
        Map<Integer, Profesor> profesori;
        List<Programare> programari;
        // TODO
        try(var fisierProfesor = new BufferedReader(new FileReader("./dataIN/profesori.txt"))){
            profesori = fisierProfesor.lines()
                    .map(linie -> new Profesor(Integer.valueOf(linie.split("\t")[0]),
                            linie.split("\t")[1],
                            linie.split("\t")[2],
                            linie.split("\t")[3]))
                    .collect(Collectors.toMap(Profesor::getIdProfesor, Function.identity()));
        }

        profesori.entrySet().stream()
                .forEach(entry -> System.out.println(entry.getValue().toString()));

        try(var fisierProgramare = new BufferedReader(new FileReader("./dataIN/programari.txt"))){
            programari = fisierProgramare.lines()
                    .map(linie -> new Programare(
                            linie.split("\t")[0],
                            linie.split("\t")[1],
                            profesori.get(Integer.valueOf(linie.split("\t")[2])),
                            linie.split("\t")[3],
                            linie.split("\t")[4],
                            Boolean.valueOf(linie.split("\t")[5]),
                            linie.split("\t")[6]))
                    .collect(Collectors.toList());
        }

        programari.stream()
//                .forEach(programare -> System.out.println(programare.toString()));
                .forEach(System.out::println);

        // 2. Prelucrari
        // Afișare lista cursuri în ordine alfabetică
        programari.stream()
                .filter(Programare::esteCurs)
                .map(Programare::getDisciplina)
                .distinct()
                .sorted()
                .forEach(System.out::println);

//        programari.stream()
//                .filter(Programare::esteCurs)
//                .map(Programare::getDisciplina)
//                .distinct()
//                .sorted(Comparator.reverseOrder())
//                .forEach(System.out::println);

        // Afișare număr de activități pentru fiecare profesor
        System.out.printf("%40s\t%2s\t%2s\n", "Profesor", "C", "S");
        programari.stream()
                .collect(Collectors.groupingBy(Programare::getProfesor))
                .forEach((prof, progProf) ->
                    System.out.printf("%40s\t%2d\t%2d\n", prof.getNumeComplet(),
                            progProf.stream()
                                    .filter(Programare::esteCurs)
                                    .count(),
                            progProf.stream()
                                    .filter(programare -> !programare.esteCurs())
                                    .count())
                );


        // Lista departamentelor ordonate descrescator dupa numărul de activități
        // Definire clasa interna Departament: (String) denumire, (long) numarActivitati
        class Departament {
            String denumire;
            long numarActivitati;

            public Departament(String denumire, long numarActivitati) {
                this.denumire = denumire;
                this.numarActivitati = numarActivitati;
            }

            @Override
            public String toString() {
//                return "Departament{" +
//                        "denumire='" + denumire + '\'' +
//                        ", numarActivitati=" + numarActivitati +
//                        '}';
                return String.format("%-80s\t%d", denumire, numarActivitati);
            }
        }
        System.out.printf("%-80s\t%s\n", "Denumire departament", "#Activitati");
        programari.stream()
                .map(programare -> programare.getProfesor().getDepartament())
                .distinct()
                .map(denumire -> new Departament(denumire,
                        programari.stream()
                                .map(programare -> programare.getProfesor().getDepartament())
                                .filter(denDep -> denDep.equals(denumire))
                                .count()))
                // sortare in ordine descrescatoare
                .sorted((d1, d2) -> Long.compare(d2.numarActivitati, d1.numarActivitati))
                .forEach(System.out::println);

//        Componența seriilor este primită ca parametru sub formă de dicționar
//        construit în programul principal cu următoarele valori:
//        C: 1045,1046,1047,1048,1049
//        D: 1050,1051,1052,1053,1054
//        E: 1055,1056,1057,1058

        List<String> seriaC = Arrays.asList("1045", "1046", "1047", "1048", "1049");
        List<String> seriaD = Arrays.asList("1050", "1051", "1052", "1053", "1054");
        List<String> seriaE = Arrays.asList("1055", "1056", "1057", "1058");
        Map<String, List<String>> componentaSerii = Map.ofEntries(entry("C", seriaC),
                entry("D", seriaD),
                entry("E", seriaE));
        // afisare continut Map componenta serii
        componentaSerii.entrySet().stream()
                .forEach(System.out::println); // <k, v>

        afisareOrarGrupa("1056", programari, componentaSerii);

    }
}
