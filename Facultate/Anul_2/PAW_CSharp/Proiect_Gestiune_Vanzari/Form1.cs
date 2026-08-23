using System.IO;
using System.Windows.Forms;
using System.Xml.Serialization;
using Microsoft.Data.Sqlite;

namespace Proiect
{
    public partial class Form1 : Form
    {
        List<Produs> listaProduse = new List<Produs>();
        List<Client> listaClienti = new List<Client>();


        public Form1()
        {
            InitializeComponent();
        }


        //FUNCTII PRODUS
        private void btnAdaugaProdus_Click(object sender, EventArgs e)
        {
            int id;
            string denumire;
            double pret;

            try
            {
                id = Convert.ToInt32(txtIdProdus.Text);
            }
            catch (Exception ex)
            {
                errorProvider1.SetError(txtIdProdus, "ID-ul trebuie sa fie o valoare numerica");
                txtIdProdus.ForeColor = Color.Red;
                txtIdProdus.Focus();
                return;
            }
            txtIdProdus.ForeColor = Color.Black;
            errorProvider1.Clear();

            denumire = txtDenumire.Text;

            try
            {
                pret = Convert.ToDouble(txtPret.Text);
            }
            catch (Exception ex)
            {
                errorProvider2.SetError(txtPret, "Pretul trebuie sa fie o valoare numerica");
                txtPret.ForeColor = Color.Red;
                txtPret.Focus();
                return;
            }
            txtPret.ForeColor = Color.Black;
            errorProvider2.Clear();

            Produs p = new Produs(id, denumire, pret);
            listaProduse.Add(p);
            lstBx_date.Items.Add(p.Denumire + " - " + p.Pret + " RON");

            MessageBox.Show("Produsul " + denumire + " a fost adaugat cu succes!");

            txtIdProdus.Clear();
            txtDenumire.Clear();
            txtPret.Clear();

            ActualizeazaBinding();

        }

        private void txtDenumire_KeyPress(object sender, KeyPressEventArgs e)
        {

            if (e.KeyChar >= '0' && e.KeyChar <= '9')
                e.Handled = true;
            else

                e.Handled = false;
        }

