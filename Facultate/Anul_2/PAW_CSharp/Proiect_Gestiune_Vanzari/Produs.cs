using Proiect_gestiuneVanzari;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;
namespace Proiect
{
    public class Produs : ICloneable, IComparable, IReducere
    {
        private int id;
        private string denumire;
        private double pret;

        public delegate void ModificarePretDelegate(double pretNou);
        public event ModificarePretDelegate PretModificat;

        public Produs() {}

        public Produs(int id, string denumire, double pret)
        {
            this.id = id;
            this.denumire = denumire;
            this.pret = pret;
        }

        public int Id { get => id; set => id = value; }
        public string Denumire { get => denumire; set => denumire = value; }
        public double Pret
        { 
            get => pret;
            set
            {
                if (pret != value)
                {
                    pret = value;

                    if (PretModificat != null)
                        PretModificat(pret);
                }

            }
        }

        public void AplicaReducere(double procentaj)
        {
            this.pret -= this.pret * (procentaj / 100);
        }

        public object Clone()
        {
            return this.MemberwiseClone();
        }

        public int CompareTo(object? obj)
        {
            if (obj == null || obj.GetType() != this.GetType())
                return -1;

            Produs p = (Produs)obj;
            return this.pret.CompareTo(p.pret);
        }

        public static Produs operator +(Produs p, double val)
        {
            Produs nou = (Produs)p.Clone();

            nou.Pret = p.Pret + val;
            return nou;
        }

        public static Produs operator +(double val, Produs p)
        {
            return p + val;
        }

        public static bool operator < (Produs p1, Produs p2)
        {
            return p1.Pret < p2.Pret;
        }

        public static bool operator > (Produs p1, Produs p2)
        {
            return p1.Pret > p2.Pret;
        }
    }
}