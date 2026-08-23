using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_7
{
    internal class Concert : Eveniment
    {
        private string artist;
        private bool inAerLiber;

        public string Artist { get => artist; set => artist = value; }
        public bool InAerLiber { get => inAerLiber; set => inAerLiber = value; }

        public Concert(string artist, bool inAerLiber, int cod, string titlu, DateTime dataOra, int durataMinute, decimal pretBilet) : base(cod, titlu, dataOra, durataMinute, pretBilet)
        {
            this.artist = artist;
            this.inAerLiber = inAerLiber;
        }

        public override ListViewItem Afisare()
        {
            ListViewItem item = new ListViewItem(Cod.ToString());

            item.SubItems.Add(Titlu);
            item.SubItems.Add("Concert");
            item.SubItems.Add(DataOra.ToString());
            item.SubItems.Add(DurataMinute.ToString());
            item.SubItems.Add(PretBilet.ToString());
            item.SubItems.Add("Artist: " + Artist + ", Este in aer liber: " + InAerLiber.ToString());

            return item;
        }
    }
}
