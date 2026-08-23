using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Subiect_7
{
    public partial class AdaugaEveniment : Form
    {
        public AdaugaEveniment()
        {
            InitializeComponent();
        }

        public Eveniment EvenimentNou { get; private set; }

        private void rbFilm_CheckedChanged(object sender, EventArgs e)
        {
            if (rbFilm.Checked) { 
                textBoxArtist.Enabled = false;
                checkBox1.Enabled = false;

                textBoxGen.Enabled = true;
                numericUpDownVarsta.Enabled = true;
            }
        }

        private void rbConcert_CheckedChanged(object sender, EventArgs e)
        {
            if (rbConcert.Checked)
            {
                textBoxGen.Enabled = false;
                numericUpDownVarsta.Enabled = false;

                textBoxArtist.Enabled = true;
                checkBox1.Enabled = true;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int cod = int.Parse(textBoxCod.Text);
            string titlu = textBoxTitlu.Text;
            DateTime dataOra = dateTimePickerData.Value;
            int durataMinute = (int)numericUpDownDurata.Value;
            decimal pretBilet = numericUpDownPret.Value;

            if (rbFilm.Checked)
            {
                string gen = textBoxGen.Text;
                int varstaMinima = (int)numericUpDownVarsta.Value;
                EvenimentNou = new Film(gen, varstaMinima, cod, titlu, dataOra, durataMinute, pretBilet);
            }
            else
            {
                string artist = textBoxArtist.Text;
                bool inAerLiber = checkBox1.Checked;
                EvenimentNou = new Concert(artist, inAerLiber, cod, titlu, dataOra, durataMinute, pretBilet);
            }

            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
