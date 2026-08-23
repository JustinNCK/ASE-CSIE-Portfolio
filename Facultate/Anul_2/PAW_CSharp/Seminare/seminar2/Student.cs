internal class Student : Persoana
{
    private float medieANI;

    public Student(float medieANI)
    {
        this.medieANI = medieANI;
    }

    public Student() : base()
    {
        medieANI = 0.0f;
    }

    public override string? ToString()
    {
        return base.ToString() + ", medie ani: " + medieANI;
    }

    public static Student operator +(Student a, float b)
    {
        a.medieANI += b;
        return a;
    }

    public static Student operator +(float a, Student b)
    {
        return b + a;
    }
}
