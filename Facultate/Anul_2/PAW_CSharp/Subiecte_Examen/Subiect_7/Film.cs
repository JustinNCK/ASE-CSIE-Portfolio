using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_7
{
    internal class Film : Eveniment
    {
        private string gen;
        private int varstaMinima;

        public string Gen { get => gen; set => gen = value; }
        public int VarstaMinima { get => varstaMinima; set => varstaMinima = value; }

        public Film(string gen, int varstaMinima, int cod, string titlu, DateTime dataOra, int durataMinute, decimal pretBilet) : base(cod, titlu, dataOra, durataMinute, pretBilet)
        {
            Gen = gen;
            VarstaMinima = varstaMinima;
        }

        public override ListViewItem Afisare()
        {
            ListViewItem item = new ListViewItem(Cod.ToString());

            item.SubItems.Add(Titlu);
            item.SubItems.Add("Film");
            item.SubItems.Add(DataOra.ToString());
            item.SubItems.Add(DurataMinute.ToString());
            item.SubItems.Add(PretBilet.ToString());
            item.SubItems.Add("Gen: " + Gen + ", Varsta minima: " + VarstaMinima.ToString());

            return item;
        }
    }
}
