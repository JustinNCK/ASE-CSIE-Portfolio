namespace Subiect_7
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
            listViewEvenimente = new ListView();
            Cod = new ColumnHeader();
            Titlu = new ColumnHeader();
            DataOra = new ColumnHeader();
            Tip = new ColumnHeader();
            Durata = new ColumnHeader();
            PretBilet = new ColumnHeader();
            Detalii = new ColumnHeader();
            menuStrip1 = new MenuStrip();
            adaugaEvenimentToolStripMenuItem = new ToolStripMenuItem();
            statusStrip1 = new StatusStrip();
            toolStripStatusLabel1 = new ToolStripStatusLabel();
            menuStrip1.SuspendLayout();
            statusStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // listViewEvenimente
            // 
            listViewEvenimente.Columns.AddRange(new ColumnHeader[] { Cod, Titlu, DataOra, Tip, Durata, PretBilet, Detalii });
            listViewEvenimente.Location = new Point(12, 38);
            listViewEvenimente.Name = "listViewEvenimente";
            listViewEvenimente.Size = new Size(776, 373);
            listViewEvenimente.TabIndex = 0;
            listViewEvenimente.UseCompatibleStateImageBehavior = false;
            listViewEvenimente.View = View.Details;
            // 
            // Cod
            // 
            Cod.Tag = "Cod";
            Cod.Text = "Cod";
            // 
            // Titlu
            // 
            Titlu.Tag = "Titlu";
            Titlu.Text = "Titlu";
            // 
            // DataOra
            // 
            DataOra.Tag = "Data/Ora";
            DataOra.Text = "Data/Ora";
            // 
            // Tip
            // 
            Tip.Tag = "Tip";
            Tip.Text = "Tip";
            // 
            // Durata
            // 
            Durata.Tag = "Durata";
            Durata.Text = "Durata";
            // 
            // PretBilet
            // 
            PretBilet.Tag = "Pret Bilet";
            PretBilet.Text = "Pret Bilet";
            // 
            // Detalii
            // 
            Detalii.Tag = "Detalii";
            Detalii.Text = "Detalii";
            // 
            // menuStrip1
            // 
            menuStrip1.ImageScalingSize = new Size(24, 24);
            menuStrip1.Items.AddRange(new ToolStripItem[] { adaugaEvenimentToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(800, 33);
            menuStrip1.TabIndex = 1;
            menuStrip1.Text = "menuStrip1";
            // 
            // adaugaEvenimentToolStripMenuItem
            // 
            adaugaEvenimentToolStripMenuItem.Name = "adaugaEvenimentToolStripMenuItem";
            adaugaEvenimentToolStripMenuItem.Size = new Size(177, 29);
            adaugaEvenimentToolStripMenuItem.Text = "Adauga Eveniment";
            adaugaEvenimentToolStripMenuItem.Click += adaugaEvenimentToolStripMenuItem_Click;
            // 
            // statusStrip1
            // 
            statusStrip1.ImageScalingSize = new Size(24, 24);
            statusStrip1.Items.AddRange(new ToolStripItem[] { toolStripStatusLabel1 });
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
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(statusStrip1);
            Controls.Add(listViewEvenimente);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "Form1";
            FormClosing += Form1_FormClosing;
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            statusStrip1.ResumeLayout(false);
            statusStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListView listViewEvenimente;
        private ColumnHeader Cod;
        private ColumnHeader Titlu;
        private ColumnHeader DataOra;
        private ColumnHeader Tip;
        private ColumnHeader Durata;
        private ColumnHeader PretBilet;
        private ColumnHeader Detalii;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem adaugaEvenimentToolStripMenuItem;
        private StatusStrip statusStrip1;
        private ToolStripStatusLabel toolStripStatusLabel1;
    }
}
