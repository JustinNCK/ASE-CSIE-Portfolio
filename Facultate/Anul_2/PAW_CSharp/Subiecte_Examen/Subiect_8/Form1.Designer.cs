namespace Subiect_8
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
            listViewService = new ListView();
            NumarInmatriculare = new ColumnHeader();
            Descriere = new ColumnHeader();
            Marca = new ColumnHeader();
            CostTotal = new ColumnHeader();
            Finalizata = new ColumnHeader();
            toolStrip1 = new ToolStrip();
            toolStripButton1 = new ToolStripButton();
            statusStrip1 = new StatusStrip();
            toolStripStatusLabelService = new ToolStripStatusLabel();
            toolStrip1.SuspendLayout();
            statusStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // listViewService
            // 
            listViewService.Columns.AddRange(new ColumnHeader[] { NumarInmatriculare, Marca, Descriere, CostTotal, Finalizata });
            listViewService.Location = new Point(0, 36);
            listViewService.Name = "listViewService";
            listViewService.Size = new Size(800, 389);
            listViewService.TabIndex = 0;
            listViewService.UseCompatibleStateImageBehavior = false;
            listViewService.View = View.Details;
            listViewService.MouseDoubleClick += listViewService_MouseDoubleClick;
            // 
            // NumarInmatriculare
            // 
            NumarInmatriculare.Tag = "Numar Inmatriculare";
            NumarInmatriculare.Text = "Numar Inmatriculare";
            // 
            // Descriere
            // 
            Descriere.Tag = "Descriere";
            Descriere.Text = "Descriere";
            // 
            // Marca
            // 
            Marca.Tag = "Marca";
            Marca.Text = "Marca";
            // 
            // CostTotal
            // 
            CostTotal.Tag = "Cost Total";
            CostTotal.Text = "Cost Total";
            // 
            // Finalizata
            // 
            Finalizata.Tag = "Finalizata";
            Finalizata.Text = "Finalizata";
            // 
            // toolStrip1
            // 
            toolStrip1.ImageScalingSize = new Size(24, 24);
            toolStrip1.Items.AddRange(new ToolStripItem[] { toolStripButton1 });
            toolStrip1.Location = new Point(0, 0);
            toolStrip1.Name = "toolStrip1";
            toolStrip1.Size = new Size(800, 33);
            toolStrip1.TabIndex = 1;
            toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            toolStripButton1.DisplayStyle = ToolStripItemDisplayStyle.Image;
            toolStripButton1.Image = (Image)resources.GetObject("toolStripButton1.Image");
            toolStripButton1.ImageTransparentColor = Color.Magenta;
            toolStripButton1.Name = "toolStripButton1";
            toolStripButton1.Size = new Size(34, 28);
            toolStripButton1.Text = "Adauga reparatie";
            toolStripButton1.Click += toolStripButton1_Click;
            // 
            // statusStrip1
            // 
            statusStrip1.ImageScalingSize = new Size(24, 24);
            statusStrip1.Items.AddRange(new ToolStripItem[] { toolStripStatusLabelService });
            statusStrip1.Location = new Point(0, 418);
            statusStrip1.Name = "statusStrip1";
            statusStrip1.Size = new Size(800, 32);
            statusStrip1.TabIndex = 2;
            statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabelService
            // 
            toolStripStatusLabelService.Name = "toolStripStatusLabelService";
            toolStripStatusLabelService.Size = new Size(179, 25);
            toolStripStatusLabelService.Text = "toolStripStatusLabel1";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(statusStrip1);
            Controls.Add(toolStrip1);
            Controls.Add(listViewService);
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

        private ListView listViewService;
        private ColumnHeader NumarInmatriculare;
        private ColumnHeader Marca;
        private ColumnHeader Descriere;
        private ColumnHeader CostTotal;
        private ColumnHeader Finalizata;
        private ToolStrip toolStrip1;
        private ToolStripButton toolStripButton1;
        private StatusStrip statusStrip1;
        private ToolStripStatusLabel toolStripStatusLabelService;
    }
}
