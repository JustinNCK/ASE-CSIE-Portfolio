using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Drawing;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Imobiliare
{
    public partial class FormAdaugare : Form
    {
        public FormAdaugare()
        {
            InitializeComponent();
        }

        public Locuinta LocuintaNoua {  get; set; }

        private void buttonAdaugare_Click(object sender, EventArgs e)
        {
            int cod;
            string denumire;
            int suprafata;
            int nrCamere;
            int pret;

            cod = Convert.ToInt32(textBox1.Text);
            denumire = textBox2.Text;
            suprafata = Convert.ToInt32(textBox3.Text);
            nrCamere = Convert.ToInt32(textBox5.Text);
            pret = Convert.ToInt32(textBox4.Text);

            if (radioButtonApartament.Checked)
            {
                int etaj = Convert.ToInt32(textBox6.Text);
                LocuintaNoua = new Apartament(etaj, cod, denumire, suprafata, nrCamere, pret);
            }
            else if (radioButtonCasa.Checked)
            {
                int suprafataTeren = Convert.ToInt32(textBox7.Text);
                int nrNiveluri = Convert.ToInt32(textBox8.Text);
                LocuintaNoua = new Casa(suprafataTeren, nrNiveluri, cod, denumire, suprafata, nrCamere, pret);
            }
            DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
