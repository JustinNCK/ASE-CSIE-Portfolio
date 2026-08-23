namespace Subiect_6
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
            tabControl1 = new TabControl();
            tabPage1 = new TabPage();
            listViewMeciuri = new ListView();
            Data = new ColumnHeader();
            Gazda = new ColumnHeader();
            Oaspete = new ColumnHeader();
            ScorNeprogramat = new ColumnHeader();
            tabPage2 = new TabPage();
            listViewClasament = new ListView();
            Pozitie = new ColumnHeader();
            Echipa = new ColumnHeader();
            Localitate = new ColumnHeader();
            MeciuriJucate = new ColumnHeader();
            Puncte = new ColumnHeader();
            GoluriMarcate = new ColumnHeader();
            GoluriPrimite = new ColumnHeader();
            toolStrip1 = new ToolStrip();
            toolStripButton1 = new ToolStripButton();
            toolStripButton2 = new ToolStripButton();
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            toolStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Location = new Point(12, 38);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(776, 389);
            tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(listViewMeciuri);
            tabPage1.Location = new Point(4, 34);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(768, 351);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "tabPage1";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // listViewMeciuri
            // 
            listViewMeciuri.Columns.AddRange(new ColumnHeader[] { Data, Gazda, Oaspete, ScorNeprogramat });
            listViewMeciuri.Dock = DockStyle.Fill;
            listViewMeciuri.Location = new Point(3, 3);
            listViewMeciuri.Name = "listViewMeciuri";
            listViewMeciuri.Size = new Size(762, 345);
            listViewMeciuri.TabIndex = 0;
            listViewMeciuri.UseCompatibleStateImageBehavior = false;
            listViewMeciuri.View = View.Details;
            // 
            // Data
            // 
            Data.Tag = "Data";
            Data.Text = "Data";
            // 
            // Gazda
            // 
            Gazda.Tag = "Gazda";
            Gazda.Text = "Gazda";
            // 
            // Oaspete
            // 
            Oaspete.Tag = "Oaspete";
            Oaspete.Text = "Oaspete";
            // 
            // ScorNeprogramat
            // 
            ScorNeprogramat.Tag = "Scor/Neprogramat";
            ScorNeprogramat.Text = "Scor/Neprogramat";
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(listViewClasament);
            tabPage2.Location = new Point(4, 34);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(768, 351);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "tabPage2";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // listViewClasament
            // 
            listViewClasament.Columns.AddRange(new ColumnHeader[] { Pozitie, Echipa, Localitate, MeciuriJucate, Puncte, GoluriMarcate, GoluriPrimite });
            listViewClasament.Dock = DockStyle.Fill;
            listViewClasament.Location = new Point(3, 3);
            listViewClasament.Name = "listViewClasament";
            listViewClasament.Size = new Size(762, 345);
            listViewClasament.TabIndex = 0;
            listViewClasament.UseCompatibleStateImageBehavior = false;
            listViewClasament.View = View.Details;
            // 
            // Pozitie
            // 
            Pozitie.Tag = "Pozitie";
            Pozitie.Text = "Pozitie";
            // 
            // Echipa
            // 
            Echipa.Tag = "Echipa";
            Echipa.Text = "Echipa";
            // 
            // Localitate
            // 
            Localitate.Tag = "Localitate";
            Localitate.Text = "Localitate";
            // 
            // MeciuriJucate
            // 
            MeciuriJucate.Tag = "Meciuri jucate";
            MeciuriJucate.Text = "Meciuri jucate";
            // 
            // Puncte
            // 
            Puncte.Tag = "Puncte";
            Puncte.Text = "Puncte";
            // 
            // GoluriMarcate
            // 
            GoluriMarcate.Tag = "Goluri marcate";
            GoluriMarcate.Text = "Goluri marcate";
            // 
            // GoluriPrimite
            // 
            GoluriPrimite.Tag = "Goluri primite";
            GoluriPrimite.Text = "Goluri primite";
            // 
            // toolStrip1
            // 
            toolStrip1.ImageScalingSize = new Size(24, 24);
            toolStrip1.Items.AddRange(new ToolStripItem[] { toolStripButton1, toolStripButton2 });
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
            toolStripButton1.Text = "toolStripButton1";
            toolStripButton1.Click += toolStripButton1_Click;
            // 
            // toolStripButton2
            // 
            toolStripButton2.DisplayStyle = ToolStripItemDisplayStyle.Image;
            toolStripButton2.Image = (Image)resources.GetObject("toolStripButton2.Image");
            toolStripButton2.ImageTransparentColor = Color.Magenta;
            toolStripButton2.Name = "toolStripButton2";
            toolStripButton2.Size = new Size(34, 28);
            toolStripButton2.Text = "toolStripButton2";
            toolStripButton2.Click += toolStripButton2_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(toolStrip1);
            Controls.Add(tabControl1);
            Name = "Form1";
            Text = "Form1";
            FormClosing += Form1_FormClosing;
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage2.ResumeLayout(false);
            toolStrip1.ResumeLayout(false);
            toolStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TabControl tabControl1;
        private TabPage tabPage1;
        private ListView listViewMeciuri;
        private TabPage tabPage2;
        private ColumnHeader Data;
        private ColumnHeader Gazda;
        private ColumnHeader Oaspete;
        private ColumnHeader ScorNeprogramat;
        private ListView listViewClasament;
        private ColumnHeader Pozitie;
        private ColumnHeader Echipa;
        private ColumnHeader Localitate;
        private ColumnHeader MeciuriJucate;
        private ColumnHeader Puncte;
        private ColumnHeader GoluriMarcate;
        private ColumnHeader GoluriPrimite;
        private ToolStrip toolStrip1;
        private ToolStripButton toolStripButton1;
        private ToolStripButton toolStripButton2;
    }
}
