using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_8
{
    public class Masina
    {
        private string numarInmatriculare;
        private string model;
        private string marca;
        private int anFabricatie;

        public Masina(string numarInmatriculare, string model, string marca, int anFabricatie)
        {
            NumarInmatriculare = numarInmatriculare;
            Model = model;
            Marca = marca;
            AnFabricatie = anFabricatie;
        }

        public string NumarInmatriculare { get => numarInmatriculare; set => numarInmatriculare = value; }
        public string Model { get => model; set => model = value; }
        public string Marca { get => marca; set => marca = value; }
        public int AnFabricatie { get => anFabricatie; set {
                if (value >= 1950 && value <= 2026)
                    this.anFabricatie = value;
                else
                    throw new ArgumentException("Anul de fabricatie nu este bun");
        } }
    }
}
