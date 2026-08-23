using System.Windows.Forms;

namespace Restaurant
{
    public partial class Form1 : Form
    {
        List<Produs> produse;

        public Form1()
        {
            InitializeComponent();

            Ingredient somonProaspat = new Ingredient("somon proaspat", 15.0m);
            Ingredient somonFumee = new Ingredient("somon fumee", 12.5m);
            Ingredient avocado = new Ingredient("avocado", 6.0m);
            Ingredient ridiche = new Ingredient("ridiche alba", 2.0m);

            Ingredient rosii = new Ingredient("rosii", 3.5m);
            Ingredient parmezan = new Ingredient("parmezan", 8.0m);
            Ingredient usturoi = new Ingredient("usturoi", 1.5m);

            Ingredient paste = new Ingredient("paste", 4.0m);
            Ingredient carneTocata = new Ingredient("carne tocata", 14.0m);

            Produs p1 = new Produs();
            p1.Denumire = "Tartar de Somon cu Avocado";
            p1.AdaosComercial = 40;
            p1.AdaugaIngredient(somonProaspat, 1);
            p1.AdaugaIngredient(somonFumee, 1);
            p1.AdaugaIngredient(avocado, 1);
            p1.AdaugaIngredient(ridiche, 2);

            Produs p2 = new Produs();
            p2.Denumire = "Supa de rosii";
            p2.AdaosComercial = 50;
            p2.AdaugaIngredient(rosii, 3);
            p2.AdaugaIngredient(parmezan, 1);
            p2.AdaugaIngredient(usturoi, 1);

            Produs p3 = new Produs();
            p3.Denumire = "Paste Bolognese";
            p3.AdaosComercial = 45;
            p3.AdaugaIngredient(paste, 1);
            p3.AdaugaIngredient(carneTocata, 1);
            p3.AdaugaIngredient(parmezan, 1);

            if (!File.Exists("produse.txt"))
                produse = new List<Produs>() { p1, p2, p3 };
            else
            {
                produse = new List<Produs>();
                CitireDinFisier();
            }


            dataGridViewProduse.DataSource = produse;
        }


        void ScriereInFisier()
        {
            using (StreamWriter sw = new StreamWriter("produse.txt"))
            {
                foreach (var p in produse)
                {
                    sw.Write(p.Denumire + "," + p.AdaosComercial + "," + p.NumarIngrediente);
                    for (int i = 0; i < p.NumarIngrediente; i++)
                    {
                        sw.Write("," + p.Ingrediente[i].Denumire + "," + p.Ingrediente[i].PretUnitar + "," + p.Cantitati[i]);
                    }
                    sw.WriteLine();
                }
            }
        }

        void CitireDinFisier()
        {
            if (File.Exists("produse.txt"))
            {
                produse.Clear();
                using (StreamReader sr = new StreamReader("produse.txt"))
                {
                    string linie;
                    while ((linie = sr.ReadLine()) != null)
                    {
                        string[] args = linie.Split(",");
                        string denumire = args[0];
                        decimal adaousComercial = decimal.Parse(args[1]);
                        int nr = int.Parse(args[2]);
                        List<Ingredient> ingrediente = new List<Ingredient>();
                        List<int> cantitati = new List<int>();
                        int index = 3;
                        for (int i = 0; i < nr; i++)
                        {
                            string denumire_i = args[index];
                            decimal pretUnitar = decimal.Parse(args[index + 1]);
                            Ingredient ing = new Ingredient(denumire_i, pretUnitar);
                            int cantitate = int.Parse(args[index + 2]);
                            ingrediente.Add(ing);
                            cantitati.Add(cantitate);
                            index += 3;
                        }

                        Produs p = new Produs(denumire, ingrediente, cantitati, adaousComercial);
                        produse.Add(p);
                    }

                }
            }

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            ScriereInFisier();
        }

        private void exportToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dataGridViewProduse.CurrentRow != null)
            {
                Produs p = (Produs)dataGridViewProduse.CurrentRow.DataBoundItem;

                string textExport = $"{p.Denumire}\tAdaos: {p.AdaosComercial}%\r\n";

                for (int i = 0; i < p.NumarIngrediente; i++)
                {
                    Ingredient ing = p.ObtineIngredient(i);
                    int cantitate = p.ObtineCantitate(i);

                    textExport += $"{ing.Denumire}\t{ing.PretUnitar}\t{cantitate}\r\n";
                }

                Clipboard.SetText(textExport);

                MessageBox.Show("Date copiate! Acum poti da Paste (Ctrl+V) in Excel.");
            }
        }
    }
}
