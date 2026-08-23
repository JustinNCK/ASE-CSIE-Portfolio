internal class Angajat : Persoana
{
    public int Vechime{ get; set; }

    override public void Afiseaza()
    {
        Console.WriteLine("Obiectul este de tipul ANGAJAT");
    }

    public override void Detalii()
    {
        Console.WriteLine("ANGAJAT - Detalii");
    }
}