using System.Collections;
using System.Windows.Forms;
using System.Xml;

namespace Seminar_8
{
    public partial class Form1 : Form
    {
        ArrayList listaTBCalificativ = new ArrayList();

        public Form1()
        {
            InitializeComponent();
            listaTBCalificativ.Add(txtCalificativ);
        }

        private void btnPlus_Click(object sender, EventArgs e)
        {

            int x = txtCalificativ.Location.X;
            int y = ((TextBox)listaTBCalificativ[listaTBCalificativ.Count - 1]).Location.Y;
            int w = txtCalificativ.Width;

            TextBox newTB = new TextBox();
            newTB.Location = new Point(x, y + 30);
            newTB.Width = w;
            newTB.TextAlign = HorizontalAlignment.Right;


            listaTBCalificativ.Add((newTB));
            Controls.Add(newTB);

            newTB.Focus();
        }

        private void btnMinus_Click(object sender, EventArgs e)
        {

            if (listaTBCalificativ.Count > 1)
            {
                TextBox TBdeSters = (TextBox)listaTBCalificativ[listaTBCalificativ.Count - 1];
                Controls.Remove(TBdeSters);
                listaTBCalificativ.Remove(TBdeSters);


            }

            TextBox TBUltimul = (TextBox)listaTBCalificativ[listaTBCalificativ.Count - 1];
            TBUltimul.Focus();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            errorProvider1.Clear();

            // denumire produs
            string denumire = txtDenProdus.Text.Trim();
            if (denumire.Length == 0)
            {
                errorProvider1.SetError(txtDenProdus, "Numele produsului este obligatoriu!");
                return;
            }

            // calificative
            foreach (TextBox tb in listaTBCalificativ)
            {
                int nota = 0;
                try
                {
                    nota = Convert.ToInt32(tb.Text);
                }
                catch
                {
                    errorProvider1.SetError(tb, "Calificativul trebuie sa fie numeric!");
                    tb.Focus();
                    return;
                }

                if (nota < 0 || nota > 5)
                {
                    errorProvider1.SetError(tb, "Calificativul trebuie sa fie in intervalul 0-5!");
                    return;
                }
            }

            string text = "Produs: " + txtDenProdus.Text + ", Calificative: ";
            for (int i = 0; i < listaTBCalificativ.Count; i++)
            {
                text += ((TextBox)listaTBCalificativ[i]).Text + " ";
            }
            lstCalificative.Items.Add(text);

            // cleanup
            int nr_calificative = listaTBCalificativ.Count;
            for (int i = 1; i < nr_calificative; i++)
            {
                TextBox tbDEsters = (TextBox)listaTBCalificativ[1];
                Controls.Remove(tbDEsters);
                listaTBCalificativ.Remove(tbDEsters);
            }

            txtCalificativ.Text = "";
            txtDenProdus.Text = "";
            txtDenProdus.Focus();

        }
    }
}
