namespace Seminar_6
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
            lblNota1 = new Label();
            lblNota2 = new Label();
            lblNota3 = new Label();
            txtNota1 = new TextBox();
            txtNota2 = new TextBox();
            txtNota3 = new TextBox();
            btnNote = new Button();
            errorProvider1 = new ErrorProvider(components);
            btnErrOn = new Button();
            btnOFF = new Button();
            menuStrip1 = new MenuStrip();
            noteAleatoareToolStripMenuItem = new ToolStripMenuItem();
            stergeNoteToolStripMenuItem = new ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).BeginInit();
            menuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // lblNota1
            // 
            lblNota1.BorderStyle = BorderStyle.Fixed3D;
            lblNota1.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            lblNota1.Location = new Point(12, 35);
            lblNota1.Name = "lblNota1";
            lblNota1.Size = new Size(79, 23);
            lblNota1.TabIndex = 0;
            lblNota1.Text = "Nota #1";
            // 
            // lblNota2
            // 
            lblNota2.BorderStyle = BorderStyle.Fixed3D;
            lblNota2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            lblNota2.Location = new Point(12, 70);
            lblNota2.Name = "lblNota2";
            lblNota2.Size = new Size(79, 23);
            lblNota2.TabIndex = 1;
            lblNota2.Text = "Nota #2";
            // 
            // lblNota3
            // 
            lblNota3.BorderStyle = BorderStyle.Fixed3D;
            lblNota3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            lblNota3.Location = new Point(12, 104);
            lblNota3.Name = "lblNota3";
            lblNota3.Size = new Size(79, 23);
            lblNota3.TabIndex = 2;
            lblNota3.Text = "Nota #3";
            // 
            // txtNota1
            // 
            txtNota1.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            txtNota1.Location = new Point(97, 35);
            txtNota1.Name = "txtNota1";
            txtNota1.Size = new Size(100, 23);
            txtNota1.TabIndex = 3;
            txtNota1.TextAlign = HorizontalAlignment.Right;
            // 
            // txtNota2
            // 
            txtNota2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            txtNota2.Location = new Point(97, 68);
            txtNota2.Name = "txtNota2";
            txtNota2.Size = new Size(100, 23);
            txtNota2.TabIndex = 4;
            txtNota2.TextAlign = HorizontalAlignment.Center;
            // 
            // txtNota3
            // 
            txtNota3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            txtNota3.Location = new Point(97, 104);
            txtNota3.Name = "txtNota3";
            txtNota3.Size = new Size(100, 23);
            txtNota3.TabIndex = 5;
            txtNota3.KeyPress += nota3_keypress;
            txtNota3.Validating += nota3_validating;
            // 
            // btnNote
            // 
            btnNote.Location = new Point(13, 141);
            btnNote.Name = "btnNote";
            btnNote.Size = new Size(184, 23);
            btnNote.TabIndex = 6;
            btnNote.Text = "&Arata NOTE";
            btnNote.UseVisualStyleBackColor = true;
            btnNote.Click += btnNote_Click;
            // 
            // errorProvider1
            // 
            errorProvider1.ContainerControl = this;
            // 
            // btnErrOn
            // 
            btnErrOn.Location = new Point(12, 179);
            btnErrOn.Name = "btnErrOn";
            btnErrOn.Size = new Size(75, 23);
            btnErrOn.TabIndex = 7;
            btnErrOn.Text = "Err ON";
            btnErrOn.UseVisualStyleBackColor = true;
            btnErrOn.Click += btnErrOn_Click;
            // 
            // btnOFF
            // 
            btnOFF.Location = new Point(122, 179);
            btnOFF.Name = "btnOFF";
            btnOFF.Size = new Size(75, 23);
            btnOFF.TabIndex = 8;
            btnOFF.Text = "Err OFF";
            btnOFF.UseVisualStyleBackColor = true;
            btnOFF.Click += btnOFF_Click;
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { noteAleatoareToolStripMenuItem, stergeNoteToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(215, 24);
            menuStrip1.TabIndex = 9;
            menuStrip1.Text = "menuStrip1";
            // 
            // noteAleatoareToolStripMenuItem
            // 
            noteAleatoareToolStripMenuItem.Name = "noteAleatoareToolStripMenuItem";
            noteAleatoareToolStripMenuItem.Size = new Size(98, 20);
            noteAleatoareToolStripMenuItem.Text = "Note Aleatoare";
            noteAleatoareToolStripMenuItem.Click += noteAleatoareToolStripMenuItem_Click;
            // 
            // stergeNoteToolStripMenuItem
            // 
            stergeNoteToolStripMenuItem.Name = "stergeNoteToolStripMenuItem";
            stergeNoteToolStripMenuItem.Size = new Size(81, 20);
            stergeNoteToolStripMenuItem.Text = "Sterge Note";
            stergeNoteToolStripMenuItem.Click += stergeNoteToolStripMenuItem_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.GradientInactiveCaption;
            ClientSize = new Size(215, 171);
            Controls.Add(btnOFF);
            Controls.Add(btnErrOn);
            Controls.Add(btnNote);
            Controls.Add(txtNota3);
            Controls.Add(txtNota2);
            Controls.Add(txtNota1);
            Controls.Add(lblNota3);
            Controls.Add(lblNota2);
            Controls.Add(lblNota1);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "App #6";
            ((System.ComponentModel.ISupportInitialize)errorProvider1).EndInit();
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label lblNota1;
        private Label lblNota2;
        private Label lblNota3;
        private TextBox txtNota1;
        private TextBox txtNota2;
        private TextBox txtNota3;
        private Button btnNote;
        private ErrorProvider errorProvider1;
        private Button btnOFF;
        private Button btnErrOn;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem noteAleatoareToolStripMenuItem;
        private ToolStripMenuItem stergeNoteToolStripMenuItem;
    }
}
