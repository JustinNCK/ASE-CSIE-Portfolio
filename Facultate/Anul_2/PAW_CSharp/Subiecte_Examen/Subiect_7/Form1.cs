namespace Subiect_7
{
    public partial class Form1 : Form
    {
        List<Eveniment> evenimente = new List<Eveniment>();
        Film f1 = new Film("Sci-Fi", 12, 101, "Interstellar", new DateTime(2026, 07, 15, 19, 30, 0), 169, 35.50m);
        Film f2 = new Film("Horror", 18, 102, "The Shining", new DateTime(2026, 10, 31, 22, 0, 0), 146, 30.00m);
        Concert c1 = new Concert("Coldplay", true, 201, "Music of the Spheres Tour", new DateTime(2026, 08, 12, 20, 0, 0), 120, 250.00m);
        Concert c2 = new Concert("Hans Zimmer", false, 202, "Live in Bucharest", new DateTime(2026, 11, 05, 19, 0, 0), 150, 180.50m);

        public Form1()
        {

            InitializeComponent();


            if (File.Exists("evenimente.txt"))
            {
                CitireDinFisier();
            }
            else
            {
                evenimente.Add(f1);
                evenimente.Add(f2);
                evenimente.Add(c1);
                evenimente.Add(c2);
            }

            populareListView();
            ActualizareStatusStrip();
        }


        void populareListView()
        {
            listViewEvenimente.Items.Clear();

            foreach (var e in evenimente)
            {
                listViewEvenimente.Items.Add(e.Afisare());
            }
        }

        void ActualizareStatusStrip()
        {
            int nrFilme = 0;
            int nrConcerte = 0;
            decimal sumaPreturi = 0;

            foreach (var ev in evenimente)
            {
                if(ev is Film)
                    nrFilme++;
                else
                    nrConcerte++;

                sumaPreturi += ev.PretBilet;
            }

            if (evenimente.Count > 0)
                sumaPreturi /= evenimente.Count;
            toolStripStatusLabel1.Text = "Filme: " + nrFilme + ", Concerte: " + nrConcerte + ", Pret mediu: " + sumaPreturi;
        }

        private void adaugaEvenimentToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (AdaugaEveniment ae = new AdaugaEveniment()) {
                if (ae.ShowDialog() == DialogResult.OK) {
                    Eveniment nou = ae.EvenimentNou;

                    bool codExista = false;

                    foreach (var ev in evenimente)
                    {
                        if (ev.Cod == nou.Cod)
                        {
                            codExista = true;
                            break;
                        }
                    }

                    if (!codExista)
                    {
                        evenimente.Add(nou);
                        populareListView();
                        ActualizareStatusStrip();
                    }
                    else
                    {
                        MessageBox.Show("Codul exista deja");
                    }
                }
            }
        }

        void SalvareInFisier()
        {
            using (StreamWriter sw = new StreamWriter("evenimente.txt"))
            {
                foreach (var ev in evenimente)
                {
                    if (ev is Film)
                    {
                        Film f = (Film)ev;
                        sw.WriteLine("Film," + f.Cod + "," + f.Titlu + "," + f.DataOra + "," + f.DurataMinute + "," + f.PretBilet + "," + f.Gen + "," + f.VarstaMinima);
                    }
                    else if (ev is Concert)
                    {
                        Concert c = (Concert)ev;
                        sw.WriteLine("Concert," + c.Cod + "," + c.Titlu + "," + c.DataOra + "," + c.DurataMinute + "," + c.PretBilet + "," + c.Artist + "," + c.InAerLiber);
                    }
                }
            }
        }

        void CitireDinFisier()
        {
            if (File.Exists("evenimente.txt"))
            {
                using (StreamReader sr = new StreamReader("evenimente.txt"))
                {
                    string linie;
                    while ((linie = sr.ReadLine()) != null)
                    {
                        string[] args = linie.Split(',');
                        string tip = args[0];
                        int cod = int.Parse(args[1]);
                        string titlu = args[2];
                        DateTime dataOra = DateTime.Parse(args[3]);
                        int durataMinute = int.Parse(args[4]);
                        decimal pretBilet = decimal.Parse(args[5]);

                        if (tip == "Film")
                        {
                            string gen = args[6];
                            int varstaMinima = int.Parse(args[7]);
                            Film f = new Film(gen, varstaMinima, cod, titlu, dataOra, durataMinute, pretBilet);
                            evenimente.Add(f);
                        }
                        else if (tip == "Concert")
                        {
                            string artist = args[6];
                            bool inAerLiber = bool.Parse(args[7]);
                            Concert c = new Concert(artist, inAerLiber, cod, titlu, dataOra, durataMinute, pretBilet);
                            evenimente.Add(c);
                        }
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
