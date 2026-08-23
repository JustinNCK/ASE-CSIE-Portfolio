using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Imobiliare
{
    internal class Apartament : Locuinta
    {
        private int etaj;

        public Apartament(int etaj, int cod, string denumire, int suprafata, int nrCamere, int pret) : base(cod, denumire, suprafata, nrCamere, pret)
        {
            this.etaj = etaj;
        }

        public int Etaj { get => etaj; private set => etaj = value; }

        public override ListViewItem Afisare()
        {
            ListViewItem lvi = new ListViewItem(Cod.ToString());
            lvi.SubItems.Add(Denumire);
            lvi.SubItems.Add("Apartament");
            lvi.SubItems.Add(Suprafata.ToString());
            lvi.SubItems.Add(NrCamere.ToString());
            lvi.SubItems.Add(Pret.ToString());
            lvi.SubItems.Add(Etaj.ToString());
            lvi.SubItems.Add("-");

            return lvi;
        }
    }
}
