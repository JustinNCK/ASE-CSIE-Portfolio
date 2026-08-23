namespace Subiect_5
{
    public partial class Form1 : Form
    {
        List<Carte> cartiDisponibile;
        Biblioteca biblioteca;
        public Form1()
        {
            InitializeComponent();

            cartiDisponibile = new List<Carte>()
            {
                new Carte(101, "Cel mai iubit dintre pamanteni", "Marin Preda", 1980, true),
                new Carte(102, "Enigma Otiliei", "George Calinescu", 1938, true),
                new Carte(103, "Ion", "Liviu Rebreanu", 1920, true),
                new Carte(104, "Moara cu noroc", "Ioan Slavici", 1881, true)
            };

            biblioteca = new Biblioteca();

            IncarcaDate();

            if (biblioteca.Imprumuturi.Count == 0)
            {
                biblioteca.Imprumuta(cartiDisponibile[0], "Popescu Ion", DateTime.Today.AddDays(10));
                biblioteca.Imprumuta(cartiDisponibile[1], "Ionescu Maria", DateTime.Today.AddDays(-5));
            }


            ActualizareListView();
        }

        void ActualizareListView()
        {
            listViewImprumuturi.Items.Clear();
            foreach (var im in biblioteca.Imprumuturi)
            {
                if (!im.Carte.Disponibila)
                {
                    ListViewItem item = new ListViewItem(im.Carte.Cod.ToString());
                    item.SubItems.Add(im.Carte.Titlu);
                    item.SubItems.Add(im.Carte.Autor);
                    item.SubItems.Add(im.NumeCititor);
                    item.SubItems.Add(im.DataImprumut.ToString());
                    item.SubItems.Add(im.DataReturnare.ToString());
                    if (im.EsteDepasit)
                    {
                        item.SubItems.Add("Da");
                        item.BackColor = Color.MistyRose;
                    }
                    else
                        item.SubItems.Add("Nu");
                    listViewImprumuturi.Items.Add(item);
                }
            }
            ActualizareStatus();
        }

        private void toolStripButtonImprumuta_Click(object sender, EventArgs e)
        {
            using (Imprumuta a = new Imprumuta(cartiDisponibile))
            {
                if (a.ShowDialog() == DialogResult.OK)
                {
                    Carte carte = a.ICarte;
                    string nume = a.INume;
                    DateTime returnare = a.IData;
                    
                    biblioteca.Imprumuta(carte, nume, returnare);

                    ActualizareListView();
                }
            }
        }

        void SalveazaDate()
        {
            StreamWriter sw = new StreamWriter("date.txt");

            sw.WriteLine(cartiDisponibile.Count);
            foreach (var c in cartiDisponibile)
            {
                sw.WriteLine(c.Cod + "|" + c.Titlu + "|" + c.Autor + "|" + c.AnAparatie + "|" + c.Disponibila);
            }

            sw.WriteLine(biblioteca.Imprumuturi.Count);
            foreach (var im in biblioteca.Imprumuturi)
            {
                long ticksReturnare = im.DataReturnare.HasValue ? im.DataReturnare.Value.Ticks : 0;

                sw.WriteLine(im.Carte.Cod + "|" + im.NumeCititor + "|" + im.DataImprumut.Ticks + "|" + ticksReturnare);
            }
            sw.Close();
        }

        void IncarcaDate()
        {
            if (File.Exists("date.txt"))
            {
                StreamReader sr = new StreamReader("date.txt");

                int nrCarti = int.Parse(sr.ReadLine());
                cartiDisponibile.Clear();
                for (int i = 0; i < nrCarti; i++)
                {
                    string[] linie = sr.ReadLine().Split('|');
                    cartiDisponibile.Add(new Carte(int.Parse(linie[0]), linie[1], linie[2], int.Parse(linie[3]), bool.Parse(linie[4])));
                }

                int nrImprumuturi = int.Parse(sr.ReadLine());
                biblioteca.Imprumuturi.Clear();
                for (int i = 0; i < nrImprumuturi; i++)
                {
                    string[] linie = sr.ReadLine().Split('|');
                    int cod = int.Parse(linie[0]);
                    Carte carte = cartiDisponibile.Find(c => c.Cod == cod);
                    if (carte != null)
                    {
                        DateTime d1 = new DateTime(long.Parse(linie[2]));

                        long ticks = long.Parse(linie[3]);
                        DateTime? d2 = null;
                        if (ticks != 0)
                        {
                            d2 = new DateTime(ticks);
                        }

                        biblioteca.Imprumuturi.Add(new Imprumut(carte, linie[1], d1, d2));
                    }
                }
                    sr.Close();
            }
        }

        void ActualizareStatus()
        {
            int nr = 0;
            foreach (var c in cartiDisponibile)
            {
                if (c.Disponibila) nr++;
            }
            toolStripStatusLabel1.Text = "Carti disponibile: " + nr;
            toolStripStatusLabel2.Text = " Imprumuturi active: " + biblioteca.NumarImprumuturiActive;
            toolStripStatusLabel3.Text = " Imprumuturi depasite: " + biblioteca.NumarImprumuturiDepasite;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            SalveazaDate();
        }
    }
}
