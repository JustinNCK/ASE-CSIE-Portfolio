using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_5
{
    public class Imprumut
    {
        private Carte carte;
        private string numeCititor;
        private DateTime dataImprumut;
        private DateTime? dataReturnare;

        public Imprumut(Carte carte, string numeCititor, DateTime dataImprumut, DateTime? dataReturnare)
        {
            Carte = carte;
            NumeCititor = numeCititor;
            DataImprumut = dataImprumut;
            DataReturnare = dataReturnare;
        }

        public Carte Carte { get => carte; set => carte = value; }
        public string NumeCititor { get => numeCititor; set => numeCititor = value; }
        public DateTime DataImprumut { get => dataImprumut; set => dataImprumut = value; }
        public DateTime? DataReturnare { get => dataReturnare; set => dataReturnare = value; }
        public bool EsteDepasit { get { 
                if ( !Carte.Disponibila && dataReturnare.HasValue && dataReturnare.Value < DateTime.Today )
                    return true;
                else
                    return false;
        } }
    }
}
