using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_7
{
    public abstract class Eveniment
    {
        private int cod;
        private string titlu;
        private DateTime dataOra;
        private int durataMinute;
        private decimal pretBilet;

        public int Cod { get => cod; set => cod = value; }
        public string Titlu { get => titlu; set => titlu = value; }
        public DateTime DataOra { get => dataOra; set => dataOra = value; }
        public int DurataMinute { get => durataMinute; set {
                if (value <= 0)
                    throw new ArgumentException("Durat nu poate sa fie negativa sau zero");
                else
                    durataMinute = value;
            } }
        public decimal PretBilet { get => pretBilet; set
            {
                if (value <= 0)
                    throw new ArgumentException("Pretul nu poate sa fie negativa sau zero");
                else
                    pretBilet = value;
            }
        }

        protected Eveniment(int cod, string titlu, DateTime dataOra, int durataMinute, decimal pretBilet)
        {
            Cod = cod;
            Titlu = titlu;
            DataOra = dataOra;
            DurataMinute = durataMinute;
            PretBilet = pretBilet;
        }

        public abstract ListViewItem Afisare();
    }
}
