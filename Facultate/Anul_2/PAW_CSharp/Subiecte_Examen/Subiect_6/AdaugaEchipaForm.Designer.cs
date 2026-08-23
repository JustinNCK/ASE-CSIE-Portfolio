namespace Subiect_6
{
    partial class AdaugaEchipaForm
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
            textBoxDenumire = new TextBox();
            label2 = new Label();
            textBoxLocalitate = new TextBox();
            buttonSalvare = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(39, 35);
            label1.Name = "label1";
            label1.Size = new Size(89, 25);
            label1.TabIndex = 0;
            label1.Text = "Denumire";
            // 
            // textBoxDenumire
            // 
            textBoxDenumire.Location = new Point(132, 32);
            textBoxDenumire.Name = "textBoxDenumire";
            textBoxDenumire.Size = new Size(182, 31);
            textBoxDenumire.TabIndex = 1;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(39, 87);
            label2.Name = "label2";
            label2.Size = new Size(86, 25);
            label2.TabIndex = 2;
            label2.Text = "Localitate";
            // 
            // textBoxLocalitate
            // 
            textBoxLocalitate.Location = new Point(132, 84);
            textBoxLocalitate.Name = "textBoxLocalitate";
            textBoxLocalitate.Size = new Size(182, 31);
            textBoxLocalitate.TabIndex = 3;
            // 
            // buttonSalvare
            // 
            buttonSalvare.Location = new Point(252, 200);
            buttonSalvare.Name = "buttonSalvare";
            buttonSalvare.Size = new Size(112, 34);
            buttonSalvare.TabIndex = 4;
            buttonSalvare.Text = "Salvare";
            buttonSalvare.UseVisualStyleBackColor = true;
            buttonSalvare.Click += buttonSalvare_Click;
            // 
            // AdaugaEchipaForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(656, 417);
            Controls.Add(buttonSalvare);
            Controls.Add(textBoxLocalitate);
            Controls.Add(label2);
            Controls.Add(textBoxDenumire);
            Controls.Add(label1);
            Name = "AdaugaEchipaForm";
            Text = "Adauga Echipa";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox textBoxDenumire;
        private Label label2;
        private TextBox textBoxLocalitate;
        private Button buttonSalvare;
    }
}