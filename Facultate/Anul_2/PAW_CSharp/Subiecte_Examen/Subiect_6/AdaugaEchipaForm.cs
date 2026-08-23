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
    public partial class AdaugaEchipaForm : Form
    {
        public AdaugaEchipaForm()
        {
            InitializeComponent();
        }

        public string EDenumire { get; set; }
        public string ELocalitate { get; set; }

        private void buttonSalvare_Click(object sender, EventArgs e)
        {
            EDenumire = textBoxDenumire.Text;
            ELocalitate = textBoxLocalitate.Text;

            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
