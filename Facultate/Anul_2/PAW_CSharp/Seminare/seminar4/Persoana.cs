internal abstract class Persoana : ICetatean, IAngajat
{
    public string Nume {  get; set; }
    public virtual void Afiseaza()
    {
        Console.WriteLine("Obiectul este de tipul PERSOANA");
    }

    public abstract void Detalii();

    public void Salariu()
    {
        Console.WriteLine("Salariu");
    }
    public void CNP()
    {
        Console.WriteLine("CNP");
    }
}