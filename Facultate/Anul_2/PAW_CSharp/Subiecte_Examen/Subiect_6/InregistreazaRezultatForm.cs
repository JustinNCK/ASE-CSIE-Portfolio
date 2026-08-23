using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Subiect_6
{
    public partial class InregistreazaRezultatForm : Form
    {
        public InregistreazaRezultatForm(List<Meci> meciuri)
        {
            InitializeComponent();

            foreach (var m in meciuri)
            {
                if (m.Rezultat == Rezultate.Necunoscut)
                {
                    comboBoxMeciuri.Items.Add(m);
                }
            }

            if (comboBoxMeciuri.Items.Count > 0)
                comboBoxMeciuri.SelectedIndex = 0;
        }

        public Meci MeciSelectat { get; set; }
        public int GoluriGazda { get; set; }
        public int GoluriOaspete { get; set; }

        private void buttonSalvare_Click(object sender, EventArgs e)
        {
            MeciSelectat = comboBoxMeciuri.SelectedItem as Meci;
            GoluriGazda = (int)numericUpDownGazda.Value;
            GoluriOaspete = (int)numericUpDownOaspete.Value;

            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}