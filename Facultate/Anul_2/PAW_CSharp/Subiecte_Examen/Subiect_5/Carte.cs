using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_5
{
    public class Carte
    {
        private int cod;
        private string titlu;
        private string autor;
        private int anAparatie;
        private bool disponibila;

        public Carte(int cod, string titlu, string autor, int anAparatie, bool disponibila)
        {
            Cod = cod;
            Titlu = titlu;
            Autor = autor;
            AnAparatie = anAparatie;
            Disponibila = disponibila;
        }

        public int Cod { get => cod; set => cod = value; }
        public string Titlu { get => titlu; set => titlu = value; }
        public string Autor { get => autor; set => autor = value; }
        public int AnAparatie { get => anAparatie; set {
                if (value >= 1450 && value <= DateTime.Today.Year)
                    anAparatie = value;
                else
                    throw new ArgumentException("Anul nu este bun");
        } }
        public bool Disponibila { get => disponibila; set => disponibila = value; }

        public override string ToString()
        {
            return Titlu + " - " + Autor;
        }
    }
}
