using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace Restaurant
{
    internal class Produs
    {
        private string denumire;
        private List<Ingredient> ingrediente;
        private List<int> cantitati;
        private decimal adaosComercial;

        public Produs(string denumire, List<Ingredient> ingrediente, List<int> cantitati, decimal adaosComercial)
        {
            this.denumire = denumire;
            this.ingrediente = ingrediente;
            this.cantitati = cantitati;
            this.adaosComercial = adaosComercial;
        }

        public Produs()
        {
            ingrediente = new List<Ingredient>();
            cantitati = new List<int>();
        }

        public string Denumire { get => denumire; set => denumire = value; }
        public decimal AdaosComercial { get => adaosComercial; set => adaosComercial = value; }
        public int NumarIngrediente { get => ingrediente.Count; }

        public int PretFinal {  get {
                decimal costTotal = 0;
                for (int i = 0; i < ingrediente.Count; i++)
                {
                    costTotal += ingrediente[i].PretUnitar * cantitati[i];
                }

                costTotal += costTotal * adaosComercial / 100;

                return (int)costTotal;
            } }

        internal List<Ingredient> Ingrediente { get => ingrediente; set => ingrediente = value; }
        public List<int> Cantitati { get => cantitati; set => cantitati = value; }

        public void AdaugaIngredient(Ingredient i, int canitatea)
        {
            ingrediente.Add(i);
            cantitati.Add(canitatea);
        }

        public Ingredient ObtineIngredient(int pozitie)
        {
            if (pozitie >= 0 && pozitie < ingrediente.Count)
                return ingrediente[pozitie];
            return null;
        }

        public int ObtineCantitate(int pozitie)
        {
            if (pozitie >= 0 && pozitie < cantitati.Count)
                return cantitati[pozitie];
            return 0;
        }
    }
}
