namespace Subiect_5
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            listViewImprumuturi = new ListView();
            Cod = new ColumnHeader();
            Titlu = new ColumnHeader();
            Autor = new ColumnHeader();
            Cititor = new ColumnHeader();
            DataImprumut = new ColumnHeader();
            Termen = new ColumnHeader();
            Depasit = new ColumnHeader();
            toolStrip1 = new ToolStrip();
            toolStripButtonImprumuta = new ToolStripButton();
            statusStrip1 = new StatusStrip();
            toolStripStatusLabel1 = new ToolStripStatusLabel();
            toolStripStatusLabel2 = new ToolStripStatusLabel();
            toolStripStatusLabel3 = new ToolStripStatusLabel();
            toolStrip1.SuspendLayout();
            statusStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // listViewImprumuturi
            // 
            listViewImprumuturi.Columns.AddRange(new ColumnHeader[] { Cod, Titlu, Autor, Cititor, DataImprumut, Termen, Depasit });
            listViewImprumuturi.Location = new Point(12, 39);
            listViewImprumuturi.Name = "listViewImprumuturi";
            listViewImprumuturi.Size = new Size(776, 362);
            listViewImprumuturi.TabIndex = 0;
            listViewImprumuturi.UseCompatibleStateImageBehavior = false;
            listViewImprumuturi.View = View.Details;
            // 
            // Cod
            // 
            Cod.Tag = "Cod";
            Cod.Text = "Cod";
            // 
            // Titlu
            // 
            Titlu.DisplayIndex = 4;
            Titlu.Tag = "Titlu";
            Titlu.Text = "Titlu";
            // 
            // Autor
            // 
            Autor.DisplayIndex = 3;
            Autor.Tag = "Autor";
            Autor.Text = "Autor";
            // 
            // Cititor
            // 
            Cititor.DisplayIndex = 1;
            Cititor.Tag = "Cititor";
            Cititor.Text = "Cititor";
            // 
            // DataImprumut
            // 
            DataImprumut.DisplayIndex = 2;
            DataImprumut.Tag = "Data Imprumut";
            DataImprumut.Text = "Data Imprumut";
            // 
            // Termen
            // 
            Termen.Tag = "Termen";
            Termen.Text = "Termen";
            // 
            // Depasit
            // 
            Depasit.Tag = "Depasit";
            Depasit.Text = "Depasit";
            // 
            // toolStrip1
            // 
            toolStrip1.ImageScalingSize = new Size(24, 24);
            toolStrip1.Items.AddRange(new ToolStripItem[] { toolStripButtonImprumuta });
            toolStrip1.Location = new Point(0, 0);
            toolStrip1.Name = "toolStrip1";
            toolStrip1.Size = new Size(800, 33);
            toolStrip1.TabIndex = 1;
            toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButtonImprumuta
            // 
            toolStripButtonImprumuta.DisplayStyle = ToolStripItemDisplayStyle.Image;
            toolStripButtonImprumuta.Image = (Image)resources.GetObject("toolStripButtonImprumuta.Image");
            toolStripButtonImprumuta.ImageTransparentColor = Color.Magenta;
            toolStripButtonImprumuta.Name = "toolStripButtonImprumuta";
            toolStripButtonImprumuta.Size = new Size(34, 28);
            toolStripButtonImprumuta.Text = "toolStripButton1";
            toolStripButtonImprumuta.Click += toolStripButtonImprumuta_Click;
            // 
            // statusStrip1
            // 
            statusStrip1.ImageScalingSize = new Size(24, 24);
            statusStrip1.Items.AddRange(new ToolStripItem[] { toolStripStatusLabel1, toolStripStatusLabel2, toolStripStatusLabel3 });
            statusStrip1.Location = new Point(0, 418);
            statusStrip1.Name = "statusStrip1";
            statusStrip1.Size = new Size(800, 32);
            statusStrip1.TabIndex = 2;
            statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            toolStripStatusLabel1.Size = new Size(179, 25);
            toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // toolStripStatusLabel2
            // 
            toolStripStatusLabel2.Name = "toolStripStatusLabel2";
            toolStripStatusLabel2.Size = new Size(179, 25);
            toolStripStatusLabel2.Text = "toolStripStatusLabel2";
            // 
            // toolStripStatusLabel3
            // 
            toolStripStatusLabel3.Name = "toolStripStatusLabel3";
            toolStripStatusLabel3.Size = new Size(179, 25);
            toolStripStatusLabel3.Text = "toolStripStatusLabel3";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(statusStrip1);
            Controls.Add(toolStrip1);
            Controls.Add(listViewImprumuturi);
            Name = "Form1";
            Text = "Form1";
            FormClosing += Form1_FormClosing;
            toolStrip1.ResumeLayout(false);
            toolStrip1.PerformLayout();
            statusStrip1.ResumeLayout(false);
            statusStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListView listViewImprumuturi;
        private ColumnHeader Cod;
        private ColumnHeader Titlu;
        private ColumnHeader Autor;
        private ColumnHeader Cititor;
        private ColumnHeader DataImprumut;
        private ColumnHeader Termen;
        private ColumnHeader Depasit;
        private ToolStrip toolStrip1;
        private ToolStripButton toolStripButtonImprumuta;
        private StatusStrip statusStrip1;
        private ToolStripStatusLabel toolStripStatusLabel1;
        private ToolStripStatusLabel toolStripStatusLabel2;
        private ToolStripStatusLabel toolStripStatusLabel3;
    }
}
