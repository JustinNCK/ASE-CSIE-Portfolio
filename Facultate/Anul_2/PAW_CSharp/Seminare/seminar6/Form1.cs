namespace Seminar_6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnNote_Click(object sender, EventArgs e)
        {
            int nota1 = 0;

            try
            {
                nota1 = Convert.ToInt32(txtNota1.Text);
            }
            catch (Exception ex)
            {
                //MessageBox.Show("Nota trebuie sa fie numerica", "Eroare");
                txtNota1.ForeColor = Color.Red;
                txtNota1.Focus();
                return;
            }

            if (nota1 < 1 || nota1 > 10)
            {
                Random rnd = new Random();
                txtNota1.ForeColor = Color.FromArgb(rnd.Next(256), rnd.Next(256), rnd.Next(256), rnd.Next(256));
                txtNota1.Focus();

                return;
            }

            txtNota1.ForeColor = SystemColors.WindowText;

            int nota2 = 0;

            try
            {
                nota2 = Convert.ToInt32(txtNota2.Text);
            }
            catch (Exception ex)
            {
                errorProvider1.SetError(txtNota2, "Nota trebuie sa fie numerica");
                return;
            }

            if (nota2 < 1 || nota2 > 10)
            {
                errorProvider1.SetError(txtNota2, "Nota trebuie sa fie in intervalul 1-10");
                return;
            }

            errorProvider1.Clear();

            MessageBox.Show("Notele sunt: " + txtNota1.Text + ", " + txtNota2.Text + ", " + txtNota3.Text, "INFO");
        }

        private void btnErrOn_Click(object sender, EventArgs e)
        {
            errorProvider1.SetError(txtNota2, "Eroare nota");
        }

        private void btnOFF_Click(object sender, EventArgs e)
        {
            errorProvider1.Clear();
        }

        private void nota3_keypress(object sender, KeyPressEventArgs e)
        {

            if ((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar == 8)
                e.Handled = false;
            else
                e.Handled = true;
        }

        private void nota3_validating(object sender, System.ComponentModel.CancelEventArgs e)
        {

            TextBox tb = (TextBox)sender;
            int nota3 = 0;

            try
            {
                nota3 = Convert.ToInt32(tb.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                tb.Focus();
                return;
            }

            if (nota3 < 1 || nota3 > 10)
            {
                MessageBox.Show("Nota intre 1 si 10", "Eroare");
                tb.Focus();
                return;
            }
        }

        private void noteAleatoareToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();

            txtNota1.ForeColor = SystemColors.WindowText;
            txtNota1.Text = rnd.Next(1, 11).ToString();
            txtNota2.Text = rnd.Next(1, 11).ToString();
            txtNota3.Text = rnd.Next(1, 11).ToString();
            txtNota1.Focus();
        }

        private void stergeNoteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            txtNota1.Text = "";
            txtNota2.Text = "";
            txtNota3.Text = "";
            txtNota1.Focus();
        }
    }
}
