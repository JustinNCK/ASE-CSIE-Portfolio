//using Proiect;
//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

////Pentru ca testarea sa functioneze tot codul din Program.cs trebuie comentat
////mai trebuie schimbat din  Solution Explorer -> Properties  -> Application -> Output type -> Console Application
////aceasta modificare este necesara ca sa se afiseze in consola

//namespace Proiect_gestiuneVanzari
//{
//    internal class Testare_functii_clase
//    {
//        static void AfiseazaMesajPretSchimbat(double pretNou)
//        {
//            Console.WriteLine($"[ALERTA EVENT] Pretul produsului a fost modificat! Noul pret este: {pretNou} RON.");
//        }

//        static void Main(string[] args)
//        {

//            Console.WriteLine("=== TESTARE APLICATIE GESTIUNE VANZARI ===\n");

//            // 1. Testare Clasa Produs, Event si Operatori
//            Produs p1 = new Produs(1, "Laptop", 3500);
//            Produs p2 = new Produs(2, "Mouse", 150);

//            // Ne abonam la evenimentul produsului p1
//            p1.PretModificat += AfiseazaMesajPretSchimbat;
            
//            Console.WriteLine("Modificam pretul laptopului pentru a testa Event-ul...");
//            p1.Pret = 3200; // Aceasta linie va declansa automat metoda AfiseazaMesajPretSchimbat!

//            // Testam supraincarcarea operatorului +
//            Produs p3 = p2 + 50;
//            Console.WriteLine($"\nPret initial {p2.Denumire}: {p2.Pret} RON. Pret dupa adaugare 50: {p3.Pret} RON.");

//            // 2. Testare Clasa Client si Clasa Abstracta
//            Console.WriteLine("\n--- Testare Client ---");
//            Client c1 = new Client(101, "Popescu Ion", "Strada Viitorului 10");
//            c1.AfiseazaDetalii(); // Apealeaza metoda implementata din clasa abstracta Persoana

//            // 3. Testare Tranzactie, Indexer si Metode de prelucrare
//            Console.WriteLine("\n--- Testare Tranzactie ---");
//            Produs[] cosCumparaturi = { p1, p3 }; // Cumpara un Laptop la reducere si un Mouse mai scump
//            int[] cantitati = { 1, 2 }; // 1 Laptop, 2 Mousi

//            Tranzactie tranzactie1 = new Tranzactie(1001, DateTime.Now, cantitati, cosCumparaturi);

//            Console.WriteLine($"Tranzactia are in total: {tranzactie1.CalculeazaTotalArticole()} articole fizice.");
//            Console.WriteLine($"Valoarea totala a tranzactiei este: {tranzactie1.CalculeazaValoareTotala()} RON.");

//            // Testam indexer-ul
//            Console.WriteLine($"Folosind indexer-ul, primul produs cumparat este: {tranzactie1.ProduseCumparate[0].Denumire}");

//            // 4. Testare Sortare (IComparable)
//            Console.WriteLine("\n--- Testare Sortare Produse dupa Pret ---");
//            Produs[] arrayProduse = { p1, p2, new Produs(3, "Tastatura", 250) };

//            // Sortarea se face bazandu-se pe metoda CompareTo implementata de tine [2]
//            Array.Sort(arrayProduse);

//            foreach (var produs in arrayProduse)
//            {
//                Console.WriteLine($"Produs: {produs.Denumire} - Pret: {produs.Pret} RON");
//            }

//            Console.WriteLine("\nModelul de date este complet functional!");
//        }
//    }
//}