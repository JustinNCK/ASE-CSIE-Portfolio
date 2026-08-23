internal class Student : Persoana, ICloneable, IPromovat
{
    public int[] NoteV {  get; set; }
    public List<int> NoteL { get; set; }

    public override string? ToString()
    {
        string rezultat = base.ToString() + " si notele:\n";

        if (NoteV != null)
        {
            foreach (int note in NoteV)
                rezultat += note + " ";
            rezultat += "\n";
        }

        if (NoteL != null)
        {
            foreach (int note in NoteL)
                rezultat += note + " ";
            rezultat += "\n";
        }

        return rezultat;
    }

    public void medie()
    {
        float mV = (float)NoteV.Sum() / NoteV.Length;
        float mL = (float)NoteL.Sum() / NoteL.Count;
        Console.WriteLine("Medii: " + mV + " si " + mL);
    }

    public bool StudentPromovat()
    {
        float mV = (float)NoteV.Sum() / NoteV.Length;
        float mL = (float)NoteL.Sum() / NoteL.Count;

        if(mV >= 5 && mL >= 5)
            return true;
        else
            return false;
    }

    public override void AfiseazaTipObiect()
    {
        Console.WriteLine("Obiectul este un STUDENT!!!");
    }
}

internal interface IPromovat
{
    public bool StudentPromovat();
}