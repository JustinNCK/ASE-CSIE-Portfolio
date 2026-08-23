using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Subiect_8
{
    public partial class Adaugare : Form
    {
        public Adaugare()
        {
            InitializeComponent();

            Masina masina1 = new Masina("B123ABC", "Logan", "Dacia", 2018);
            Masina masina2 = new Masina("IF99XYZ", "Golf", "Volkswagen", 2020);
            Masina masina3 = new Masina("CJ45DEF", "320d", "BMW", 2015);
            comboBoxMasini.DisplayMember = "NumarInmatriculare";
            comboBoxMasini.Items.Add(masina1);
            comboBoxMasini.Items.Add(masina2);
            comboBoxMasini.Items.Add(masina3);
            comboBoxMasini.SelectedIndex = 0;


        }

        private void buttonSalvare_Click(object sender, EventArgs e)
        {
            Masina masina = comboBoxMasini.SelectedItem as Masina;
            decimal costManopera = numericUpDownManopera.Value;
            decimal costPiese = numericUpDownPiese.Value;
            string descriere = textBoxDescriere.Text;

            ReparatieNoua = new Reparatie(masina, descriere, costPiese, costManopera);

            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        public Reparatie ReparatieNoua {  get; set; }
    }
}
