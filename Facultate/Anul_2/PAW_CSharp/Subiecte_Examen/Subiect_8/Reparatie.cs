using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_8
{
    public class Reparatie
    {
        private Masina masina;
        private string descriere;
        private decimal costPiese;
        private decimal costManopera;
        private bool finalizat;

        public Reparatie(Masina masina, string descriere, decimal costPiese, decimal costManopera)
        {
            Masina = masina;
            Descriere = descriere;
            CostPiese = costPiese;
            CostManopera = costManopera;
            Finalizat = false;
        }

        public Reparatie(Masina masina, string descriere, decimal costPiese, decimal costManopera, bool finalizat)
        {
            Masina = masina;
            Descriere = descriere;
            CostPiese = costPiese;
            CostManopera = costManopera;
            Finalizat = finalizat;
        }

        public string Descriere { get => descriere; set => descriere = value; }
        public decimal CostPiese { get => costPiese; set {
                if (value > 0) costPiese = value;
                else throw new ArgumentException("Nu se poate introduce un cost negativ");
            } }
        public decimal CostManopera { get => costManopera; set{
                if (value > 0) costManopera = value;
                else throw new ArgumentException("Nu se poate introduce un cost negativ");
        } }
        public bool Finalizat { get => finalizat; set => finalizat = value; }
        public Masina Masina { get => masina; set => masina = value; }
        public decimal CostTotal{ get { return CostManopera + CostPiese; } }
    }
}
