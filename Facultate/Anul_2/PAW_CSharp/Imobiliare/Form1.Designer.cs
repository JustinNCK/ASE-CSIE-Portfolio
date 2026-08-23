namespace Imobiliare
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
            ListViewItem listViewItem10 = new ListViewItem("");
            ListViewItem listViewItem11 = new ListViewItem("");
            ListViewItem listViewItem12 = new ListViewItem("");
            ListViewItem listViewItem13 = new ListViewItem("");
            ListViewItem listViewItem14 = new ListViewItem("");
            ListViewItem listViewItem15 = new ListViewItem("");
            ListViewItem listViewItem16 = new ListViewItem("");
            ListViewItem listViewItem17 = new ListViewItem("");
            ListViewItem listViewItem18 = new ListViewItem("");
            listViewLocuinte = new ListView();
            Cod = new ColumnHeader();
            Denumire = new ColumnHeader();
            Tip = new ColumnHeader();
            Suprafata = new ColumnHeader();
            NumarCamere = new ColumnHeader();
            Pret = new ColumnHeader();
            EtajNiveluri = new ColumnHeader();
            SuprafataTeren = new ColumnHeader();
            menuStrip1 = new MenuStrip();
            adaugareAnuntToolStripMenuItem = new ToolStripMenuItem();
            statusStrip1 = new StatusStrip();
            toolStripStatusLabelNrCase = new ToolStripStatusLabel();
            toolStripStatusLabelNrApartamente = new ToolStripStatusLabel();
            toolStripStatusLabelPretMediu = new ToolStripStatusLabel();
            tiparireToolStripMenuItem = new ToolStripMenuItem();
            menuStrip1.SuspendLayout();
            statusStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // listViewLocuinte
            // 
            listViewLocuinte.Columns.AddRange(new ColumnHeader[] { Cod, Denumire, Tip, Suprafata, NumarCamere, Pret, EtajNiveluri, SuprafataTeren });
            listViewLocuinte.FullRowSelect = true;
            listViewLocuinte.Items.AddRange(new ListViewItem[] { listViewItem10, listViewItem11, listViewItem12, listViewItem13, listViewItem14, listViewItem15, listViewItem16, listViewItem17, listViewItem18 });
            listViewLocuinte.Location = new Point(0, 33);
            listViewLocuinte.Name = "listViewLocuinte";
            listViewLocuinte.Size = new Size(800, 379);
            listViewLocuinte.TabIndex = 0;
            listViewLocuinte.UseCompatibleStateImageBehavior = false;
            listViewLocuinte.View = View.Details;
            // 
            // Cod
            // 
            Cod.Tag = "Cod";
            Cod.Text = "Cod";
            // 
            // Denumire
            // 
            Denumire.Tag = "Denumire";
            Denumire.Text = "Denumire";
            // 
            // Tip
            // 
            Tip.Tag = "Tip";
            Tip.Text = "Tip";
            // 
            // Suprafata
            // 
            Suprafata.Tag = "Suprafata";
            Suprafata.Text = "Suprafata";
            // 
            // NumarCamere
            // 
            NumarCamere.Tag = "Numar camere";
            NumarCamere.Text = "NumarCamere";
            // 
            // Pret
            // 
            Pret.Tag = "Pret";
            Pret.Text = "Pret";
            // 
            // EtajNiveluri
            // 
            EtajNiveluri.Tag = "Etaj/Niveluri";
            EtajNiveluri.Text = "Etaj/Niveluri";
            // 
            // SuprafataTeren
            // 
            SuprafataTeren.Tag = "Suprafata teren";
            SuprafataTeren.Text = "Suprafata teren";
            // 
            // menuStrip1
            // 
            menuStrip1.ImageScalingSize = new Size(24, 24);
            menuStrip1.Items.AddRange(new ToolStripItem[] { adaugareAnuntToolStripMenuItem, tiparireToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(800, 33);
            menuStrip1.TabIndex = 1;
            menuStrip1.Text = "menuStrip1";
            // 
            // adaugareAnuntToolStripMenuItem
            // 
            adaugareAnuntToolStripMenuItem.Name = "adaugareAnuntToolStripMenuItem";
            adaugareAnuntToolStripMenuItem.Size = new Size(158, 29);
            adaugareAnuntToolStripMenuItem.Text = "Adaugare Anunt";
            adaugareAnuntToolStripMenuItem.Click += adaugareAnuntToolStripMenuItem_Click;
            // 
            // statusStrip1
            // 
            statusStrip1.ImageScalingSize = new Size(24, 24);
            statusStrip1.Items.AddRange(new ToolStripItem[] { toolStripStatusLabelNrCase, toolStripStatusLabelNrApartamente, toolStripStatusLabelPretMediu });
            statusStrip1.Location = new Point(0, 418);
            statusStrip1.Name = "statusStrip1";
            statusStrip1.Size = new Size(800, 32);
            statusStrip1.TabIndex = 2;
            statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabelNrCase
            // 
            toolStripStatusLabelNrCase.Name = "toolStripStatusLabelNrCase";
            toolStripStatusLabelNrCase.Size = new Size(179, 25);
            toolStripStatusLabelNrCase.Text = "toolStripStatusLabel1";
            // 
            // toolStripStatusLabelNrApartamente
            // 
            toolStripStatusLabelNrApartamente.Name = "toolStripStatusLabelNrApartamente";
            toolStripStatusLabelNrApartamente.Size = new Size(179, 25);
            toolStripStatusLabelNrApartamente.Text = "toolStripStatusLabel2";
            // 
            // toolStripStatusLabelPretMediu
            // 
            toolStripStatusLabelPretMediu.Name = "toolStripStatusLabelPretMediu";
            toolStripStatusLabelPretMediu.Size = new Size(179, 25);
            toolStripStatusLabelPretMediu.Text = "toolStripStatusLabel3";
            // 
            // tiparireToolStripMenuItem
            // 
            tiparireToolStripMenuItem.Name = "tiparireToolStripMenuItem";
            tiparireToolStripMenuItem.Size = new Size(86, 29);
            tiparireToolStripMenuItem.Text = "Tiparire";
            tiparireToolStripMenuItem.Click += tiparireToolStripMenuItem_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(statusStrip1);
            Controls.Add(listViewLocuinte);
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

        private ListView listViewLocuinte;
        private ColumnHeader Cod;
        private ColumnHeader Denumire;
        private ColumnHeader Suprafata;
        private ColumnHeader NumarCamere;
        private ColumnHeader Pret;
        private ColumnHeader EtajNiveluri;
        private ColumnHeader SuprafataTeren;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem adaugareAnuntToolStripMenuItem;
        private ColumnHeader Tip;
        private StatusStrip statusStrip1;
        private ToolStripStatusLabel toolStripStatusLabelNrCase;
        private ToolStripStatusLabel toolStripStatusLabelNrApartamente;
        private ToolStripStatusLabel toolStripStatusLabelPretMediu;
        private ToolStripMenuItem tiparireToolStripMenuItem;
    }
}
