using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Orar
{
    public partial class FormAdaugare : Form
    {
        public Element ElementNou { get; private set; }

        public FormAdaugare()
        {
            InitializeComponent();
        }

        private void buttonSalvare_Click(object sender, EventArgs e)
        {
            int zi = int.Parse(comboBoxZi.SelectedItem.ToString());

            Ora.ora ora = (Ora.ora)Enum.Parse(typeof(Ora), comboBoxOra.SelectedItem.ToString());

            string denumire = textBoxDenumire.Text;
            bool esteCurs = checkBoxCurs.Checked;

            ElementNou = new Element(zi, ora, denumire, esteCurs);

            DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
