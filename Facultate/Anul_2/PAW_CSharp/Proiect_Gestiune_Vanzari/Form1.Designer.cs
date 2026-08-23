namespace Proiect
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
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            menuStrip1 = new MenuStrip();
            adaugaToolStripMenuItem = new ToolStripMenuItem();
            produsToolStripMenuItem = new ToolStripMenuItem();
            clientToolStripMenuItem = new ToolStripMenuItem();
            fisierToolStripMenuItem = new ToolStripMenuItem();
            salveazaDateToolStripMenuItem = new ToolStripMenuItem();
            afiseazaDateToolStripMenuItem = new ToolStripMenuItem();
            salveazaXMLToolStripMenuItem = new ToolStripMenuItem();
            incarcaXMLToolStripMenuItem = new ToolStripMenuItem();
            printeazaListaProduseToolStripMenuItem = new ToolStripMenuItem();
            fisierClientiToolStripMenuItem = new ToolStripMenuItem();
            salveazaClientiToolStripMenuItem = new ToolStripMenuItem();
            afiseazaClientiToolStripMenuItem = new ToolStripMenuItem();
            graficPreturiToolStripMenuItem = new ToolStripMenuItem();
            vizualizareTabelToolStripMenuItem = new ToolStripMenuItem();
            bazaDeDateToolStripMenuItem = new ToolStripMenuItem();
            salveazaInBDToolStripMenuItem = new ToolStripMenuItem();
            incarcaDinBDToolStripMenuItem = new ToolStripMenuItem();
            lblIdProdus = new Label();
            lblPret = new Label();
            lblDenumire = new Label();
            txtIdProdus = new TextBox();
            txtDenumire = new TextBox();
            txtPret = new TextBox();
            btnAdaugaProdus = new Button();
            errorProvider1 = new ErrorProvider(components);
            errorProvider2 = new ErrorProvider(components);
            lstBx_date = new ListBox();
            ContextMenuStripProduse = new ContextMenuStrip(components);
            stergeProduseToolStripMenuItem = new ToolStripMenuItem();
            panelProdus = new Panel();
            lblCosDeCumparaturi = new Label();
            lstBx_cosDeCumparaturi = new ListBox();
            statusControl1 = new Proiect_gestiuneVanzari.StatusControl();
            panelClient = new Panel();
            lstBx_clienti = new ListBox();
            contextMenuStripClienti = new ContextMenuStrip(components);
            stergereClientToolStripMenuItem = new ToolStripMenuItem();
            btnAdaugaClient = new Button();
            txtAdresa = new TextBox();
            txtNume = new TextBox();
            txtIdClient = new TextBox();
            lblNume = new Label();
            lblAdresa = new Label();
            lblIdClient = new Label();
            errorProvider3 = new ErrorProvider(components);
            panelGrafic = new Panel();
            panelTabel = new Panel();
            dgvProduse = new DataGridView();
            contextMenuStripTabel = new ContextMenuStrip(components);
            copiazaInClipboardToolStripMenuItem = new ToolStripMenuItem();
            printDocument1 = new System.Drawing.Printing.PrintDocument();
            printPreviewDialog1 = new PrintPreviewDialog();
            menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).BeginInit();
            ContextMenuStripProduse.SuspendLayout();
            panelProdus.SuspendLayout();
            panelClient.SuspendLayout();
            contextMenuStripClienti.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)errorProvider3).BeginInit();
            panelTabel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dgvProduse).BeginInit();
            contextMenuStripTabel.SuspendLayout();
            SuspendLayout();
            // 
            // menuStrip1
            // 
            menuStrip1.ImageScalingSize = new Size(24, 24);
            menuStrip1.Items.AddRange(new ToolStripItem[] { adaugaToolStripMenuItem, fisierToolStripMenuItem, fisierClientiToolStripMenuItem, graficPreturiToolStripMenuItem, vizualizareTabelToolStripMenuItem, bazaDeDateToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(1345, 33);
            menuStrip1.TabIndex = 0;
            menuStrip1.Text = "menuStrip1";
            // 
            // adaugaToolStripMenuItem
            // 
            adaugaToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { produsToolStripMenuItem, clientToolStripMenuItem });
            adaugaToolStripMenuItem.Name = "adaugaToolStripMenuItem";
            adaugaToolStripMenuItem.Size = new Size(90, 29);
            adaugaToolStripMenuItem.Text = "Adauga";
            // 
            // produsToolStripMenuItem
            // 
            produsToolStripMenuItem.Name = "produsToolStripMenuItem";
            produsToolStripMenuItem.Size = new Size(170, 34);
            produsToolStripMenuItem.Text = "Produs";
            produsToolStripMenuItem.Click += produsToolStripMenuItem_Click;
            // 
            // clientToolStripMenuItem
            // 
            clientToolStripMenuItem.Name = "clientToolStripMenuItem";
            clientToolStripMenuItem.Size = new Size(170, 34);
            clientToolStripMenuItem.Text = "Client";
            clientToolStripMenuItem.Click += clientToolStripMenuItem_Click;
            // 
            // fisierToolStripMenuItem
            // 
            fisierToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { salveazaDateToolStripMenuItem, afiseazaDateToolStripMenuItem, salveazaXMLToolStripMenuItem, incarcaXMLToolStripMenuItem, printeazaListaProduseToolStripMenuItem });
            fisierToolStripMenuItem.Name = "fisierToolStripMenuItem";
            fisierToolStripMenuItem.Size = new Size(139, 29);
            fisierToolStripMenuItem.Text = "Fisier produse";
            // 
            // salveazaDateToolStripMenuItem
            // 
            salveazaDateToolStripMenuItem.Name = "salveazaDateToolStripMenuItem";
            salveazaDateToolStripMenuItem.Size = new Size(292, 34);
            salveazaDateToolStripMenuItem.Text = "Salveaza produse";
            salveazaDateToolStripMenuItem.Click += salveazaDateToolStripMenuItem_Click;
            // 
            // afiseazaDateToolStripMenuItem
            // 
            afiseazaDateToolStripMenuItem.Name = "afiseazaDateToolStripMenuItem";
            afiseazaDateToolStripMenuItem.Size = new Size(292, 34);
            afiseazaDateToolStripMenuItem.Text = "Afiseaza produse";
            afiseazaDateToolStripMenuItem.Click += afiseazaDateToolStripMenuItem_Click;
            // 
            // salveazaXMLToolStripMenuItem
            // 
            salveazaXMLToolStripMenuItem.Name = "salveazaXMLToolStripMenuItem";
            salveazaXMLToolStripMenuItem.Size = new Size(292, 34);
            salveazaXMLToolStripMenuItem.Text = "Salveaza XML produse";
            salveazaXMLToolStripMenuItem.Click += salveazaXMLToolStripMenuItem_Click;
            // 
            // incarcaXMLToolStripMenuItem
            // 
            incarcaXMLToolStripMenuItem.Name = "incarcaXMLToolStripMenuItem";
            incarcaXMLToolStripMenuItem.Size = new Size(292, 34);
            incarcaXMLToolStripMenuItem.Text = "Incarca XML produse";
            incarcaXMLToolStripMenuItem.Click += incarcaXMLToolStripMenuItem_Click;
            // 
            // printeazaListaProduseToolStripMenuItem
            // 
            printeazaListaProduseToolStripMenuItem.Name = "printeazaListaProduseToolStripMenuItem";
            printeazaListaProduseToolStripMenuItem.Size = new Size(292, 34);
            printeazaListaProduseToolStripMenuItem.Text = "Printeaza lista produse";
            printeazaListaProduseToolStripMenuItem.Click += printeazaListaProduseToolStripMenuItem_Click;
            // 
            // fisierClientiToolStripMenuItem
            // 
            fisierClientiToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { salveazaClientiToolStripMenuItem, afiseazaClientiToolStripMenuItem });
            fisierClientiToolStripMenuItem.Name = "fisierClientiToolStripMenuItem";
            fisierClientiToolStripMenuItem.Size = new Size(118, 29);
            fisierClientiToolStripMenuItem.Text = "Fisier clienti";
            // 
            // salveazaClientiToolStripMenuItem
            // 
            salveazaClientiToolStripMenuItem.Name = "salveazaClientiToolStripMenuItem";
            salveazaClientiToolStripMenuItem.Size = new Size(231, 34);
            salveazaClientiToolStripMenuItem.Text = "Salveaza clienti";
            salveazaClientiToolStripMenuItem.Click += salveazaClientiToolStripMenuItem_Click;
            // 
            // afiseazaClientiToolStripMenuItem
            // 
            afiseazaClientiToolStripMenuItem.Name = "afiseazaClientiToolStripMenuItem";
            afiseazaClientiToolStripMenuItem.Size = new Size(231, 34);
            afiseazaClientiToolStripMenuItem.Text = "Afiseaza clienti";
            afiseazaClientiToolStripMenuItem.Click += afiseazaClientiToolStripMenuItem_Click;
            // 
            // graficPreturiToolStripMenuItem
            // 
            graficPreturiToolStripMenuItem.Name = "graficPreturiToolStripMenuItem";
            graficPreturiToolStripMenuItem.Size = new Size(130, 29);
            graficPreturiToolStripMenuItem.Text = "Grafic preturi";
            graficPreturiToolStripMenuItem.Click += graficPreturiToolStripMenuItem_Click;
            // 
            // vizualizareTabelToolStripMenuItem
            // 
            vizualizareTabelToolStripMenuItem.Name = "vizualizareTabelToolStripMenuItem";
            vizualizareTabelToolStripMenuItem.Size = new Size(155, 29);
            vizualizareTabelToolStripMenuItem.Text = "Vizualizare Tabel";
            vizualizareTabelToolStripMenuItem.Click += vizualizareTabelToolStripMenuItem_Click;
            // 
            // bazaDeDateToolStripMenuItem
            // 
            bazaDeDateToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { salveazaInBDToolStripMenuItem, incarcaDinBDToolStripMenuItem });
            bazaDeDateToolStripMenuItem.Name = "bazaDeDateToolStripMenuItem";
            bazaDeDateToolStripMenuItem.Size = new Size(129, 29);
            bazaDeDateToolStripMenuItem.Text = "Baza de date";
            // 
            // salveazaInBDToolStripMenuItem
            // 
            salveazaInBDToolStripMenuItem.Name = "salveazaInBDToolStripMenuItem";
            salveazaInBDToolStripMenuItem.Size = new Size(228, 34);
            salveazaInBDToolStripMenuItem.Text = "Salveaza in BD";
            salveazaInBDToolStripMenuItem.Click += salveazaInBDToolStripMenuItem_Click;
            // 
            // incarcaDinBDToolStripMenuItem
            // 
            incarcaDinBDToolStripMenuItem.Name = "incarcaDinBDToolStripMenuItem";
            incarcaDinBDToolStripMenuItem.Size = new Size(228, 34);
            incarcaDinBDToolStripMenuItem.Text = "Incarca din BD";
            incarcaDinBDToolStripMenuItem.Click += incarcaDinBDToolStripMenuItem_Click;
            // 
            // lblIdProdus
            // 
            lblIdProdus.AutoSize = true;
            lblIdProdus.Location = new Point(5, 22);
            lblIdProdus.Name = "lblIdProdus";
            lblIdProdus.Size = new Size(91, 25);
            lblIdProdus.TabIndex = 2;
            lblIdProdus.Text = "ID Produs";
            // 
            // lblPret
            // 
            lblPret.AutoSize = true;
            lblPret.Location = new Point(5, 101);
            lblPret.Name = "lblPret";
            lblPret.Size = new Size(43, 25);
            lblPret.TabIndex = 3;
            lblPret.Text = "Pret";
            // 
            // lblDenumire
            // 
            lblDenumire.AutoSize = true;
            lblDenumire.Location = new Point(5, 62);
            lblDenumire.Name = "lblDenumire";
            lblDenumire.Size = new Size(89, 25);
            lblDenumire.TabIndex = 4;
            lblDenumire.Text = "Denumire";
            // 
            // txtIdProdus
            // 
            txtIdProdus.Location = new Point(102, 19);
            txtIdProdus.Name = "txtIdProdus";
            txtIdProdus.Size = new Size(150, 31);
            txtIdProdus.TabIndex = 5;
            txtIdProdus.KeyPress += txtIdProdus_KeyPress;
            // 
            // txtDenumire
            // 
            txtDenumire.Location = new Point(100, 59);
            txtDenumire.Name = "txtDenumire";
            txtDenumire.Size = new Size(150, 31);
            txtDenumire.TabIndex = 6;
            txtDenumire.KeyPress += txtDenumire_KeyPress;
            // 
            // txtPret
            // 
            txtPret.Location = new Point(54, 98);
            txtPret.Name = "txtPret";
            txtPret.Size = new Size(150, 31);
            txtPret.TabIndex = 7;
            txtPret.KeyPress += txtPret_KeyPress;
            // 
            // btnAdaugaProdus
            // 
            btnAdaugaProdus.Location = new Point(29, 161);
            btnAdaugaProdus.Name = "btnAdaugaProdus";
            btnAdaugaProdus.Size = new Size(193, 34);
            btnAdaugaProdus.TabIndex = 8;
            btnAdaugaProdus.Text = "Adauga produs";
            btnAdaugaProdus.UseVisualStyleBackColor = true;
            btnAdaugaProdus.Click += btnAdaugaProdus_Click;
            // 
            // errorProvider1
            // 
            errorProvider1.ContainerControl = this;
            // 
            // errorProvider2
            // 
            errorProvider2.ContainerControl = this;
            // 
            // lstBx_date
            // 
            lstBx_date.ContextMenuStrip = ContextMenuStripProduse;
            lstBx_date.FormattingEnabled = true;
            lstBx_date.ItemHeight = 25;
            lstBx_date.Location = new Point(438, 19);
            lstBx_date.Name = "lstBx_date";
            lstBx_date.Size = new Size(278, 354);
            lstBx_date.TabIndex = 9;
            lstBx_date.MouseDown += lstBx_date_MouseDown;
            // 
            // ContextMenuStripProduse
            // 
            ContextMenuStripProduse.ImageScalingSize = new Size(24, 24);
            ContextMenuStripProduse.Items.AddRange(new ToolStripItem[] { stergeProduseToolStripMenuItem });
            ContextMenuStripProduse.Name = "contextMenuStrip1";
            ContextMenuStripProduse.Size = new Size(241, 69);
            // 
            // stergeProduseToolStripMenuItem
            // 
            stergeProduseToolStripMenuItem.Name = "stergeProduseToolStripMenuItem";
            stergeProduseToolStripMenuItem.Size = new Size(240, 32);
            stergeProduseToolStripMenuItem.Text = "Sterge produse";
            stergeProduseToolStripMenuItem.Click += stergeProduseToolStripMenuItem_Click;
            // 
            // panelProdus
            // 
            panelProdus.Controls.Add(lblCosDeCumparaturi);
            panelProdus.Controls.Add(lstBx_cosDeCumparaturi);
            panelProdus.Controls.Add(lstBx_date);
            panelProdus.Controls.Add(btnAdaugaProdus);
            panelProdus.Controls.Add(txtPret);
            panelProdus.Controls.Add(txtDenumire);
            panelProdus.Controls.Add(txtIdProdus);
            panelProdus.Controls.Add(lblDenumire);
            panelProdus.Controls.Add(lblPret);
            panelProdus.Controls.Add(lblIdProdus);
            panelProdus.Location = new Point(23, 46);
            panelProdus.Name = "panelProdus";
            panelProdus.Size = new Size(1196, 411);
            panelProdus.TabIndex = 10;
            // 
            // lblCosDeCumparaturi
            // 
            lblCosDeCumparaturi.AutoSize = true;
            lblCosDeCumparaturi.Location = new Point(848, 25);
            lblCosDeCumparaturi.Name = "lblCosDeCumparaturi";
            lblCosDeCumparaturi.Size = new Size(167, 25);
            lblCosDeCumparaturi.TabIndex = 11;
            lblCosDeCumparaturi.Text = "Cos de cumparaturi";
            // 
            // lstBx_cosDeCumparaturi
            // 
            lstBx_cosDeCumparaturi.AllowDrop = true;
            lstBx_cosDeCumparaturi.FormattingEnabled = true;
            lstBx_cosDeCumparaturi.ItemHeight = 25;
            lstBx_cosDeCumparaturi.Location = new Point(798, 69);
            lstBx_cosDeCumparaturi.Name = "lstBx_cosDeCumparaturi";
            lstBx_cosDeCumparaturi.Size = new Size(277, 304);
            lstBx_cosDeCumparaturi.TabIndex = 10;
            lstBx_cosDeCumparaturi.DragDrop += lstBx_cosDeCumparaturi_DragDrop;
            lstBx_cosDeCumparaturi.DragEnter += lstBx_cosDeCumparaturi_DragEnter;
            // 
            // statusControl1
            // 
            statusControl1.Location = new Point(28, 547);
            statusControl1.Name = "statusControl1";
            statusControl1.Size = new Size(382, 64);
            statusControl1.TabIndex = 12;
            // 
            // panelClient
            // 
            panelClient.Controls.Add(lstBx_clienti);
            panelClient.Controls.Add(btnAdaugaClient);
            panelClient.Controls.Add(txtAdresa);
            panelClient.Controls.Add(txtNume);
            panelClient.Controls.Add(txtIdClient);
            panelClient.Controls.Add(lblNume);
            panelClient.Controls.Add(lblAdresa);
            panelClient.Controls.Add(lblIdClient);
            panelClient.Location = new Point(23, 46);
            panelClient.Name = "panelClient";
            panelClient.Size = new Size(933, 473);
            panelClient.TabIndex = 10;
            panelClient.Visible = false;
            // 
            // lstBx_clienti
            // 
            lstBx_clienti.ContextMenuStrip = contextMenuStripClienti;
            lstBx_clienti.FormattingEnabled = true;
            lstBx_clienti.ItemHeight = 25;
            lstBx_clienti.Location = new Point(438, 16);
            lstBx_clienti.Name = "lstBx_clienti";
            lstBx_clienti.Size = new Size(278, 379);
            lstBx_clienti.TabIndex = 16;
            // 
            // contextMenuStripClienti
            // 
            contextMenuStripClienti.ImageScalingSize = new Size(24, 24);
            contextMenuStripClienti.Items.AddRange(new ToolStripItem[] { stergereClientToolStripMenuItem });
            contextMenuStripClienti.Name = "contextMenuStrip1";
            contextMenuStripClienti.Size = new Size(196, 36);
            // 
            // stergereClientToolStripMenuItem
            // 
            stergereClientToolStripMenuItem.Name = "stergereClientToolStripMenuItem";
            stergereClientToolStripMenuItem.Size = new Size(195, 32);
            stergereClientToolStripMenuItem.Text = "Stergere client";
            stergereClientToolStripMenuItem.Click += stergeClientiToolStripMenuItem_Click;
            // 
            // btnAdaugaClient
            // 
            btnAdaugaClient.Location = new Point(44, 158);
            btnAdaugaClient.Name = "btnAdaugaClient";
            btnAdaugaClient.Size = new Size(193, 34);
            btnAdaugaClient.TabIndex = 15;
            btnAdaugaClient.Text = "Adauga client";
            btnAdaugaClient.UseVisualStyleBackColor = true;
            btnAdaugaClient.Click += btnAdaugaClient_Click;
            // 
            // txtAdresa
            // 
            txtAdresa.Location = new Point(93, 95);
            txtAdresa.Name = "txtAdresa";
            txtAdresa.ScrollBars = ScrollBars.Horizontal;
            txtAdresa.Size = new Size(150, 31);
            txtAdresa.TabIndex = 14;
            // 
            // txtNume
            // 
            txtNume.Location = new Point(87, 56);
            txtNume.Name = "txtNume";
            txtNume.Size = new Size(150, 31);
            txtNume.TabIndex = 13;
            txtNume.KeyPress += txtNume_KeyPress;
            // 
            // txtIdClient
            // 
            txtIdClient.Location = new Point(105, 16);
            txtIdClient.Name = "txtIdClient";
            txtIdClient.Size = new Size(150, 31);
            txtIdClient.TabIndex = 12;
            txtIdClient.KeyPress += txtIdClient_KeyPress;
            // 
            // lblNume
            // 
            lblNume.AutoSize = true;
            lblNume.Location = new Point(20, 59);
            lblNume.Name = "lblNume";
            lblNume.Size = new Size(60, 25);
            lblNume.TabIndex = 11;
            lblNume.Text = "Nume";
            // 
            // lblAdresa
            // 
            lblAdresa.AutoSize = true;
            lblAdresa.Location = new Point(20, 98);
            lblAdresa.Name = "lblAdresa";
            lblAdresa.Size = new Size(67, 25);
            lblAdresa.TabIndex = 10;
            lblAdresa.Text = "Adresa";
            // 
            // lblIdClient
            // 
            lblIdClient.AutoSize = true;
            lblIdClient.Location = new Point(20, 19);
            lblIdClient.Name = "lblIdClient";
            lblIdClient.Size = new Size(79, 25);
            lblIdClient.TabIndex = 9;
            lblIdClient.Text = "ID Client";
            // 
            // errorProvider3
            // 
            errorProvider3.ContainerControl = this;
            // 
            // panelGrafic
            // 
            panelGrafic.Location = new Point(23, 46);
            panelGrafic.Name = "panelGrafic";
            panelGrafic.Size = new Size(730, 422);
            panelGrafic.TabIndex = 11;
            panelGrafic.Visible = false;
            panelGrafic.Paint += panelGrafic_Paint;
            // 
            // panelTabel
            // 
            panelTabel.Controls.Add(dgvProduse);
            panelTabel.Location = new Point(26, 49);
            panelTabel.Name = "panelTabel";
            panelTabel.Size = new Size(1170, 480);
            panelTabel.TabIndex = 13;
            panelTabel.Visible = false;
            // 
            // dgvProduse
            // 
            dgvProduse.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvProduse.ContextMenuStrip = contextMenuStripTabel;
            dgvProduse.Location = new Point(0, 0);
            dgvProduse.Name = "dgvProduse";
            dgvProduse.RowHeadersWidth = 62;
            dgvProduse.Size = new Size(1170, 480);
            dgvProduse.TabIndex = 0;
            // 
            // contextMenuStripTabel
            // 
            contextMenuStripTabel.ImageScalingSize = new Size(24, 24);
            contextMenuStripTabel.Items.AddRange(new ToolStripItem[] { copiazaInClipboardToolStripMenuItem });
            contextMenuStripTabel.Name = "contextMenuStripTabel";
            contextMenuStripTabel.Size = new Size(250, 36);
            // 
            // copiazaInClipboardToolStripMenuItem
            // 
            copiazaInClipboardToolStripMenuItem.Name = "copiazaInClipboardToolStripMenuItem";
            copiazaInClipboardToolStripMenuItem.Size = new Size(249, 32);
            copiazaInClipboardToolStripMenuItem.Text = "Copiaza in Clipboard";
            copiazaInClipboardToolStripMenuItem.Click += copiazaInClipboardToolStripMenuItem_Click_1;
            // 
            // printDocument1
            // 
            printDocument1.PrintPage += printDocument1_PrintPage;
            // 
            // printPreviewDialog1
            // 
            printPreviewDialog1.AutoScrollMargin = new Size(0, 0);
            printPreviewDialog1.AutoScrollMinSize = new Size(0, 0);
            printPreviewDialog1.ClientSize = new Size(400, 300);
            printPreviewDialog1.Enabled = true;
            printPreviewDialog1.Icon = (Icon)resources.GetObject("printPreviewDialog1.Icon");
            printPreviewDialog1.Name = "printPreviewDialog1";
            printPreviewDialog1.Visible = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1345, 640);
            Controls.Add(panelProdus);
            Controls.Add(panelTabel);
            Controls.Add(statusControl1);
            Controls.Add(panelGrafic);
            Controls.Add(panelClient);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "Form1";
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).EndInit();
            ContextMenuStripProduse.ResumeLayout(false);
            panelProdus.ResumeLayout(false);
            panelProdus.PerformLayout();
            panelClient.ResumeLayout(false);
            panelClient.PerformLayout();
            contextMenuStripClienti.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)errorProvider3).EndInit();
            panelTabel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dgvProduse).EndInit();
            contextMenuStripTabel.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private MenuStrip menuStrip1;
        private ToolStripMenuItem fisierToolStripMenuItem;
        private ToolStripMenuItem salveazaDateToolStripMenuItem;
        private ToolStripMenuItem afiseazaDateToolStripMenuItem;
        private ToolStripMenuItem adaugaToolStripMenuItem;
        private ToolStripMenuItem produsToolStripMenuItem;
        private ToolStripMenuItem clientToolStripMenuItem;
        private Label lblIdProdus;
        private Label lblPret;
        private Label lblDenumire;
        private TextBox txtIdProdus;
        private TextBox txtDenumire;
        private TextBox txtPret;
        private Button btnAdaugaProdus;
        private ErrorProvider errorProvider1;
        private ErrorProvider errorProvider2;
        private ListBox lstBx_date;
        private ContextMenuStrip ContextMenuStripProduse;
        private ToolStripMenuItem stergeProduseToolStripMenuItem;
        private Panel panelClient;
        private Button btnAdaugaClient;
        private TextBox txtAdresa;
        private TextBox txtNume;
        private TextBox txtIdClient;
        private Label lblNume;
        private Label lblAdresa;
        private Label lblIdClient;
        private Panel panelProdus;
        private ListBox lstBx_clienti;
        private ErrorProvider errorProvider3;
        private ContextMenuStrip contextMenuStripClienti;
        private ToolStripMenuItem stergereClientToolStripMenuItem;
        private ToolStripMenuItem fisierClientiToolStripMenuItem;
        private ToolStripMenuItem salveazaClientiToolStripMenuItem;
        private ToolStripMenuItem afiseazaClientiToolStripMenuItem;
        private ListBox lstBx_cosDeCumparaturi;
        private Label lblCosDeCumparaturi;
        private ToolStripMenuItem graficPreturiToolStripMenuItem;
        private Panel panelGrafic;
        private ToolStripMenuItem salveazaXMLToolStripMenuItem;
        private ToolStripMenuItem incarcaXMLToolStripMenuItem;
        private Proiect_gestiuneVanzari.StatusControl statusControl1;
        private ToolStripMenuItem vizualizareTabelToolStripMenuItem;
        private Panel panelTabel;
        private DataGridView dgvProduse;
        private ToolStripMenuItem printeazaListaProduseToolStripMenuItem;
        private System.Drawing.Printing.PrintDocument printDocument1;
        private PrintPreviewDialog printPreviewDialog1;
        private ToolStripMenuItem bazaDeDateToolStripMenuItem;
        private ToolStripMenuItem salveazaInBDToolStripMenuItem;
        private ToolStripMenuItem incarcaDinBDToolStripMenuItem;
        private ContextMenuStrip contextMenuStripTabel;
        private ToolStripMenuItem copiazaInClipboardToolStripMenuItem;
    }
}
