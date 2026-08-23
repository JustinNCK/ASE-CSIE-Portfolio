namespace Imobiliare
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
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            textBox1 = new TextBox();
            textBox2 = new TextBox();
            textBox3 = new TextBox();
            textBox4 = new TextBox();
            textBox5 = new TextBox();
            radioButtonCasa = new RadioButton();
            radioButtonApartament = new RadioButton();
            label6 = new Label();
            label7 = new Label();
            label8 = new Label();
            textBox6 = new TextBox();
            textBox7 = new TextBox();
            textBox8 = new TextBox();
            buttonAdaugare = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.Location = new Point(46, 44);
            label1.Name = "label1";
            label1.Size = new Size(88, 38);
            label1.TabIndex = 0;
            label1.Text = "Cod";
            // 
            // label2
            // 
            label2.Location = new Point(46, 82);
            label2.Name = "label2";
            label2.Size = new Size(106, 38);
            label2.TabIndex = 1;
            label2.Text = "Denumire";
            // 
            // label3
            // 
            label3.Location = new Point(46, 120);
            label3.Name = "label3";
            label3.Size = new Size(88, 38);
            label3.TabIndex = 2;
            label3.Text = "Suprafata";
            // 
            // label4
            // 
            label4.Location = new Point(46, 158);
            label4.Name = "label4";
            label4.Size = new Size(88, 38);
            label4.TabIndex = 3;
            label4.Text = "Pret";
            // 
            // label5
            // 
            label5.Location = new Point(46, 196);
            label5.Name = "label5";
            label5.Size = new Size(147, 38);
            label5.TabIndex = 4;
            label5.Text = "Numar Camere";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(199, 41);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(150, 31);
            textBox1.TabIndex = 5;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(199, 80);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(150, 31);
            textBox2.TabIndex = 6;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(199, 117);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(150, 31);
            textBox3.TabIndex = 7;
            // 
            // textBox4
            // 
            textBox4.Location = new Point(199, 155);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(150, 31);
            textBox4.TabIndex = 8;
            // 
            // textBox5
            // 
            textBox5.Location = new Point(199, 196);
            textBox5.Name = "textBox5";
            textBox5.Size = new Size(150, 31);
            textBox5.TabIndex = 9;
            // 
            // radioButtonCasa
            // 
            radioButtonCasa.AutoSize = true;
            radioButtonCasa.Location = new Point(556, 69);
            radioButtonCasa.Name = "radioButtonCasa";
            radioButtonCasa.Size = new Size(74, 29);
            radioButtonCasa.TabIndex = 10;
            radioButtonCasa.TabStop = true;
            radioButtonCasa.Text = "Casa";
            radioButtonCasa.UseVisualStyleBackColor = true;
            // 
            // radioButtonApartament
            // 
            radioButtonApartament.AutoSize = true;
            radioButtonApartament.Location = new Point(556, 117);
            radioButtonApartament.Name = "radioButtonApartament";
            radioButtonApartament.Size = new Size(131, 29);
            radioButtonApartament.TabIndex = 11;
            radioButtonApartament.TabStop = true;
            radioButtonApartament.Text = "Apartament";
            radioButtonApartament.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            label6.Location = new Point(33, 271);
            label6.Name = "label6";
            label6.Size = new Size(147, 38);
            label6.TabIndex = 12;
            label6.Text = "Etaj";
            // 
            // label7
            // 
            label7.Location = new Point(33, 309);
            label7.Name = "label7";
            label7.Size = new Size(147, 38);
            label7.TabIndex = 13;
            label7.Text = "Suprafata teren";
            // 
            // label8
            // 
            label8.Location = new Point(33, 347);
            label8.Name = "label8";
            label8.Size = new Size(147, 38);
            label8.TabIndex = 14;
            label8.Text = "Numar niveluri";
            // 
            // textBox6
            // 
            textBox6.Location = new Point(186, 268);
            textBox6.Name = "textBox6";
            textBox6.Size = new Size(150, 31);
            textBox6.TabIndex = 15;
            // 
            // textBox7
            // 
            textBox7.Location = new Point(186, 305);
            textBox7.Name = "textBox7";
            textBox7.Size = new Size(150, 31);
            textBox7.TabIndex = 16;
            // 
            // textBox8
            // 
            textBox8.Location = new Point(186, 344);
            textBox8.Name = "textBox8";
            textBox8.Size = new Size(150, 31);
            textBox8.TabIndex = 17;
            // 
            // buttonAdaugare
            // 
            buttonAdaugare.Location = new Point(448, 229);
            buttonAdaugare.Name = "buttonAdaugare";
            buttonAdaugare.Size = new Size(165, 92);
            buttonAdaugare.TabIndex = 18;
            buttonAdaugare.Text = "Adaugare";
            buttonAdaugare.UseVisualStyleBackColor = true;
            buttonAdaugare.Click += buttonAdaugare_Click;
            // 
            // FormAdaugare
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(buttonAdaugare);
            Controls.Add(textBox8);
            Controls.Add(textBox7);
            Controls.Add(textBox6);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(label6);
            Controls.Add(radioButtonApartament);
            Controls.Add(radioButtonCasa);
            Controls.Add(textBox5);
            Controls.Add(textBox4);
            Controls.Add(textBox3);
            Controls.Add(textBox2);
            Controls.Add(textBox1);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "FormAdaugare";
            Text = "FormAdaugare";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private TextBox textBox1;
        private TextBox textBox2;
        private TextBox textBox3;
        private TextBox textBox4;
        private TextBox textBox5;
        private RadioButton radioButtonCasa;
        private RadioButton radioButtonApartament;
        private Label label6;
        private Label label7;
        private Label label8;
        private TextBox textBox6;
        private TextBox textBox7;
        private TextBox textBox8;
        private Button buttonAdaugare;
    }
}