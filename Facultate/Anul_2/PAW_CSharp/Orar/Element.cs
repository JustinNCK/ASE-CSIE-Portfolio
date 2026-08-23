using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Orar
{
    public class Element
    {
        private int zi;
        private Ora.ora ora;
        private string denumire;
        private bool esteCurs;

        public int Zi { get => zi; set {
                if (value >= 1 && value <= 5)
                    zi = value;
                else
                    throw new ArgumentException("Ziua trebuie sa fie intre 1 si 5");
            } }
        public Ora.ora Ora { get => ora; set => ora = value; }
        public string Denumire { get => denumire; set => denumire = value; }
        public bool EsteCurs { get => esteCurs; set => esteCurs = value; }

        public Element(int zi, Ora.ora ora, string denumire, bool esteCurs)
        {
            Zi = zi;
            Ora = ora;
            Denumire = denumire;
            EsteCurs = esteCurs;
        }

        public bool SeSuprapune(Element elem)
        {
            if(elem.Zi == this.Zi && elem.Ora == this.Ora)
                return true;
            else
                return false;
        }
    }
}
