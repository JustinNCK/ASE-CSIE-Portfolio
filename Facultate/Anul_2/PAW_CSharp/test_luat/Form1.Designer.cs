namespace test_luat
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
            components = new System.ComponentModel.Container();
            colorDialog1 = new ColorDialog();
            lbl_nume = new Label();
            lbl_varsta = new Label();
            lbl_onorariu = new Label();
            lbl_disciplina = new Label();
            txt_nume = new TextBox();
            txt_onorariu = new TextBox();
            txt_Disciplina = new TextBox();
            txt_varsta = new TextBox();
            btn_salvare = new Button();
            errorProvider1 = new ErrorProvider(components);
            errorProvider2 = new ErrorProvider(components);
            lbl_nrSportivi = new Label();
            lbl_totalOnorarii = new Label();
            listBox1 = new ListBox();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).BeginInit();
            SuspendLayout();
            // 
            // lbl_nume
            // 
            lbl_nume.AutoSize = true;
            lbl_nume.Location = new Point(18, 40);
            lbl_nume.Name = "lbl_nume";
            lbl_nume.Size = new Size(60, 25);
            lbl_nume.TabIndex = 0;
            lbl_nume.Text = "Nume";
            // 
            // lbl_varsta
            // 
            lbl_varsta.AutoSize = true;
            lbl_varsta.Location = new Point(18, 84);
            lbl_varsta.Name = "lbl_varsta";
            lbl_varsta.Size = new Size(60, 25);
            lbl_varsta.TabIndex = 1;
            lbl_varsta.Text = "Varsta";
            // 
            // lbl_onorariu
            // 
            lbl_onorariu.AutoSize = true;
            lbl_onorariu.Location = new Point(18, 162);
            lbl_onorariu.Name = "lbl_onorariu";
            lbl_onorariu.Size = new Size(82, 25);
            lbl_onorariu.TabIndex = 2;
            lbl_onorariu.Text = "Onorariu";
            // 
            // lbl_disciplina
            // 
            lbl_disciplina.AutoSize = true;
            lbl_disciplina.Location = new Point(18, 119);
            lbl_disciplina.Name = "lbl_disciplina";
            lbl_disciplina.Size = new Size(87, 25);
            lbl_disciplina.TabIndex = 3;
            lbl_disciplina.Text = "Disciplina";
            // 
            // txt_nume
            // 
            txt_nume.Location = new Point(84, 40);
            txt_nume.Name = "txt_nume";
            txt_nume.Size = new Size(150, 31);
            txt_nume.TabIndex = 4;
            // 
            // txt_onorariu
            // 
            txt_onorariu.Location = new Point(106, 162);
            txt_onorariu.Name = "txt_onorariu";
            txt_onorariu.Size = new Size(150, 31);
            txt_onorariu.TabIndex = 5;
            txt_onorariu.KeyPress += txt_onorariu_KeyPress;
            // 
            // txt_Disciplina
            // 
            txt_Disciplina.Location = new Point(111, 122);
            txt_Disciplina.Name = "txt_Disciplina";
            txt_Disciplina.Size = new Size(150, 31);
            txt_Disciplina.TabIndex = 6;
            // 
            // txt_varsta
            // 
            txt_varsta.Location = new Point(84, 85);
            txt_varsta.Name = "txt_varsta";
            txt_varsta.ShortcutsEnabled = false;
            txt_varsta.Size = new Size(150, 31);
            txt_varsta.TabIndex = 7;
            // 
            // btn_salvare
            // 
            btn_salvare.Location = new Point(122, 222);
            btn_salvare.Name = "btn_salvare";
            btn_salvare.Size = new Size(112, 34);
            btn_salvare.TabIndex = 8;
            btn_salvare.Text = "Salvare";
            btn_salvare.UseVisualStyleBackColor = true;
            btn_salvare.Click += btn_salvare_Click;
            // 
            // errorProvider1
            // 
            errorProvider1.ContainerControl = this;
            // 
            // errorProvider2
            // 
            errorProvider2.ContainerControl = this;
            // 
            // lbl_nrSportivi
            // 
            lbl_nrSportivi.AutoSize = true;
            lbl_nrSportivi.Location = new Point(359, 84);
            lbl_nrSportivi.Name = "lbl_nrSportivi";
            lbl_nrSportivi.Size = new Size(180, 25);
            lbl_nrSportivi.TabIndex = 9;
            lbl_nrSportivi.Text = "Numar total sportivi: ";
            // 
            // lbl_totalOnorarii
            // 
            lbl_totalOnorarii.AutoSize = true;
            lbl_totalOnorarii.Location = new Point(359, 146);
            lbl_totalOnorarii.Name = "lbl_totalOnorarii";
            lbl_totalOnorarii.Size = new Size(124, 25);
            lbl_totalOnorarii.TabIndex = 10;
            lbl_totalOnorarii.Text = "Total onorarii: ";
            // 
            // listBox1
            // 
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 25;
            listBox1.Location = new Point(413, 248);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(180, 129);
            listBox1.TabIndex = 11;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(806, 577);
            Controls.Add(listBox1);
            Controls.Add(lbl_totalOnorarii);
            Controls.Add(lbl_nrSportivi);
            Controls.Add(btn_salvare);
            Controls.Add(txt_varsta);
            Controls.Add(txt_Disciplina);
            Controls.Add(txt_onorariu);
            Controls.Add(txt_nume);
            Controls.Add(lbl_disciplina);
            Controls.Add(lbl_onorariu);
            Controls.Add(lbl_varsta);
            Controls.Add(lbl_nume);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)errorProvider1).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ColorDialog colorDialog1;
        private Label lbl_nume;
        private Label lbl_varsta;
        private Label lbl_onorariu;
        private Label lbl_disciplina;
        private TextBox txt_nume;
        private TextBox txt_onorariu;
        private TextBox txt_Disciplina;
        private TextBox txt_varsta;
        private Button btn_salvare;
        private ErrorProvider errorProvider1;
        private ErrorProvider errorProvider2;
        private Label lbl_totalOnorarii;
        private Label lbl_nrSportivi;
        private ListBox listBox1;
    }
}
