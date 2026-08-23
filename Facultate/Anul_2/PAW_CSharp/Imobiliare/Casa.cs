using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Imobiliare
{
    public class Casa : Locuinta
    {
        private int suprafataTeren;
        private int nrNiveluri;

        public Casa(int suprafataTeren, int nrNiveluri, int cod, string denumire, int suprafata, int nrCamere, int pret) : base(cod, denumire, suprafata, nrCamere, pret)
        {
            this.suprafataTeren = suprafataTeren;
            this.nrNiveluri = nrNiveluri;
        }

        public int SuprafataTeren { get => suprafataTeren; set => suprafataTeren = value; }
        public int NrNiveluri { get => nrNiveluri; set => nrNiveluri = value; }

        public override ListViewItem Afisare()
        {
            ListViewItem lvi = new ListViewItem(Cod.ToString());
            lvi.SubItems.Add(Denumire);
            lvi.SubItems.Add("Casa");
            lvi.SubItems.Add(Suprafata.ToString());
            lvi.SubItems.Add(NrCamere.ToString());
            lvi.SubItems.Add(Pret.ToString());
            lvi.SubItems.Add(NrNiveluri.ToString());
            lvi.SubItems.Add(SuprafataTeren.ToString());

            return lvi;
        }
    }
}
