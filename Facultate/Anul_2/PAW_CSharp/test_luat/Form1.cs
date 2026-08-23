using System.Numerics;

namespace test_luat
{
    public partial class Form1 : Form
    {
        internal class Cetatean
        {
            string nume;
            int varsta;

            public Cetatean(string nume, int varsta)
            {
                this.nume = nume;
                this.varsta = varsta;
            }
            public string Nume { get => nume; set => nume = value; }
            public int Varsta { get => varsta; set => varsta = value; }

            public override string? ToString()
            {
                return "Nume: " + nume + ", Varsta: " + varsta + ", An nastere: " + (2026 - varsta);
            }
        }

        internal class Sportiv : Cetatean
        {
            string disciplina;
            int onorariu;

            public Sportiv(string disciplina, int onorariu, string nume, int varsta) : base(nume, varsta)
            {
                this.disciplina = disciplina;
                this.onorariu = onorariu;
            }

            public string Disciplina { get => disciplina; set => disciplina = value; }
            public int Onorariu { get => onorariu; set => onorariu = value; }

            public override string? ToString()
            {
                return base.ToString() + ", Disciplina: " + disciplina + ", Onorariu: " + onorariu;
            }
        }

        List<Sportiv> listSportivi = new List<Sportiv>();
        private void btn_salvare_Click(object sender, EventArgs e)
        {
            string nume;
            int varsta;
            string disciplina;
            int onorariu;

            nume = txt_nume.Text;

            try
            {
                varsta = Convert.ToInt32(txt_varsta.Text);
            }
            catch (Exception ex)
            {
                txt_varsta.ForeColor = Color.Red;
                MessageBox.Show("Varsta trebuie sa fie valoare numerica");
                return;
            }
            txt_varsta.ForeColor = Color.Black;

            if (varsta < 1 || varsta > 99)
            {
                errorProvider1.SetError(txt_varsta, "Varsta este invalida");
                return;
            }

            errorProvider1.Clear();

            disciplina = txt_Disciplina.Text;

            if (disciplina != "Alergare" || disciplina != "Basket")
            {
                errorProvider2.SetError(txt_Disciplina, "Disciplina este invalida");
                return;
            }

            errorProvider2.Clear();

            try
            {
                onorariu = Convert.ToInt32(txt_onorariu.Text);
            }
            catch (Exception ex)
            {
                txt_onorariu.ForeColor = Color.Red;
                MessageBox.Show("Onorarul trebuie sa fie o valoare numerica");
                return;
            }

            txt_onorariu.ForeColor = Color.Black;

            Sportiv s = new Sportiv(disciplina, onorariu, nume, varsta);


            listBox1.Items.Add(s.ToString());
            listSportivi.Add(s);

            lbl_nrSportivi.Text = "Numar sportivi: " + listSportivi.Count;

            int suma = 0;
            foreach(Sportiv s1 in listSportivi)
            {
                suma += s1.Onorariu;
            }
            lbl_totalOnorarii.Text = "Total onorarii: " + suma;

        }


        private void txt_onorariu_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar >= '0' && e.KeyChar <= '9')
                e.Handled = false;
            else
                e.Handled = true;

        }
    }
}
