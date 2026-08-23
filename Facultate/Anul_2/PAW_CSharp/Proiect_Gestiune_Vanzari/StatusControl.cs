using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Proiect_gestiuneVanzari
{
    public partial class StatusControl : UserControl
    {
        public StatusControl()
        {
            InitializeComponent();
        }

        public void ActualizeazaDate(int nrProduse, int nrClienti)
        {
            lblNrProduse.Text = "Numar produse: " + nrProduse;
            lblNrClienti.Text = "Numar clienti: " + nrClienti;
        }
    }
}
