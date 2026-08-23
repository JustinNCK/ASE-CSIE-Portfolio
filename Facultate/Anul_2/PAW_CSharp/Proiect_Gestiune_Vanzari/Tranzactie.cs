using Proiect_gestiuneVanzari;
using System.Collections;
using System.Security.Policy;
namespace Proiect
{
    internal class Tranzactie : IEnumerable
    {
        private int idTranzactie;
        private DateTime data;
        private int[] cantitatiProduse;
        private Produs[] produseCumparate;

        public Tranzactie() {}

        public Tranzactie(int idTranzactie, DateTime data, int[] cantitatiProduse, Produs[] produseCumparate)
        {
            this.idTranzactie = idTranzactie;
            this.data = data;
            if (cantitatiProduse != null)
                this.cantitatiProduse = (int[])cantitatiProduse.Clone();
            if (produseCumparate != null)
                this.produseCumparate = (Produs[])produseCumparate.Clone();
        }

        public int IdTranzactie { get => idTranzactie; set => idTranzactie = value; }
        public DateTime Data { get => data; set => data = value; }
        public int[] CantitatiProduse { get => cantitatiProduse; set => cantitatiProduse = value; }
        internal Produs[] ProduseCumparate { get => produseCumparate; set => produseCumparate = value; }

        public Produs this[int index]
        {
            get
            {
                if (produseCumparate != null && index >= 0 && index < produseCumparate.Length)
                    return produseCumparate[index];
                return null;
            }
            set
            {
                if (produseCumparate != null && index >= 0 && index < produseCumparate.Length)
                    produseCumparate[index] = value;
            }
        }

        public double CalculeazaValoareTotala()
        {
            double total = 0;
            if(produseCumparate != null && cantitatiProduse != null)
            {
                for (int i = 0; i < produseCumparate.Length && i < cantitatiProduse.Length; i++)
                {
                    if (produseCumparate[i] != null)
                    {
                        total += produseCumparate[i].Pret * cantitatiProduse[i];
                    }
                }
            }
            return total;
        }

        public int CalculeazaTotalArticole()
        {
            int totalArticole = 0;

            if(cantitatiProduse != null)
            foreach(int cantitate in cantitatiProduse)
                    totalArticole += cantitate;

            return totalArticole;
        }

        public IEnumerator GetEnumerator()
        {
            for (int i = 0; i < produseCumparate.Length; i++)
            {
                yield return produseCumparate[i];
            }
        }
    }
}