namespace Seminar10_PAW
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
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            txtNume = new TextBox();
            txtNote = new TextBox();
            btnAdd = new Button();
            listBox1 = new ListBox();
            contextMenuStrip1 = new ContextMenuStrip(components);
            serializareToolStripMenuItem = new ToolStripMenuItem();
            xMLToolStripMenuItem = new ToolStripMenuItem();
            jSONToolStripMenuItem = new ToolStripMenuItem();
            deserializareToolStripMenuItem = new ToolStripMenuItem();
            xMLToolStripMenuItem1 = new ToolStripMenuItem();
            jSONToolStripMenuItem1 = new ToolStripMenuItem();
            btnList = new Button();
            menuStrip1 = new MenuStrip();
            salvareTEXTToolStripMenuItem = new ToolStripMenuItem();
            afisareTEXTToolStripMenuItem = new ToolStripMenuItem();
            contextMenuStrip1.SuspendLayout();
            menuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 14F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.ForeColor = Color.DarkOrchid;
            label1.Location = new Point(39, 53);
            label1.Name = "label1";
            label1.Size = new Size(190, 38);
            label1.TabIndex = 0;
            label1.Text = "Note student";
            label1.Click += label1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 14F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label2.ForeColor = Color.DarkOrchid;
            label2.Location = new Point(39, 101);
            label2.Name = "label2";
            label2.Size = new Size(205, 38);
            label2.TabIndex = 1;
            label2.Text = "Nume student";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 14F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label3.ForeColor = Color.DarkOrchid;
            label3.Location = new Point(39, 150);
            label3.Name = "label3";
            label3.Size = new Size(350, 38);
            label3.TabIndex = 2;
            label3.Text = "Note separate prin spatiu";
            // 
            // txtNume
            // 
            txtNume.Location = new Point(414, 101);
            txtNume.Name = "txtNume";
            txtNume.Size = new Size(300, 31);
            txtNume.TabIndex = 3;
            // 
            // txtNote
            // 
            txtNote.Location = new Point(414, 157);
            txtNote.Name = "txtNote";
            txtNote.Size = new Size(300, 31);
            txtNote.TabIndex = 4;
            // 
            // btnAdd
            // 
            btnAdd.Location = new Point(43, 238);
            btnAdd.Name = "btnAdd";
            btnAdd.Size = new Size(671, 73);
            btnAdd.TabIndex = 5;
            btnAdd.Text = "&Adaugare Student";
            btnAdd.UseVisualStyleBackColor = true;
            btnAdd.Click += btnAdd_Click;
            // 
            // listBox1
            // 
            listBox1.ContextMenuStrip = contextMenuStrip1;
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 25;
            listBox1.Location = new Point(742, 53);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(442, 154);
            listBox1.TabIndex = 6;
            // 
            // contextMenuStrip1
            // 
            contextMenuStrip1.ImageScalingSize = new Size(24, 24);
            contextMenuStrip1.Items.AddRange(new ToolStripItem[] { serializareToolStripMenuItem, deserializareToolStripMenuItem });
            contextMenuStrip1.Name = "contextMenuStrip1";
            contextMenuStrip1.Size = new Size(241, 101);
            // 
            // serializareToolStripMenuItem
            // 
            serializareToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { xMLToolStripMenuItem, jSONToolStripMenuItem });
            serializareToolStripMenuItem.Name = "serializareToolStripMenuItem";
            serializareToolStripMenuItem.Size = new Size(240, 32);
            serializareToolStripMenuItem.Text = "Serializare";
            // 
            // xMLToolStripMenuItem
            // 
            xMLToolStripMenuItem.Name = "xMLToolStripMenuItem";
            xMLToolStripMenuItem.Size = new Size(157, 34);
            xMLToolStripMenuItem.Text = "XML";
            xMLToolStripMenuItem.Click += xMLToolStripMenuItem_Click;
            // 
            // jSONToolStripMenuItem
            // 
            jSONToolStripMenuItem.Name = "jSONToolStripMenuItem";
            jSONToolStripMenuItem.Size = new Size(157, 34);
            jSONToolStripMenuItem.Text = "JSON";
            jSONToolStripMenuItem.Click += jSONToolStripMenuItem_Click;
            // 
            // deserializareToolStripMenuItem
            // 
            deserializareToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { xMLToolStripMenuItem1, jSONToolStripMenuItem1 });
            deserializareToolStripMenuItem.Name = "deserializareToolStripMenuItem";
            deserializareToolStripMenuItem.Size = new Size(240, 32);
            deserializareToolStripMenuItem.Text = "Deserializare";
            // 
            // xMLToolStripMenuItem1
            // 
            xMLToolStripMenuItem1.Name = "xMLToolStripMenuItem1";
            xMLToolStripMenuItem1.Size = new Size(270, 34);
            xMLToolStripMenuItem1.Text = "XML";
            xMLToolStripMenuItem1.Click += xMLToolStripMenuItem1_Click;
            // 
            // jSONToolStripMenuItem1
            // 
            jSONToolStripMenuItem1.Name = "jSONToolStripMenuItem1";
            jSONToolStripMenuItem1.Size = new Size(270, 34);
            jSONToolStripMenuItem1.Text = "JSON";
            jSONToolStripMenuItem1.Click += jSONToolStripMenuItem1_Click;
            // 
            // btnList
            // 
            btnList.Location = new Point(742, 238);
            btnList.Name = "btnList";
            btnList.Size = new Size(442, 73);
            btnList.TabIndex = 7;
            btnList.Text = "Incarca studenti";
            btnList.UseVisualStyleBackColor = true;
            btnList.Click += btnList_Click;
            // 
            // menuStrip1
            // 
            menuStrip1.ImageScalingSize = new Size(24, 24);
            menuStrip1.Items.AddRange(new ToolStripItem[] { salvareTEXTToolStripMenuItem, afisareTEXTToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(1261, 33);
            menuStrip1.TabIndex = 8;
            menuStrip1.Text = "menuStrip1";
            // 
            // salvareTEXTToolStripMenuItem
            // 
            salvareTEXTToolStripMenuItem.Name = "salvareTEXTToolStripMenuItem";
            salvareTEXTToolStripMenuItem.Size = new Size(127, 29);
            salvareTEXTToolStripMenuItem.Text = "Salvare TEXT";
            salvareTEXTToolStripMenuItem.Click += salvareTEXTToolStripMenuItem_Click;
            // 
            // afisareTEXTToolStripMenuItem
            // 
            afisareTEXTToolStripMenuItem.Name = "afisareTEXTToolStripMenuItem";
            afisareTEXTToolStripMenuItem.Size = new Size(125, 29);
            afisareTEXTToolStripMenuItem.Text = "Afisare TEXT";
            afisareTEXTToolStripMenuItem.Click += afisareTEXTToolStripMenuItem_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.LavenderBlush;
            ClientSize = new Size(1261, 746);
            Controls.Add(btnList);
            Controls.Add(listBox1);
            Controls.Add(btnAdd);
            Controls.Add(txtNote);
            Controls.Add(txtNume);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "Seminar 10 - Serializare";
            contextMenuStrip1.ResumeLayout(false);
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox txtNume;
        private TextBox txtNote;
        private Button btnAdd;
        private ListBox listBox1;
        private Button btnList;
        private ContextMenuStrip contextMenuStrip1;
        private ToolStripMenuItem serializareToolStripMenuItem;
        private ToolStripMenuItem xMLToolStripMenuItem;
        private ToolStripMenuItem jSONToolStripMenuItem;
        private ToolStripMenuItem deserializareToolStripMenuItem;
        private ToolStripMenuItem xMLToolStripMenuItem1;
        private ToolStripMenuItem jSONToolStripMenuItem1;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem salvareTEXTToolStripMenuItem;
        private ToolStripMenuItem afisareTEXTToolStripMenuItem;
    }
}
