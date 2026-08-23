namespace Subiect_8
{
    partial class Adaugare
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            comboBoxMasini = new ComboBox();
            label1 = new Label();
            numericUpDownManopera = new NumericUpDown();
            numericUpDownPiese = new NumericUpDown();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            textBoxDescriere = new TextBox();
            buttonSalvare = new Button();
            ((System.ComponentModel.ISupportInitialize)numericUpDownManopera).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownPiese).BeginInit();
            SuspendLayout();
            // 
            // comboBoxMasini
            // 
            comboBoxMasini.FormattingEnabled = true;
            comboBoxMasini.Location = new Point(102, 29);
            comboBoxMasini.Name = "comboBoxMasini";
            comboBoxMasini.Size = new Size(182, 33);
            comboBoxMasini.TabIndex = 0;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(28, 32);
            label1.Name = "label1";
            label1.Size = new Size(68, 25);
            label1.TabIndex = 1;
            label1.Text = "Masina";
            // 
            // numericUpDownManopera
            // 
            numericUpDownManopera.Location = new Point(127, 90);
            numericUpDownManopera.Name = "numericUpDownManopera";
            numericUpDownManopera.Size = new Size(180, 31);
            numericUpDownManopera.TabIndex = 2;
            // 
            // numericUpDownPiese
            // 
            numericUpDownPiese.Location = new Point(86, 144);
            numericUpDownPiese.Name = "numericUpDownPiese";
            numericUpDownPiese.Size = new Size(180, 31);
            numericUpDownPiese.TabIndex = 3;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(28, 92);
            label2.Name = "label2";
            label2.Size = new Size(93, 25);
            label2.TabIndex = 4;
            label2.Text = "Manopera";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(28, 146);
            label3.Name = "label3";
            label3.Size = new Size(52, 25);
            label3.TabIndex = 5;
            label3.Text = "Piese";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(28, 198);
            label4.Name = "label4";
            label4.Size = new Size(84, 25);
            label4.TabIndex = 6;
            label4.Text = "Descriere";
            // 
            // textBoxDescriere
            // 
            textBoxDescriere.Location = new Point(118, 195);
            textBoxDescriere.Name = "textBoxDescriere";
            textBoxDescriere.Size = new Size(150, 31);
            textBoxDescriere.TabIndex = 7;
            // 
            // buttonSalvare
            // 
            buttonSalvare.Location = new Point(282, 294);
            buttonSalvare.Name = "buttonSalvare";
            buttonSalvare.Size = new Size(112, 34);
            buttonSalvare.TabIndex = 9;
            buttonSalvare.Text = "Salvare";
            buttonSalvare.UseVisualStyleBackColor = true;
            buttonSalvare.Click += buttonSalvare_Click;
            // 
            // Adaugare
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(buttonSalvare);
            Controls.Add(textBoxDescriere);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(numericUpDownPiese);
            Controls.Add(numericUpDownManopera);
            Controls.Add(label1);
            Controls.Add(comboBoxMasini);
            Name = "Adaugare";
            Text = "Adaugare";
            ((System.ComponentModel.ISupportInitialize)numericUpDownManopera).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownPiese).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ComboBox comboBoxMasini;
        private Label label1;
        private NumericUpDown numericUpDownManopera;
        private NumericUpDown numericUpDownPiese;
        private Label label2;
        private Label label3;
        private Label label4;
        private TextBox textBoxDescriere;
        private Button buttonSalvare;
    }
}