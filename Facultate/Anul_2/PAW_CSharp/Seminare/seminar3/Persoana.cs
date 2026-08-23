internal class Persoana : ICloneable, IComparable
{
    public Persoana()
    {
        Nume = "???";
        Varsta = 99;
    }

    public Persoana(string nume, int varsta)
    {
        Nume = nume;
        Varsta = varsta;
    }

    public string Nume {  get; set; }
    public int Varsta { get; set; }

    public object Clone()
    {
        return MemberwiseClone();
    }

    public int CompareTo(object? obj)
    {
        Persoana p = (Persoana)obj;
        if(this.Varsta < p.Varsta)
            return -1;
        else if(this.Varsta == p.Varsta)
            return 0;
        else return 1;
    }

    public override string? ToString()
    {
        return "Persoana - Nume: " + Nume + ", Varsta: " + Varsta;
    }

    public virtual void AfiseazaTipObiect()
    {
        Console.WriteLine("Obiectul este o PERSOANA!!!");
    }
}