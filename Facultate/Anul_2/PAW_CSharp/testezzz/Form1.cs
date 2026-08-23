namespace testezzz
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            button1 = new Button();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(755, 501);
            button1.Name = "button1";
            button1.Size = new Size(80, 19);
            button1.TabIndex = 0;
            button1.Text = "button1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Form1
            // 
            ClientSize = new Size(847, 546);
            Controls.Add(button1);
            Name = "Form1";
            ResumeLayout(false);

        }

        internal class Persoana : ICloneable, IComparable
        {
            private int id;
            string nume;
            private int varsta;

            public int Id { get => id; set => id = value; }
            public string Nume { get => nume; set => nume = value; }
            protected int Varsta { get => varsta; set => varsta = value; }

            public Persoana(int id, string nume, int varsta)
            {
                this.id = id;
                this.nume = nume;
                this.varsta = varsta;
            }

            public Persoana()
            {
                id = 0;
                nume = "N/A";
                varsta = 0;
            }

            public Persoana(Persoana p)
            {
                this.id = p.id;
                this.nume = p.nume;
                this.varsta = p.varsta;
            }


            public override string ToString()
            {
                return id + " " + nume + " " + varsta;
            }

            public int CompareTo(object obj)
            {
                Persoana p1 = (Persoana)obj;

                if (this.id < p1.id)
                {
                    return -1;
                }
                else if (this.id > p1.id)
                    return 1;
                else return 0;
            }

            public object Clone()
            {
                return this.MemberwiseClone();
            }
        }

        internal class Student : Persoana {
            private float medieAni;

            public Student() : base()
            {
                medieAni = 0;
            }

            public Student(float medieAni)
            {
                this.medieAni = medieAni;
            }

            public override string ToString()
            {
                return base.ToString() + "Medie ani: " + medieAni;
            }

            public static Student operator +(Student a, float b)
            {
                a.medieAni += b;
                return a;
            }   
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Persoana p1 = new Persoana();
            MessageBox.Show(p1.ToString());

            p1.Nume = "Andrei";

            MessageBox.Show(p1.ToString());

            Persoana p2 = (Persoana)p1.Clone(), p3 = new Persoana(1, "Bobita", 13);
            List<Persoana> lista = new List<Persoana>();
            lista.AddRange(new Persoana[] { p1, p2, p3 });

            foreach (Persoana p in lista)
            {
                MessageBox.Show(p.ToString());
            }
        }


    }
}
