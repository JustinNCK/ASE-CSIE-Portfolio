using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_8
{
    public class Service
    {
        private List<Reparatie> reparatii;

        public Service() { reparatii = new List<Reparatie>(); }

        public List<Reparatie> Reparatii { get => reparatii; }

        public void Adauga(Reparatie reparatie)
        {
            reparatii.Add(reparatie);
        }

        public int NrReparatii { get {
                int nrReparatii = 0;
                foreach (var reparatie in reparatii) { 
                    if(reparatie.Finalizat == false)
                        nrReparatii++;
                }
                return nrReparatii;
        } }

        public decimal SumaIncasata
        { get {
                decimal total = 0;
                foreach (var reparatie in reparatii)
                {
                    if (reparatie.Finalizat)
                        total += reparatie.CostTotal;
                }
                return total;
            }
        }

        public void Finalizeaza(int pozitie)
        {
            if (reparatii[pozitie].Finalizat)
                throw new Exception("Reparația este deja finalizată!");
            else
                reparatii[pozitie].Finalizat = true;
        }

        public Reparatie this[int index]{ get { return reparatii[index]; } }
    }
}
