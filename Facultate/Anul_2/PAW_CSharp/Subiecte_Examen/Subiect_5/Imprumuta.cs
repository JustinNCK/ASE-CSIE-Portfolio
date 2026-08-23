using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace Subiect_5
{
    public partial class Imprumuta : Form
    {
        public Imprumuta(List<Carte> cartiDisponibile)
        {
            InitializeComponent();
            
            foreach (var carte in cartiDisponibile)
            {
                if(carte.Disponibila)
                    comboBoxCartiDisponibile.Items.Add(carte);
            }
            comboBoxCartiDisponibile.SelectedIndex = 0;
        }

        public Carte ICarte { get; set; }
        public string INume { get; set; }
        public DateTime IData { get; set; }

        private void button1_Click(object sender, EventArgs e)
        {
            ICarte = comboBoxCartiDisponibile.SelectedItem as Carte;
            INume = textBoxNume.Text;
            IData = dateTimePickerReturnare.Value;

            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
