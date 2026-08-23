namespace Orar
{
    public partial class Form1 : Form
    {
        Orar orarCurent = new Orar();
        Element cursProgramare = new Element(1, Ora.ora.O9_00, "Programare C#", true);

        Element seminarMate = new Element(2, Ora.ora.O10_30, "Matematica", false);

        Element cursFizica = new Element(3, Ora.ora.O13_30, "Fizica", true);
        public Form1()
        {
            InitializeComponent();

            if (!File.Exists("orar.txt"))
            {
                orarCurent.AdugareElement(cursProgramare);
                orarCurent.AdugareElement(seminarMate);
                orarCurent.AdugareElement(cursFizica);
            }
            else
            {
                CitireDinFisier();
            }

            dataGridViewOrar.DataSource = orarCurent.lista;
        }

        private void toolStripButtonAdaugareElemet_Click(object sender, EventArgs e)
        {
            FormAdaugare fa = new FormAdaugare();
            if (fa.ShowDialog() == DialogResult.OK)
            {
                Element elem = fa.ElementNou;

                bool exisa = false;
                try
                {
                    orarCurent.AdugareElement(elem);

                    dataGridViewOrar.DataSource = null;
                    dataGridViewOrar.DataSource = orarCurent.lista;
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Eroare suprapunere", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        void SalvareInFisier()
        {
            using (StreamWriter sw = new StreamWriter("orar.txt"))
            {
                foreach (var elem in orarCurent.lista)
                {
                    sw.WriteLine(elem.Zi + "," + elem.Ora + "," + elem.Denumire + "," + elem.EsteCurs);
                }
            }
        }

        void CitireDinFisier()
        {
            if (File.Exists("orar.txt"))
            {
                using (StreamReader sr = new StreamReader("orar.txt"))
                {
                    string linie;
                    while ((linie = sr.ReadLine()) != null)
                    {
                        string[] args = linie.Split(',');
                        int zi = int.Parse(args[0]);
                        Ora.ora ora = (Ora.ora)Enum.Parse(typeof(Ora.ora), args[1]);
                        string denumire = args[2];
                        bool esteCurs = bool.Parse(args[3]);
                        Element elem = new Element(zi, ora, denumire, esteCurs);
                        orarCurent.AdugareElement(elem);
                    }
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            SalvareInFisier();
        }
    }
}
