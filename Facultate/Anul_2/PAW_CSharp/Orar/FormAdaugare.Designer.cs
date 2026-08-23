namespace Orar
{
    partial class FormAdaugare
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
            comboBoxZi = new ComboBox();
            comboBoxOra = new ComboBox();
            textBoxDenumire = new TextBox();
            label1 = new Label();
            checkBoxCurs = new CheckBox();
            buttonSalvare = new Button();
            SuspendLayout();
            // 
            // comboBoxZi
            // 
            comboBoxZi.FormattingEnabled = true;
            comboBoxZi.Items.AddRange(new object[] { "1", "2", "3", "4", "5" });
            comboBoxZi.Location = new Point(12, 28);
            comboBoxZi.Name = "comboBoxZi";
            comboBoxZi.Size = new Size(182, 33);
            comboBoxZi.TabIndex = 0;
            // 
            // comboBoxOra
            // 
            comboBoxOra.FormattingEnabled = true;
            comboBoxOra.Items.AddRange(new object[] { "O7_30", "O9_00", "O10_30", "O12_00", "O13_30", "O15_00", "O16_30" });
            comboBoxOra.Location = new Point(12, 82);
            comboBoxOra.Name = "comboBoxOra";
            comboBoxOra.Size = new Size(182, 33);
            comboBoxOra.TabIndex = 1;
            // 
            // textBoxDenumire
            // 
            textBoxDenumire.Location = new Point(105, 131);
            textBoxDenumire.Name = "textBoxDenumire";
            textBoxDenumire.Size = new Size(150, 31);
            textBoxDenumire.TabIndex = 2;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(12, 134);
            label1.Name = "label1";
            label1.Size = new Size(87, 30);
            label1.TabIndex = 3;
            label1.Text = "Denumire";
            label1.UseCompatibleTextRendering = true;
            // 
            // checkBoxCurs
            // 
            checkBoxCurs.AutoSize = true;
            checkBoxCurs.Location = new Point(26, 187);
            checkBoxCurs.Name = "checkBoxCurs";
            checkBoxCurs.Size = new Size(73, 29);
            checkBoxCurs.TabIndex = 4;
            checkBoxCurs.Text = "Curs";
            checkBoxCurs.UseVisualStyleBackColor = true;
            // 
            // buttonSalvare
            // 
            buttonSalvare.Location = new Point(26, 271);
            buttonSalvare.Name = "buttonSalvare";
            buttonSalvare.Size = new Size(112, 34);
            buttonSalvare.TabIndex = 5;
            buttonSalvare.Text = "Salvare";
            buttonSalvare.UseVisualStyleBackColor = true;
            buttonSalvare.Click += buttonSalvare_Click;
            // 
            // FormAdaugare
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(buttonSalvare);
            Controls.Add(checkBoxCurs);
            Controls.Add(label1);
            Controls.Add(textBoxDenumire);
            Controls.Add(comboBoxOra);
            Controls.Add(comboBoxZi);
            Name = "FormAdaugare";
            Text = "FormAdaugare";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ComboBox comboBoxZi;
        private ComboBox comboBoxOra;
        private TextBox textBoxDenumire;
        private Label label1;
        private CheckBox checkBoxCurs;
        private Button buttonSalvare;
    }
}