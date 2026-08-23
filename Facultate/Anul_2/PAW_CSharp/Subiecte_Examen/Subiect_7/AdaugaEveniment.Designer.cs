namespace Subiect_7
{
    partial class AdaugaEveniment
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
            rbFilm = new RadioButton();
            rbConcert = new RadioButton();
            label1 = new Label();
            textBoxCod = new TextBox();
            textBoxTitlu = new TextBox();
            label2 = new Label();
            label3 = new Label();
            dateTimePickerData = new DateTimePicker();
            numericUpDownVarsta = new NumericUpDown();
            numericUpDownPret = new NumericUpDown();
            label4 = new Label();
            label5 = new Label();
            textBoxGen = new TextBox();
            label6 = new Label();
            textBoxArtist = new TextBox();
            label7 = new Label();
            label8 = new Label();
            numericUpDownDurata = new NumericUpDown();
            checkBox1 = new CheckBox();
            button1 = new Button();
            ((System.ComponentModel.ISupportInitialize)numericUpDownVarsta).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownPret).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownDurata).BeginInit();
            SuspendLayout();
            // 
            // rbFilm
            // 
            rbFilm.AutoSize = true;
            rbFilm.BackColor = Color.Transparent;
            rbFilm.Checked = true;
            rbFilm.Location = new Point(580, 36);
            rbFilm.Name = "rbFilm";
            rbFilm.Size = new Size(70, 29);
            rbFilm.TabIndex = 0;
            rbFilm.TabStop = true;
            rbFilm.Text = "Film";
            rbFilm.UseVisualStyleBackColor = false;
            rbFilm.CheckedChanged += rbFilm_CheckedChanged;
            // 
            // rbConcert
            // 
            rbConcert.AutoSize = true;
            rbConcert.Location = new Point(560, 197);
            rbConcert.Name = "rbConcert";
            rbConcert.Size = new Size(98, 29);
            rbConcert.TabIndex = 1;
            rbConcert.Text = "Concert";
            rbConcert.UseVisualStyleBackColor = true;
            rbConcert.CheckedChanged += rbConcert_CheckedChanged;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Location = new Point(32, 34);
            label1.Name = "label1";
            label1.Size = new Size(45, 25);
            label1.TabIndex = 2;
            label1.Text = "Cod";
            // 
            // textBoxCod
            // 
            textBoxCod.Location = new Point(81, 34);
            textBoxCod.Name = "textBoxCod";
            textBoxCod.Size = new Size(150, 31);
            textBoxCod.TabIndex = 3;
            // 
            // textBoxTitlu
            // 
            textBoxTitlu.Location = new Point(83, 80);
            textBoxTitlu.Name = "textBoxTitlu";
            textBoxTitlu.Size = new Size(150, 31);
            textBoxTitlu.TabIndex = 5;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Location = new Point(32, 79);
            label2.Name = "label2";
            label2.Size = new Size(45, 25);
            label2.TabIndex = 4;
            label2.Text = "Titlu";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Location = new Point(32, 122);
            label3.Name = "label3";
            label3.Size = new Size(85, 25);
            label3.TabIndex = 6;
            label3.Text = "Data/Ora";
            // 
            // dateTimePickerData
            // 
            dateTimePickerData.Location = new Point(123, 117);
            dateTimePickerData.Name = "dateTimePickerData";
            dateTimePickerData.Size = new Size(300, 31);
            dateTimePickerData.TabIndex = 7;
            // 
            // numericUpDownVarsta
            // 
            numericUpDownVarsta.Location = new Point(580, 132);
            numericUpDownVarsta.Name = "numericUpDownVarsta";
            numericUpDownVarsta.Size = new Size(180, 31);
            numericUpDownVarsta.TabIndex = 8;
            // 
            // numericUpDownPret
            // 
            numericUpDownPret.Location = new Point(83, 171);
            numericUpDownPret.Name = "numericUpDownPret";
            numericUpDownPret.Size = new Size(180, 31);
            numericUpDownPret.TabIndex = 9;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.BackColor = Color.Transparent;
            label4.Location = new Point(450, 132);
            label4.Name = "label4";
            label4.Size = new Size(124, 25);
            label4.TabIndex = 10;
            label4.Text = "Varsta minima";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.BackColor = Color.Transparent;
            label5.Location = new Point(32, 171);
            label5.Name = "label5";
            label5.Size = new Size(43, 25);
            label5.TabIndex = 11;
            label5.Text = "Pret";
            // 
            // textBoxGen
            // 
            textBoxGen.Location = new Point(580, 80);
            textBoxGen.Name = "textBoxGen";
            textBoxGen.Size = new Size(150, 31);
            textBoxGen.TabIndex = 13;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.BackColor = Color.Transparent;
            label6.Location = new Point(531, 80);
            label6.Name = "label6";
            label6.Size = new Size(43, 25);
            label6.TabIndex = 12;
            label6.Text = "Gen";
            // 
            // textBoxArtist
            // 
            textBoxArtist.Location = new Point(580, 244);
            textBoxArtist.Name = "textBoxArtist";
            textBoxArtist.Size = new Size(150, 31);
            textBoxArtist.TabIndex = 15;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.BackColor = Color.Transparent;
            label7.Location = new Point(526, 244);
            label7.Name = "label7";
            label7.Size = new Size(54, 25);
            label7.TabIndex = 14;
            label7.Text = "Artist";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.BackColor = Color.Transparent;
            label8.Location = new Point(32, 218);
            label8.Name = "label8";
            label8.Size = new Size(125, 25);
            label8.TabIndex = 17;
            label8.Text = "Durata minute";
            // 
            // numericUpDownDurata
            // 
            numericUpDownDurata.Location = new Point(167, 218);
            numericUpDownDurata.Name = "numericUpDownDurata";
            numericUpDownDurata.Size = new Size(184, 31);
            numericUpDownDurata.TabIndex = 16;
            // 
            // checkBox1
            // 
            checkBox1.AutoSize = true;
            checkBox1.Location = new Point(546, 294);
            checkBox1.Name = "checkBox1";
            checkBox1.Size = new Size(121, 29);
            checkBox1.TabIndex = 18;
            checkBox1.Text = "In aer liber";
            checkBox1.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            button1.Location = new Point(187, 311);
            button1.Name = "button1";
            button1.Size = new Size(112, 34);
            button1.TabIndex = 19;
            button1.Text = "Salveaza";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // AdaugaEveniment
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button1);
            Controls.Add(checkBox1);
            Controls.Add(label8);
            Controls.Add(numericUpDownDurata);
            Controls.Add(textBoxArtist);
            Controls.Add(label7);
            Controls.Add(textBoxGen);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(numericUpDownPret);
            Controls.Add(numericUpDownVarsta);
            Controls.Add(dateTimePickerData);
            Controls.Add(label3);
            Controls.Add(textBoxTitlu);
            Controls.Add(label2);
            Controls.Add(textBoxCod);
            Controls.Add(label1);
            Controls.Add(rbConcert);
            Controls.Add(rbFilm);
            Name = "AdaugaEveniment";
            Text = "AdaugaEveniment";
            ((System.ComponentModel.ISupportInitialize)numericUpDownVarsta).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownPret).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDownDurata).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private RadioButton rbFilm;
        private RadioButton rbConcert;
        private Label label1;
        private TextBox textBoxCod;
        private TextBox textBoxTitlu;
        private Label label2;
        private Label label3;
        private DateTimePicker dateTimePickerData;
        private NumericUpDown numericUpDownVarsta;
        private NumericUpDown numericUpDownPret;
        private Label label4;
        private Label label5;
        private TextBox textBoxGen;
        private Label label6;
        private TextBox textBoxArtist;
        private Label label7;
        public Label label8;
        private NumericUpDown numericUpDownDurata;
        private CheckBox checkBox1;
        private Button button1;
    }
}