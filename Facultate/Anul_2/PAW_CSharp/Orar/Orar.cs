using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Orar
{
    internal class Orar
    {
        private List<Element> elemete;

        public Orar() { elemete = new List<Element>(); }

        public int NrElemnte {  get { return elemete.Count; }}

        public List<Element> lista { get { return elemete; } }

        public void AdugareElement(Element value)
            {
                bool exista = false;
                foreach (var elem in elemete)
                    if (elem.SeSuprapune(value))
                    {
                        exista = true;
                        break;
                    }

                if (!exista)
                    elemete.Add(value);
                else
                    throw new Exception("Eroare de suprapunere!");
            }

        public Element this[int index] { get { return elemete[index]; } }
    }
}
