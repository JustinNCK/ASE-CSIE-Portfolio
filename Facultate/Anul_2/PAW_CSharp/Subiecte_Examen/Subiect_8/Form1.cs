namespace Subiect_8
{
    public partial class Form1 : Form
    {
        Service serviceAuto;

        public Form1()
        {
            InitializeComponent();

            serviceAuto = new Service();

            if (File.Exists("reparatii.txt"))
            {
                CitireDinFisier();
            }
            else
            {

                Masina masina1 = new Masina("B123ABC", "Logan", "Dacia", 2018);
                Masina masina2 = new Masina("IF99XYZ", "Golf", "Volkswagen", 2020);
                Masina masina3 = new Masina("CJ45DEF", "320d", "BMW", 2015);

                Reparatie rep1 = new Reparatie(masina1, "Schimb ulei si filtre", 350, 150);
                Reparatie rep2 = new Reparatie(masina2, "Inlocuire placute frana", 400, 200);
                Reparatie rep3 = new Reparatie(masina3, "Schimb distributie", 1200, 600);
                Reparatie rep4 = new Reparatie(masina1, "Bec far ars", 30, 20);

                serviceAuto.Adauga(rep1);
                serviceAuto.Adauga(rep2);
                serviceAuto.Adauga(rep3);
                serviceAuto.Adauga(rep4);
            }

            ActualizareListView();
        }

        void ActualizareListView()
        {
            listViewService.Items.Clear();
            foreach (var sa in serviceAuto.Reparatii)
            {
                ListViewItem item = new ListViewItem(sa.Masina.NumarInmatriculare);
                item.SubItems.Add(sa.Masina.Marca);
                item.SubItems.Add(sa.Descriere);
                item.SubItems.Add(sa.CostTotal.ToString());
                if (sa.Finalizat == false)
                    item.SubItems.Add("Nu");
                else
                    item.SubItems.Add("Da");

                listViewService.Items.Add(item);
            }
            ActualizareStatusStrip();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            using (Adaugare a = new Adaugare())
            {
                if (a.ShowDialog() == DialogResult.OK)
                {
                    Reparatie r = a.ReparatieNoua;

                    serviceAuto.Reparatii.Add(r);
                }

            }

            ActualizareListView();

        }

        void SalvareInFisier()
        {
            using (StreamWriter sw = new StreamWriter("reparatii.txt"))
            {
                foreach (var sv in serviceAuto.Reparatii)
                {
                    sw.Write(sv.Masina.NumarInmatriculare + "," + sv.Masina.Marca + "," + sv.Masina.Model + "," + sv.Masina.AnFabricatie + ",");
                    sw.WriteLine(sv.Descriere + "," + sv.CostPiese + "," + sv.CostManopera + "," + sv.Finalizat);
                }
            }
        }

        void CitireDinFisier()
        {
            using (StreamReader sr = new StreamReader("reparatii.txt"))
            {
                string linie;
                while ((linie = sr.ReadLine()) != null)
                {
                    string[] args = linie.Split(',');
                    string numarInmatriculare = args[0];
                    string marca = args[1];
                    string model = args[2];
                    int anFabricatie = int.Parse(args[3]);
                    Masina masina = new Masina(numarInmatriculare, model, marca, anFabricatie);

                    string descriere = args[4];
                    decimal costPiese = decimal.Parse(args[5]);
                    decimal costManopera = decimal.Parse(args[6]);
                    bool finalizat = bool.Parse(args[7]);

                    Reparatie r = new Reparatie(masina, descriere, costPiese, costManopera, finalizat);

                    serviceAuto.Adauga(r);
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            SalvareInFisier();
        }

        void ActualizareStatusStrip()
        {
            toolStripStatusLabelService.Text = "Reparatii in desfasurare: " + serviceAuto.NrReparatii + " Costul Total incasat: " + serviceAuto.SumaIncasata;
        }

        private void listViewService_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (listViewService.SelectedItems.Count > 0) {
                DialogResult raspuns = MessageBox.Show("Sigur doriti sa marcati aceasta reparatie ca finalizata?",
                "Confirmare Finalizare", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

                if (raspuns == DialogResult.Yes)
                {
                    int pozitie = listViewService.SelectedIndices[0];

                    try
                    {
                        serviceAuto.Finalizeaza(pozitie);

                        ActualizareListView();

                        ActualizareStatusStrip();
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message, "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    }
                }
            }
        }
    }
}