        private void txtIdProdus_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar == 8)
                e.Handled = false;
            else
                e.Handled = true;
        }

        private void txtPret_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar == 8 || e.KeyChar == '.')
                e.Handled = false;
            else
                e.Handled = true;
        }

        private void salveazaDateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter("produse.txt"))
                {
                    foreach (Produs p in listaProduse)
                    {
                        sw.WriteLine(p.Id + "|" + p.Denumire + "|" + p.Pret);
                    }
                }
                MessageBox.Show("Datele au fost salvate cu succes in fisierul produse.txt!", "Salvare reusita");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la salvarea fisierului: " + ex.Message);
            }
        }

        private void afiseazaDateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (!File.Exists("produse.txt"))
                {
                    MessageBox.Show("Fisierul produse.txt nu exista inca. Salveaza date mai intai!", "Atentie");
                    return;
                }

                listaProduse.Clear();
                lstBx_date.Items.Clear();

                using (StreamReader sr = new StreamReader("produse.txt"))
                {
                    string linie;
                    while ((linie = sr.ReadLine()) != null)
                    {
                        string[] atribute = linie.Split('|');

                        if (atribute.Length == 3)
                        {
                            int id = Convert.ToInt32(atribute[0]);
                            string denumire = atribute[1];
                            double pret = Convert.ToDouble(atribute[2]);

                            Produs p = new Produs(id, denumire, pret);
                            listaProduse.Add(p);
                            lstBx_date.Items.Add(p.Denumire + " - " + p.Pret + " RON");
                        }
                    }
                }
                MessageBox.Show($"Datele au fost restaurate cu succes!\nAvem {listaProduse.Count} produse in aplicatie.", "Incarcare reusita");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la incarcarea fisierului: " + ex.Message);
            }
        }

        private void stergeProduseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (lstBx_date.SelectedIndex != -1)
            {
                int index = lstBx_date.SelectedIndex;

                listaProduse.RemoveAt(index);

                lstBx_date.Items.RemoveAt(index);

                MessageBox.Show("Produsul a fost sters cu succes!", "Stergere");
            }
            else
            {
                MessageBox.Show("Te rog sa selectezi un produs dand click pe el inainte de a-l sterge.", "Atentie");
            }

            ActualizeazaBinding();
        }

        private void lstBx_date_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                if (lstBx_date.SelectedIndex != -1)
                {
                    string produsSelectat = lstBx_date.SelectedItem.ToString();
                    lstBx_date.DoDragDrop(produsSelectat, DragDropEffects.Copy);
                }
            }

           if (e.Button == MouseButtons.Right)
            {
                int index = lstBx_date.IndexFromPoint(e.Location);

                if (index != -1)
                {
                    lstBx_date.SelectedIndex = index;
                }
            }
        }

        private void lstBx_cosDeCumparaturi_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.StringFormat))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void panelGrafic_Paint(object sender, PaintEventArgs e)
        {
            if (listaProduse.Count == 0) return;

            Graphics g = e.Graphics;
            Rectangle zonaClient = e.ClipRectangle;

            int latimeBara = zonaClient.Width / listaProduse.Count / 2;
            int distanta = (zonaClient.Width - (latimeBara * listaProduse.Count)) / (listaProduse.Count + 1);

            double pretMax = 0;
            foreach (Produs p in listaProduse)
            {
                if (p.Pret > pretMax)
                    pretMax = p.Pret;
            }

            if (pretMax == 0)
                pretMax = 1;

            Brush pensula = new SolidBrush(Color.Blue);
            Font font = new Font("Arial", 10);
            Brush pensulaText = new SolidBrush(Color.Black);

            for (int i = 0; i < listaProduse.Count; i++)
            {
                int inaltimeBara = (int)((listaProduse[i].Pret / pretMax) * (zonaClient.Height - 50));

                int x = distanta + i * (latimeBara + distanta);
                int y = zonaClient.Height - inaltimeBara - 20;

                g.FillRectangle(pensula, x, y, latimeBara, inaltimeBara);

                g.DrawString(listaProduse[i].Denumire, font, pensulaText, x, zonaClient.Height - 15);
                g.DrawString(listaProduse[i].Pret.ToString(), font, pensulaText, x, y - 20);
            }
        }

        private void lstBx_cosDeCumparaturi_DragDrop(object sender, DragEventArgs e)
        {
            string produsAdaugat = (string)e.Data.GetData(DataFormats.StringFormat);

            lstBx_cosDeCumparaturi.Items.Add(produsAdaugat);

            MessageBox.Show("Ai adaugat in cos: " + produsAdaugat, "Cos de cumparaturi");
        }

        private void salveazaXMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                XmlSerializer serializer = new XmlSerializer(typeof(List<Produs>));

                using (FileStream fs = new FileStream("produse.xml", FileMode.Create))
                {
                    serializer.Serialize(fs, listaProduse);
                }

                MessageBox.Show("Datele au fost salvate cu succes in format XML!", "Salvare XML");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la salvarea XML: " + ex.Message);
            }
        }

        private void incarcaXMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (!File.Exists("produse.xml"))
                {
                    MessageBox.Show("Fisierul produse.xml nu exista inca!", "Atentie");
                    return;
                }

                XmlSerializer serializer = new XmlSerializer(typeof(List<Produs>));

                using (FileStream fs = new FileStream("produse.xml", FileMode.Open))
                {
                    List<Produs> listaNoua = (List<Produs>)serializer.Deserialize(fs);

                    listaProduse.Clear();
                    lstBx_date.Items.Clear();

                    foreach (Produs p in listaNoua)
                    {
                        listaProduse.Add(p);
                        lstBx_date.Items.Add(p.Denumire + " - " + p.Pret + " RON");
                    }
                }

                MessageBox.Show($"Datele au fost restaurate cu succes din XML!\nAvem {listaProduse.Count} produse.", "Incarcare XML");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la incarcarea XML: " + ex.Message);
            }

            ActualizeazaBinding();
        }

        private void ActualizeazaStatusBar()
        {
            statusControl1.ActualizeazaDate(listaProduse.Count, listaClienti.Count);
        }

        private void ActualizeazaBinding()
        {
            dgvProduse.DataSource = null;
            dgvProduse.DataSource = listaProduse;

            ActualizeazaStatusBar();
        }

        private void copiazaInClipboardToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dgvProduse.CurrentRow != null)
            {
                Produs p = (Produs)dgvProduse.CurrentRow.DataBoundItem;
                string text = "Produs: " + p.Denumire + " - Pret: " + p.Pret;

                Clipboard.SetText(text);
                MessageBox.Show("Datele produsului au fost copiate in Clipboard!");
            }
        }

        private void printeazaListaProduseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            printPreviewDialog1.Document = printDocument1;

            printPreviewDialog1.ShowDialog();
        }

        private void produsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panelTabel.Visible = false;
            panelProdus.Visible = true;
            panelClient.Visible = false;
            panelGrafic.Visible = false;
        }

        private void clientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panelTabel.Visible = false;
            panelProdus.Visible = false;
            panelClient.Visible = true;
            panelGrafic.Visible = false;
        }

        private void graficPreturiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panelTabel.Visible = false;
            panelProdus.Visible = false;
            panelClient.Visible = false;
            panelGrafic.Visible = true;

            panelGrafic.Invalidate();
        }

        private void vizualizareTabelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panelProdus.Visible = false;
            panelClient.Visible = false;
            panelGrafic.Visible = false;
            panelTabel.Visible = true;

            ActualizeazaBinding();
        }


        //FUNCTII CLIENT
        private void btnAdaugaClient_Click(object sender, EventArgs e)
        {
            int id;
            string nume;
            string adresa;

            try
            {
                id = Convert.ToInt32(txtIdClient.Text);
            }
            catch (Exception ex)
            {
                errorProvider1.SetError(txtIdClient, "ID-ul trebuie sa fie o valoare numerica");
                txtIdClient.ForeColor = Color.Red;
                txtIdClient.Focus();
                return;
            }
            txtIdClient.ForeColor = Color.Black;
            errorProvider1.Clear();

            nume = txtNume.Text;
            adresa = txtAdresa.Text;

            Client c = new Client(id, nume, adresa);
            listaClienti.Add(c);
            lstBx_clienti.Items.Add(c.Nume + " - " + c.Adresa);

            MessageBox.Show("Clientul " + nume + " a fost adaugat cu succes!");

            txtIdClient.Clear();
            txtNume.Clear();
            txtAdresa.Clear();

            ActualizeazaBinding();
        }

        private void txtNume_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar >= '0' && e.KeyChar <= '9')
                e.Handled = true;
            else
                e.Handled = false;
        }

        private void txtIdClient_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar == 8)
                e.Handled = false;
            else
                e.Handled = true;
        }

        private void salveazaClientiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter("clienti.txt"))
                {
                    foreach (Client c in listaClienti)
                    {
                        sw.WriteLine(c.IdClient + "|" + c.Nume + "|" + c.Adresa);
                    }
                }
                MessageBox.Show("Datele au fost salvate cu succes in fisierul clienti.txt!", "Salvare reusita");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la salvarea fisierului: " + ex.Message);
            }
        }

        private void afiseazaClientiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (!File.Exists("clienti.txt"))
                {
                    MessageBox.Show("Fisierul clienti.txt nu exista inca. Salveaza date mai intai!", "Atentie");
                    return;
                }

                listaClienti.Clear();
                lstBx_clienti.Items.Clear();

                using (StreamReader sr = new StreamReader("clienti.txt"))
                {
                    string linie;
                    while ((linie = sr.ReadLine()) != null)
                    {
                        string[] atribute = linie.Split('|');
                        if (atribute.Length == 3)
                        {
                            int id = Convert.ToInt32(atribute[0]);
                            string nume = atribute[1];
                            string adresa = atribute[2];

                            Client c = new Client(id, nume, adresa);
                            listaClienti.Add(c);
                            lstBx_clienti.Items.Add(c.Nume + " - " + c.Adresa);
                        }
                    }
                }
                MessageBox.Show($"Datele au fost restaurate cu succes!\nAvem {listaClienti.Count} clienti in aplicatie.", "Incarcare reusita");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la incarcarea fisierului: " + ex.Message);
            }

            ActualizeazaBinding();
        }

        private void stergeClientiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (lstBx_clienti.SelectedIndex != -1)
            {
                int index = lstBx_clienti.SelectedIndex;
                listaClienti.RemoveAt(index);
                lstBx_clienti.Items.RemoveAt(index);
                MessageBox.Show("Clientul a fost sters cu succes!", "Stergere");
            }
            else
            {
                MessageBox.Show("Te rog sa selectezi un client dand click pe el inainte de a-l sterge.", "Atentie");
            }

            ActualizeazaBinding();
        }

        private void printDocument1_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            Graphics g = e.Graphics;

            Font fontTitlu = new Font("Arial", 16, FontStyle.Bold);
            Font fontText = new Font("Arial", 12);
            Brush pensula = Brushes.Black;

            int y = 50;
            int x = 50;

            g.DrawString("Raport Gestiune Vanzari - Lista Produse", fontTitlu, pensula, x, y);
            y += 50;

            if (listaProduse.Count == 0)
            {
                g.DrawString("Nu exista produse salvate in aplicatie.", fontText, pensula, x, y);
                return;
            }

            foreach (Produs p in listaProduse)
            {
                string linie = "ID: " + p.Id + " | Denumire: " + p.Denumire + " | Pret: " + p.Pret + " RON";
                g.DrawString(linie, fontText, pensula, x, y);
                y += 30;
            }

            y += 50;
            g.DrawString("Data printarii: " + DateTime.Now.ToString("dd/MM/yyyy HH:mm"), fontText, Brushes.Gray, x, y);
        }

        private void salveazaInBDToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                string connectionString = "Data Source=gestiune.db";

                using (SqliteConnection conexiune = new SqliteConnection(connectionString))
                {
                    conexiune.Open();

                    string queryCreare = "CREATE TABLE IF NOT EXISTS Produse (Id INTEGER, Denumire TEXT, Pret REAL)";
                    using (SqliteCommand cmdCreare = new SqliteCommand(queryCreare, conexiune))
                    {
                        cmdCreare.ExecuteNonQuery();
                    }

                    string queryStergere = "DELETE FROM Produse";
                    using (SqliteCommand cmdStergere = new SqliteCommand(queryStergere, conexiune))
                    {
                        cmdStergere.ExecuteNonQuery();
                    }

                    foreach (Produs p in listaProduse)
                    {
                        string queryInsert = "INSERT INTO Produse (Id, Denumire, Pret) VALUES (@id, @denumire, @pret)";
                        using (SqliteCommand cmdInsert = new SqliteCommand(queryInsert, conexiune))
                        {
                            cmdInsert.Parameters.AddWithValue("@id", p.Id);
                            cmdInsert.Parameters.AddWithValue("@denumire", p.Denumire);
                            cmdInsert.Parameters.AddWithValue("@pret", p.Pret);

                            cmdInsert.ExecuteNonQuery();
                        }
                    }
                }

                MessageBox.Show("Datele au fost salvate cu succes in baza de date SQLite!", "Salvare BD");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la salvarea in BD: " + ex.Message);
            }
        }

        private void incarcaDinBDToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (!File.Exists("gestiune.db"))
                {
                    MessageBox.Show("Baza de date nu exista inca. Salveaza date mai intai!", "Atentie");
                    return;
                }

                string connectionString = "Data Source=gestiune.db";
                using (SqliteConnection conexiune = new SqliteConnection(connectionString))
                {
                    conexiune.Open();

                    string querySelect = "SELECT * FROM Produse";
                    using (SqliteCommand cmdSelect = new SqliteCommand(querySelect, conexiune))
                    {
                        using (SqliteDataReader reader = cmdSelect.ExecuteReader())
                        {
                            listaProduse.Clear();
                            lstBx_date.Items.Clear();

                            while (reader.Read())
                            {
                                int id = Convert.ToInt32(reader["Id"]);
                                string denumire = reader["Denumire"].ToString();
                                double pret = Convert.ToDouble(reader["Pret"]);

                                Produs p = new Produs(id, denumire, pret);
                                listaProduse.Add(p);
                                lstBx_date.Items.Add(p.Denumire + " - " + p.Pret + " RON");
                            }
                        }
                    }
                }

                ActualizeazaBinding();
                MessageBox.Show($"Au fost incarcate cu succes {listaProduse.Count} produse din baza de date!", "Incarcare BD");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Eroare la incarcarea din BD: " + ex.Message);
            }
        }

        private void copiazaInClipboardToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            copiazaInClipboardToolStripMenuItem_Click(sender, e);
        }
    }
}