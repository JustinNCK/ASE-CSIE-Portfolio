internal class Persoana : ICloneable, IComparable
{
    public int id;
    string nume; // private
    protected int varsta;

    public Persoana(int id, string nume, int varsta)
    {
        this.id = id;
        this.nume = nume;
        this.varsta = varsta;
    }

    public Persoana()
    {
        id = 0;
        nume = "???";
        varsta = 0;
    }

    public Persoana(Persoana p)
    {
        this.id = p.id;
        this.nume = p.nume;
        this.varsta = p.varsta;
    }

    public string Nume { get => nume; set => nume = value; }

    public override string? ToString()
    {
        return id + " " + nume + " " + varsta;
    }

    public object Clone()
    {
        //throw new NotImplementedException();
        return this.MemberwiseClone();
    }

    public int CompareTo(object? obj)
    {
        //throw new NotImplementedException();

        Persoana p = (Persoana)obj;

        if (this.id < p.id)
            return -1;
        else
            if (this.id > p.id)
            return 1;
        else
            return 0;
    }


    // var 1
    //public string GetNume() {
    //    return nume;
    //}
    //public void SetNume(string nume) {
    //    this.nume = nume;
    //}

    // var 2 - proprietati


}
