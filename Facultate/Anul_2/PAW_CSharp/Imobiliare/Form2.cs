using System.Drawing.Printing;

namespace Imobiliare
{
    public partial class Form1 : Form
    {
        Apartament ap1 = new Apartament(2, 101, "Apartament 2 camere Romana", 60, 2, 110000);
        Apartament ap2 = new Apartament(5, 102, "Penthouse Herastrau", 150, 4, 450000);

        Casa casa1 = new Casa(350, 2, 201, "Vila Pipera P+1", 180, 5, 320000);
        Casa casa2 = new Casa(600, 1, 202, "Casa Snagov Parter", 110, 3, 185000);

        List<Locuinta> locuinte;

        void PopuleazaListView()
        {
            listViewLocuinte.Items.Clear();
            foreach (Locuinta loc in locuinte)
            {
                listViewLocuinte.Items.Add(loc.Afisare());
            }
            StatusStripUpdate();
        }

        void StatusStripUpdate()
        {
            int nrCase = 0;
            int nrApartamente = 0;
            decimal pretMediu = 0;
            foreach (Locuinta loc in locuinte)
            {
                if (loc is Apartament)
                    nrApartamente++;
                else
                    nrCase++;

                pretMediu += loc.Pret / loc.Suprafata;
            }

            pretMediu = pretMediu / locuinte.Count();

            toolStripStatusLabelNrApartamente.Text = "Numar apartamente: " + nrApartamente;
            toolStripStatusLabelNrCase.Text = "Numar case: " + nrCase;
            toolStripStatusLabelPretMediu.Text = "Pretul mediu pe metru patrat: " + pretMediu;
        }

        public Form1()
        {
            InitializeComponent();
            if (!File.Exists("locuinte.txt"))
                locuinte = new List<Locuinta>() { ap1, ap2, casa1, casa2 };
            else
            {
                locuinte = new List<Locuinta>();
                CitireDinFisier();
            }

            PopuleazaListView();
        }

        private void adaugareAnuntToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (FormAdaugare frm = new FormAdaugare())
            {
                if (frm.ShowDialog() == DialogResult.OK)
                {
                    Locuinta locNoua = frm.LocuintaNoua;
                    bool codGasit = false;

                    foreach (Locuinta loc in locuinte)
                    {
                        if (loc.Cod == locNoua.Cod)
                        {
                            codGasit = true;
                            break;
                        }
                    }

                    if (codGasit)
                    {
                        MessageBox.Show("Eroare: O locuinta cu acest cod exista deja!", "Cod Duplicat", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                    else
                    {
                        locuinte.Add(locNoua);
                        PopuleazaListView();
                    }
                }
            }
        }

        private void SalvareInFisier()
        {
            using (StreamWriter sw = new StreamWriter("locuinte.txt"))
            {
                foreach (Locuinta loc in locuinte)
                {
                    if (loc is Apartament)
                    {
                        Apartament ap = (Apartament)loc;
                        sw.WriteLine("Apartament," + ap.Cod + "," + ap.Denumire + "," + ap.Suprafata + "," + ap.NrCamere + "," + ap.Pret + "," + ap.Etaj);
                    }
                    else
                    {
                        Casa casa = (Casa)loc;
                        sw.WriteLine("Casa," + casa.Cod + "," + casa.Denumire + "," + casa.Suprafata + "," + casa.NrCamere + "," + casa.Pret + "," + casa.SuprafataTeren + "," + casa.NrNiveluri);
                    }
                }

            }
        }

        private void CitireDinFisier()
        {
            if (File.Exists("locuinte.txt"))
            {
                using (StreamReader sr = new StreamReader("locuinte.txt"))
                {
                    string linie;
                    while ((linie = sr.ReadLine()) != null)
                    {
                        string[] args = linie.Split(',');
                        int cod = int.Parse(args[1]);
                        string denumire = args[2];
                        int suprafata = int.Parse(args[3]);
                        int nrCamere = int.Parse(args[4]);
                        int pret = int.Parse(args[5]);
                        if (args[0] == "Apartament")
                        {
                            int etaj = int.Parse(args[6]);
                            Apartament ap = new Apartament(etaj, cod, denumire, suprafata, nrCamere, pret);
                            locuinte.Add(ap);
                        }
                        else
                        {
                            int suprafataTeren = int.Parse(args[6]);
                            int nrNiveluri = int.Parse(args[7]);
                            Casa casa = new Casa(suprafataTeren, nrNiveluri, cod, denumire, suprafata, nrCamere, pret);
                            locuinte.Add(casa);
                        }
                    }

                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            SalvareInFisier();
        }

        private void tiparireToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintDocument pd = new PrintDocument();
            pd.PrintPage += Pd_PrintPage;

            PrintPreviewDialog ppd = new PrintPreviewDialog();
            ppd.Document = pd;
            ppd.ShowDialog();
        }

        private void Pd_PrintPage(object sender, PrintPageEventArgs e)
        {
            Graphics g = e.Graphics;

            Font fontTitlu = new Font("Arial", 16, FontStyle.Bold);
            Font fontCapTabel = new Font("Arial", 12, FontStyle.Bold);
            Font fontText = new Font("Arial", 12);
            Brush brush = Brushes.Black;

            int x = 50;
            int yCurent = 50;

            g.DrawString("Lista Oferte Imobiliare", fontTitlu, brush, x, yCurent);
            yCurent += 50;

            g.DrawString("Cod | Denumire | Tip | Suprafata | Pret", fontCapTabel, brush, x, yCurent);
            yCurent += 30;

            g.DrawString("--------------------------------------------------------------------------------", fontText, brush, x, yCurent);
            yCurent += 30;

            foreach (Locuinta loc in locuinte)
            {
                string tip = loc is Apartament ? "Apartament" : "Casa";

                string randTabel = $"{loc.Cod} | {loc.Denumire} | {tip} | {loc.Suprafata} mp | {loc.Pret} EUR";

                g.DrawString(randTabel, fontText, brush, x, yCurent);
                yCurent += 30;
            }
        }
    }
}
