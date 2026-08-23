using System.Diagnostics.CodeAnalysis;

namespace seminar5
{
    partial class Form1
    {
        Label lbl1;
        TextBox txt1;
        Label lbl2;
        TextBox txt2;
        Label lbl3;
        TextBox txt3;
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
            lbl1 = new Label();
            txt1 = new TextBox();
            lbl2 = new Label();
            txt2 = new TextBox();
            btn = new Button();
            SuspendLayout();
            // 
            // lbl1
            // 
            lbl1.BorderStyle = BorderStyle.Fixed3D;
            lbl1.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            lbl1.ForeColor = Color.LawnGreen;
            lbl1.Location = new Point(100, 30);
            lbl1.Name = "lbl1";
            lbl1.Size = new Size(140, 60);
            lbl1.TabIndex = 0;
            lbl1.Text = "Nota 1";
            lbl1.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // txt1
            // 
            txt1.BackColor = Color.MistyRose;
            txt1.Enabled = false;
            txt1.ForeColor = Color.BlueViolet;
            txt1.Location = new Point(263, 36);
            txt1.Name = "txt1";
            txt1.Size = new Size(100, 30);
            txt1.TabIndex = 1;
            txt1.TextAlign = HorizontalAlignment.Center;
            // 
            // lbl2
            // 
            lbl2.BorderStyle = BorderStyle.Fixed3D;
            lbl2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            lbl2.ForeColor = Color.LightSeaGreen;
            lbl2.Location = new Point(101, 100);
            lbl2.Name = "lbl2";
            lbl2.Size = new Size(140, 60);
            lbl2.TabIndex = 2;
            lbl2.Text = "Nota 2";
            lbl2.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // txt2
            // 
            txt2.BackColor = Color.MistyRose;
            txt2.Enabled = false;
            txt2.ForeColor = Color.BlueViolet;
            txt2.Location = new Point(263, 114);
            txt2.Name = "txt2";
            txt2.Size = new Size(100, 31);
            txt2.TabIndex = 3;
            txt2.TextAlign = HorizontalAlignment.Center;
            // 
            // btn
            // 
            btn.BackColor = Color.MistyRose;
            btn.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btn.ForeColor = Color.RoyalBlue;
            btn.Location = new Point(184, 200);
            btn.Name = "btn";
            btn.Size = new Size(120, 30);
            btn.TabIndex = 4;
            btn.Text = "START";
            btn.UseVisualStyleBackColor = false;
            btn.Click += btn_1st_click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.RebeccaPurple;
            ClientSize = new Size(500, 500);
            Controls.Add(lbl1);
            Controls.Add(txt1);
            Controls.Add(lbl2);
            Controls.Add(txt2);
            Controls.Add(btn);
            Name = "Form1";
            Text = "Seminar5";
            ResumeLayout(false);
            PerformLayout();
        }

        private void btn_1st_click(object sender, EventArgs e)
        {
            Button b = sender as Button;
            MessageBox.Show("Butonul " + b.Text + " a fost apasat", "Important!!!");

            txt1.Enabled = Enabled;
            txt2.Enabled = Enabled;

            b.Text = "TOTAL";

            b.Click -= new EventHandler(btn_1st_click);
            b.Click += new EventHandler(btn_click);
        }

        private void btn_click(object sender, EventArgs e)
        {

            int nota1, nota2;
            try
            {
                nota1 = Convert.ToInt32(txt1.Text);
            }
            catch (Exception ex)
            {
                txt1.ForeColor = Color.DarkRed;
                txt1.Focus();
                return;
            }

            try
            {
                nota2 = Convert.ToInt32(txt2.Text);
            }
            catch(Exception ex)
            {
                txt2.ForeColor = Color.DarkRed;
                txt2.Focus();
                return;
            }

            txt1.ForeColor = Color.BlueViolet;
            txt2.ForeColor = Color.BlueViolet;

            if(nota1 < 1 || nota1 > 10)
            {
                Random rdm = new Random();
                txt1.ForeColor = Color.FromArgb(rdm.Next(256), rdm.Next(256), rdm.Next(256), rdm.Next(256));
                txt1.Focus();
                return;
            }
            if(nota2 < 1 || nota2 > 10)
            {
                Random rdm = new Random();
                txt2.ForeColor = Color.FromArgb(rdm.Next(256), rdm.Next(256), rdm.Next(256), rdm.Next(256));
                txt2.Focus();
                return;
            }

            MessageBox.Show(txt1.Text + " + " + txt2.Text + " = " + (nota1 + nota2), "Suma");

        }

        #endregion

        private Button btn;
    }
}
