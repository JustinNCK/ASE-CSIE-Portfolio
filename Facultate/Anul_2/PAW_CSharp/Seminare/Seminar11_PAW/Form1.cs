using System.Xml;

namespace Seminar11_PAW
{
    public partial class Form1 : Form
    {

        List<Label> labels;
        List<TextBox> textboxes;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DateTime dt = dateTimePicker1.Value;

            if (dt.DayOfWeek == DayOfWeek.Sunday)
            {
                dt = dt.AddDays(-2);
            }

            if (dt.DayOfWeek == DayOfWeek.Saturday)
            {
                dt = dt.AddDays(-1);
            }
            lblData.Text = dt.ToString("yyyy-MM-dd");

            String data = "";
            XmlReader xmlReader = XmlReader.Create("https://curs.bnr.ro/files/xml/years/nbrfxrates2026.xml");
            while (xmlReader.Read())
            {
                if ((xmlReader.NodeType == XmlNodeType.Element) && (xmlReader.Name == "Cube"))
                    data = xmlReader.GetAttribute("date");

                if (data == dt.ToString("yyyy-MM-dd"))
                    if ((xmlReader.NodeType == XmlNodeType.Element) && (xmlReader.Name == "Rate"))
                    {
                        String atribut = xmlReader["currency"];
                        for (int i = 0; i < labels.Count; i++)
                        {
                            if (atribut == labels[i].Text)
                            {
                                xmlReader.Read();
                                textboxes[i].Text = xmlReader.Value;
                            }

                        }
                    }
            }

            //treeview + listbox

            TreeNode parinte = new TreeNode(lblData.Text);
            treeView1.Nodes.Add(parinte);
            listBox1.Items.Add(lblData.Text);
            for (int i = 0; i < labels.Count; i++)
            {
                TreeNode copil = new TreeNode(labels[i].Text);
                parinte.Nodes.Add(copil);
                TreeNode nepot = new TreeNode(textboxes[i].Text);
                copil.Nodes.Add(nepot);
                listBox1.Items.Add(labels[i].Text + " - " + textboxes[i].Text);

            }

            treeView1.ExpandAll();
            listBox1.Items.Add("==========");

            //listview

            listView1.View = View.Details;
            listView1.GridLines = true;
            listView1.FullRowSelect = true;

            ListViewItem item = new ListViewItem(lblData.Text);
            item.SubItems.Add(txtV1.Text);
            item.SubItems.Add(txtV2.Text);
            item.SubItems.Add(txtV3.Text);
            item.SubItems.Add(txtV4.Text);

            listView1.Items.Add(item);
        }

        private void form_load(object sender, EventArgs e)
        {
            labels = new List<Label> { lblV1, lblV2, lblV3, lblV4 };
            textboxes = new List<TextBox> { txtV1, txtV2, txtV3, txtV4 };

        }

        private void button4_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            treeView1.Nodes.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }
    }
}
