namespace Proiect_gestiuneVanzari
{
    partial class StatusControl
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            lblNrProduse = new Label();
            lblNrClienti = new Label();
            SuspendLayout();
            // 
            // lblNrProduse
            // 
            lblNrProduse.AutoSize = true;
            lblNrProduse.Location = new Point(3, 17);
            lblNrProduse.Name = "lblNrProduse";
            lblNrProduse.Size = new Size(163, 25);
            lblNrProduse.TabIndex = 0;
            lblNrProduse.Text = "\"Numar produse: 0";
            // 
            // lblNrClienti
            // 
            lblNrClienti.AutoSize = true;
            lblNrClienti.Location = new Point(198, 17);
            lblNrClienti.Name = "lblNrClienti";
            lblNrClienti.Size = new Size(135, 25);
            lblNrClienti.TabIndex = 1;
            lblNrClienti.Text = "Numar clienti: 0";
            // 
            // StatusControl
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            Controls.Add(lblNrClienti);
            Controls.Add(lblNrProduse);
            Name = "StatusControl";
            Size = new Size(362, 60);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label lblNrProduse;
        private Label lblNrClienti;
    }
}
