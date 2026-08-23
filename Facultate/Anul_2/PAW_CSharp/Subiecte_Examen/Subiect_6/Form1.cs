using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace Subiect_6
{
    public partial class Form1 : Form
    {
        Turneu turneu;

        public Form1()
        {
            InitializeComponent();

            turneu = new Turneu();

            IncarcaDate();

            if (turneu.Echipe.Count == 0 && turneu.Meciuri.Count == 0)
            {
                Echipa e1 = new Echipa(1, "Steaua", "Bucuresti");
                Echipa e2 = new Echipa(2, "Dinamo", "Bucuresti");
                Echipa e3 = new Echipa(3, "CFR Cluj", "Cluj-Napoca");
                Echipa e4 = new Echipa(4, "Universitatea Craiova", "Craiova");

                turneu.AdaugaEchipa(e1);
                turneu.AdaugaEchipa(e2);
                turneu.AdaugaEchipa(e3);
                turneu.AdaugaEchipa(e4);

                Meci m1 = new Meci(101, e1, e2, DateTime.Today.AddDays(-5));
                Meci m2 = new Meci(102, e3, e4, DateTime.Today.AddDays(-3));
                Meci m3 = new Meci(103, e1, e3, DateTime.Today.AddDays(2));
                Meci m4 = new Meci(104, e4, e2, DateTime.Today.AddDays(4));

                m1.InregistreazaRezultat(3, 1);
                m2.InregistreazaRezultat(2, 2);

                turneu.ProgrameazaMeci(m1);
                turneu.ProgrameazaMeci(m2);
                turneu.ProgrameazaMeci(m3);
                turneu.ProgrameazaMeci(m4);
            }

            ActualizareTabControl();
        }

        void ActualizareTabControl()
        {
            listViewMeciuri.Items.Clear();
            foreach (var m in turneu.Meciuri)
            {
                ListViewItem item = new ListViewItem(m.DataMeci.ToShortDateString());
                item.SubItems.Add(m.Gazda.Denumire);
                item.SubItems.Add(m.Oaspete.Denumire);
                if (m.Rezultat == Rezultate.Necunoscut)
                    item.SubItems.Add("Neprogramat");
                else
                    item.SubItems.Add(m.Golgazda + " - " + m.Goloaspete);

                listViewMeciuri.Items.Add(item);
            }

            listViewClasament.Items.Clear();
            int pozitie = 1;
            foreach (var c in turneu.Clasament())
            {
                ListViewItem item = new ListViewItem(pozitie.ToString());
                item.SubItems.Add(c.Echip.Denumire);
                item.SubItems.Add(c.Echip.Localitate);
                item.SubItems.Add(c.MeciuriJucate.ToString());
                item.SubItems.Add(c.Puncte.ToString());
                item.SubItems.Add(c.GoluriMarcate.ToString());
                item.SubItems.Add(c.GoluriPrimite.ToString());

                listViewClasament.Items.Add(item);
                pozitie++;
            }
        }

        void SalveazaDate()
        {
            StreamWriter swEchipe = new StreamWriter("echipe.txt");
            swEchipe.WriteLine(turneu.Echipe.Count);
            foreach (var e in turneu.Echipe)
            {
                swEchipe.WriteLine(e.Cod + "|" + e.Denumire + "|" + e.Localitate);
            }
            swEchipe.Close();

            StreamWriter swMeciuri = new StreamWriter("meciuri.txt");
            swMeciuri.WriteLine(turneu.Meciuri.Count);
            foreach (var m in turneu.Meciuri)
            {
                swMeciuri.WriteLine(m.Cod + "|" + m.Gazda.Cod + "|" + m.Oaspete.Cod + "|" + m.DataMeci.Ticks + "|" + (int)m.Rezultat + "|" + m.Golgazda + "|" + m.Goloaspete);
            }
            swMeciuri.Close();
        }

        void IncarcaDate()
        {
            if (File.Exists("echipe.txt"))
            {
                StreamReader srEchipe = new StreamReader("echipe.txt");
                int nrEchipe = int.Parse(srEchipe.ReadLine());
                turneu.Echipe.Clear();
                for (int i = 0; i < nrEchipe; i++)
                {
                    string[] linie = srEchipe.ReadLine().Split('|');
                    turneu.Echipe.Add(new Echipa(int.Parse(linie[0]), linie[1], linie[2]));
                }
                srEchipe.Close();
            }

            if (File.Exists("meciuri.txt"))
            {
                StreamReader srMeciuri = new StreamReader("meciuri.txt");
                int nrMeciuri = int.Parse(srMeciuri.ReadLine());
                turneu.Meciuri.Clear();
                for (int i = 0; i < nrMeciuri; i++)
                {
                    string[] linie = srMeciuri.ReadLine().Split('|');
                    int codMeci = int.Parse(linie[0]);
                    int codGazda = int.Parse(linie[1]);
                    int codOaspete = int.Parse(linie[2]);
                    DateTime data = new DateTime(long.Parse(linie[3]));
                    Rezultate rez = (Rezultate)int.Parse(linie[4]);
                    int golG = int.Parse(linie[5]);
                    int golO = int.Parse(linie[6]);

                    Echipa g = turneu.Echipe.Find(e => e.Cod == codGazda);
                    Echipa o = turneu.Echipe.Find(e => e.Cod == codOaspete);

                    if (g != null && o != null)
                    {
                        Meci m = new Meci(codMeci, g, o, data);
                        m.Rezultat = rez;
                        m.Golgazda = golG;
                        m.Goloaspete = golO;
                        turneu.Meciuri.Add(m);
                    }
                }
                srMeciuri.Close();
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            SalveazaDate();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            using (InregistreazaRezultatForm f = new InregistreazaRezultatForm(turneu.Meciuri))
            {
                if (f.ShowDialog() == DialogResult.OK)
                {
                    if (f.MeciSelectat != null)
                    {
                        try
                        {
                            f.MeciSelectat.InregistreazaRezultat(f.GoluriGazda, f.GoluriOaspete);
                            ActualizareTabControl();
                        }
                        catch (ArgumentException ex)
                        {
                            MessageBox.Show(ex.Message);
                        }
                    }
                }
            }
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            using (AdaugaEchipaForm f = new AdaugaEchipaForm())
            {
                if (f.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        int urmatorulCod = turneu.Echipe.Count + 1;
                        Echipa noua = new Echipa(urmatorulCod, f.EDenumire, f.ELocalitate);

                        turneu.AdaugaEchipa(noua);
                        ActualizareTabControl();
                    }
                    catch (ArgumentException ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                }
            }
        }
    }
}