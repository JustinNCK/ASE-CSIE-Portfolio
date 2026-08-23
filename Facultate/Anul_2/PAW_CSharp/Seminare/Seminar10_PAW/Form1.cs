using System.ComponentModel.Design.Serialization;
using System.Text.Json;
using System.Xml.Serialization;

namespace Seminar10_PAW
{
    public partial class Form1 : Form
    {
        private List<Student> studenti = new List<Student>();
        public Form1()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            string nume = txtNume.Text;

            int[] note = txtNote.Text.Split(' ').Select(int.Parse).ToArray();
            MessageBox.Show(nume + " - " + string.Join(", ", note));

            Student student = new Student(nume, note);
            studenti.Add(student);

            txtNume.Text = "";
            txtNote.Text = "";
            txtNume.Focus();

            btnAdd.Text = "&Adaugare Student (" + studenti.Count + ")";

        }

        private void btnList_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            foreach (Student student in studenti)
                listBox1.Items.Add(student);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void salvareTEXTToolStripMenuItem_Click(object sender, EventArgs e)
        {
            StreamWriter sw = new StreamWriter("studenti.txt");
            foreach (Student student in studenti)
                sw.WriteLine(student);
            sw.Close();
            MessageBox.Show("Fisierul text a fost creat cu succes!");
        }

        private void afisareTEXTToolStripMenuItem_Click(object sender, EventArgs e)
        {
            StreamReader sr = new StreamReader("studenti.txt");

            string text = "";
            while (!sr.EndOfStream)
            {
                text += sr.ReadLine() + "\n";
            }

            sr.Close();
            MessageBox.Show(text, "Info");
        }

        private void xMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream("studenti.xml", FileMode.Create, FileAccess.Write);
            XmlSerializer serializator = new XmlSerializer(typeof(List<Student>));
            serializator.Serialize(fs, studenti);

            fs.Close();
            MessageBox.Show("Fisierul XML a fost creat cu succes!");
        }

        private void xMLToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream("studenti.xml", FileMode.Open, FileAccess.Read);
            XmlSerializer serializator = new XmlSerializer(typeof(List<Student>));
            serializator.Deserialize(fs);

            fs.Close();
            btnAdd.Text = "&Adaugare student (" + studenti.Count + ")";
        }

        private void jSONToolStripMenuItem_Click(object sender, EventArgs e)
        {
            JsonSerializerOptions optiuni = new JsonSerializerOptions { WriteIndented = true };
            string json = JsonSerializer.Serialize(studenti, optiuni);
            File.WriteAllText("studenti.json", json);

            MessageBox.Show("Fisierul JSON a fost creat cu succes!");
        }

        private void jSONToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string json = File.ReadAllText("studenti.json");
            studenti = JsonSerializer.Deserialize<List<Student>>(json);

            btnAdd.Text = "Adaugare Student(" + studenti.Count + ")";
        }
    }

    public class Student
    {
        public string nume { get; set; }
        public int[] note { get; set; }

        public Student()
        {
        }

        public Student(string nume, int[] note)
        {
            this.nume = nume;
            this.note = note;
        }

        public override string ToString()
        {
            return "Student - " + nume + ", Note: " + string.Join(' ', note);
        }
    }
}
