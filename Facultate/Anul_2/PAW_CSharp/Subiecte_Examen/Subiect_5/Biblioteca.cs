using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Subiect_5
{
    public class Biblioteca
    {
        private List<Imprumut> imprumuturi;

        public Biblioteca()
        {
            imprumuturi = new List<Imprumut>();
        }

        public List<Imprumut> Imprumuturi { get => imprumuturi; set => imprumuturi = value; }

        public int NumarImprumuturiActive
        {
            get
            {
                int nr = 0;
                foreach (var im in imprumuturi)
                {
                    if (!im.Carte.Disponibila)
                        nr++;
                }
                return nr;
            }
        }

        public int NumarImprumuturiDepasite
        {
            get
            {
                int nr = 0;
                foreach (var im in imprumuturi)
                {
                    if (im.EsteDepasit)
                        nr++;
                }
                return nr;
            }
        }

        public void Imprumuta(Carte carte, string numeCititor, DateTime termen)
        { 
            if (carte.Disponibila)
            {
                carte.Disponibila = false;
                Imprumut i = new Imprumut(carte, numeCititor, DateTime.Today, termen);
                imprumuturi.Add(i);
            }
            else
                throw new ArgumentException("Cartea nu este disponibila");
        }

        public void Returneaza(int codCarte)
        {
            foreach (var im in imprumuturi)
            {
                if (codCarte == im.Carte.Cod && !im.Carte.Disponibila)
                {
                    im.DataReturnare = DateTime.Now;
                    im.Carte.Disponibila = true;
                }
            }
        }

        public Imprumut this[int index]{ get => imprumuturi[index]; set => imprumuturi[index] = value; }

    }
}
