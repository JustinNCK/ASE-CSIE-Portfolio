using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_6
{
    public enum Rezultate
    {
        Necunoscut,
        VictorieGazda,
        Egal,
        VictorieOaspete
    };

    public class Meci
    {
        private int cod;
        private Echipa gazda;
        private Echipa oaspete;
        private DateTime dataMeci;
        private Rezultate rezultat;
        private int golgazda;
        private int goloaspete;

        public Meci(int cod, Echipa gazda, Echipa oaspete, DateTime dataMeci)
        {
            Cod = cod;
            Gazda = gazda;
            Oaspete = oaspete;
            DataMeci = dataMeci;
            Rezultat = Rezultate.Necunoscut;
            Golgazda = 0;
            Goloaspete = 0;
        }

        public int Cod { get => cod; set => cod = value; }
        public DateTime DataMeci { get => dataMeci; set => dataMeci = value; }
        public int Golgazda { get => golgazda; set => golgazda = value; }
        public int Goloaspete { get => goloaspete; set => goloaspete = value; }
        public Echipa Gazda { get => gazda; set => gazda = value; }
        public Echipa Oaspete { get => oaspete; set => oaspete = value; }
        public Rezultate Rezultat { get => rezultat; set => rezultat = value; }

        public void InregistreazaRezultat(int golGazda, int golOaspete)
        {
            if (golGazda >= 0 && golOaspete >= 0)
            {
                Golgazda = golGazda;
                Goloaspete = golOaspete;

                if (golGazda < golOaspete)
                    Rezultat = Rezultate.VictorieOaspete;
                else if(golGazda > golOaspete)
                    Rezultat = Rezultate.VictorieGazda;
                else 
                    Rezultat = Rezultate.Egal;
            }
            else
                throw new ArgumentException("Golurile nu pot fi negative");
        }

        public override string ToString()
        {
            return Gazda.Denumire + " vs " + Oaspete.Denumire + " (" + DataMeci.ToShortDateString() + ")";
        }
    }
}
