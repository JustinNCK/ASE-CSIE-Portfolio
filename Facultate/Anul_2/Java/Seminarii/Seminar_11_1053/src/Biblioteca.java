// loc de descarcat jdbc-sqlite. jar
// https://repo1.maven.org/maven2/org/xerial/sqlite-jdbc/3.30.1/
// https://dbeaver.io/


import java.sql.*;
import java.util.ArrayList;
import java.util.List;


public class Biblioteca {
    private static final String dbURL = "jdbc:sqlite:db\\biblioteca.db";
    // serverul de bazse de date va rula in aceeasi masina virtuala Java cu apicatia noastra
    private static final String dbName = "biblioteca";
    private static final String tableName = "carte";

    private static Connection conn;
    private static Statement sqlStatement;

    public static void main(String[] args) {
        Carte c1 = new Carte("Cota-0001", "The Adventures of Tom Sawyer",
                "Mark Twain", 1876);
        Carte c2 = new Carte("Cota-0002", "Fratii Karamozov",
                "Teodovich Dostoevski", 1878);
        Carte c3 = new Carte("Cota-0003", "Strainul",
                "Albert Camus", 1942);

        creareConexiune();
        dropTableCarte();
        creareTabelaCarte();

        inserareCarte(c1);
        inserareCarte(c2);
        inserareCarte(c3);

        selectareCarti();
        stergereCarte(c2);
        selectareCarti();
//        actualizareCarte(c3);
//        selectareCarti();
//
        inchidereConexiune();
    }

    private static void creareConexiune() {
        try {
            conn = DriverManager.getConnection(dbURL);
            System.out.println("Conectare cu succes la DB " + dbName);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static void dropTableCarte() {
        // TODO
        try {
            sqlStatement = conn.createStatement();
            sqlStatement.execute("drop table " + tableName + ";");
            System.out.println("Tabela " + tableName + " a fost stearsa cu succes");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static void creareTabelaCarte() {
        // TODO
        try {
            sqlStatement = conn.createStatement();
            sqlStatement.execute("create table " + tableName +
                    "(cota varchar2(16) primary key, titlu varchar2(64), autori varchar2(64), an number);");
            System.out.println("Tabela " + tableName + " a fost creata cu succes");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static void inserareCarte(Carte carte) {
        // TODO
        try {
            sqlStatement = conn.createStatement();
            sqlStatement.execute("insert into " + tableName +
                    " values ('" + carte.getCota() + "', '" + carte.getTitlu() + "', '" +
                    carte.getAutori() + "', " + carte.getAn() + ");");
            System.out.println("Cartea " + carte.getTitlu() + " a fost inserata cu succes");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static void stergereCarte(Carte carte) {
        // TODO
        try {
            sqlStatement = conn.createStatement();
            int nr = sqlStatement.executeUpdate("delete from " + tableName +
                    " where an = " + carte.getAn()+ ";");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static void actualizareCarte(Carte carte) {
        // TODO
    }

    private static void selectareCarti() {
       // TODO
        try {
            sqlStatement = conn.createStatement();
            ResultSet select = sqlStatement.executeQuery("select * from " + tableName +
                    " where cota like 'Cota-%';");
            List<Carte> listaCarti = new ArrayList<>();
            while(select.next()){
                Carte carte = new Carte(select.getString(1), select.getString("titlu"),
                        select.getString(3), select.getInt("an"));
                listaCarti.add(carte);
            }
            listaCarti.stream().forEach(System.out::println);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static void inchidereConexiune() {
        // TODO
        if(sqlStatement != null){
            try {
                sqlStatement.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        if(conn != null){
            try {
                conn.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }

}
