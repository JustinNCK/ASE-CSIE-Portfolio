namespace Orar
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
            dataGridViewOrar = new DataGridView();
            toolStrip1 = new ToolStrip();
            toolStripButtonAdaugareElemet = new ToolStripButton();
            ((System.ComponentModel.ISupportInitialize)dataGridViewOrar).BeginInit();
            toolStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // dataGridViewOrar
            // 
            dataGridViewOrar.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewOrar.Location = new Point(12, 40);
            dataGridViewOrar.Name = "dataGridViewOrar";
            dataGridViewOrar.RowHeadersWidth = 62;
            dataGridViewOrar.Size = new Size(734, 385);
            dataGridViewOrar.TabIndex = 0;
            // 
            // toolStrip1
            // 
            toolStrip1.ImageScalingSize = new Size(24, 24);
            toolStrip1.Items.AddRange(new ToolStripItem[] { toolStripButtonAdaugareElemet });
            toolStrip1.Location = new Point(0, 0);
            toolStrip1.Name = "toolStrip1";
            toolStrip1.Size = new Size(800, 33);
            toolStrip1.TabIndex = 1;
            toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButtonAdaugareElemet
            // 
            toolStripButtonAdaugareElemet.DisplayStyle = ToolStripItemDisplayStyle.Image;
            toolStripButtonAdaugareElemet.Image = (Image)resources.GetObject("toolStripButtonAdaugareElemet.Image");
            toolStripButtonAdaugareElemet.ImageTransparentColor = Color.Magenta;
            toolStripButtonAdaugareElemet.Name = "toolStripButtonAdaugareElemet";
            toolStripButtonAdaugareElemet.Size = new Size(34, 28);
            toolStripButtonAdaugareElemet.Text = "Adaugare element";
            toolStripButtonAdaugareElemet.Click += toolStripButtonAdaugareElemet_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(toolStrip1);
            Controls.Add(dataGridViewOrar);
            Name = "Form1";
            Text = "Form1";
            FormClosing += Form1_FormClosing;
            ((System.ComponentModel.ISupportInitialize)dataGridViewOrar).EndInit();
            toolStrip1.ResumeLayout(false);
            toolStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private DataGridView dataGridViewOrar;
        private ToolStrip toolStrip1;
        private ToolStripButton toolStripButtonAdaugareElemet;
    }
}
