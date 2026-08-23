namespace Seminar12_PAW
{
    public partial class Form1 : Form
    {
        int[] V;
        int nrElemeV;
        public Form1()
        {
            InitializeComponent();
        }

        private void incarcaDateGraficDinFisierToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Multiselect = false;
            dlg.Filter = "Doar Fisiere Text|*.txt|Toate Fisierele | *.*";
            if (dlg.ShowDialog() != DialogResult.OK)
                return;

            MessageBox.Show(dlg.FileName);

            V = new int[20];
            nrElemeV = 0;

            string linie;
            StreamReader sr = new StreamReader(dlg.FileName);
            while ((linie = sr.ReadLine()) != null)
                V[nrElemeV++] = Convert.ToInt32(linie);
            sr.Close();

            //MessageBox.Show(string.Join("-", V));

            panel1.Invalidate();

        }

        private void panel1_paint(object sender, PaintEventArgs e)
        {
            deseneazaGrafic(e.Graphics, panel1.ClientRectangle.X,
                panel1.ClientRectangle.Y,
                panel1.Width, panel1.Height);
        }

        private void deseneazaGrafic(Graphics graphics, int x, int y, int width, int height)
        {
            if (nrElemeV > 0)
            {
                // chenar principal
                int margine = 5;
                Pen penC = new Pen(Color.Orange, 5);
                Rectangle rct = new Rectangle(x + margine, y + 2*margine, width - 2*margine, height - 3*margine);
                graphics.DrawRectangle(penC, rct);

                //bare grafic

                double latime_bara = rct.Width / nrElemeV / 2;
                double distanta_bare = (rct.Width - nrElemeV * latime_bara)/ (nrElemeV + 1);

                Brush brB = new SolidBrush(Color.BlueViolet);
                Brush brT = new SolidBrush(Color.Blue);

                Rectangle[] rectangles = new Rectangle[nrElemeV];
                Pen penB = new Pen(Color.Red, 5);
                for (int i = 0; i < nrElemeV; i++)
                {
                    rectangles[i] = new Rectangle((int)(rct.Location.X + i * latime_bara + (i+1) * distanta_bare),
                        rct.Location.Y + rct.Height - rct.Height * V[i] / V.Max(),
                        (int)latime_bara,
                        rct.Height * V[i] / V.Max());
                    graphics.DrawRectangle(penB, rectangles[i]);

                    graphics.DrawString(V[i].ToString(),
                        new Font(FontFamily.GenericSansSerif, 15), brT, (int)(rectangles[i].X + latime_bara / 3) , rectangles[i].Y - Font.Height);
                    
                }
                graphics.FillRectangles(brB, rectangles);

                // trend line
                Pen penTL = new Pen(Color.Green, 5);
                for (int i = 0;i<nrElemeV - 1;i++)
                {
                    graphics.DrawLine(penTL, (int)(rectangles[i].X + latime_bara / 2), rectangles[i].Y,
                        (int)(rectangles[i + 1].X + latime_bara / 2), rectangles[i + 1].Y);
                }
            }
        }
    }
}
