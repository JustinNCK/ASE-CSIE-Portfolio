using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_6
{
    public class Echipa
    {
        private int cod;
        private string denumire;
        private string localitate;

        public Echipa(int cod, string denumire, string localitate)
        {
            Cod = cod;
            Denumire = denumire;
            Localitate = localitate;
        }

        public int Cod { get => cod; set => cod = value; }
        public string Denumire { get => denumire; set => denumire = value; }
        public string Localitate { get => localitate; set => localitate = value; }
    }
}
