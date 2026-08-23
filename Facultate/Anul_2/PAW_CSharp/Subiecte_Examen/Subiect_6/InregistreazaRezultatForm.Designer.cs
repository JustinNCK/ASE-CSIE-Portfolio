namespace Subiect_6
{
    partial class InregistreazaRezultatForm
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            label1 = new Label();
            comboBoxMeciuri = new ComboBox();
            label2 = new Label();
            numericUpDownGazda = new NumericUpDown();
            label3 = new Label();
            numericUpDownOaspete = new NumericUpDown();
            buttonSalvare = new Button();
            ((System.ComponentModel.ISupportInitialize)numericUpDownGazda).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownOaspete).BeginInit();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(39, 35);
            label1.Name = "label1";
            label1.Size = new Size(49, 25);
            label1.TabIndex = 0;
            label1.Text = "Meci";
            // 
            // comboBoxMeciuri
            // 
            comboBoxMeciuri.FormattingEnabled = true;
            comboBoxMeciuri.Location = new Point(94, 32);
            comboBoxMeciuri.Name = "comboBoxMeciuri";
            comboBoxMeciuri.Size = new Size(300, 33);
            comboBoxMeciuri.TabIndex = 1;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(39, 87);
            label2.Name = "label2";
            label2.Size = new Size(113, 25);
            label2.TabIndex = 2;
            label2.Text = "Goluri Gazda";
            // 
            // numericUpDownGazda
            // 
            numericUpDownGazda.Location = new Point(158, 87);
            numericUpDownGazda.Name = "numericUpDownGazda";
            numericUpDownGazda.Size = new Size(120, 31);
            numericUpDownGazda.TabIndex = 3;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(39, 136);
            label3.Name = "label3";
            label3.Size = new Size(130, 25);
            label3.TabIndex = 4;
            label3.Text = "Goluri Oaspete";
            // 
            // numericUpDownOaspete
            // 
            numericUpDownOaspete.Location = new Point(175, 134);
            numericUpDownOaspete.Name = "numericUpDownOaspete";
            numericUpDownOaspete.Size = new Size(120, 31);
            numericUpDownOaspete.TabIndex = 5;
            // 
            // buttonSalvare
            // 
            buttonSalvare.Location = new Point(439, 116);
            buttonSalvare.Name = "buttonSalvare";
            buttonSalvare.Size = new Size(112, 34);
            buttonSalvare.TabIndex = 6;
            buttonSalvare.Text = "Salvare";
            buttonSalvare.UseVisualStyleBackColor = true;
            buttonSalvare.Click += buttonSalvare_Click;
            // 
            // InregistreazaRezultatForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(721, 280);
            Controls.Add(buttonSalvare);
            Controls.Add(numericUpDownOaspete);
            Controls.Add(label3);
            Controls.Add(numericUpDownGazda);
            Controls.Add(label2);
            Controls.Add(comboBoxMeciuri);
            Controls.Add(label1);
            Name = "InregistreazaRezultatForm";
            Text = "Inregistreaza Rezultat";
            ((System.ComponentModel.ISupportInitialize)numericUpDownGazda).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownOaspete).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private ComboBox comboBoxMeciuri;
        private Label label2;
        private NumericUpDown numericUpDownGazda;
        private Label label3;
        private NumericUpDown numericUpDownOaspete;
        private Button buttonSalvare;
    }
}