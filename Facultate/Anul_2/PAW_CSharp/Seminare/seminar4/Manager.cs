internal class Manager : Persoana
{
    public int nr_subordonati {  get; set; }
    override public void Afiseaza()
    {
        Console.WriteLine("Obiectul este de tipul MANAGER");
    }
    public override void Detalii()
    {
        Console.WriteLine("MANAGER - Detalii");
    }
}