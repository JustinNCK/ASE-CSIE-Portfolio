namespace Seminar12_PAW
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
            menuStrip1 = new MenuStrip();
            incarcaDateGraficDinFisierToolStripMenuItem = new ToolStripMenuItem();
            panel1 = new Panel();
            menuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // menuStrip1
            // 
            menuStrip1.ImageScalingSize = new Size(24, 24);
            menuStrip1.Items.AddRange(new ToolStripItem[] { incarcaDateGraficDinFisierToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(1286, 33);
            menuStrip1.TabIndex = 0;
            menuStrip1.Text = "menuStrip1";
            // 
            // incarcaDateGraficDinFisierToolStripMenuItem
            // 
            incarcaDateGraficDinFisierToolStripMenuItem.Name = "incarcaDateGraficDinFisierToolStripMenuItem";
            incarcaDateGraficDinFisierToolStripMenuItem.Size = new Size(250, 29);
            incarcaDateGraficDinFisierToolStripMenuItem.Text = "Incarca Date Grafic din Fisier";
            incarcaDateGraficDinFisierToolStripMenuItem.Click += incarcaDateGraficDinFisierToolStripMenuItem_Click;
            // 
            // panel1
            // 
            panel1.Location = new Point(0, 36);
            panel1.Name = "panel1";
            panel1.Size = new Size(1286, 724);
            panel1.TabIndex = 1;
            panel1.Paint += panel1_paint;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1286, 772);
            Controls.Add(panel1);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "Grafic";
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private MenuStrip menuStrip1;
        private ToolStripMenuItem incarcaDateGraficDinFisierToolStripMenuItem;
        private Panel panel1;
    }
}
