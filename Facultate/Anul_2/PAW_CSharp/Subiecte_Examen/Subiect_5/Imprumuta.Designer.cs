namespace Subiect_5
{
    partial class Imprumuta
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
            label1 = new Label();
            comboBoxCartiDisponibile = new ComboBox();
            label2 = new Label();
            label3 = new Label();
            textBoxNume = new TextBox();
            dateTimePickerReturnare = new DateTimePicker();
            button1 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(39, 35);
            label1.Name = "label1";
            label1.Size = new Size(53, 25);
            label1.TabIndex = 0;
            label1.Text = "Carte";
            // 
            // comboBoxCartiDisponibile
            // 
            comboBoxCartiDisponibile.FormattingEnabled = true;
            comboBoxCartiDisponibile.Location = new Point(98, 32);
            comboBoxCartiDisponibile.Name = "comboBoxCartiDisponibile";
            comboBoxCartiDisponibile.Size = new Size(182, 33);
            comboBoxCartiDisponibile.TabIndex = 1;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(39, 87);
            label2.Name = "label2";
            label2.Size = new Size(60, 25);
            label2.TabIndex = 2;
            label2.Text = "Nume";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(39, 136);
            label3.Name = "label3";
            label3.Size = new Size(125, 25);
            label3.TabIndex = 3;
            label3.Text = "Data returnare";
            // 
            // textBoxNume
            // 
            textBoxNume.Location = new Point(98, 84);
            textBoxNume.Name = "textBoxNume";
            textBoxNume.Size = new Size(150, 31);
            textBoxNume.TabIndex = 4;
            // 
            // dateTimePickerReturnare
            // 
            dateTimePickerReturnare.Location = new Point(170, 136);
            dateTimePickerReturnare.Name = "dateTimePickerReturnare";
            dateTimePickerReturnare.Size = new Size(300, 31);
            dateTimePickerReturnare.TabIndex = 5;
            // 
            // button1
            // 
            button1.Location = new Point(281, 243);
            button1.Name = "button1";
            button1.Size = new Size(112, 34);
            button1.TabIndex = 6;
            button1.Text = "Imprumuta";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Imprumuta
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button1);
            Controls.Add(dateTimePickerReturnare);
            Controls.Add(textBoxNume);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(comboBoxCartiDisponibile);
            Controls.Add(label1);
            Name = "Imprumuta";
            Text = "Imprumuta";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private ComboBox comboBoxCartiDisponibile;
        private Label label2;
        private Label label3;
        private TextBox textBoxNume;
        private DateTimePicker dateTimePickerReturnare;
        private Button button1;
    }
}