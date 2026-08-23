using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_6
{
    public class Turneu
    {
        private List<Echipa> echipe;
        private List<Meci> meciuri;

        public Turneu()
        {
            echipe = new List<Echipa>();
            meciuri = new List<Meci>();
        }

        public List<Echipa> Echipe { get => echipe; set => echipe = value; }
        public List<Meci> Meciuri { get => meciuri; set => meciuri = value; }

        public int NumarEchipe {  get { return echipe.Count; }}

        public int MeciuriDisputate { get {
                int nr = 0;
                foreach (var m in meciuri)
                    if (m.Rezultat != Rezultate.Necunoscut)
                        nr++;
                return nr;
        } }

        public void AdaugaEchipa(Echipa echipa)
        {
            bool exista = false;
            foreach (var e in echipe)
            {
                if (e.Cod == echipa.Cod)
                    exista = true;
            }

            if (!exista)
                echipe.Add(echipa);
            else
                throw new ArgumentException("Exista deja aceasta echipa");
        }

        public void ProgrameazaMeci(Meci meci)
        {
            bool e1 = false;
            bool e2 = false;
            bool e3 = false;

            foreach (var e in echipe)
            {
                if (e.Cod == meci.Gazda.Cod)
                    e1 = true;
                if(e.Cod == meci.Oaspete.Cod)
                    e2 = true;
            }

            foreach(var m in meciuri)
            {
                if(meci.Gazda.Cod == m.Gazda.Cod && meci.Oaspete.Cod == m.Oaspete.Cod)
                    e3 = true;
            }

            if(e1 && e2  && !e3)
                meciuri.Add(meci);
            else
                throw new ArgumentException("Nu s-a putut adauga meciul");
        }

        public List<LinieClasament> Clasament()
        {
            List<LinieClasament> linii = new List<LinieClasament>();

            foreach (var e in echipe)
            {
                LinieClasament linie = new LinieClasament { Echip = e };

                foreach (var m in meciuri)
                {
                    if (m.Rezultat != Rezultate.Necunoscut)
                    {
                        if (m.Gazda.Cod == e.Cod)
                        {
                            linie.MeciuriJucate++;
                            linie.GoluriMarcate += m.Golgazda;
                            linie.GoluriPrimite += m.Goloaspete;

                            if (m.Rezultat == Rezultate.VictorieGazda) linie.Puncte += 3;
                            else if (m.Rezultat == Rezultate.Egal) linie.Puncte += 1;
                        }
                        else if (m.Oaspete.Cod == e.Cod)
                        {
                            linie.MeciuriJucate++;
                            linie.GoluriMarcate += m.Goloaspete;
                            linie.GoluriPrimite += m.Golgazda;

                            if (m.Rezultat == Rezultate.VictorieOaspete) linie.Puncte += 3;
                            else if (m.Rezultat == Rezultate.Egal) linie.Puncte += 1;
                        }
                    }
                }
                linii.Add(linie);
            }

            return linii.OrderByDescending(l => l.Puncte)
                        .ThenByDescending(l => l.DiferentaGoluri)
                        .ToList();
        }
        public Meci this[int index] { get => meciuri[index]; set => meciuri[index] = value; }
    }

    public class LinieClasament
    {
        public Echipa Echip { get; set; }
        public int MeciuriJucate { get; set; }
        public int Puncte { get; set; }
        public int GoluriMarcate { get; set; }
        public int GoluriPrimite { get; set; }
        public int DiferentaGoluri => GoluriMarcate - GoluriPrimite;
    }
}
